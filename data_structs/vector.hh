#include <cctype>
#include <cstring>
#include <stdexcept>

#ifndef ALGORITHMS_VECTOR
#define ALGORITHMS_VECTOR

namespace Algorithms {
    class Vector {
    protected:
        int* arr_;
        size_t size_, cap_;

    public:
        Vector();

        Vector(int);

        Vector(const Vector&);

        ~Vector();

        void push(int);

        int pop();

        int back();

        size_t size();

        int& operator[] (int);
        const int& operator[] (int) const;
    };
}

#endif // ALGORITHMS_VECTOR