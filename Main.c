#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include "LinkedList.h"

 
void enter_data(struct Node** head, int index);
void display_options(struct Node** head);
void display_search_options(struct Node* head);
void await_user_prompt();
void input_data_from_file(struct Node** head);
volatile int signal_stop = 1;

void sig_handler(int signum)
{
    signal_stop = 0;
    fclose(stdin);
}

int main()
{
    signal(SIGINT, sig_handler);

    struct Node* head=NULL;
    //head = (struct Node *)malloc(sizeof(struct Node));
    input_data_from_file(&head);
    display(head, 10);
    display_options(&head);
    delete_whole_list(head);
}

void input_data_from_file(struct Node** head)
{
    char *token;
    char buffer[255];

    FILE *file = fopen("duom.txt", "r");
    if(file==NULL){
        printf("Nepavyko atverti duomenų failo\n");
        return;
    }
    for(int i=0; i<12; i++)
    {
        struct Node* data = (struct Node *)malloc(sizeof(struct Node));
        fscanf(file, "%s", buffer);

        token = strtok(buffer, ";");
        strcpy(data->name, token);

        token = strtok(NULL, ";");  
        strcpy(data->surname, token);

        token = strtok(NULL, ";");
        strcpy(data->email, token);

        token = strtok(NULL, ";");
        strcpy(data->phone, token);

        data->next=NULL;
        add_to_end(head, data);
    }
    fclose(file);
}

void enter_data(struct Node** head, int index)
{
    char token[40];
    struct Node* data = malloc(sizeof(struct Node));

    printf("Įveskite vardą: ");
    scanf("%s", token);
    strcpy(data->name, token);

    printf("Įveskite pavardę: ");
    scanf("%s", token);
    strcpy(data->surname, token);

    printf("Įveskite el. paštą: ");
    scanf("%s", token);
    strcpy(data->email, token);

    printf("Įveskite tel. nr.: ");
    scanf("%s", token);
    strcpy(data->phone, token);

    if(index == -1)
        add_to_end(head, data);
    else
        insert_at_position(head, data, index);
}

void display_search_options(struct Node* head)
{
    while(signal_stop!=0)
    {
        int option;
        char* entered_value;
        struct Node* found_element = NULL;
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
            scanf("%s", entered_value);
            found_element = find_by_name(head, entered_value);
            break;
        case 2:
            printf("Įveskite pavardę: ");
            scanf("%s", entered_value);
            found_element = find_by_surname(head, entered_value);
            break;
        case 3:
            printf("Įveskite el. paštą: ");
            scanf("%s",entered_value);
            found_element = find_by_email(head, entered_value);
            break;
        case 4:
            printf("Įveskite tel. numerį: ");
            scanf("%s", entered_value);
            found_element = find_by_phone(head, entered_value);
            break;
        case 5:
            return;
        default:
        printf("Įvyko klaida, bandykite dar kartą\n");
        getchar();
        await_user_prompt();
            break;
        }
        if(found_element !=NULL)
            if(found_element!=NULL)
                display_node(found_element);
    }
}
 
void display_options(struct Node** head)
{
    printf("ADRESŲ KNYGELĖ\n");
    while(signal_stop!=0)
    {
        int option;
        int index;
        struct Node* found_element = NULL;
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
                display(*head, -1);
                await_user_prompt();
                break;
            case 2:
                enter_data(head, -1);
                await_user_prompt();
                break;
            case 3:
                printf("Įveskite indeksą: ");
                scanf("%d", &index);
                if(index > 0)
                enter_data(head, index);
                await_user_prompt();
                break;                
            case 4:
                printf("Įveskite indeksą: ");
                scanf("%d",&index);
                remove_at_position(head, index);
                await_user_prompt();
                break;
            case 5:
                delete_whole_list(*head);
                *head=NULL;
                await_user_prompt();
                break;
            case 6:
                printf("Įveskite indeksą: ");
                scanf("%d",&index);
                found_element = find_by_index(*head, index);
                if(found_element != NULL)
                    display_node(found_element);
                await_user_prompt();
                break;
            case 7:
                display_search_options(*head);
                break;
            case 8:
                free(found_element);
                return;
            default:
                printf("Įvyko klaida. bandykite dar kartą.\n");
                getchar();
                await_user_prompt();
                break;
        }
    }
}
 
 
void await_user_prompt()
{
    printf("Spauskite 'Enter' kad tęsti darbą\n");
    getchar();
    getchar();
}