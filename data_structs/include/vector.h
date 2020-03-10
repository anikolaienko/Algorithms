#include <cctype>
#include <cstring>
#include <stdexcept>

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

    size_t size();

    int& operator[] (int);
    const int& operator[] (int) const;
};