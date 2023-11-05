#include <stdlib.h>

#ifndef LIST_H
#define LIST_H

// Node structure definition
typedef struct node{
    int id;
    struct node* next;
}Node;

// List structure definition
typedef struct nlist{
    Node* head;
}NodeList;

// Constructors
Node* init_node(int);
NodeList* init_list();

// List operations
void list_insert(NodeList*, int);
void list_delete(NodeList*, int);
Node* list_search(NodeList*, int);

// Utilities
void print_list(NodeList*);
void copy_list(NodeList*, NodeList*);

// Destructor
void list_dealloc(NodeList*);

#endif /* LIST_H */