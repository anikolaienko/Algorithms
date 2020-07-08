#include "queue.hh"

namespace Algorithms {
    Queue::Queue(): size_{0}, front_{0}, back_{0} {
        vect_ = new Vector(2);
    }

    Queue::Queue(const Queue& queue): front_{0}, back_{0} {
        vect_ = new Vector(*queue.vect_);
        size_ = queue.vect_->size();
    }

    Queue::~Queue() {
        delete vect_;
    }

    void Queue::enqueue(int x) {
        if (size_ == vect_->capacity()) {
            Vector *newVect = new Vector(size_ * 2); // TODO: handle exception ??
            int i = front_;
            while (true) {
                newVect->push((*vect_)[i++]);
                if (i >= vect_->size()) i = 0;
                if (i == back_) break;
            }
            front_ = 0;
            back_ = newVect->size();
            
            // create new vect with double size, put all elements from old in order
            // and use new vect_ now
            delete vect_;
            vect_ = newVect;
        }

        if (back_ >= (*vect_).size()) (*vect_).push(x);
        else (*vect_)[back_] = x;
        
        if (++back_ == vect_->capacity()) back_ = 0;

        size_++;
    }

    int Queue::dequeue() {
        if (size_ == 0) throw std::out_of_range("Cannot dequeue from empty queue");
        int val = (*vect_)[front_++];
        if (front_ == vect_->capacity()) front_ = 0;
        size_--;
        
        return val;
    }

    size_t Queue::size() {
        return size_;
    }
}