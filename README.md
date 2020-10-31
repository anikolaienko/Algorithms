# Algorithms
I create this repository as part of my preparation to Coding Interviews in FAANG and other big companies.

The idea is to learn/practice skills of implementing well-known data structures and algorithms from scratch.

**Note:** We are not focusing much on supporting multiple data types in algorithms. This is not important part for Coding interviews and we are not building reusable library here.

Code in this repository represents a collection of Data Structures and algorithms from different sources:
* Gayle L. McDowell "Cracking Coding Interview"
* Robert Sedgewick, Kevin Wayne "Introduction to Algorithms, 3rd Edition" (CLRS for short)
* Thomas Cormen and others "Introduction to Algorithms, 3rd Edition"
* Leetcode
* DailyCodingTask
* other sources

For contribution and other questions feel free to contact me by email [anikolaienko14@gmail.com](mailto:anikolaienko14@gmail.com)

## How to use this repository?


## Table of content
* [Data Structures](#data-structures)
* 

## Data Structures

* [Vector](/data_structs/vector.hh)
* [Queue](/data_structs/queue.hh)
* [Stack](/data_structs/stack.hh)
* [Priority Queue](/data_structs/priority_queue.hh)
* [3 stacks as one vector](/data_structs/stack3_as_vector1.hh)
* [Queue as stack](/data_structs/queue_as_stack.hh)

## Sort
* [Bubble sort](/sort/bubble_sort.cc) O(n<sup>2</sup>)
* [Insert sort](/sort/insert_sort.cc) O(n<sup>2</sup>)
* [Heap sort](/sort/heap_sort.cc) O(n log(n))
* [Merge sort](/sort/merge_sort.cc) O(n log(n))
* [Quick sort](/sort/quick_sort.cc) Average: O(n log(n)). Worst: O(n<sup>2</sup>)
    * Quick sort
    * Randomized quick sort
    * Quick sort with Hoare partitioning

## Sort in linear time
* [Counting sort](/sort/count_sort.cc) O(n + k)

## Select
* Linear Select
* MinMax
* Quick Select

## Graph Algorithms
* Union Find

## Bitwise
Lots of information is available on this resource [Bit Twiddling Hacks](http://graphics.stanford.edu/~seander/bithacks.html).

* [Sum of two numbers without using "+/-" operations](/bitwise/sum_two_nums.cc)

## RUN TESTS
When cloning `Algorithms` repository run `. init_submodules` to get all dependencies.

## Can be useful
* Commands for compiling shared library 
```
g++ -std=c++17 -fPIC -c -Wall -o math/factorial.o math/factorial.cc

g++ -std=c++17 -fPIC -c -Wall -o math/factorial.so math/factorial.cc

clang -std=c++17 -shared -undefined dynamic_lookup -o math/factorial.so math/factorial.cc
```
