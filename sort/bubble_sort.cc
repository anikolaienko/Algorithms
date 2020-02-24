#include <vector>

using namespace std;

// Bubble sort - in-place sorting algorithm
// Rarely used in practice, because of low performance
// 
// Complexity: O(n**2)
// Memory:     O(1)
void bubbleSort(vector<int> arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        bool terminate = true;
        for (int j = arr.size() - 1; j > i; j--) {
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
                terminate = false;
            }
        }
        if (terminate) return;
    }
}
