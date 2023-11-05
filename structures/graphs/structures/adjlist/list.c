#include <stdio.h>
#include <stdlib.h>

#include "list.h"

// Initialize a node
Node* init_node(int i){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node -> id = i;
    new_node -> next = NULL;

    return new_node;
}

// Initialize a list
NodeList* init_list(){
    NodeList* new_list = (NodeList*)malloc(sizeof(NodeList));
    new_list -> head = NULL;

    return new_list;
}

// Insert a node into a list
void list_insert(NodeList* nl, int i){
    Node* new_node = init_node(i);

    // Insert at the front of the list
    new_node -> next = nl -> head;
    nl -> head = new_node;
}

// Delete a node from a list
void list_delete(NodeList* nl, int i){
    Node* curr = nl -> head;

    // If the head of the list contains the id
    if (curr -> id == i){
        Node* temp = nl -> head;
        nl -> head = nl -> head -> next;

        temp -> next = NULL;
        free(temp);

        return;
    }

    // Iterate through the list until the id is found
    while (curr -> next != NULL && curr -> next -> id != i){
        curr = curr -> next;
    }

    // Delete the node with the corresponding id
    if (curr -> next != NULL){
        Node* temp = curr -> next;
        curr -> next = curr -> next -> next;

        temp -> next = NULL;
        free(temp);
    }
}

// Search for a node in a list
Node* list_search(NodeList* nl, int i){
    Node* curr = nl -> head;

    // Iterate until the id is found
    while (curr != NULL){
        if (curr -> id == i){
            return curr;
        }

        curr = curr -> next;
    }

    return NULL;
}

// Print the nodes in a list
void print_list(NodeList* nl){
    Node* curr = nl -> head;

    while (curr != NULL){
        printf("%d ", curr -> id);
        curr = curr -> next;
    }
    printf("\n");
}

// Copy one list to the other
void copy_list(NodeList* nl1, NodeList* nl2){
    Node* curr1 = nl1 -> head;

    while (curr1 != NULL){
        list_insert(nl2, curr1 -> id);
        curr1 = curr1 -> next;
    }
}

// Deallocate a list
void list_dealloc(NodeList* nl){
    
    // Continuously delete the head until the list is empty
    while (nl -> head != NULL){
        Node* temp = nl -> head;
        nl -> head = nl -> head -> next;

        temp -> next = NULL;
        free(temp);
    }

    // Deallocate the list structure
    free(nl);
}