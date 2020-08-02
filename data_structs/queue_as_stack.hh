/**
 * Task 3.4 from Cracking Coding Interview
 */

#ifndef ALGORITHMS_QUEUE_AS_STACK
#define ALGORITHMS_QUEUE_AS_STACK

#include "stack.hh"

namespace Algorithms {
    class QueueAsStack {
        Stack inStack_;
        Stack outStack_;

        void migrate();
    public:
        void push(int num);

        int pop();

        int front();

        int size();
    };
}

#endif // ALGORITHMS_QUEUE_AS_STACK