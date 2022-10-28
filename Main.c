#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

 
void enterData();
void displayOptions();
void awaitUserPrompt();
void inputDataFromFile(struct LinkedList* lp);
 
int main()
{
    struct LinkedList addressBook;
    initializeList(&addressBook);
    inputDataFromFile(&addressBook);
    display(&addressBook, 10);
    displayOptions(&addressBook);
}

void inputDataFromFile(struct LinkedList* lp)
{
    char *token;
    char buffer[255];

    FILE *file = fopen("duom.txt", "r");

    for(int i=0; i<12; i++)
    {
        struct Data* data = malloc(sizeof(struct Data));
        fscanf(file, "%s", buffer);

        token = strtok(buffer, ";");
        data->name = malloc(strlen(token)*sizeof(char));
        strcpy(data->name, token);

        token = strtok(NULL, ";");  
        data->surname = malloc(strlen(token)*sizeof(char));
        strcpy(data->surname, token);

        token = strtok(NULL, ";");
        data->email = malloc(strlen(token)*sizeof(char));
        strcpy(data->email, token);

        token = strtok(NULL, ";");
        data->phone = malloc(strlen(token)*sizeof(char));
        strcpy(data->phone, token);

        addToEnd(lp, data);
    }
}

void enterData(struct LinkedList* lp, int index)
{
    char token[20];
    struct Data* data = malloc(sizeof(struct Data));

    printf("Įveskite vardą: ");
    scanf("%s", token);
    data->name = malloc(strlen(token)*sizeof(char));
    strcpy(data->name, token);

    printf("Įveskite pavardę: ");
    scanf("%s", token);
    data->surname = malloc(strlen(token)*sizeof(char));
    strcpy(data->surname, token);

    printf("Įveskite el. paštą: ");
    scanf("%s", token);
    data->email = malloc(strlen(token)*sizeof(char));
    strcpy(data->email, token);

    printf("Įveskite tel. nr.: ");
    scanf("%s", token);
    data->phone = malloc(strlen(token)*sizeof(char));
    strcpy(data->phone, token);

    if(index == -1)
        addToEnd(lp, data);
    else
        insertAtPosition(lp, data, index);
}

void displaySearchOptions(struct LinkedList* lp)
{
    while(1)
    {
        int option;
        char* enteredValue;
        struct Node* foundElement = malloc(sizeof(struct Node));
        printf("1. Rasti pagal vardą\n");
        printf("2. Rasti pagal pavardę\n");
        printf("3. Rasti pagal el. paštą\n");
        printf("4. Rasti pagal tel. numerį\n");
        printf("5. Grįžti atgal\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Įveskite vardą: ");
            scanf("%s", enteredValue);
            foundElement = findByName(lp, enteredValue);
            break;
        case 2:
            printf("Įveskite pavardę: ");
            scanf("%s", enteredValue);
            foundElement = findBySurname(lp, enteredValue);
            break;
        case 3:
            printf("Įveskite el. paštą: ");
            scanf("%s",enteredValue);
            foundElement = findByEmail(lp, enteredValue);
            break;
        case 4:
            printf("Įveskite tel. numerį: ");
            scanf("%s", enteredValue);
            foundElement = findByPhone(lp, enteredValue);
            break;
        case 5:
            return;
        default:
        printf("Įvyko klaida, bandykite dar kartą\n");
        getchar();
        awaitUserPrompt();
            break;
        }
        if(foundElement!=NULL)
            displayNode(foundElement);
    }
}
 
void displayOptions(struct LinkedList* lp)
{
    printf("ADRESŲ KNYGELĖ\n");
    while(1)
    {
        int option;
        int index;
        struct Data data;
        struct Node* foundElement = malloc(sizeof(struct Node));
        printf("1. Peržiūrėti visą sąrašą\n");
        printf("2. Pridėti naują kontaktą į galą\n");
        printf("3. Įterpti pagal poziciją\n");
        printf("4. Ištrinti pagal poziciją\n");
        printf("5. Ištrinti visą sąrašą\n");
        printf("6. Rasti įrašą nurodžius poziciją\n");
        printf("7. Ieškoti sąraše\n");
        printf("8. Baigti darbą\n");
        scanf("%d", &option);
 
        switch(option)
        {
            case 1:
                display(lp, -1);
                awaitUserPrompt();
                break;
            case 2:
                enterData(lp, -1);
                awaitUserPrompt();
                break;
            case 3:
                printf("Įveskite indeksą: ");
                scanf("%d", &index);
                if(index > 0)
                enterData(lp, index);
                awaitUserPrompt();
                break;                
            case 4:
                printf("Įveskite indeksą: ");
                scanf("%d",&index);
                removeAtPosition(lp, index);
                awaitUserPrompt();
                break;
            case 5:
                deleteWholeList(lp);
                awaitUserPrompt();
                break;
            case 6:
                printf("Įveskite indeksą: ");
                scanf("%d",&index);
                foundElement = findByIndex(lp, index);
                if(foundElement != NULL)
                    displayNode(foundElement);
                awaitUserPrompt();
                break;
            case 7:
                displaySearchOptions(lp);
                break;
            case 8:
                return;
            default:
                printf("Įvyko klaida. bandykite dar kartą.\n");
                getchar();
                awaitUserPrompt();
                break;
        }
    }
}
 
 
void awaitUserPrompt()
{
    printf("Spauskite 'Enter' kad tęsti darbą\n");
    getchar();
    getchar();
}