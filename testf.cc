#include <iostream>
#include "factorial.hh"

int main() {
    std::cout << "Factorial: " << Algorithms::factorial(5) << std::endl;
    std::cout << "Zeros: " << Algorithms::factorialTrailingZeros(66) << std::endl;
}