// Longest Common Subsequence algorithm

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

void lcs(string& X, string& Y);
void printLCS(vector< vector<char> >& b, string& X, int i, int j);

/*
matrix b stores directions for last phace.
Directions are the following:
D U
L
Where:
U - up
L - left
D - diagonally up left
*/
void lcs(string& X, string& Y) {
    int m = X.size(), n = Y.size();
    vector< vector<char> > b (m, vector<char>(n, 0));
    vector< vector<int> > c (m + 1, vector<int>(n + 1, 0));
    // TODO: optimize to use only vector c instead of matrix
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (X[i] == Y[j]) {
                c[i + 1][j + 1] = c[i][j] + 1;
                b[i][j] = 'D';
            } else if (c[i][j + 1] >= c[i + 1][j]) {
                c[i + 1][j + 1] = c[i][j + 1];
                b[i][j] = 'U';
            } else {
                c[i + 1][j + 1] = c[i + 1][j];
                b[i][j] = 'L';
            }
        }
    }

    cout << "Result: ";
    printLCS(b, X, m - 1, n - 1);
}

void printLCS(vector< vector<char> >& b, string& X, int i, int j) {
    if (i < 0 || j < 0) return;
    if (b[i][j] == 'D') {
        printLCS(b, X, i - 1, j - 1);
        cout << X[i];
    } else if (b[i][j] == 'U') {
        printLCS(b, X, i - 1, j);
    } else {
        printLCS(b, X, i, j - 1);
    }
}

// TODO: copied from Leencode: https://leetcode.com/problems/delete-operation-for-two-strings/
// 4 similar approaches, but little different enterpretation
using int_mtx = vector<vector<int>>;

int minDistance(string word1, string word2) {
    vector<vector<int>> memo(word1.size(), vector<int> (word2.size(), 0));
    return lcs(word1, word2, 0, 0, memo);
}

int lcs(string& s1, string& s2, int s1Pos, int s2Pos, int_mtx& memo) {
    if (s1Pos == s1.size() || s2Pos == s2.size()) {
        int maxLeftDiff = max(s1.size() - s1Pos, s2.size() - s2Pos);
        return max(0, maxLeftDiff);
    }
    if (memo[s1Pos][s2Pos] > 0) return memo[s1Pos][s2Pos];
    
    if (s1[s1Pos] == s2[s2Pos]) {
        memo[s1Pos][s2Pos] = lcs(s1, s2, s1Pos + 1, s2Pos + 1, memo);
    } else {
        memo[s1Pos][s2Pos] = 1 + min(lcs(s1, s2, s1Pos + 1, s2Pos, memo),
                                    lcs(s1, s2, s1Pos, s2Pos + 1, memo));
    }
    
    return memo[s1Pos][s2Pos];
}

int minDistance1(string word1, string word2) {
    int_mtx dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
    
    for (int i = 0; i <= word1.size(); ++i) {
        for (int j = 0; j <= word2.size(); ++j) {
            if (i == 0 || j == 0) continue;
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    
    return word1.size() + word2.size() - 2*dp[word1.size()][word2.size()];
}

  int minDistance2(string word1, string word2) {
    int_mtx dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
    
    for (int i = 0; i <= word1.size(); ++i) {
        for (int j = 0; j <= word2.size(); ++j) {
            if (i == 0 || j == 0)
                dp[i][j] = i + j;
            else if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    
    return dp[word1.size()][word2.size()];
}

int minDistance3(string word1, string word2) {
    vector<int> dp(word2.size() + 1, 0);
    
    for (int i = 0; i <= word1.size(); ++i) {
        vector<int> temp(word2.size() + 1, 0);
        for (int j = 0; j <= word2.size(); ++j) {
            if (i == 0 || j == 0)
                temp[j] = i + j;
            else if (word1[i - 1] == word2[j - 1])
                temp[j] = dp[j - 1];
            else
                temp[j] = 1 + min(dp[j], temp[j - 1]);
        }
        dp = temp;
    }
    
    return dp[word2.size()];
}

int main(int argc, char* argv[]) {
    if (argc != 3) throw invalid_argument("\nLCS takes 2 string arguments! Provided: " + to_string(argc - 1));
    string X(argv[1]), Y(argv[2]);
    cout << "Searching for longest common substring between:" << endl << X << endl << Y << endl;

    lcs(X, Y);
    cout << endl;
    return 0;
}