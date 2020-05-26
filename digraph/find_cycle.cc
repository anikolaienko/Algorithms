#include "../data_structs/digraph.cc"

using namespace std;

class CycleFinder {
    Digraph graph_;
    vector<bool> onStack_;
    vector<bool> visited_;

    bool findCycle(int i) {
        onStack_[i] = true;
        visited_[i] = true;
        for (int& j: graph_.adj(i)) {
            if (onStack_[j]) return true;
            if (visited_[j]) continue;
            if (findCycle(j)) return true;
        }

        onStack_[i] = false;
        return false;
    }

public:
    CycleFinder(Digraph graph): graph_ {graph} {};

    bool hasCycle() {
        int v = graph_.v();
        onStack_ = vector<bool>(v, false);
        visited_ = vector<bool>(v, false);

        for (int i = 0; i < v; ++i) {
            if (visited_[i]) continue;
            if (findCycle(i)) return true;
        }
        return false;
    }
};