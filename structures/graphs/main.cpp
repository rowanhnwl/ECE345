#include <iostream>

#include "node.hpp"
#include "graph.hpp"
#include "algorithms.hpp"

int main(void){
    Graph new_graph;
    
    for (int i = 1; i <= 10; i++){
        new_graph.insert_node(i);
    }

    // Source: 2, Destination: 8
    new_graph.insert_edge(2, 3, 1);
    new_graph.insert_edge(3, 6, 1);
    new_graph.insert_edge(6, 1, 1);
    new_graph.insert_edge(1, 7, 1);
    new_graph.insert_edge(7, 10, 1);
    new_graph.insert_edge(10, 8, 1);
    new_graph.insert_edge(6, 4, 1);
    new_graph.insert_edge(8, 9, 1);
    new_graph.insert_edge(1, 2, 1);
    new_graph.insert_edge(3, 7, 1);
    new_graph.insert_edge(2, 4, 1);
    new_graph.insert_edge(5, 8, 1);

    std::vector<Node*> path = Algorithms::bfs(new_graph, 2, 8);
    Algorithms::Utilities::print_path(path);

    //new_graph.print_graph();
}