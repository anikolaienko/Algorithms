#include "./include/priority_queue.hpp"

template<typename T>
PriorityQueue<T>::PriorityQueue() {}

template<typename T>
PriorityQueue<T>::PriorityQueue(ForwardIterator<T> start, ForwardIterator<T> end) {
    arr = vector<T>(start, end);
    build_max_heap(arr);
}

// Increases value at index `i` to new value `key`
//     i   - index of value we want to increase
//     key - new value, should be > or == to old value by index `i`
// Complexity: O(log(n))
template<typename T>
void PriorityQueue<T>::increase_key(int i, T key) {
    if (i < 0 || i >= arr.size())
        throw std::overflow_error("Index i (" + to_string(i) + ") is outside the range of existing indexes.");
    if (key < arr[i])
        throw std::underflow_error("New value " + to_string(key) + " is lower than previous " + to_string(arr[i]));
    arr[i] = key;
    while (i > 0 && arr[parent(i)] < A[i]) {
        std::swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }
}

// Insert new value into queue
//     x - new value to be inserted
// Complexity O(log(n))
template<typename T>
void PriorityQueue<T>::insert(T x) {
    arr.resize(arr.size() + 1);
    arr[arr.size() - 1] = x;
    insert_key(arr.size() - 1, x);
}

// Pop value from the top of the queue
// Complexity O(log(n))
template<typename T>
T PriorityQueue<T>::pop() {
    if (arr.empty())
        throw std::underflow_error("Queue is empty");

    T max = arr[0];
    arr[0] = arr.back();
    arr.pop_back();

    int size = arr.size();
    max_heapify(arr, size, 0);

    return max;
}

// Peek the max value
// Complexity O(1)
template<typename T>
T PriorityQueue<T>::top() {
    return A[0];
}