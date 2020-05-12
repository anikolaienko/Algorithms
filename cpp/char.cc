///////////////////////////////////////////////////////
// Playing around with char data type
//
// Author: Andrii Nikolaienko
///////////////////////////////////////////////////////
#include <iostream>

using namespace std;

/**
 * What's the size of unicode character
 */
void test_unicode() {
    const char *c = "ф";
    cout << c << endl;
    for (int i = 0; i < 4; i++) {
        cout << (unsigned char)*(c + i) << endl;
    }
}

/**
 * Main running function
 */
int main() {
    test_unicode();
}