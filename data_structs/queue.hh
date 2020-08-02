/**
 * Queue data structure
 * 
 * Queue is using Vector internally as dynamicly sized items storage
 * Vector is used as cyclic array
 */

#ifndef ALGORITHMS_QUEUE
#define ALGORITHMS_QUEUE

#include <cctype>
#include <stdexcept>
#include "vector.hh"

namespace Algorithms {
    class Queue {
        Vector *vect_;
        int size_;
        int front_, back_;

    public:
        Queue();

        Queue(const Queue& queue);

        ~Queue();

        void enqueue(int x);

        int dequeue();

        size_t size();
    };
}

#endif // ALGORITHMS_QUEUE