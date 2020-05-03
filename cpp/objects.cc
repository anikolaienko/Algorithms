#include <iostream>
using namespace std;

struct alignas(16) S {
    int x;
};

int main() {
    cout << "Alignment of S: " << alignof(S) << " Size: " << sizeof(S) << endl;
}