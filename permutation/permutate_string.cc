/**
 * Get all string permutations
 * 
 * Time complexity: O(n^2 * n!)
 * Space complexity: O(n * n!)
 */

#include <array>
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

#include <factorial.hh>

using namespace std;

vector<string> permutate(string& str);
void permutate(vector<string>& result, string& str, string prefix);

vector<string> permutate(string& str) {
    vector<string> result;
    permutate(result, str, "");

    return result;
}

void permutate(vector<string>& result, string& str, string prefix) {
    if (str.empty()) {
        result.push_back(prefix);
    } else {
        for (int i = 0; i < str.size(); ++i) {
            string newStr = str.substr(0, i) + str.substr(i + 1);
            permutate(result, newStr, prefix + str.substr(i, 1));
        }
    }
}

/**
 * Checks if permutations are correct.
 * Tricky part here with repeating letters.
 * If letter repeats 2 times there 2 same words,
 * 3 times - 6 same words,
 * 4 times - 24 and so on.
 * 
 * If two different letters have duplicates,
 * we multiply there results of same words.
 */
bool isValid(string& original, vector<string> words) {
    array<int, 127> charCounter {0};
    for (char& c: original) charCounter[c]++;

    int repeatCount = 1;
    for (int& count: charCounter) {
        if (count) repeatCount *= Algorithms::factorial(count);
    }
    cout << "Each word repeats: " << repeatCount << endl;

    unordered_map<string, int> counter;

    for (string& word: words) counter[word]++;

    for (auto it = counter.begin(); it != counter.end(); it++) {
        if (it->second != repeatCount) return false;
    }

    return true;
}

int main() {
    vector<string> tests { "hello", "wwordd", "appppt" };

    for (string& str: tests) {
        cout << "Permutating: " + str << endl;
        auto permutations = permutate(str);
        for (string& permutation: permutations) {
            cout << permutation << "  ";
        }
        cout << endl;
        
        if (!isValid(str, permutations)) cout << "ERROR!!! Permutations are not valid!";
        cout << endl << endl;
    }
}
