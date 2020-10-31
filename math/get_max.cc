/**
 * Task #16.7 from Cracking Coding Interview
 */

/**
 * Flips bit: 0x1 -> 0x0 and 0x0 -> 0x1
 */
int flip(int bit) {
    return 1 ^ bit;
}

/**
 * Returns `1` if `a >= 0` and `0` if `a < 0`
 */
int sign(int a) {
    return flip((a >> 31) & 0x1);
}

/**
 * Returns max value from `a` and `b` without using comparison operators.
 */
int getMax(int a, int b) {
    int c = a - b;

    int sa = sign(a);
    int sb = sign(b);
    int sc = sign(c);

    
}