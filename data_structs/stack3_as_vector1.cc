#include "stack3_as_vector1.hh"

std::vector<int> Algorithms::Stack3::copy(int cap1, int cap2, int cap3) {
    std::vector<int> newVect(cap1 + cap2 + cap3);

    for (int i = 0; i <= size1(); ++i)
        newVect[i] = vect[i];
    
    for (int i = 0, j = cap1; i <= size2(); ++i)
        newVect[j + i] = vect[s2_start + i];

    for (int i = 0, j = cap1 + cap2; i <= size3(); ++i)
        newVect[j + i] = vect[s3_start + i];

    s2_curr = cap1 + size2();
    s3_curr = cap1 + cap2 + size3();

    s2_start = s1_end = cap1;
    s3_start = s2_end = cap1 + cap2;
    s3_end = cap1 + cap2 + cap3;

    return newVect;
}

void Algorithms::Stack3::resize1() {
    int cap1 = capacity1() << 1, cap2 = capacity2(), cap3 = capacity3();
    vect = copy(cap1, cap2, cap3);
}

void Algorithms::Stack3::resize2() {
    int cap1 = capacity1(), cap2 = capacity2() << 1, cap3 = capacity3();
    vect = copy(cap1, cap2, cap3);
}

void Algorithms::Stack3::resize3() {
    int cap1 = capacity1(), cap2 = capacity2(), cap3 = capacity3() << 1;
    vect = copy(cap1, cap2, cap3);
}

Algorithms::Stack3::Stack3(): vect{std::vector<int>(INIT_CAPACITY)} {}

void Algorithms::Stack3::push1(int num) {
    if (size1() == capacity1()) resize1();
    vect[s1_curr++] = num;
}

void Algorithms::Stack3::push2(int num) {
    if (size2() == capacity2()) resize2();
    vect[s2_curr++] = num;
}

void Algorithms::Stack3::push3(int num){
    if (size3() == capacity3()) resize3();
    vect[s3_curr++] = num;
}

int Algorithms::Stack3::pop1() {
    if (size1() == 0) throw std::overflow_error("Stack #1 is empty()");
    return vect[--s1_curr];
}

int Algorithms::Stack3::pop2() {
    if (size2() == 0) throw std::overflow_error("Stack #2 is empty()");
    return vect[--s2_curr];
}

int Algorithms::Stack3::pop3() {
    if (size3() == 0) throw std::overflow_error("Stack #3 is empty()");
    return vect[--s3_curr];
}

int Algorithms::Stack3::size1() {
    return s1_curr - s1_start;
}

int Algorithms::Stack3::size2() {
    return s2_curr - s2_start;
}

int Algorithms::Stack3::size3() {
    return s3_curr - s3_start;
}

int Algorithms::Stack3::capacity1() {
    return s1_end - s1_start;
}

int Algorithms::Stack3::capacity2() {
    return s2_end - s2_start;
}

int Algorithms::Stack3::capacity3() {
    return s3_end - s3_start;
}