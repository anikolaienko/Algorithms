#include <iostream>
#include <numeric>

using namespace std;

template<typename T>
string getMax() {
    string maxStr = to_string(numeric_limits<T>::max());
    
    int rest = maxStr.size() % 3;
    string spaceSeparetedStr(maxStr.size() + maxStr.size() / 3 + (rest == 0 ? -1 : 0), 0);
    
    if (rest == 0) rest = 3;

    for (int i = 0, j = 0; i < maxStr.size(); ++i, ++j) {
        if (j == rest) {
            spaceSeparetedStr[j++] = ' ';
            rest = j + 3;
        }

        spaceSeparetedStr[j] = maxStr[i];
    }

    return spaceSeparetedStr;
}

int main () {
    cout << sizeof(int) << " limit: " << getMax<int>() << endl;
    cout << sizeof(long) << " limit: " << getMax<long>() << endl;
    cout << sizeof(long long) << " limit: " << getMax<long long>() << endl;
    cout << sizeof(long long int) << " limit: " << getMax<long long int>() << endl;
}