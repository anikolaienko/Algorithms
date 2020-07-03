#include "stack.hh" // TODO: include `.hh` file instead

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