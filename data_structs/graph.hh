#ifndef ALGORITHMS_GRAPH
#define ALGORITHMS_GRAPH

#include <algorithm>
#include <utility>
#include <stdexcept>
#include <vector>
#include <string>

#include "stack.hh"

namespace Algorithms {
    /**
     * The graph represented here is Adjacency list Graph taken from
     * "Algorithms" 4th edition (R. Sedgewick, K. Wayne).
     * 
     * And modified with additional functionality.
     */
    class Graph {
        int v_; // number of vertexes
        int e_; // number of edges
        std::vector<std::vector<int>> adj_; // adjacency list

        bool edgeExists(int a, int b);
    public:
        Graph(int v);

        Graph(std::vector<std::pair<int,int>> edges);

        void addVertexes(int num);

        void addEdge(int a, int b);

        /**
         * Implementation of DFS with stack
         */
        bool connected(int a, int b);

        int v();

        int e();

        std::vector<int> adj(int v);

        std::string toString();
    };
}

#endif // ALGORITHMS_GRAPH