#include <iostream>
using namespace std;

struct alignas(32) S {
    int x[4];
};

struct A {
    int x[4];
};

// Checking default align on float in struct B
struct B {
    char c;
    float x;
};

int main() {
    cout << "Alignment of S: " << alignof(S) << " Size: " << sizeof(S) << " Type: " << typeid(S).name() << endl;
    cout << "Alignment of A: " << alignof(A) << " Size: " << sizeof(A) << " Type: " << typeid(A).name() << endl;
    S *s = new S {1, 2, 3, 4};
    A *a = new A {5, 6, 7, 8};
    cout << "s: " << s << " [5] " << *(reinterpret_cast<int*>(s) + 4) << " : ";
    for (int i = 0; i < 4; ++i) cout << s->x[i] << " ";
    cout << endl;
    cout << "a: " << a << " [5] " << *(reinterpret_cast<int*>(a) + 4) << " : ";
    for (int i = 0; i < 4; ++i) cout << a->x[i] << " ";
    cout << endl;

    // delete [] s;
    S *s1 = new S {9, 10, 11, 12};
    cout << "s1: " << s1 << " : ";
    for (int i = 0; i < 4; ++i) cout << s1->x[i] << " ";
    cout << endl;

    A *a1 = new A {9, 10, 11, 12};
    cout << "a1: " << a1 << " : ";
    for (int i = 0; i < 4; ++i) cout << a1->x[i] << " ";
    cout << endl;

    B b {'a', 3.14};
    cout << "b: " << &b << " c: " << *(reinterpret_cast<char*>(&b)) << " x: " << &b.x << endl;

    delete s;
    delete a;
    delete s1;
    delete a1;
}