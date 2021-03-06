#include "vector.hh"

namespace Algorithms {
    Vector::Vector() : size_{0}, cap_{2}
    {
        arr_ = new int[2];
    }

    Vector::Vector(size_t size): size_{size}, cap_{size}
    {
        arr_ = new int[size];
    }

    Vector::Vector(size_t size, int val): Vector::Vector(size * 2)
    {
        for (int i = 0; i < size; ++i) arr_[i] = val;
        size_ = size;
    }

    Vector::Vector(const Vector& vector): size_{vector.size_}, cap_{vector.cap_}
    {
        arr_ = new int[vector.cap_];
        memcpy(vector.arr_, arr_, vector.size_ * sizeof(int));
    }

    Vector::~Vector()
    {
        delete [] arr_;
    }

    void Vector::push(int x)
    {
        if (size_ == cap_) {
            int* p = arr_;
            cap_ <<= 1;
            arr_ = new int[cap_]; // TODO: we still can run out of size_t bounds
            memcpy(arr_, p, size_ * sizeof(int));
            delete p;
        }
        arr_[size_++] = x;
    }

    int Vector::pop()
    {
        if (!size_)
            throw new std::underflow_error("Popping value from empty vector");
        // TODO: add size reduction
        return arr_[--size_];
    }

    int Vector::back()
    {
        if (!size_)
            throw new std::underflow_error("Popping value from empty vector");
        return arr_[size_ - 1];
    }

    size_t Vector::size() {
        return size_;
    }

    size_t Vector::capacity() {
        return cap_;
    }

    int& Vector::operator[] (int index)
    {
        if (index < 0 || index >= size_)
            throw std::overflow_error("Index is out of vector bounds");
        return arr_[index];
    }

    const int& Vector::operator[] (int index) const
    {
        if (index < 0 || index >= size_)
            throw std::overflow_error("Index is out of vector bounds");
        return arr_[index];
    }
}