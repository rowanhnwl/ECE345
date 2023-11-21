#include <iostream>
#include <vector>
#include <queue>

#include "algorithms.hpp"
#include "graph.hpp"
#include "node.hpp"

// Breadth-first-search
std::vector<Node*> Algorithms::bfs(Graph& g, int s_id, int d_id){
    // Get a pointer to the source node
    Node* s_p = g.get_node(s_id);

    // Validate the IDs
    if (s_p == nullptr || g.get_node(d_id) == nullptr){
        return {};
    }

    // Initialize the source's members
    s_p -> change_colour('g');
    
    // Create the FIFO queue
    std::queue<Node*> bfs_queue;

    // Add the source to the queue
    bfs_queue.push(s_p);

    // While the queue is not empty
    while (!bfs_queue.empty()){
        // Remove the top of the queue
        Node* u_p = bfs_queue.back();
        bfs_queue.pop();

        // Iterate through the nodes adjacent to u_p
        for (int adj_index = 0; adj_index < u_p -> get_n_adj(); adj_index++){
            Node* v_p = (u_p -> access_node(adj_index)).first;

            // Change the attributes of the unvisited adjacent nodes
            if (v_p -> get_colour() == 'w'){
                v_p -> change_colour('g');
                v_p -> change_p(u_p);
                bfs_queue.push(v_p);
            }
        }

        // Mark the node as visited
        u_p -> change_colour('b');
    }

    std::vector<Node*> bfs_path = Algorithms::Utilities::construct_path(g, d_id);
    return bfs_path;
}

// Reconstruct the path from the destination ID
std::vector<Node*> Algorithms::Utilities::construct_path(Graph& g, int dest_id){
    std::vector<Node*> path_rev;
    std::vector<Node*> path;

    // Get a pointer to the destiation node and add it to the reversed path
    Node* d_p = g.get_node(dest_id);
    path_rev.push_back(d_p);

    // Iterate backwards through the predecessors until the source is found
    Node* curr = d_p -> get_p();
    while (curr != nullptr){
        path_rev.push_back(curr);
        curr = curr -> get_p();
    }

    // Reverse the path
    for (int node_index = path_rev.size() - 1; node_index >= 0; node_index--){
        path.push_back(path_rev[node_index]);
    }

    return path;
}

// Print a path
void Algorithms::Utilities::print_path(std::vector<Node*> path){
    std::cout << std::endl;
    for (int node_index = 0; node_index < (int)path.size(); node_index++){
        std::cout << path[node_index] -> get_id();
        
        if (node_index < (int)path.size() - 1){
            std::cout << " -> ";
        }
    }
    std::cout << std::endl;
}