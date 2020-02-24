#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>

#define left(i) i << 1
#define right(i) (i << 1) | 1
#define parent(i) i >> 1

// Complexity O(log(n))
void max_heapify(std::vector<int>& A, int& size, int i);

// Complexity O(n*log(n))
void build_max_heap(std::vector<int>& A);

// Complexity O(n*log(n))
void heapsort(std::vector<int>& A);

// Quick sort is in-place sorting algoring
// Average complexity is O(n log(n)), Worst case O(n^2)
//     A - array to sort in-place
//     p - start index to sort
//     r - end index to sort (inclusive)
template <class T>
void quick_sort(std::vector<T>& A, int p, int r);

// Randomized partitioning
// Used in Quick Sort and Quick Select algorithms
template<class T>
int partition_random(std::vector<T>& A, int p, int r);