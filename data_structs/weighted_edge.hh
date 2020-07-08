
/**
 * Weighted Edge data structure
 * This is necessary data structure for Edge Weighted Graph
 * 
 * Origin: Algorithms 4th Edition by Robert Sedgewick, Kevin Wayne
 */

#ifndef ALGORITHMS_WEIGHTED_EDGE
#define ALGORITHMS_WEIGHTED_EDGE

#include <string>
#include <stdexcept>

namespace Algorithms {
    class WeightedEdge {
        int v_, w_, weight_;
    public:
        WeightedEdge(int v, int w, int weight);

        int weight();

        int either();

        int other(int vertex);

        bool operator<(const WeightedEdge& edge) const;

        explicit operator std::string() const;
    };
}

#endif // ALGORITHMS_WEIGHTED_EDGE