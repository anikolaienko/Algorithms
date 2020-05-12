#include <vector>
#include <stdexcept>
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * The graph represented here is Adjacency list Graph taken from
 * "Algorithms" 4th edition (R. Sedgewick, K. Wayne)
 * 
 */
class Graph {
    int vCount_;
    int eCount_;
    vector<vector<int>> adj_; // adjacency list

public:
    Graph(int v) : vCount_{v}, eCount_(0) {
        adj_.assign(v, vector<int> {});
    }

    Graph(vector<pair<int,int>> edges) {
        for (auto& edge: edges) {
            addEdge(edge.first, edge.second);
        }
    }

    void addEdge(int a, int b) {
        int maxNode = max(a, b);
        if (vCount_ < maxNode) {
            vCount_ = maxNode;
            adj_.resize(vCount_, vector<int> {});
        }
        adj_[a - 1].push_back(b - 1);
        adj_[b - 1].push_back(a - 1);
    }

    int vCount() {
        return vCount_;
    }

    int eCount() {
        return eCount_;
    }

    vector<int> adj(int v) {
        if (v < 1 || v > vCount_)
            throw invalid_argument("Vertex `v` is out of boundaries");
        return adj_[v];
    }
};

int main() {
    vector<pair<int,int>> edges { make_pair(1,2), make_pair(2,3) };
    Graph graph(edges);
}