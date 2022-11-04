#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include "LinkedList.h"

 
void enterData(struct Node* head, struct Node* tail, int index);
void displayOptions(struct Node* head, struct Node* tail);
void displaySearchOptions(struct Node* head, struct Node* tail);
void awaitUserPrompt();
void inputDataFromFile(struct Node* head, struct Node* tail);
volatile int signalStop = 1;

void sig_handler(int signum)
{
    signalStop = 0;
    fclose(stdin);
}

int main()
{
    signal(SIGINT, sig_handler);

    struct Node *head, *tail;
    init_list(&head, &tail);
    inputDataFromFile(head,tail);
    display(head,tail, 10);
    displayOptions(head, tail);
    deleteWholeList(head, tail);
    free(head);
    free(tail);
}

void inputDataFromFile(struct Node* head, struct Node* tail)
{
    char *token;
    char buffer[255];

    FILE *file = fopen("duom.txt", "r");

    for(int i=0; i<12; i++)
    {
        struct Node* data = (struct Node *)malloc(sizeof(struct Node));
        fscanf(file, "%s", buffer);

        token = strtok(buffer, ";");
        //data->name = malloc(strlen(token)*sizeof(char));
        strcpy(data->name, token);

        token = strtok(NULL, ";");  
        //data->surname = malloc(strlen(token)*sizeof(char));
        strcpy(data->surname, token);

        token = strtok(NULL, ";");
        //data->email = malloc(strlen(token)*sizeof(char));
        strcpy(data->email, token);

        token = strtok(NULL, ";");
        //data->phone = malloc(strlen(token)*sizeof(char));
        strcpy(data->phone, token);

        data->next=NULL;
        addToEnd(head, tail, data);
    }
    fclose(file);
}

void enterData(struct Node* head, struct Node* tail, int index)
{
    char token[20];
    struct Node* data = malloc(sizeof(struct Node));

    printf("Įveskite vardą: ");
    scanf("%s", token);
    //data->name = malloc(strlen(token)*sizeof(char));
    strcpy(data->name, token);

    printf("Įveskite pavardę: ");
    scanf("%s", token);
    //data->surname = malloc(strlen(token)*sizeof(char));
    strcpy(data->surname, token);

    printf("Įveskite el. paštą: ");
    scanf("%s", token);
    //data->email = malloc(strlen(token)*sizeof(char));
    strcpy(data->email, token);

    printf("Įveskite tel. nr.: ");
    scanf("%s", token);
    //data->phone = malloc(strlen(token)*sizeof(char));
    strcpy(data->phone, token);

    if(index == -1)
        addToEnd(head, tail, data);
    else
        insertAtPosition(head, tail, data, index);
}

void displaySearchOptions(struct Node* head, struct Node* tail)
{
    while(signalStop!=0)
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
            foundElement = findByName(head, tail, enteredValue);
            break;
        case 2:
            printf("Įveskite pavardę: ");
            scanf("%s", enteredValue);
            foundElement = findBySurname(head, tail, enteredValue);
            break;
        case 3:
            printf("Įveskite el. paštą: ");
            scanf("%s",enteredValue);
            foundElement = findByEmail(head, tail, enteredValue);
            break;
        case 4:
            printf("Įveskite tel. numerį: ");
            scanf("%s", enteredValue);
            foundElement = findByPhone(head, tail, enteredValue);
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
        free(foundElement);
    }
}
 
void displayOptions(struct Node* head, struct Node* tail)
{
    printf("ADRESŲ KNYGELĖ\n");
    while(signalStop!=0)
    {
        int option;
        int index;
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
                display(head, tail, -1);
                awaitUserPrompt();
                break;
            case 2:
                enterData(head,tail, -1);
                awaitUserPrompt();
                break;
            case 3:
                printf("Įveskite indeksą: ");
                scanf("%d", &index);
                if(index > 0)
                enterData(head, tail, index);
                awaitUserPrompt();
                break;                
            case 4:
                printf("Įveskite indeksą: ");
                scanf("%d",&index);
                removeAtPosition(head, tail, index);
                awaitUserPrompt();
                break;
            case 5:
                deleteWholeList(head, tail);
                awaitUserPrompt();
                break;
            case 6:
                printf("Įveskite indeksą: ");
                scanf("%d",&index);
                foundElement = findByIndex(head, tail, index);
                if(foundElement != NULL)
                    displayNode(foundElement);
                awaitUserPrompt();
                break;
            case 7:
                displaySearchOptions(head, tail);
                break;
            case 8:
                deleteWholeList(head, tail);
                free(foundElement);
                return;
            default:
                printf("Įvyko klaida. bandykite dar kartą.\n");
                getchar();
                awaitUserPrompt();
                break;
        }
        free(foundElement);
    }
}
 
 
void awaitUserPrompt()
{
    printf("Spauskite 'Enter' kad tęsti darbą\n");
    getchar();
    getchar();
}