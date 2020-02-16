#include "./include/sort.hpp"

// Counting sort
// Not comparison sorting algorithm
// Complexity: O(n + k)
// Extra space: O(n + k)
std::vector<int> count_sort(std::vector<int>& A, int k) {
    std::vector<int> C(k + 1, 0), B(A.size());
    for (int& a: A)
        C[a]++;

    for (int i = 1; i <= k; i++)
        C[i] += C[i - 1];

    for (int i = 0; i < A.size(); i++) {
        B[C[A[i]]] = A[i];
        C[A[i]]--;
    }
    return B;
}