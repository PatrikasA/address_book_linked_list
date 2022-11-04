#ifndef LINKEDLIST
#define LINKEDLIST

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char name[20];
    char surname[20];
    char phone[15];
    char email[50];
    struct Node* next;
};

void display(struct Node* head, int number);
void displayNode(struct Node* node);
void addToEnd(struct Node** first, struct Node *data);
void insertAtPosition(struct Node** head, struct Node* data, int position);
void removeAtPosition(struct Node** head, int position);
struct Node* findByEmail(struct Node* head, char* email);
struct Node* findByName(struct Node* head, char* name);
struct Node* findBySurname(struct Node* head, char* surname);
struct Node* findByPhone(struct Node* head, char* phone);
struct Node* findByIndex(struct Node* head, int index);
void deleteWholeList(struct Node* head);

#endif