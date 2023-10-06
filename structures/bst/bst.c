#include <stdlib.h>
#include <stdio.h>

#include <bst.h>

int main()
{
    BSTree* tree;
    tree -> root = (Node*)malloc(sizeof(Node));

    tree -> root -> left = NULL;
    tree -> root -> right = NULL;
}

Node* create_node(int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode -> data = value;
    newNode -> left = NULL;
    newNode -> right = NULL;
    newNode -> p = NULL;

    return newNode;
}

void print(BSTree * tree)
{
    print_in_order(tree->root);
}

void print_in_order(Node * n)
{
    if(n!=NULL)
    {
        print_in_order(n->left);
        printf("%d", n->data);
        print_in_order(n->right);
    }
}

Node* search(BSTree * tree, int value)
{
    Node * current = tree -> root;

    while(current != NULL && current -> data != value)
    {
        if(current->data > value)
        {
            current = current -> left;
        }
        else
        {
            current = current -> right;
        }
    }

    return current;
}

void insert(BSTree * tree, int value)
{
    Node* current = tree -> root;
    Node* parent = NULL;

    if (tree -> root == NULL)
    {
        tree -> root = create_node(value);
    }

    while(current != NULL)
    {
        parent = current;
        if(current->data > value)
        {
            current = current -> left;
        }
        else
        {
            current = current -> right;
        }        
    }

    if(value < parent -> data)
    {
        parent -> left = create_node(value);
        parent -> left -> p = parent;
    }
    else
    {
        parent -> right = create_node(value);
        parent -> right -> p = parent;
    }
}

Node* tree_minimum(Node* z){
    Node* x = z;
    
    while (x -> left != NULL){
        x = x -> left;
    }

    return x;
}

Node* tree_successor(Node* z){
    Node* x = z;
    
    if (x -> right != NULL){
        return tree_minimum(x);
    }

    Node* y = x -> p;

    while (y != NULL && x == y -> right){
        x = y;
        y = y -> p;
    }

    return y;
}

void transplant(BSTree* t, Node* u, Node* v){
    if (u -> p == NULL){
        t -> root = v;
    }
    else if (u == u -> p -> left){
        u -> p -> left = v;
    }
    else{
        u -> p -> right = v;
    }

    if (v != NULL){
        v -> p = u -> p;
    }
}

void tree_delete(BSTree* t, Node* z){
    if (z -> left == NULL){
        transplant(t, z, z -> right);
    }
    else if (z -> right == NULL){
        transplant(t, z, z -> left);
    }
    else {
        Node* y = tree_minimum(z -> right);

        if (y -> p != z){
            transplant(t, y, y -> right);
        }

        transplant(t, z, y);
        y -> left = z -> left;
        y -> left -> p = y;
    }

    free(z);
}