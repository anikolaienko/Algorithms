/**
 * Collection of bitwise operations
 */

#include "bitwise.hh"

#include <climits>
#include <bitset>

int Algorithms::getRightBit(int num) {
    if (num == INT_MIN) return INT_MIN;
    return num & (-num);
}

std::string Algorithms::toBinString(int num) {
    return std::bitset<32>(num).to_string();
}
