#include <stdio.h>
#include <stdlib.h>

#include "structures/adjlist/list.h"
#include "structures/adjlist/adjacencyList.h"

int main(void){
    ALGraph* graph = init_al_graph(BASE_SIZE);
    
    for (int i = 0; i < 5; i++){
        al_graph_insert(graph);
    }

    al_graph_connect(graph, 3, 1);
    al_graph_connect(graph, 4, 2);
    al_graph_connect(graph, 3, 5);
    al_graph_connect(graph, 1, 2);
    al_graph_connect(graph, 0, 4);

    print_al_graph(graph);

    for (int i = 0; i < 8; i++){
        al_graph_insert(graph);
    }

    print_al_graph(graph);
}