#include <vector>

#include "graph.hpp"
#include "node.hpp"

#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

namespace Algorithms {
    // Breadth-first-search
    std::vector<Node*> bfs(Graph& g, int source_id, int dest_id);

    // Depth-first-search
    std::vector<Node*> dfs(Graph& g, int source_id, int dest_id);

    // Dijkstra's Algorithm
    std::vector<Node*> dijkstra(Graph& g, int source_id, int dest_id);

    // Prim's Algorithm
    std::vector<std::pair<Node*, Node*>> prim(Graph& g);

    // Utility functions
    namespace Utilities {
        // Construct a path through back-tracking from the destination
        std::vector<Node*> construct_path(Graph& g, int dest_id);

        // Print a path
        void print_path(std::vector<Node*> path);
    }
};

#endif /* ALGORITHMS_HPP */