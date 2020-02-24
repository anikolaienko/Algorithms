#include "./include/stack.hpp"

Stack::Stack()
{
    vect_ = new Vector();
}

Stack::Stack(const Stack& stack)
{
    vect_ = new Vector(*stack.vect_);
}

Stack::~Stack()
{
    delete vect_;
}

void Stack::push(int x)
{
    vect_->push(x);
}

int Stack::pop()
{
    return vect_->pop();
}

int Stack::top()
{
    return vect_->top();
}

size_t Stack::size()
{
    return vect_->size();
}