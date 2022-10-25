#include "LinkedList.h"

void initializeList(struct LinkedList* listptr )
{
    listptr->head = NULL;
    listptr->tail = NULL;
    listptr->numberOfElements = 0;
}
 
void display(struct LinkedList* lp)
{
    if(lp->head == NULL)
    {
        printf("Adresu knygele tuscia\n");
    }
    else
    {
        struct Node* current = lp->head;
        printf("Saraso elementai:");
        while(current!=NULL)
        {
            printf("%s %s %s %s",current->data->name, current->data->surname, current->data->phone, current->data->email);
            current=current->next;
        }
    }
}
 
void addToStart(struct LinkedList* lp, struct Node* element)
{
	//if list is empty.
	if(lp->head == NULL)
	{
		lp->head = element;
		lp->tail = element;
	}
	else
	{
		element->next = lp->head;
		lp->head = element;
	}		
}
 
void addToEnd(struct LinkedList* lp, struct Node* element)
{
 
    // if list is empty
    if(lp -> head == NULL)
    {
        lp -> head = element;
        lp -> tail = element;
    }
    else
    {
        lp -> tail -> next = element;
        lp -> tail = lp -> tail -> next;
    }
}
 
void insertAtPosition(struct LinkedList* lp, struct Node* element, int position)
{
    //sanity check
    if(position <= 0 || position > lp->numberOfElements+1)
    {
        printf("Ivestas neteisingas indeksas\n");
    }
    //if we need to append element to end of list
    else if(position == lp ->numberOfElements+1)
    {
        addToEnd(lp,element);
    }
    //if element needs to be added to start of list
    else if(position==1)
    {
        addToStart(lp,element);
    }
    //if we need to insert element somewhere else
    else
    {
        struct Node* temp = lp->head;
        int i = 0;
        while(i<=position)
        {
            if(temp -> next != NULL)
            {
                temp = temp -> next;
            }
        }
 
        element->next = temp->next;
        temp->next = element;
    }
}
 
void removeFromTail(struct LinkedList* lp)
{
	struct Node* temp;
 
	if(lp->tail == NULL)
	{	
	    printf("Sarasas tuscias\n");
	}
	else
	{
		temp = lp->head;
 
		while(temp->next != lp->tail)
		{ temp = temp->next;}
 
 
		lp->tail = temp;
        free(lp->tail->next); 
		lp->tail->next = NULL;		
	}	
}
 
void removeFromHead(struct LinkedList* lp)
{
    if(lp->head == NULL)
	{	
		printf("Sarasas tuscias\n"); 	
	}
	else
	{
        struct Node* tmp = lp->head;
		lp->head = lp->head->next;
        free(tmp);		
	}	
}
 
void removeAtPosition(struct LinkedList* lp, int position)
{
    //sanity checks
    if(lp->head == NULL)
    {
        printf("Sarasas tuscias. Salinimas negalimas.\n");
    }
    else if(position <= 0 || position > lp->numberOfElements)
    {
        printf("Ivestas neteisingas indeksas\n");
    }
    //if we need to remove at end of list
    else if(position == lp->numberOfElements)
    {
        removeFromTail(lp);
    }
    //if we need to remove at start of list
    else if(position == 1)
    {
        removeFromHead(lp);
    }
    //if we need to remove somewhere else
    else
    {
        int i = 0;
        struct Node* temp = lp->head;
        while(i<=position)
        {
            if(temp -> next != NULL)
            {
                temp = temp -> next;
            }
        }
        struct Node* nodeToFree = temp -> next;
        temp -> next = temp -> next -> next;
        free(nodeToFree);
    }
 
}

struct Node* findByEmail(struct LinkedList* lp, char* email)
{
    struct Node* temp = lp->head;
    while(temp->next != lp->tail)
    {
        temp = temp->next;
        if(strcmp(temp->data->email, email) == 0)
            return temp;
    }
    return NULL;
}

struct Node* findByPhone(struct LinkedList* lp, char* phone)
{
    struct Node* temp = lp->head;
    while(temp->next != lp->tail)
    {
        temp = temp->next;
        if(strcmp(temp->data->phone, phone) == 0)
            return temp;
    }
    return NULL;
}

struct Node* findByName(struct LinkedList* lp, char* name)
{
    struct Node* temp = lp->head;
    while(temp->next != lp->tail)
    {
        temp = temp->next;
        if(strcmp(temp->data->name, name) == 0)
            return temp;
    }
    return NULL;
}

struct Node* findBySurname(struct LinkedList* lp, char* surname)
{
    struct Node* temp = lp->head;
    while(temp->next != lp->tail)
    {
        temp = temp->next;
        if(strcmp(temp->data->surname, surname) == 0)
            return temp;
    }
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
    struct Node *curr = lp->head->next;
    while (curr->next != lp->tail)
    {
       struct Node *tmp = curr;
       curr = curr->next;
       free(tmp);
    }
   lp->head->next = lp->tail;    
}