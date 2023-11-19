#include <iostream>

#include "node.hpp"
#include "graph.hpp"

int main(void){
    Graph new_graph;
    
    for (int i = 1; i <= 10; i++){
        new_graph.insert_node(i);
    }

    new_graph.insert_edge(4, 7, 25);
    new_graph.insert_edge(4, 7, 21);

    new_graph.print_graph();

    new_graph.delete_edge(4, 7);

    new_graph.print_graph();
}