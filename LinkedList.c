#include "LinkedList.h"

void displayNode(struct Node* node)
{
    if(node == NULL)
        printf("Klaida\n");
    else
        printf("%s %s %s %s\n",node->name, node->surname, node->phone, node->email);
}

void display(struct Node* head, int number)
{
    if(head==NULL)
    {
        printf("Adresu knygele tuscia\n");
    }
    else
    {
        int i = 1; //used to display indexes
        int j = 0; //used to display a limited number of entries
        printf("Sąrašo elementai:\n");
        while(head!=NULL)
        {
            if(number != -1 && j >= number)
                return;
            printf("%d. ",i);
            displayNode(head);
            head=head->next;
            i++;
            j++;
        }
    }
}
 
 
void addToEnd(struct Node** head, struct Node* data)
{

    struct Node* temp = *head;
    if (temp == NULL) {
        *head = data;
        return; 
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = data;
}
 
void insertAtPosition(struct Node** head, struct Node* data, int position)
{
    displayNode(data);
    if(position <= 0)
    {
        printf("Ivestas neteisingas indeksas\n");
        return;
    }
    else if(position == 1)
    {
        data -> next = *head;
        *head = data;
        return;
    }

    struct Node* temp = *head;
    int i = 0;
    while(i < (position-2) && temp != NULL)
    {
        temp = temp -> next;
        i++;
    }
    if(temp == NULL)
    {
        addToEnd(head, data);
    }
    else
    {
    struct Node *newTemp = temp -> next;
    temp -> next = data;
    data -> next = newTemp;
    }

}
 
 
void removeAtPosition(struct Node** head, int position)
{
    struct Node* temp = *head; 
    int i;
    if(position < 1)
    {
        printf("Įvestas neteisingas indeksas\n");
        return;
    }
    else
    {
        struct Node* temp = *head;
        if(position==1)
        {
            *head = (*head)->next;

            if(temp !=  NULL)
                free(temp);
        }
        else
        {
            int i = 0;
            while(i < (position-2) && temp != NULL)
            {
                temp = temp -> next;
                i++;
            }
            if(temp == NULL)
            {
                printf("Įvestas indeksas per didelis\n");
                return;
            }
            struct Node* toDel = temp -> next;
            temp -> next = toDel -> next;

            if(toDel != NULL)
                free(toDel);
        }




    }
}

struct Node* findByEmail(struct Node* head, char* email)
{
    struct Node* temp = head;
    if(temp == NULL)
    {
        printf("Sąrašas tuščias\n");
        return NULL;
    }
    while(temp!=NULL)
    {
        if(strcmp(temp->email, email) == 0)
            return temp;
        temp = temp->next;
    }
    printf("Įrašas nerastas\n");
    return NULL;
}

struct Node* findByPhone(struct Node* head, char* phone)
{
    struct Node* temp = head;
    if(temp == NULL)
    {
        printf("Sąrašas tuščias\n");
        return NULL;
    }
    while(temp!=NULL)
    {
        if(strcmp(temp->phone, phone) == 0)
            return temp;
        temp = temp->next;
    }
    printf("Įrašas nerastas\n");
    return NULL;
}

struct Node* findByName(struct Node* head, char* name)
{
    struct Node* temp = head;
    if(temp == NULL)
    {
        printf("Sąrašas tuščias\n");
        return NULL;
    }
    while(temp!=NULL)
    {
        if(strcmp(temp->name, name) == 0)
            return temp;
        temp = temp->next;
    }
    printf("Įrašas nerastas\n");
    return NULL;
}

struct Node* findBySurname(struct Node* head, char* surname)
{
    struct Node* temp = head;
    if(temp == NULL)
    {
        printf("Sąrašas tuščias\n");
        return NULL;
    }
    while(temp!=NULL)
    {
        if(strcmp(temp->surname, surname) == 0)
            return temp;
        temp = temp->next;
    }
    printf("Įrašas nerastas\n");
    return NULL;
}
 
struct Node* findByIndex(struct Node* head, int index)
{
    if(head==NULL)
    {
        printf("Sąrašas yra tuščias\n");
        return NULL;
    }
    if(index < 1)
    {
        printf("Įvestas neteisingas indeksas\n");
        return NULL;
    }
    else
    {
        struct Node* temp = head;
        int i = 0;
        while(i < index && temp != NULL)
        {
            temp = temp -> next;
            i++;
        }
        return temp;
    }
}
 
void deleteWholeList(struct Node *list)
{
    struct Node *to_delete = list;
    while (list != NULL) {
        list = list->next;
        if(to_delete !=NULL)
            free(to_delete);
        to_delete = NULL;
        to_delete = list;
    }
}