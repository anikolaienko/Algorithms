#include <vector>
#include <stdexcept>

using namespace std;

using matrix = vector<vector<int>>;

matrix multiply(matrix& A, matrix B) {
    if (A.empty()) throw invalid_argument("A cannot be empty");
    if (A[0].size() != B.size())
        throw invalid_argument("A # of columns should be equal to B # of rows");
    matrix C(B.size(), vector<int> (A[0].size()));

    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < B[0].size(); ++j) {
            int x = 0;
            for (int k = 0; k < A[0].size(); ++k) {
                x += A[i][k] * B[k][j];
            }
            C[i][j] = x;
        }
    }
    
    return C;
}