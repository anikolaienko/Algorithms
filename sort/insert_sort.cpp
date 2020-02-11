#include <vector>

using namespace std;

// Insert sort.
// Commonly used in-place sorting algorithm.
// Often used on small array size as addition to Merge Sort.
// 
// Complexity: O(n*n)
// Memory:     O(1)
void insertSort(vector<int> arr) {
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}