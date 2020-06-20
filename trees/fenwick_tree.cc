/**
 * Fenwick tree (BIT - binary index tree)
 * Purpose: dynamically find sum of first `m` elements in the array
 * Time complexity:
 *      * Calculate sum: O(log(n))
 *      * Update number in array: O(log(n))
 * Space complexity: 
 *      * Build a tree: O(n)
 * 
 * Sources: 
 *      * https://www.youtube.com/watch?v=kPaJfAUwViY
 *      * https://www.topcoder.com/community/competitive-programming/tutorials/binary-indexed-trees/
 */

#include <vector>
#include <iostream>

using namespace std;

namespace Algorithms {
    class BIT {
        int size_;
        vector<int> table_;
    public:
        BIT(int size): size_{size} {
            table_.resize(size_);
        }

        void update(int position, int delta) {

        }

        int sum(int position) {

        }

        int rangeSum(int pos1, int pos2) {
            return sum(pos2) - sum(pos1);
        }
    };
}

int main() {
    vector<int> arr {};
    Algorithms::BIT bit(arr.size());
}