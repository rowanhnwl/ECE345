#include <iostream>
#include <vector>

#include "node.hpp"

// Constructor
Node::Node(int _id){
    id = _id;
    adjNodes = {};
}

// Access an ID
int Node::get_id(){
    return id;
}

// Get the number of adjacent nodes
int Node::get_n_adj(){
    return (int)adjNodes.size();
}

// Access an adjacent node and edge given an index
std::pair<Node*, int> Node::access_node(int adj_index){
    return adjNodes[adj_index];
}

// Check if a specific edge exists
int Node::query_edge(int adj_id){
    for (int adj_index = 0; adj_index < (int)adjNodes.size(); adj_index++){
        if ((access_node(adj_index).first) -> id == adj_id){
            return adj_index;
        }
    }

    return -1;
}

// Change the ID
void Node::change_id(int new_id){
    id = new_id;
}

// Insert a node into the adjacency list
void Node::insert_edge(Node* to_node, int w){
    std::pair<Node*, int> new_edge(to_node, w);
    adjNodes.push_back(new_edge);
}

// Delete a node from the adjacency list
bool Node::delete_edge(int del_id){
    int adj_index = query_edge(del_id);

    if (adj_index == -1){
        return false;
    }

    // Delete all connections
    while (adj_index != -1){
        adjNodes.erase(std::next(adjNodes.begin(), adj_index));
        adj_index = query_edge(del_id);
    }

    return true;
}

// Print the adjacent nodes
void Node::print_adj_nodes(){
    for (int adj_index = 0; adj_index < (int)adjNodes.size(); adj_index++){
        std::cout << "(ID: " << (adjNodes[adj_index].first) -> id << ", W: " << adjNodes[adj_index].second << ") ";
    }
    std::cout << std::endl;
}