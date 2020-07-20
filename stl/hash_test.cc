#include <iostream>
#include <unordered_set>
#include <functional>

using namespace std;

void hashOneCharStrings() {
    cout << "hash(\"a\"): " << hash<string>()("a") << endl;
    cout << "hash(\"b\"): " << hash<string>()("b") << endl;
    cout << "hash(\"c\"): " << hash<string>()("c") << endl;
}

void hashSameCharDiffLengthStrings() {
    cout << "hash(\"a\"):   " << hash<string>()("a") << endl;
    cout << "hash(\"aa\"):  " << hash<string>()("aa") << endl;
    cout << "hash(\"aaa\"): " << hash<string>()("aaa") << endl;
}

void sameFractionDifferentDoubles() {
    #define DIVISOR 93.0
    unordered_set<double> dict { 1 / DIVISOR };

    for (double i = 1; i < 100; i += 0.1) {
        double val = i/(i * DIVISOR);
        if (!dict.count(val)) {
            cout << "Hash of " + to_string(i) + "/" + to_string(i*(int)DIVISOR) + ":"
                 << hash<double>()(i/(i * DIVISOR)) << endl;
        }
    }
}

int main() {
    // sameFractionDifferentDoubles();
    hashOneCharStrings();
    hashSameCharDiffLengthStrings();
}