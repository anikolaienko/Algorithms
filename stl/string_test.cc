#include <iostream>
#include <string>

using namespace std;

void copyOnAssign() {
    string s1 = "Hello";
    string s2 = s1;

    s1.back() = '!';
    cout << "s1: " << s1 << endl << "s2: " << s2 << endl;
}

void appendAndPop() {
    string str;
    const char *buf {"abcd"};

    str.append(buf, 4);

    while(str.size()) {
        cout << "Out: " << str.back() << endl;
        str.pop_back();
    }

    cout << "Capacity: " << str.capacity() << endl;
}

int main() {
    // appendAndPop();
    copyOnAssign();
}