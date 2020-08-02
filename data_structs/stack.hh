/**
 * Stack data structure
 * 
 * Since Vector class is implemented with all needed for Stack,
 * Stack is basically an wrapper (Adapter) over Vector.
 */

#ifndef ALGORITHMS_STACK
#define ALGORITHMS_STACK

#include "vector.hh"

namespace Algorithms {
    class Stack {
        Vector *vect_;

    public:
        Stack();

        Stack(const Stack& stack);

        ~Stack();

        void push(int x);

        int pop();

        int top();

        size_t size();
    };
}

#endif // ALGORITHMS_STACK