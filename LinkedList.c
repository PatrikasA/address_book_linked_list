#include "LinkedList.h"


void init_list(struct Node **head, struct Node **tail)
{
   *head = malloc(sizeof(struct Node));
   *tail = malloc(sizeof(struct Node));
   (*head)->next = *tail;
}

void displayNode(struct Node* node)
{
    printf("%s %s %s %s\n",node->name, node->surname, node->phone, node->email);
}

void display(struct Node* head, struct Node* tail, int number)
{
    if(head->next == tail)
    {
        printf("Adresu knygele tuscia\n");
    }
    else
    {
        struct Node* current = head;
        int i = 1; //used to display indexes
        int j = 0; //used to display a limited number of entries
        printf("Sąrašo elementai:\n");
        while(current->next!=tail)
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
 
 
void addToEnd(struct Node* first, struct Node *last, struct Node* data)
{
   struct Node *curr = first;
   while (curr->next != last)
   {
      curr = curr->next;
   }
   curr->next = malloc(sizeof(struct Node));
   curr->next = data;
   curr->next->next = last;
}
 
void insertAtPosition(struct Node* head, struct Node* tail, struct Node* data, int position)
{
    if(position <= 0)
    {
        printf("Ivestas neteisingas indeksas\n");
    }
    else
    {
        struct Node* current = head;
        if(current->next == tail)
            printf("Sąrašas tuščias");

        for(int i = 0; i < position-1; i++)
        {
            if(current -> next == tail)
                break;
            current = current->next;
        }

        if(current -> next == tail)
            addToEnd(head,tail, data);
        else
        {
            struct Node* temp = current -> next;
            current -> next = malloc(sizeof(struct Node));
            current -> next = data;
            current -> next -> next = temp; 
        }
    }
}
 
 
void removeAtPosition(struct Node* head, struct Node* tail, int position)
{
    struct Node* temp = head; 
    int i;
    if(position < 1)
    {
        printf("Įvestas neteisingas indeksas\n");
        return;
    }
    else
    {
        for (i = 1; i < position; i++)
        {
            if(temp -> next != tail)
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

struct Node* findByEmail(struct Node* head, struct Node* tail, char* email)
{
    struct Node* temp = head;
    if(temp == NULL)
    {
        printf("Sąrašas tuščias\n");
        return NULL;
    }
    while(temp->next != tail)
    {
        temp = temp->next;
        if(strcmp(temp->email, email) == 0)
            return temp;
    }
    printf("Įrašas nerastas\n");
    return NULL;
}

struct Node* findByPhone(struct Node* head, struct Node* tail, char* phone)
{
    struct Node* temp = head;
    if(temp == NULL)
    {
        printf("Sąrašas tuščias\n");
        return NULL;
    }
    while(temp->next != tail)
    {
        temp = temp->next;
        if(strcmp(temp->phone, phone) == 0)
            return temp;
    }
    printf("Įrašas nerastas\n");
    return NULL;
}

struct Node* findByName(struct Node* head, struct Node* tail, char* name)
{
    struct Node* temp = head;
    if(temp == NULL)
    {
        printf("Sąrašas tuščias\n");
        return NULL;
    }
    while(temp->next != tail)
    {
        temp = temp->next;
        if(strcmp(temp->name, name) == 0)
            return temp;
    }
    printf("Įrašas nerastas\n");
    return NULL;
}

struct Node* findBySurname(struct Node* head, struct Node* tail, char* surname)
{
    struct Node* temp = head;
    if(temp->next == tail)
    {
        printf("Sąrašas tuščias\n");
        return NULL;
    }
    while(temp->next != tail)
    {
        temp = temp->next;
        if(strcmp(temp->surname, surname) == 0)
            return temp;
    }
    printf("Įrašas nerastas\n");
    return NULL;
}
 
struct Node* findByIndex(struct Node* head, struct Node* tail, int index)
{
    if(head->next == tail)
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
            if(temp -> next != tail)
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
 
void deleteWholeList(struct Node* head, struct Node* tail)
{   
    if(head->next != tail)
    {
    struct Node* current = head->next;
    while (current->next != tail) {
        struct Node* temp = current;
        current = current -> next;
        free(temp); 
    }
    head -> next = tail;
    }
}