#include <vector>

#include "graph.hpp"
#include "node.hpp"

#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

namespace Algorithms {

    // Single source shortest path algorithms
    namespace SSSP{
        // Breadth-first-search
        void bfs(Graph& g, int source_id);

        // Depth-first-search
        void dfs(Graph& g, int source_id);

        // Dijkstra's Algorithm
        void dijkstra(Graph& g, int source_id);
    };

    // Min-spanning tree algorithms
    namespace MST{
        // Prim's Algorithm
        std::vector<std::pair<Node*, Node*>> prim(Graph& g);
    };

    // Utility functions
    namespace Utilities {
        // Path relaxation
        bool relax(Node* u, int adj_index);

        // Construct a path through back-tracking from the destination
        std::vector<Node*> construct_path(Graph& g, int dest_id);

        // Print a path
        void print_path(std::vector<Node*> path);

        // Print shortest paths
        void print_sssp(Graph& g, int source_id);
    };

    // Custom comparators
    namespace Comparators {
        // Node distance comparator
        struct dist_comp {
            inline bool operator() (Node* n1, Node* n2){
                return ((n1 -> get_dist()) > (n2 -> get_dist()));
            }
        };
    };
};

#endif /* ALGORITHMS_HPP */