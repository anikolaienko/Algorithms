/**
 * Edge Weighted Graph data structure
 * 
 * Origin: Algorithms 4th Edition by Robert Sedgewick, Kevin Wayne
 */

#ifndef ALGORITHMS_EDGE_WEIGHTED_GRAPH
#define ALGORITHMS_EDGE_WEIGHTED_GRAPH

#include <vector>
#include <string>
#include "weighted_edge.hh"

namespace Algorithms {
    class EdgeWeightedGraph {
        EdgeWeightedGraph(int v);

        int v();

        int e();

        void addEdge(WeightedEdge edge);

        std::vector<WeightedEdge> adj(int v);

        std::vector<WeightedEdge> edges();

        explicit operator std::string() const;
    };
}

#endif // ALGORITHMS_EDGE_WEIGHTED_GRAPH