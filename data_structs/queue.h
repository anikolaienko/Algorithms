#include <cctype>
#include "./vector"

// Queue data structure
//
// Queue is using Vector internally as dynamicly sized items storage
// Vector is used as cyclic array
//
class Queue {
    Vector vect_*;

public:
    Queue();

    Queue(const Queue& queue);

    ~Queue();

    void enqueue(int x);

    int dequeue();

    size_t size();
}