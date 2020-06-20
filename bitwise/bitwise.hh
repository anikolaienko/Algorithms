/**
 * Header file for Bitwise operations
 */
#include <string>

namespace Algorithms {
    /**
     * Get right most bit in the integer
     * Returns -1 if integer is 0
     * 
     * Complexity: O(1)
     */
    int getRightBit(int num);

    std::string toBinString(int num);
}