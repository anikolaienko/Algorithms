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
    int v_;
    int e_;
    vector<vector<int>> adj_; // adjacency list

public:
    Graph(int v) : v_{v}, e_(0) {
        adj_.assign(v, vector<int> {});
    }

    Graph(vector<pair<int,int>> edges) {
        for (auto& edge: edges) {
            addEdge(edge.first, edge.second);
        }
    }

    void addEdge(int a, int b) {
        // TODO: check if edge doesn't exist already
        int maxNode = max(a, b);
        if (v_ < maxNode) {
            v_ = maxNode;
            adj_.resize(v_, vector<int> {});
        }
        adj_[a - 1].push_back(b - 1);
        adj_[b - 1].push_back(a - 1);
        e_++;
    }

    int v() {
        return v_;
    }

    int e() {
        return e_;
    }

    vector<int> adj(int v) {
        if (v < 1 || v > v_)
            throw invalid_argument("Vertex `v` is out of boundaries");
        return adj_[v];
    }

    string toString() {
        string str;
        for (int i = 0; i < v_; ++i) {
            string row;
            for (int j = 0; j < adj_[i].size(); ++j) {
                str.append((row.size() ? ", " : "") + to_string(adj_[i][j]));
            }

            if (row.size()) {
                if (str.size()) str.push_back('\n');
                str.append(to_string(i) + ": " + row);
            }
        }
        return str;
    }
};

int main() {
    vector<pair<int,int>> edges { make_pair(1,2), make_pair(2,3) };
    Graph graph(edges);
}