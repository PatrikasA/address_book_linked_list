#include "LinkedList.h"

void initializeList(struct LinkedList* listptr )
{
    listptr->head = malloc(sizeof(struct Node));
    listptr->tail = malloc(sizeof(struct Node));
    listptr->head->next = listptr->tail;
    listptr->numberOfElements = 0;
}

void displayNode(struct Node* node)
{
    printf("%s %s %s %s\n",node->data->name, node->data->surname, node->data->phone, node->data->email);
}
 
void display(struct LinkedList* lp, int number)
{
    if(lp->head->next == lp->tail)
    {
        printf("Adresu knygele tuscia\n");
    }
    else
    {
        struct Node* current = lp->head;
        int i = 1; //used to display indexes
        int j = 0; //used to display a limited number of entries
        printf("Sąrašo elementai:\n");
        while(current->next!=lp->tail)
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
 
 
void addToEnd(struct LinkedList* lp, struct Data* data)
{
    struct Node* current = lp -> head;
    while(current -> next != lp -> tail)
    {
        current = current ->next;
    }
    
    current -> next = malloc(sizeof(struct Node));
    current -> next ->data = data;
    current -> next -> next = lp -> tail;
    lp ->numberOfElements++;
}
 
void insertAtPosition(struct LinkedList* lp, struct Data* data, int position)
{
    if(position <= 0 || position > lp->numberOfElements+1)
    {
        printf("Ivestas neteisingas indeksas\n");
    }
    else
    {
        struct Node* current = lp -> head;

        for(int i =0; i < position-1; i++)
        {
            current = current->next;
            if(current == lp ->tail)
                break;
        }

        struct Node* temp = current -> next;
        current -> next = malloc(sizeof(struct Node));
        current -> next -> data = data;
        current -> next -> next = temp; 
        lp -> numberOfElements++;
    }
}
 
 
void removeAtPosition(struct LinkedList* lp, int position)
{
    struct Node* temp = lp -> head; 
    int i;
    if(position < 1 || position > lp -> numberOfElements)
    {
        printf("Įvestas neteisingas indeksas\n");
        return;
    }
    if (position == 1) {
        lp->head = lp->head->next; 
        temp->next = NULL;
        free(temp);
        lp->numberOfElements--;
        printf("Sėkmingai panaikinta\n");
        return;
    }
    else if(position==lp->numberOfElements)
    {
        struct Node* temp = lp->head;
        while(temp->next != lp->tail)
        {
            temp = temp->next;

        }

        lp->tail = temp;
        temp = temp ->next;
        free(temp);
        lp->numberOfElements--;
        printf("Sėkmingai panaikinta\n");
        return;
    } 
    else
    {
        for (i = 1; i < position; i++) {
            temp = temp->next;
        }
        struct Node* del
            = temp->next;
        temp->next = temp->next->next;
        free(del);
        lp->numberOfElements--;
        printf("Sėkmingai panaikinta\n");
        return;
    }
}

struct Node* findByEmail(struct LinkedList* lp, char* email)
{
    struct Node* temp = lp->head;
    if(temp->next == lp->tail)
    {
        printf("Sąrašas tuščias\n");
        return NULL;
    }
    while(temp->next != lp->tail)
    {
        temp = temp->next;
        if(strcmp(temp->data->email, email) == 0)
            return temp;
    }
    printf("Įrašas nerastas\n");
    return NULL;
}

struct Node* findByPhone(struct LinkedList* lp, char* phone)
{
    struct Node* temp = lp->head;
    if(temp->next == lp->tail)
    {
        printf("Sąrašas tuščias\n");
        return NULL;
    }
    while(temp->next != lp->tail)
    {
        temp = temp->next;
        if(strcmp(temp->data->phone, phone) == 0)
            return temp;
    }
    printf("Įrašas nerastas\n");
    return NULL;
}

struct Node* findByName(struct LinkedList* lp, char* name)
{
    struct Node* temp = lp->head;
    if(temp->next == lp->tail)
    {
        printf("Sąrašas tuščias\n");
        return NULL;
    }
    while(temp->next != lp->tail)
    {
        temp = temp->next;
        if(strcmp(temp->data->name, name) == 0)
            return temp;
    }
    printf("Įrašas nerastas\n");
    return NULL;
}

struct Node* findBySurname(struct LinkedList* lp, char* surname)
{
    struct Node* temp = lp->head;
    if(temp->next == lp->tail)
    {
        printf("Sąrašas tuščias\n");
        return NULL;
    }
    while(temp->next != lp->tail)
    {
        temp = temp->next;
        if(strcmp(temp->data->surname, surname) == 0)
            return temp;
    }
    printf("Įrašas nerastas\n");
    return NULL;
}
 
struct Node* findByIndex(struct LinkedList* lp, int index)
{
    if(lp->head == lp->tail)
    {
        printf("Sąrašas yra tuščias\n");
        return NULL;
    }
    if(index < 1 || index > (lp -> numberOfElements))
    {
        printf("Įvestas neteisingas indeksas\n");
        return NULL;
    }
    else
    {
        struct Node* temp = lp -> head;
        for(int i = 0; i < index; i++)
        {
            temp = temp -> next;
        }
        return temp;
    }
}
 
void deleteWholeList(struct LinkedList* lp)
{
    struct Node *current = lp->head->next;
    while (current->next != lp->tail)
    {
       struct Node *tmp = current;
       current = current->next;
       free(tmp);
    }
   lp->head->next = lp->tail;
   lp ->numberOfElements = 0;    
}
