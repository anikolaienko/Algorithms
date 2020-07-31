// Task 16.1 from Cracking Coding Interview

namespace Algorithms {
    // Just using bitwise XOR
    void swap(int& a, int& b) {
        b ^= a;
        a ^= b;
        b ^= a;
    }
}