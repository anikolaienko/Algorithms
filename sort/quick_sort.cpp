#include "./include/sort.hpp"

// Rearanges subarray A[p..r] in place
template <class T>
int partition(std::vector<T>& A, int p, int r) {
    int x = A[r], i = p - 1;
    for (int j = p; j < r; j++) {
        if (A[j] < x) {
            i++;
            std::swap(A[i], A[j]);
        }
    }
    std::swap(A[i + 1], A[r]);
    return i + 1;
}

template <class T>
void quick_sort(std::vector<T>& A, int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quick_sort(A, p, q - 1);
        quick_sort(A, q + 1, r);
    }
}

template<class T>
int partition_hoare(std::vector<T>& A, int p, int r) {
    int x = A[p];
    i = p - 1;
    j = r + 1;
    while (true) {
        do {
            j--;
        } while (A[j] <= x);

        do {
            i++;
        } while (A[i >= x]);

        if (i < j) std::swap(A[i], A[j]);
        else return j;
    }
}

template<class T>
void quick_sort_hoare(std::vector<T>& A, int p, int r) {
    if (p < r) {
        int q = partition_hoare(A, p, r);
        quick_sort_hoare(A, p, q - 1);
        quick_sort_hoare(A, q + 1, r);
    }
}

template<class T>
int partition_random(std::vector<T>& A, int p, int r) {
    int i = rand() % (r - p) + p;
    std::swap(A[i], A[r]);
    return partition(A, p, r);
}

template <class T>
void quick_sort_random(std::vector<T>& A, int p, int r) {
    if (p < r) {
        int q = partition_random(A, p, r);
        quick_sort_random(A, p, q - 1);
        quick_sort_random(A, q + 1, r);
    }
}