#include <iostream>

#include "graph.hpp"
#include "node.hpp"

// Constructor
Graph::Graph(){
    nodes = {};
}

// Get the index of a node by its ID
int Graph::query_node(int id){
    for (int node_index = 0; node_index < (int)nodes.size(); node_index++){
        if (nodes[node_index].get_id() == id){
            return node_index;
        }
    }

    return -1;
}

// Check if a graph edge exists. If so, return the weight
int Graph::query_edge(int from_id, int to_id){
    int from_index = query_node(from_id);
    int to_index = query_node(to_id);

    // If either ID does not exist in the graph
    if (from_index == -1){
        std::cout << "Error: No node exists with ID " << from_id << std::endl;
        return -1;
    }
    else if (to_index == -1){
        std::cout << "Error: No node exists with ID " << to_id << std::endl;
        return -1;
    }
    
    int adj_index = nodes[from_index].query_edge(to_id);
    
    // If the edge does not exist
    if (adj_index == -1){
        return -1;
    }

    int w = nodes[from_index].access_node(adj_index).second;

    return w;
}

// Get the number of nodes in the graph
int Graph::get_n_nodes(){
    return (int)nodes.size();
}

// Get the number of edges in the graph
int Graph::get_n_edges(){
    int n_edges = 0;

    for (int node_index = 0; node_index < (int)nodes.size(); node_index++){
        n_edges += nodes[node_index].get_n_adj();    
    }

    return n_edges;
}

// Get a pointer to a node by index
Node* Graph::get_node(int id){
    int node_index = query_node(id);

    if (node_index == -1){
        std::cout << "Error: No node exists with ID " << id << std::endl;
        return nullptr;
    }

    return &nodes[node_index];
}

// Insert an edge into the graph
bool Graph::insert_edge(int from_id, int to_id, int w){
    int to_index = query_node(to_id);
    int from_index = query_node(from_id);

    if (from_index == -1){
        std::cout << "Error: No node exists with ID " << from_id << std::endl;
        return false;
    }
    else if (to_index == -1) {
        std::cout << "Error: No node exists with ID " << to_id << std::endl;
        return false;
    }
    
    Node* p_to_node = &nodes[to_index];

    nodes[from_index].insert_edge(p_to_node, w);
    return true;
}

// Delete an edge from the graph
bool Graph::delete_edge(int from_id, int to_id){
    int to_index = query_node(to_id);
    int from_index = query_node(from_id);
    
    if (from_index == -1){
        std::cout << "Error: No node exists with ID " << from_id << std::endl;
        return false;
    }
    else if (to_index == -1) {
        std::cout << "Error: No node exists with ID " << to_id << std::endl;
        return false;
    }

    return nodes[from_index].delete_edge(to_id);
}

// Insert a node into the graph
bool Graph::insert_node(int id){
    // If a matching ID exists in the graph
    if (query_node(id) != -1){
        std::cout << "Error: A node already exists with ID " << id << std::endl;
        return false;
    }

    Node new_node(id);
    nodes.push_back(new_node);
    return true;
}

// Delete a node from the graph
bool Graph::delete_node(int id){
    int del_index = query_node(id);
    if (del_index == -1){
        std::cout << "Error: No node exists with ID " << id << std::endl;
        return false;
    }
    
    // Delete the connections
    for (int node_index = 0; node_index < (int)nodes.size(); node_index++){
        nodes[node_index].delete_edge(id);
    }

    // Delete the node
    nodes.erase(std::next(nodes.begin(), del_index));
    return true;
}

// Change a node's ID
bool Graph::change_node_id(int old_id, int new_id){
    int old_index = query_node(old_id);
    
    // If the old ID does not exist or the new ID does exist
    if (old_index == -1){
        std::cout << "Error: No node exists with ID " << old_index << std::endl;
        return false;
    }
    else if (query_node(new_id) != -1){
        std::cout << "Error: A node already exists with ID " << new_id << std::endl;
        return false;
    }

    nodes[old_index].change_id(new_id);
    return true;
}

// Change the weight of an edge
bool Graph::change_edge_weight(int from_id, int to_id, int w){
    int to_index = query_node(to_id);
    int from_index = query_node(from_id);
    
    if (from_index == -1){
        std::cout << "Error: No node exists with ID " << from_id << std::endl;
        return false;
    }
    else if (to_index == -1) {
        std::cout << "Error: No node exists with ID " << to_id << std::endl;
        return false;
    }

    return nodes[from_index].change_edge_weight(to_id, w);
}

// Operator overload for access by index
Node* Graph::operator[](int index){
    return &nodes[index];
}

// Reset the nodes in the graph
void Graph::reset(){
    for (int node_index = 0; node_index < nodes.size(); node_index++){
        nodes[node_index].reset();
    }
}

// Clear the edges in the graph (keep the nodes)
void Graph::clear_edges(){
    for (int node_index = 0; node_index < nodes.size(); node_index++){
        nodes[node_index].reset();
        nodes[node_index].clear_edges();
    }
}

// Clear the graph
void Graph::clear_nodes(){
    nodes = {};
}

// Print the graph
void Graph::print_graph(){
    std::cout << std::endl;
    for (int node_index = 0; node_index < (int)nodes.size(); node_index++){
        std::cout << "ID: " << nodes[node_index].get_id() << " -> ";
        nodes[node_index].print_adj_nodes();
    }
    std::cout << std::endl;
}