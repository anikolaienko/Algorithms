#include "../data_structs/digraph.cc"

using namespace std;

class TopologicalSort {
    Digraph graph_;
    vector<bool> visited_;
    queue<int> preOrderQueue_;
    queue<int> postOrderQueue_;
    stack<int> revPostOrderQueue_;
    // TODO: we can use only one container, 
    // no need to have queue and vector for each order
    vector<int> preOrder_;
    vector<int> postOrder_;
    vector<int> revPostOrder_;

    void dft(int i) {
        visited_[i] = true;
        preOrderQueue_.push(i);
        for (int& j: graph_.adj(i)) {
            if (!visited_[j]) dft(j);
        }
        postOrderQueue_.push(i);
        revPostOrderQueue_.push(i);
    }

    void getOrdered() {
        int v = graph_.v();
        
        for (int i = 0; i < v; ++i) {
            if (!visited_[i]) dft(i);
        }
        
        while (!preOrderQueue_.empty()) {
            preOrder_.push_back(preOrderQueue_.front());
            preOrderQueue_.pop();
        }
        while (!postOrderQueue_.empty()) {
            postOrder_.push_back(postOrderQueue_.front());
            postOrderQueue_.pop();
        }
        while (!revPostOrderQueue_.empty()) {
            revPostOrder_.push_back(revPostOrderQueue_.top());
            revPostOrderQueue_.pop();
        }
    }
public:
    TopologicalSort(Digraph graph) {
        graph_ = graph;
        visited_ = vector<bool>(graph_.v(), false);
        getOrdered();
    }
    
    vector<int> preOrder() {
        return preOrder_;
    }

    vector<int> postOrder() {
        return postOrder_;
    }

    vector<int> reversePostOrder() {
        return revPostOrder_;
    }

    vector<int> topologicalSort() {
        return reversePostOrder();
    }
};