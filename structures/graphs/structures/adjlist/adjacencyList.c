#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "adjacencyList.h"
#include "list.h"

// Initialize an adjacency list graph
ALGraph* init_al_graph(int s){
    ALGraph* new_al_graph = (ALGraph*)malloc(sizeof(ALGraph));
    BaseNode** new_basenode_arr = (BaseNode**)malloc(sizeof(BaseNode*) * s);

    // Set the pointers to null
    for (int i = 0; i < s; i++){
        new_basenode_arr[i] = NULL;
    }

    new_al_graph -> nodeArray = new_basenode_arr;
    new_al_graph -> graphSize = s;
    new_al_graph -> population = 0;

    return new_al_graph;
}

// Initialize a base node
BaseNode* init_basenode(int i){
    BaseNode* new_basenode = (BaseNode*)malloc(sizeof(BaseNode));

    // Initialize the list of adjacent nodes
    NodeList* new_nl = init_list();

    new_basenode -> id = i;
    new_basenode -> adjNodes = new_nl;

    return new_basenode;
}

// Insert a new node into the graph
void al_graph_insert(ALGraph* alg){
    // If the current array is full
    if (alg -> population == alg -> graphSize){
        resize_al_graph(alg);
        (alg -> nodeArray)[alg -> population] = init_basenode(alg -> population);
        return;
    }

    // Find the first empty location
    for (int i = 0; i < alg -> graphSize; i++){
        if ((alg -> nodeArray)[i] == NULL){
            (alg -> nodeArray)[i] = init_basenode(i);

            // Update the population
            (alg -> population)++;
            return;
        }
    }
}

// Delete a node from the graph
void al_graph_delete(ALGraph* alg, int del_id){
    // Delete all of the connections to the node
    for (int i = 0; i < alg -> graphSize; i++){
        if ((alg -> nodeArray)[i] != NULL){
            list_delete((alg -> nodeArray)[i] -> adjNodes, del_id);
        }
    }

    // Delete the node from the graph
    BaseNode* temp = (alg -> nodeArray)[del_id];
    (alg -> nodeArray)[del_id] = NULL;
    (alg -> population)--;

    basenode_dealloc(temp);
}

// Connect two nodes in the graph (n1 -> n2)
void al_graph_connect(ALGraph* alg, int n1_id, int n2_id){
    // Check if the connection already exists
    if (!al_graph_query_edge(alg, n1_id, n2_id)){
        list_insert((alg -> nodeArray)[n1_id] -> adjNodes, n2_id);
    }
}

// Disconnect two nodes in the graph (n1 -/> n2)
void al_graph_disconnect(ALGraph* alg, int n1_id, int n2_id){
    // Check if the connection exists
    if (al_graph_query_edge(alg, n1_id, n2_id)){
        list_delete((alg -> nodeArray)[n1_id] -> adjNodes, n2_id);
    }
}

// Check if an edge exists in the graph (n1 -> n2)
bool al_graph_query_edge(ALGraph* alg, int n1_id, int n2_id){
    if (list_search((alg -> nodeArray)[n1_id] -> adjNodes, n2_id) == NULL){
        return false;
    }

    return true;
}

// Resize the graph if it becomes full
void resize_al_graph(ALGraph* alg){
    ALGraph* temp = alg;
    ALGraph* new_alg = init_al_graph((alg -> graphSize) * 2);

    for (int i = 0; i < (alg -> graphSize); i++){
        (new_alg -> nodeArray)[i] = init_basenode(i);
        (new_alg -> nodeArray)[i] -> id = i;
        copy_list((alg -> nodeArray)[i] -> adjNodes, (new_alg -> nodeArray)[i] -> adjNodes);
    }

    new_alg -> population = alg -> population;
    alg = new_alg;

    al_graph_dealloc(temp);
}

// Print the contents of a graph
void print_al_graph(ALGraph* alg){
    for (int i = 0; i < alg -> graphSize; i++){
        if ((alg -> nodeArray)[i] != NULL){
            printf("%d: ", i);
            print_list((alg -> nodeArray)[i] -> adjNodes);
        }
    }
}

// Deallocate a base node
void basenode_dealloc(BaseNode* bn){
    NodeList* temp = bn -> adjNodes;
    bn -> adjNodes = NULL;
    
    list_dealloc(temp);
    free(bn);
}

// Deallocate the full graph
void al_graph_dealloc(ALGraph* alg){
    // Deallocate each base node
    for (int i = 0; i < alg -> graphSize; i++){
        BaseNode* temp = (alg -> nodeArray)[i];
        (alg -> nodeArray)[i] = NULL;

        basenode_dealloc(temp);
    }

    // Deallocate the node array
    BaseNode** temp = alg -> nodeArray;
    alg -> nodeArray = NULL;
    free(temp);

    // Deallocate the graph
    free(alg);
}