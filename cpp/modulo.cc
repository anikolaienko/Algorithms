#include <iostream>

int main(){
    int a = 32, b = 12, m = 2;
    
    std::cout << "Properties of modulo (%) operator:" << std::endl;
    std::cout << ((a + b) % m == (a % m + b % m) % m) << std::endl;
    std::cout << ((a - b) % m == (a % m - b % m) % m) << std::endl;
    std::cout << ((a * b) % m == (a % m * b % m) % m) << std::endl;

    return 1;
}