#include "../../sort/include/sort"
#include <stdexcept>
#include <iterator>

template <class T>
struct ForwardIterator : std::iterator<std::forward_iterator_tag, T> {};

// Implementation of priority queue using max heap
template <class T>
class PriorityQueue {
    std::vector<T> arr;
public:
    PriorityQueue();

    PriorityQueue(ForwardIterator<T> start, ForwardIterator<T> end);

    // Increases value at index `i` to new value `key`
    //     i   - index of value we want to increase
    //     key - new value, should be > or == to old value by index `i`
    // Complexity: O(log(n))
    void increase_key(int i, T key);

    // Insert new value into queue
    //     x - new value to be inserted
    // Complexity O(log(n))
    void insert(T x);

    // Pop value from the top of the queue
    // Complexity O(log(n))
    T pop();

    // Peek the max value
    // Complexity O(1)
    T top();
};