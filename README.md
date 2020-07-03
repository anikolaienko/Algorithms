This is algorithms implementations from the book "Introduction to Algorithms, 3rd Edition" (CLRS for short).
Also I put here some tasks solutions I've met on Leetcode, DailyCodingTask and other platforms.

## Data Structures
* [Vector](/data_structs/include/vector.h)
* [Queue](/data_structs/include/queue.h)
* [Stack](/data_structs/include/stack.h)
* [Priority Queue](/data_structs/include/priority_queue.h)

## Sort
* [Bubble sort](/sort/bubble_sort.cpp) O(n<sup>2</sup>)
* [Insert sort](/sort/insert_sort.cpp) O(n<sup>2</sup>)
* [Heap sort](/sort/heap_sort.cpp) O(n log(n))
* [Merge sort](/sort/merge_sort.cpp) O(n log(n))
* [Quick sort](/sort/quick_sort.cpp) Average: O(n log(n)). Worst case: O(n<sup>2</sup>)
    * Quick sort
    * Randomized quick sort
    * Quick sort with Hoare partitioning

## Sort in linear time
* [Counting sort](/sort/count_sort.cpp) O(n + k)

## Select
* Linear Select
* MinMax
* Quick Select

## Graph Algorithms
* Union Find

## Bitwise
Lots of information is available on this resource [Bit Twiddling Hacks](http://graphics.stanford.edu/~seander/bithacks.html).

* [Sum of two numbers without using "+/-" operations](/bitwise/sum_two_nums.cpp)

## RUN TESTS
When cloning `Algorithms` repository run `. init_submodules` to get all dependencies.


## TODO
* Organize libraries build into one folder and headers in another
* Create unit tests


## Can be useful
```
g++ -std=c++17 -fPIC -c -Wall -o math/factorial.o math/factorial.cc

g++ -std=c++17 -fPIC -c -Wall -o math/factorial.so math/factorial.cc

clang -std=c++17 -shared -undefined dynamic_lookup -o math/factorial.so math/factorial.cc
```
