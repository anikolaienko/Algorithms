/**
 * Task 3.1 from Cracking Coding Interview
 * 
 * We are going to use vector and extend it's size as stacks are growing
 */

#ifndef ALGORITHMS_STACK3_AS_VECTOR
#define ALGORITHMS_STACK3_AS_VECTOR

#include <vector>
#include <stdexcept>

namespace Algorithms {
    class Stack3 {
        #define INIT_CAPACITY 6

        std::vector<int> vect;

        int s1_start = 0, s1_curr = 0, s1_end = 2;
        int s2_start = 2, s2_curr = 2, s2_end = 4;
        int s3_start = 4, s3_curr = 4, s3_end = 6;

        std::vector<int> copy(int cap1, int cap2, int cap3);

        void resize1();
        void resize2();
        void resize3();
    public:
        Stack3();

        void push1(int num);
        void push2(int num);
        void push3(int num);

        int pop1();
        int pop2();
        int pop3();

        int size1();
        int size2();
        int size3();

        int capacity1();
        int capacity2();
        int capacity3();
    };
}

#endif