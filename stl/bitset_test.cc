#include <bitset>
#include <iostream>

using namespace std;

void test_bitset_shift() {
    bitset<21> bs(1);
    cout << "Bitset: " << bs.to_string() << endl;
    for (const int& i: {1, 3, 4}) {
        bs |= bs << i;
        cout << "Bitset: " << bs.to_string() << " i: " << i << endl;
    }
    
    cout << "Bitset: " << bs.to_string() << endl;
}

int main () {
    test_bitset_shift();
}