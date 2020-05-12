#include <vector>

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
            adj_[edge.first].push_back(edge.second);
            adj_[edge.second].push_back(edge.first);
        }
    }

    int vCount() {
        return vCount_;
    }

    int eCount() {
        return eCount_;
    }
};