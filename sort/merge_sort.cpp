#include <vector>

using namespace std;

// Merge sort.
// Commonly used sorting algorithm.
// Often used together with Insert Sort for small array size.
// 
// Complexity: O(n*log(n))
// Memory:     O(n*log(n))
void mergeSort(vector<int> arr, int p, int r) {
    if (p < r) {
        int q = p / r;
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

// Merge function for Merge Sort.
void merge(vector<int> arr, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    vector<int> L(n1), R(n2);
    for (int i = p; i < q; i++) L[i - p] = arr[i];
    for (int i = q; i <= r; i++) R[i - q] = arr[i];
    int i = 0, j = 0;
    for (int k = p; k <= r; k++) {
        if (i < L.size() && L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
    }
}

