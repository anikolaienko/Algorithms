#include <iostream>

using namespace std;

struct S1 {
    int *x;
    string y;
    int z;
};

void structSimpleInitializer() {
    cout << "structSimpleInitializer: " << endl;
    S1 s {new int[10] {}, "hello", 4};
    cout << s.z << endl;
}

void structComplexInitializer() {
    cout << "structSimpleInitializer: " << endl;
    struct {int x; double z;} a {10, 20};
    cout << "a.x: " << a.x << " ; a.z: " << a.z << endl;

    struct point {int x, y;} p {.y = 5, .x = 3};
    cout << "point: (" << p.x << "," << p.y << ")" << endl;
}

int main() {
    structSimpleInitializer();
    structComplexInitializer();
}