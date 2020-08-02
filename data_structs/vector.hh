/**
 * Vector data structure
 * 
 * Vector is a dynamicly sized array
 */

#ifndef ALGORITHMS_VECTOR
#define ALGORITHMS_VECTOR

#include <cctype>
#include <cstring>
#include <stdexcept>

namespace Algorithms {
    class Vector {
    protected:
        int* arr_;
        size_t size_, cap_;

    public:
        Vector();

        Vector(size_t);

        Vector(size_t, int);

        Vector(const Vector&);

        ~Vector();

        void push(int);

        int pop();

        int back();

        size_t size();

        size_t capacity();

        int& operator[] (int);
        const int& operator[] (int) const;
    };
}

#endif // ALGORITHMS_VECTOR