#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

/**
 * Checking difference between lower_bound and upper_bound
 */
void lower_upper_bounds_test() {
    vector<int> v1 {0, 4, 8};
    for (int i = 0; i <= 8; ++i) {
        cout << "Lower " << i << ": " << *lower_bound(begin(v1), end(v1), i) 
             << " Upper:" << *upper_bound(begin(v1), end(v1), i) << endl;
    }
}

int main(int argc, char *argv[]) {
    lower_upper_bounds_test();
}