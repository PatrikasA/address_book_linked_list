#ifndef LINKEDLIST
#define LINKEDLIST

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data
{
    char name[20];
    char surname[20];
    char phone[8];
    char email[40];
};

struct Node
{
    struct Data data;
    struct Node* next;
};
 
struct LinkedList
{
    struct Node* head;
    struct Node* tail;
    int numberOfElements;
};

void initializeList(struct LinkedList* listptr );
void display(struct LinkedList* lp);
void addToEnd(struct LinkedList* lp, struct Data data);
void insertAtPosition(struct LinkedList* lp, struct Data data, int position);
void removeFromTail(struct LinkedList* lp);
void removeFromHead(struct LinkedList* lp);
void removeAtPosition(struct LinkedList* lp, int position);
struct Node* findByEmail(struct LinkedList* lp, char email[20]);
struct Node* findByName(struct LinkedList* lp, char* name);
struct Node* findBySurname(struct LinkedList* lp, char* surname);
struct Node* findByPhone(struct LinkedList* lp, char* phone);
struct Node* findByIndex(struct LinkedList* lp, int index);
void deleteWholeList(struct LinkedList* lp);

#endif