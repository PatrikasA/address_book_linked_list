#include "LinkedList.h"

void displayNode(struct Node* node)
{
    printf("%s %s %s %s\n",node->name, node->surname, node->phone, node->email);
}
 
void display(struct Node* head, int number)
{
    if(head == NULL)
    {
        printf("Adresu knygele tuscia\n");
    }
    else
    {
        struct Node* current = head;
        int i = 1; //used to display indexes
        int j = 0; //used to display a limited number of entries
        printf("Sąrašo elementai:\n");
        while(current->next!=NULL)
        {
            if(number != -1 && j >= number)
                return;
            current=current->next;
            printf("%d. ",i);
            displayNode(current);
            i++;
            j++;
        }
    }
}
 
 
void addToEnd(struct Node* head, struct Node* data)
{
    if(head == NULL)
    {
        head = (struct Node *)malloc(sizeof(struct Node));
        head = data;
        head -> next = NULL;
        return;
    }
    struct Node* current = head;
    while(current -> next != NULL)
    {
        current = current ->next;
    }
    
    current -> next = malloc(sizeof(struct Node));
    current -> next = data;
    current -> next -> next = NULL;
}
 
void insertAtPosition(struct Node* head, struct Node* data, int position)
{
    if(position <= 0)
    {
        printf("Ivestas neteisingas indeksas\n");
    }
    else
    {
        struct Node* current = head;
        if(current == NULL)
            printf("Sąrašas tuščias");

        for(int i = 0; i < position-1; i++)
        {
            if(current -> next == NULL)
                break;
            current = current->next;
        }

        if(current -> next == NULL)
            addToEnd(head, data);
        else
        {
            struct Node* temp = current -> next;
            current -> next = malloc(sizeof(struct Node));
            current -> next = data;
            current -> next -> next = temp; 
        }
    }
}
 
 
void removeAtPosition(struct Node* head, int position)
{
    struct Node* temp = head; 
    int i;
    if(position < 1)
    {
        printf("Įvestas neteisingas indeksas\n");
        return;
    }
    if(position == 1) {
        head = head->next; 
        temp->next = NULL;
        free(temp);
        printf("Sėkmingai panaikinta\n");
        return;
    }
    else
    {
        for (i = 1; i < position; i++)
        {
            if(temp -> next != NULL)
                temp = temp->next;
            else
            {
                printf("Įvestas neteisingas indeksas (didesnis nei elementų skaičius)\n");
                return;
            }
        }
        struct Node* del = temp->next;
        temp->next = temp->next->next;
        free(del);
        printf("Sėkmingai panaikinta\n");
        return;
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
    while(temp->next != NULL)
    {
        temp = temp->next;
        if(strcmp(temp->email, email) == 0)
            return temp;
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
    while(temp->next != NULL)
    {
        temp = temp->next;
        if(strcmp(temp->phone, phone) == 0)
            return temp;
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
    while(temp->next != NULL)
    {
        temp = temp->next;
        if(strcmp(temp->name, name) == 0)
            return temp;
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
    while(temp->next != NULL)
    {
        temp = temp->next;
        if(strcmp(temp->surname, surname) == 0)
            return temp;
    }
    printf("Įrašas nerastas\n");
    return NULL;
}
 
struct Node* findByIndex(struct Node* head, int index)
{
    if(head == NULL)
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
        for(int i = 0; i < index; i++)
        {   
            if(temp -> next != NULL)
               temp = temp -> next;
            else
            {
                printf("Įvestas neteisingas indeksas\n");
                return NULL;
            }
        }
        return temp;
    }
}
 
void deleteWholeList(struct Node* head)
{
struct Node* to_delete = head;
    while (head != NULL) {
        head = head->next;
        free(to_delete->next);
        to_delete = head;
    }
}