#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<string> permutate(string str) {
    vector<string> result;
    permutate(result, str, "");

    return result;
}

void permutate(vector<string>& result, string str, string prefix) {
    if (str.empty()) {
        result.push_back(prefix);
    } else {
        for (int i = 0; i < str.size(); ++i) {
            string newStr = str.substr(0, i) + str.substr(i + 1);
            permutate(result, newStr, prefix + str.substr(i, 1));
        }
    }
}

int main() {
    vector<string> tests { "hello" };

    for (string& str: tests) {
        cout << "Permutating: " + str << endl;
        for (string& permutation: permutate(str)) {
            cout << permutation << "  ";
        }
        cout << endl;
    }
}
