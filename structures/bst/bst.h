#include <stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
    struct node* p;
}Node;

typedef struct bstree
{
    Node* root;
}BSTree;

Node* create_node(int);
void print_tree(BSTree*);
void print_in_order(Node*);
Node* search(BSTree*, int);
void insert(BSTree*, int);

Node* tree_minimum(Node*);
Node* tree_successor(Node*);
void transplant(BSTree*, Node*, Node*);
void tree_delete(BSTree*, Node*);