#include <iostream>

using namespace std;

struct S {
    // three-bit unsigned field,
    // allowed values are 0...7
    unsigned int a : 3;

    // will usually occupy 2 bytes:
    // 3 bits: value of b1
    // 2 bits: unused
    // 6 bits: value of b2
    // 2 bits: value of b3
    // 3 bits: unused
    unsigned char b1 : 3, : 2, b2 : 6, b3 : 2;
    
    unsigned char c1 : 3;
    unsigned char :0; // start a new byte
    unsigned char c2 : 6;
}


int main() {

}