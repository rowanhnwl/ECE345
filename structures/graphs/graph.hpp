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
        int get_n_edges();

        // Modifiers
        bool insert_edge(int from_id, int to_id, int w); // Inserts an edge (from, to) with a specified weight
        bool delete_edge(int from_id, int to_id); // Deletes an edge (from, to)
        bool insert_node(int id); // Inserts a node into the graph
        bool delete_node(int id); // Deletes a node (and its connections)
        bool change_node_id(int old_id, int new_id);

        // Printing
        void print_graph();
};

#endif /* GRAPH_HPP */