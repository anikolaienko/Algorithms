#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Digraph {
    int v_;
    int e_;
    vector<vector<int>> adj_;

public:
    Digraph(int v): v_{v} {
        adj_.resize(v);
    }

    Digraph(vector<pair<int, int>> edges) {
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
        e_++;
    }

    void removeEdge(int a, int b) {
        int maxNode = max(a, b);
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

    Digraph reverse() {
        Digraph revGraph(v_);
        for (int i = 0; i < v_; ++i) {
            for (int j = 0; j < adj_[i].size(); ++j) {
                revGraph.addEdge(adj_[i][j], i);
            }
        }
        return revGraph;
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
