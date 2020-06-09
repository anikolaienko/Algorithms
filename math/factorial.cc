#include <iostream>

#include "factorial.hh"

int Algorithms::factorial(int n) {
    if (n < 0) return 0;
    else if (n == 0) return 1;
    else return n * factorial(n - 1);
}

// int main() {
//     int nums[] {-2, 0, 1, 4, 5};
//     for (int& num: nums) {
//         std::cout << "Factorial of " << num << ": " << Algorithms::factorial(num) << std::endl;
//     }
// }