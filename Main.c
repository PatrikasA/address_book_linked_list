#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include "LinkedList.h"

 
void enterData();
void displayOptions();
void awaitUserPrompt();
void inputDataFromFile(struct Node* head);
int signalStop = 1;

void sig_handler(int signum)
{
    signalStop = 0;
    return;
}

int main()
{
    struct Node list;
    list.next = NULL;
    signal(SIGINT, sig_handler);
    //inputDataFromFile(&list);
    printf("CIA YRA PIRMAS ELELEMTAS HEAD ");
    //displayNode(&list);
    display(&list, 10);
    displayOptions(&list);
}

void inputDataFromFile(struct Node* head)
{
    char *token;
    char buffer[255];

    FILE *file = fopen("duom.txt", "r");

    for(int i=0; i<12; i++)
    {
        struct Node* data = (struct Node *)malloc(sizeof(struct Node));
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

        data->next=NULL;
        addToEnd(head, data);
    }
}

void enterData(struct Node* head, int index)
{
    char token[20];
    struct Node* data = malloc(sizeof(struct Node));

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
        addToEnd(head, data);
    else
        insertAtPosition(head, data, index);
}

void displaySearchOptions(struct Node* head)
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
            foundElement = findByName(head, enteredValue);
            break;
        case 2:
            printf("Įveskite pavardę: ");
            scanf("%s", enteredValue);
            foundElement = findBySurname(head, enteredValue);
            break;
        case 3:
            printf("Įveskite el. paštą: ");
            scanf("%s",enteredValue);
            foundElement = findByEmail(head, enteredValue);
            break;
        case 4:
            printf("Įveskite tel. numerį: ");
            scanf("%s", enteredValue);
            foundElement = findByPhone(head, enteredValue);
            break;
        case 5:
            return;
        default:
        printf("Įvyko klaida, bandykite dar kartą\n");
        getchar();
        awaitUserPrompt();
            break;
        }
        if(foundElement !=NULL)
            if(foundElement!=NULL)
                displayNode(foundElement);
    }
}
 
void displayOptions(struct Node* head)
{
    printf("ADRESŲ KNYGELĖ\n");
    while(1)
    {
        int option;
        int index;
        struct Node data;
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
                display(head, -1);
                awaitUserPrompt();
                break;
            case 2:
                enterData(head, -1);
                awaitUserPrompt();
                break;
            case 3:
                printf("Įveskite indeksą: ");
                scanf("%d", &index);
                if(index > 0)
                enterData(head, index);
                awaitUserPrompt();
                break;                
            case 4:
                printf("Įveskite indeksą: ");
                scanf("%d",&index);
                removeAtPosition(head, index);
                awaitUserPrompt();
                break;
            case 5:
                deleteWholeList(head);
                awaitUserPrompt();
                break;
            case 6:
                printf("Įveskite indeksą: ");
                scanf("%d",&index);
                foundElement = findByIndex(head, index);
                if(foundElement != NULL)
                    displayNode(foundElement);
                awaitUserPrompt();
                break;
            case 7:
                displaySearchOptions(head);
                break;
            case 8:
                deleteWholeList(head);
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