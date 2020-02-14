#include <vector>
#include <algorithm>

#define left(i) i << 1
#define right(i) (i << 1) | 1
#define parent(i) i >> 1

// Complexity O(log(n))
void max_heapify(std::vector<int>& A, int& size, int i);

// Complexity O(n*log(n))
void build_max_heap(std::vector<int>& A);

// Complexity O(n*log(n))
void heapsort(std::vector<int>& A);