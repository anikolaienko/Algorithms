#include "./include/sort"

// Complexity O(log(n))
void max_heapify(std::vector<int>& A, int& size, int i) {
    int l = left(i);
    int r = right(i);
    int largest = i;
    if (l < size && A[l] > A[largest])
        largest = l;
    if (r < size && A[r] > A[largest])
        largest = r;
    if (largest != i) {
        std::swap(A[largest], A[i]);
        max_heapify(A, size, largest);
    }
}

// Complexity O(n*log(n))
void build_max_heap(std::vector<int>& A) {
    int size = A.size();
    for (int i = A.size() >> 1; i >= 0; i--)
        max_heapify(A, size, i);
}

// Complexity O(n*log(n))
void heapsort(std::vector<int>& A) {
    build_max_heap(A);
    for (int i = A.size() - 1; i > 0; i--) {
        std::swap(A[0], A[i]);
        max_heapify(A, i, 0);
    }
}