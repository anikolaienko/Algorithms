#include "weighted_edge.hh"

namespace Algorithms {
    WeightedEdge::WeightedEdge(int v, int w, int weight):
        v_{v}, w_{w}, weight_{weight} { }

    int WeightedEdge::weight()
    {
        return weight_;
    }

    int WeightedEdge::either()
    {
        return v_;
    }

    int WeightedEdge::other(int vertex)
    {
        if (vertex == v_) return w_;
        if (vertex != w_) {
            throw std::invalid_argument("Vertex argument doesn't equal to any of current edge vertexes");
        }
        return v_;
    }

    bool WeightedEdge::operator<(const WeightedEdge& edge) const {
        return weight_ < edge.weight_;
    }

    WeightedEdge::operator std::string() const
    {
        return std::to_string(v_) + " (" + std::to_string(weight_) + ") " + std::to_string(w_);
    }
}