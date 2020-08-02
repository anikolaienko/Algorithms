#include "factorial.hh"

namespace Algorithms {
    int factorial(int n) {
        if (n < 0) return 0;
        else if (n == 0) return 1;
        else return n * factorial(n - 1);
    }

    int factorialTrailingZeros(int n) {
        if (n <= 0) return 0;

        int count = 0;
        while (n >= 5) {
            n /= 5;
            count += n;
        }

        return count;
    }
}