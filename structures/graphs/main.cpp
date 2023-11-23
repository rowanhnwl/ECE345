#include <iostream>

#include "node.hpp"
#include "graph.hpp"
#include "algorithms.hpp"

int main(void){
    Graph new_graph;
    
    for (int i = 1; i <= 5; i++){
        new_graph.insert_node(i);
    }

    new_graph.insert_edge(1, 2, 1);
    new_graph.insert_edge(2, 3, 1);
    new_graph.insert_edge(1, 4, 1);
    new_graph.insert_edge(2, 5, 1);
    new_graph.insert_edge(3, 4, 1);
    new_graph.insert_edge(4, 5, 1);
    new_graph.insert_edge(5, 3, 1);

    Algorithms::SSSP::bfs(new_graph, 1);

    std::vector<Node*> path = Algorithms::Utilities::construct_path(new_graph, 3);
    Algorithms::Utilities::print_path(path);

    //new_graph.print_graph();
}