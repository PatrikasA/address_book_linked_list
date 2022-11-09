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
void display_node(struct Node* node);
void add_to_end(struct Node** first, struct Node *data);
void insert_at_position(struct Node** head, struct Node* data, int position);
void remove_at_position(struct Node** head, int position);
struct Node* find_by_email(struct Node* head, char* email);
struct Node* find_by_name(struct Node* head, char* name);
struct Node* find_by_surname(struct Node* head, char* surname);
struct Node* find_by_phone(struct Node* head, char* phone);
struct Node* find_by_index(struct Node* head, int index);
void delete_whole_list(struct Node* head);

#endif