#include <iostream>

using namespace std;

struct S1 {
    int *x;
    string y;
    int z;
};


int main() {
    S1 s {new int[10] {}, "hello", 4};
    cout << s.z << endl;
}