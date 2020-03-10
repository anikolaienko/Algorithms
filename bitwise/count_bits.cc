#include <vector>

// Given a non negative integer number num.
// For every numbers i in the range 0 ≤ i ≤ num
// calculate the number of 1's in their binary
// representation and return them as an array.
std::vector<int> countBits(int num) {
    std::vector<int> res(num + 1, 0);
    for (int i = 1; i <= num; i++) {
        res[i] = res[i >> 1] + (i & 1);
    }
    return res;
}