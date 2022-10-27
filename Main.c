#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

 
 
void displayOptions();
void awaitUserPrompt();
 
int main()
{
    struct LinkedList addressBook;
    initializeList(&addressBook);
    displayOptions(&addressBook);
}

void displaySearchOptions(struct LinkedList* lp)
{
    while(1)
    {
        int option;
        char enteredValue[20];
        struct Node* foundElement = NULL;
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
            findByName(lp, enteredValue);
            break;
        case 2:
            printf("Įveskite pavardę: ");
            scanf("%s", enteredValue);
            findBySurname(lp, enteredValue);
            break;
        case 3:
            printf("Įveskite el. paštą: \n");
            scanf("%s",enteredValue);
            printf("%s\n", enteredValue);
            printf("Pasiekta\n");
            foundElement = findByEmail(lp, enteredValue);
            break;
        case 4:
            printf("Įveskite tel. numerį: ");
            scanf("%s", enteredValue);
            findByPhone(lp, enteredValue);
            break;
        case 5:
            return;
        default:
        printf("Įvyko klaida, bandykite dar kartą\n");
        getchar();
        awaitUserPrompt();
            break;
        }
    }
}
 
void displayOptions(struct LinkedList* lp)
{
    printf("ADRESU KNYGELE\n");
    while(1)
    {
        int option;
        int index;
        printf("1. Peržiūrėti visą sąrašą\n");
        printf("2. Prideti naują kontaktą į galą\n");
        printf("3. Įterpti pagal poziciją\n");
        printf("4. Ištrinti pagal poziciją\n");
        printf("5. Ištrinti visą sąrašą\n");
        printf("6. Rasti įrašą pagal nurodžius poziciją\n");
        printf("7. Ieškoti sąraše\n");
        printf("8. Baigti darbą\n");
        scanf("%d", &option);
 
        switch(option)
        {
            case 1:
                display(lp);
                awaitUserPrompt();
                break;
            case 2:
                awaitUserPrompt();
                break;
            case 3:
                awaitUserPrompt();
                break;                
            case 4:
                printf("Įveskite indeksą: ");
                scanf("%d",&index);
                removeAtPosition(lp, index);
                awaitUserPrompt();
                break;
            case 5:
                awaitUserPrompt();
                break;
            case 6:
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