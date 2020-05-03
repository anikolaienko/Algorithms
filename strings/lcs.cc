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

int main(int argc, char* argv[]) {
    if (argc != 3) throw invalid_argument("\nLCS takes 2 string arguments! Provided: " + to_string(argc - 1));
    string X(argv[1]), Y(argv[2]);
    cout << "Searching for longest common substring between:" << endl << X << endl << Y << endl;

    lcs(X, Y);
    cout << endl;
    return 0;
}