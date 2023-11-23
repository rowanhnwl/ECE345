#include <vector>

#include "node.hpp"

#ifndef GRAPH_HPP
#define GRAPH_HPP

class Graph {
    private:
        std::vector<Node> nodes;
    public:
        // Constructor
        Graph();

        // Accessors
        int query_node(int id); // Checks if a node exists in the graph and returns its index
        int query_edge(int from_id, int to_id); // Checks if an edge exists (from, to), returns the weight
        int get_n_nodes();
        int get_n_edges();
        Node* get_node(int id); // Get a pointer to a node by ID

        // Modifiers
        bool insert_edge(int from_id, int to_id, int w); // Inserts an edge (from, to) with a specified weight
        bool delete_edge(int from_id, int to_id); // Deletes an edge (from, to)
        bool insert_node(int id); // Inserts a node into the graph
        bool delete_node(int id); // Deletes a node (and its connections)
        bool change_node_id(int old_id, int new_id);
        bool change_edge_weight(int from_id, int to_id, int w);

        // Operator overload
        Node* operator[](int index); // Access a node at a given index

        // Utilities
        void reset(); // Reset all node properties
        void clear_edges(); // Clear the graph of all edges
        void clear_nodes(); // Clear the graph of all nodes

        // Printing
        void print_graph();
};

#endif /* GRAPH_HPP */