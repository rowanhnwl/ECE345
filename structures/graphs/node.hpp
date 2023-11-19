#include <vector>

#ifndef NODE_HPP
#define NODE_HPP

class Node {
    private:
        int id;
        std::vector<std::pair<Node*, int>> adjNodes; // Holds nodes and weights
    public:
        // Constructor
        Node(int);

        // Accessors
        int get_id();
        int get_n_adj();
        std::pair<Node*, int> access_node(int index); // Access an adjacent node and the edge weight by index
        int query_edge(int to_id); // Check if a specific edge exists (returns the index)

        // Modifiers
        void change_id(int new_id);
        void insert_edge(Node* new_node, int w);
        bool delete_edge(int del_id); // Delete a node based on its ID (returns the status)

        // Printing
        void print_adj_nodes();
};

#endif /* NODE_HPP */