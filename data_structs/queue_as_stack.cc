#include "queue_as_stack.hh" // TODO: include `.hh` file instead

namespace Algorithms {
    void QueueAsStack::migrate() {
        while (inStack_.size()) outStack_.push(inStack_.pop());
    }

    void QueueAsStack::push(int num) {
        inStack_.push(num);
    }

    int QueueAsStack::pop() {
        if (outStack_.size()) return outStack_.pop();

        migrate();

        return outStack_.pop();
    }

    int QueueAsStack::front() {
        if (outStack_.size()) return outStack_.top();

        migrate();

        return outStack_.top();
    }

    int QueueAsStack::size() {
        return inStack_.size() + outStack_.size();
    }
}