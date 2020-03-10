#include "../sort/include/sort"

// Quick Select (Randomized Select) algorithm
// Selects i-th smallest element in array
int quick_select(std::vector<int>& A, int p, int r, int i) {
    if (p == r)
        return A[p];
    int q = partition_random(A, p, r);
    int k = q - p + 1;

    if (i == k)
        return A[q];
    else if (i < k)
        return quick_select(A, p, q - 1, i);
    else
        return quick_select(A, q + 1, r, i - k);
}