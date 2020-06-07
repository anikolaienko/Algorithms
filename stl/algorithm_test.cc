#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

/**
 * Checking difference between lower_bound and upper_bound
 */
void lower_upper_bounds_test() {
    vector<int> v1 {0, 4, 4, 8, 8};
    for (int i = 0; i <= 9; ++i) {
        cout << "Lower " << i << ": " << distance(begin(v1), lower_bound(begin(v1), end(v1), i)) 
             << " Upper:" << distance(begin(v1), upper_bound(begin(v1), end(v1), i)) << endl;
    }
}

int main(int argc, char *argv[]) {
    lower_upper_bounds_test();
}