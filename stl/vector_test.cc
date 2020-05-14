#include <array>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

void display(vector<int>& v, string message) {
    cout << message << endl;
    for_each(begin(v), end(v), [](int& a) { cout << a << " ";});
    cout << endl;
}

void pass_copy(vector<int> v) {
    v[0] = 3;
    display(v, "Inside:");
}

/**
 * We are curious about size of data()
 * cause as we know `vector<bool>` is special data type in STL
 * optimized by space and basically is bitset in its nature
 */
void bool_vector_test() {
    vector<bool> v {false, true, false, true};
    cout << "V size: " << v.size() << " cap: " << v.capacity() << endl;
    cout << "Data: " << "oops, there is not data() function in `vector<bool`" << endl;
}

/**
 * Testing `swap` replaces content
 * In fast swap replaces pointers to internal arrays in V1 and V2
 * standalone `swap` function from `utility` or from `vector` libs works same way for vector
 */
void swap_test() {
    vector<int> v1(2,300);
    vector<int> v2(2,400);
    cout << "V1 at: " << &v1 << " data: " << v1.data() << endl;
    cout << "V2 at: " << &v2 << " data: " << v2.data() << endl;

    v1.swap(v2); // same result as `swap(v1, v2);`
    swap(v1, v2);
    display(v1, "V1: ");
    display(v2, "V2: ");

    cout << "V1 at: " << &v1 << " data: " << v1.data() << endl;
    cout << "V2 at: " << &v2 << " data: " << v2.data() << endl;
}

/**
 * Testing insert capabilities
 */
void insert_test() {
    std::vector<int> v (3,100);
    std::vector<int>::iterator it;
    display(v, "Initial vector:");

    it = v.begin();
    it = v.insert (it , 200 );
    display(v, "Insert into beginning:"); // 200, 2, 300

    v.insert (it, 2, 300); // 300, 300, 200, 2, 300
    display(v, "Two 300 into same position:");

    // "it" no longer valid, get a new one:
    it = v.begin();

    std::vector<int> v2 (2,400);
    v.insert (it+2, v2.begin(), v2.end());
    display(v, "Inserted at second position another array (400, 400):");

    int arr [] = { 501,502,503 };
    v.insert (v.begin(), arr, arr + 3);
    display(v, "Inserted at beginning another array (501, 502, 503)");
}

/**
 * We want to check if iterator persist it's position to end()
 * It turns out that iterator is pretty simple and it points at memory position
 * if vector is updated, new iterator should be created, cause old one may be not valid anymore.
 */
void iterator_test() {
    int arr[] {1, 2, 3};
    vector<int> vect {1,2};
    vect.push_back(3);

    cout << "Arr: start = " << arr << " end = " << (arr + sizeof(arr) / sizeof(int)) << endl;

    cout << "Vect: start = " << &(*(vect.begin())) << " end = " << &(*(vect.end())) << endl;
    cout << "Vect: front = " << &vect.front() << " last: " << &vect.back() << endl;

    cout << "Vect: size: " << vect.size() << " max_size: " << vect.max_size() << " capacity: " << vect.capacity() << endl;
    
    vector<int>::iterator it = vect.end();
    cout << "Iterator &: " << &(*it) << endl;

    vect.push_back(4);
    cout << "Vect: start = " << &(*(vect.begin())) << " end = " << &(*(vect.end())) << endl;
    cout << "Vect: front = " << &vect.front() << " last: " << &vect.back() << endl;
    cout << "Vect: size: " << vect.size() << " max_size: " << vect.max_size() << " capacity: " << vect.capacity() << endl;

    cout << "Iterator &: " << &(*it) << endl;
    cout << "Iterator value: " << (*it) << endl;
}

/**
 * Testing if end iterator changes
 * with push/pop operations
 */
void test_end_changes() {
    vector<int> v1 { 20, 30, 40 };
    auto v1Begin = v1.begin();
    auto v1End = v1.end();
    cout << "Begin iterator: " << &(*v1Begin) << " End iterator: " << &(*v1End) << endl;
    for (int i: {1, 2, 3, 4, 5, 6, 7, 8, 9}) v1.push_back(i);
    
    v1Begin = v1.begin();
    v1End = v1.end();
    cout << "Begin iterator: " << &(*v1Begin) << " End iterator: " << &(*v1End) << endl;
}

/**
 * Testing if sort throws exception
 * Sort doesn't throw exception on vector
 */
void test_sort() {
    vector<int> v1;
    sort(v1.begin(), v1.end());
}

int main() {
    // iterator_test();
    // insert_test();
    // swap_test();
    // bool_vector_test();

    // vector<int> v { 1, 2, 3 };
    // display(v, "Initial");
    // pass_copy(v);
    // display(v, "After");

    // test_end_changes();
    test_sort();
}