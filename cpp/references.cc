#include <iostream>

using namespace std;

int f1(int x) {
    cout << "x &: " << &x << endl;
    return x + 10;
}

int f2(int&& x) {
    cout << "x: " << x << " &: " << &x << endl;
    x = 11;
    return x;
}

int main () {
    int x = 10;
    cout << "init x&: " << &x << endl;
    cout << "x: " << f2(f1(x)) << endl;
}