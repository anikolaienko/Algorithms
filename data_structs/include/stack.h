#include "./vector"

// Stack data structure
//
// Since Vector class is implemented with all needed for Stack
// Stack is basically an adapter over Vector
//
class Stack {
    Vector vect_*;

public:
    Stack();

    Stack(const Stack& stack);

    ~Stack();

    void push(int x);

    int pop();

    int top();

    size_t size();
};