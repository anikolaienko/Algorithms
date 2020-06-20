/**
 * Collection of bitwise operations
 */

#include "bitwise.hh"

#include <bitset>

int Algorithms::getRightBit(int num) {
    return num & (-num);
}

template<int k>
std::string Algorithms::toBitString(int num) {
    return std::bitset<k>(num).to_string();
}
