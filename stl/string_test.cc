#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    //str.reserve(4);

    const char *buf {"abcd"};

    str.append(buf, 4);

    while(str.size()) {
        cout << "Out: " << str.back() << endl;
        str.pop_back();
    }

    cout << "Capacity: " << str.capacity() << endl;
}