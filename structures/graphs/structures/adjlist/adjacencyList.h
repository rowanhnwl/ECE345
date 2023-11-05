#include <stdlib.h>
#include <stdbool.h>

#include "list.h"

#ifndef ADJLIST_H
#define ADJLIST_H

#define BASE_SIZE 10

// Base node structure definition
typedef struct basenode{
    int id;
    NodeList* adjNodes;
}BaseNode;

// Adjacency list structure definition (dynamic array)
typedef struct adjlist{
    int graphSize;
    int population;
    BaseNode** nodeArray;
}ALGraph;

// Constructors
ALGraph* init_al_graph(int);
BaseNode* init_basenode(int);

// Adjacency list operations
void al_graph_insert(ALGraph*);
void al_graph_delete(ALGraph*, int);
void al_graph_connect(ALGraph*, int, int);
void al_graph_disconnect(ALGraph*, int, int);
bool al_graph_query_edge(ALGraph*, int, int);

// Maintenance functions
void resize_al_graph(ALGraph*);

// Utilities
void print_al_graph(ALGraph*);

// Destructor
void basenode_dealloc(BaseNode*);
void al_graph_dealloc(ALGraph*);

#endif /* ADJLIST_H */