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
    printf("%s %s %s %s",node->data.name, node->data.surname, node->data.phone, node->data.email);
}
 
void display(struct LinkedList* lp)
{
    if(lp->head->next == lp->tail)
    {
        printf("Adresu knygele tuscia\n");
    }
    else
    {
        struct Node* current = lp->head;
        printf("Saraso elementai:");
        while(current!=lp->tail) // TEST IF THIS SHOUD BE current->next
        {
            displayNode(current);
            current=current->next;
        }
    }
}
 
 
void addToEnd(struct LinkedList* lp, struct Data data)
{
    struct Node* current = lp -> head;
    while(current -> next != lp -> tail)
    {
        current = current ->next;
    }

    current -> next = malloc(sizeof(struct Node));
    current -> next ->data = data;
    current -> next -> next = lp ->tail;
}
 
void insertAtPosition(struct LinkedList* lp, struct Data data, int position)
{
    //sanity check
    if(position <= 0 || position > lp->numberOfElements+1)
    {
        printf("Ivestas neteisingas indeksas\n");
    }
    //if we need to append element to end of list
    else if(position == lp ->numberOfElements+1)
    {
        addToEnd(lp,data);
    }
    //if we need to insert element somewhere else
    else
    {
        struct Node* current = lp -> head;

        for(int i =0; i < position; i++)
        {
            current = current->next;
            if(current == lp ->tail)
                break;
        }

        struct Node* temp = current -> next;
        current -> next = malloc(sizeof(struct Node));
        current -> next -> data = data;
        current -> next -> next = temp; 
    }
}
 
// void removeFromTail(struct LinkedList* lp)
// {
// 	struct Node* temp;
 
// 	if(lp->tail == NULL)
// 	{	
// 	    printf("Sarasas tuscias\n");
// 	}
// 	else
// 	{
// 		temp = lp->head;
 
// 		while(temp->next != lp->tail)
// 		{ temp = temp->next;}
 
 
// 		lp->tail = temp;
//         free(lp->tail->next); 
// 		lp->tail->next = NULL;		
// 	}	
// }
 
// void removeFromHead(struct LinkedList* lp)
// {
//     if(lp->head == lp->tail)
// 	{	
// 		printf("Sarasas tuscias\n"); 	
// 	}
// 	else
// 	{
//         struct Node* tmp = lp->head;
// 		lp->head = lp->head->next;
//         free(tmp);		
// 	}	
// }
 
void removeAtPosition(struct LinkedList* lp, int position)
{
    //sanity checks
    if(lp->head->next == lp->tail)
    {
        printf("Sąrašas tuščias. Šalinimas negalimas.\n");
    }
    else if(position <= 0 || position > lp->numberOfElements)
    {
        printf("Įvestas neteisingas indeksas\n");
    }
    //if we can remove
    else
    {
        struct Node* temp = lp->head;
        for(int i=0; i<position; i++)
        {
            temp = temp ->next;
            if(temp = lp ->tail)
                break;
        }

        struct Node* nodeToFree = temp ->next;
        temp ->next = temp ->next ->next;
        free(nodeToFree);
    }
 
}

struct Node* findByEmail(struct LinkedList* lp, char email[20])
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
        if(strcmp(temp->data.email, email) == 0)
            return temp;
    }
    printf("Įrašas nerastas");
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
        if(strcmp(temp->data.phone, phone) == 0)
            return temp;
    }
    printf("Įrašas nerastas");
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
        if(strcmp(temp->data.name, name) == 0)
            return temp;
    }
    printf("Įrašas nerastas");
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
        if(strcmp(temp->data.surname, surname) == 0)
            return temp;
    }
    printf("Įrašas nerastas");
    return NULL;
}
 
struct Node* findByIndex(struct LinkedList* lp, int index)
{
    //sanity checks
    if(lp->head == NULL)
    {
        printf("Sarasas yra tuscias");
    }
    if(index < 0 || index > lp -> numberOfElements)
    {
        printf("Ivestas neteisingas indeksas");
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
}