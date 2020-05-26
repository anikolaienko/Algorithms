#include <set>
#include <iostream>
#include <iterator>
#include <cmath>

using namespace std;

bool gCompareLogOn = false;
int gCompareCount = 0;

class Node {
    int val_;
public:
    Node(int val): val_{val} {}

    int val() const {
        // cout << "Accessed: " << val_ << endl;
        return val_;
    }
};

struct NodeComparer {
    bool operator() (const Node& n1, const Node& n2) const {
        if (gCompareLogOn) {
            cout << "Compare: " << n1.val() << " & " << n2.val() << endl;
            gCompareCount++;
        }
        
        return n1.val() < n2.val();
    }
};

void test_search_in_bintree() {
    int limit = 1900;
    set<Node, NodeComparer> dict;
    for (int i = 0; i < limit; ++i)
        dict.insert(Node(i));

    Node n1(limit / 3);
    dict.insert(n1);
    gCompareLogOn = true;
    cout << "Count smaller than 6:" << endl;
    cout << distance(dict.begin(), dict.find(n1)) << endl;
    cout << "Total: " << gCompareCount << endl;
    cout << "Log(n): " << log2(limit) << endl;
}

int main() {
    test_search_in_bintree();
}
