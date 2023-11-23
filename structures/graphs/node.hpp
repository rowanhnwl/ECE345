#include <vector>

#ifndef NODE_HPP
#define NODE_HPP

class Node {
    private:
        int id;
        std::vector<std::pair<Node*, int>> adjNodes; // Holds nodes and weights
        
        // Members for searching
        char colour;
        Node* p; // Predecessor
        int dist; // Distance

    public:
        // Constructor
        Node(int);

        // Accessors
        int get_id();
        char get_colour();
        Node* get_p();
        int get_dist();
        int get_n_adj();
        std::pair<Node*, int> access_node(int index); // Access an adjacent node and the edge weight by index
        int query_edge(int to_id); // Check if a specific edge exists (returns the index)

        // Modifiers
        void change_id(int new_id);
        void change_colour(char new_colour);
        void change_p(Node* new_p);
        void change_dist(int new_dist);
        void insert_edge(Node* new_node, int w);
        bool delete_edge(int del_id); // Delete a node based on its ID (returns the status)
        bool change_edge_weight(int id, int w);

        // Utilities
        void reset();
        void clear_edges();

        // Printing
        void print_adj_nodes();
};

#endif /* NODE_HPP */