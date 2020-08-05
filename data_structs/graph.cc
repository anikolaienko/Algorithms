#include "graph.hh"

namespace Algorithms {
    Graph::Graph(int v) : v_{v}, e_{0} {
        adj_.assign(v, std::vector<int> {});
    }

    Graph::Graph(std::vector<std::pair<int,int>> edges) {
        for (auto& edge: edges) {
            addEdge(edge.first, edge.second);
        }
    }

    bool Graph::edgeExists(int a, int b) {
        if (std::max(a, b) > v_) return false;

        return any_of(begin(adj_[a]), end(adj_[a]), 
            [b] (int other) { return other == b; }
            );
    }

    void Graph::addVertexes(int num) {
        v_ += num;
        adj_.resize(v_, std::vector<int> {});
    }

    void Graph::addEdge(int a, int b) {
        if (edgeExists(a, b)) return;

        int maxNode = std::max(a, b);
        if (maxNode >= v_) addVertexes(maxNode - v_ + 1);

        adj_[a].push_back(b);
        adj_[b].push_back(a);
        e_++;
    }

    bool Graph::connected(int a, int b) {
        if (std::max(a, b) >= v_) throw std::invalid_argument("Vertex index is out of range");

        std::vector<bool> visited(v_, false);
        Stack stack;
        stack.push(a);

        while (stack.size()) {
            int vertex = stack.pop();
            visited[vertex] = true;

            for (int other: adj_[vertex]) {
                if (visited[other]) continue;
                if (other == b) return true;
                stack.push(other);
            }
        }

        return false;
    }

    int Graph::v() {
        return v_;
    }

    int Graph::e() {
        return e_;
    }

    std::vector<int> Graph::adj(int v) {
        if (v < 1 || v > v_)
            throw std::invalid_argument("Vertex `v` is out of boundaries");
        return adj_[v];
    }

    std::string Graph::toString() {
        std::string str;
        for (int i = 0; i < v_; ++i) {
            std::string row = std::to_string(i) + ": ";
            if (adj_[i].size()) {
                row = std::to_string(adj_[i][0]);
                for (int j = 1; j < adj_[i].size(); ++j) {
                    row.append(", " + std::to_string(adj_[i][j]));
                }
            }

            if (str.size()) str.push_back('\n');
            str.append(std::to_string(i) + ": " + row);
        }
        return str;
    }
}
