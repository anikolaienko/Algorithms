// Leetcode 371: https://leetcode.com/problems/sum-of-two-integers/

// Sum two integers without using "+/-" operators
// Function works with negative arguments as well
int sum(int a, int b) {
    long long carry; // 64-bit
    while (b != 0) {
        carry = a & b;
        a = a ^ b;
        b = ((carry & 0xffffffff) << 1); // limited to 32 bits
    }

    return a;
}
