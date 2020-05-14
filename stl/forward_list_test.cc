#include <forward_list>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

void display(forward_list<int> l) {
    cout << "List: ";
    for (int& num: l) cout << num << " ";
    cout << endl;
}

/**
 * Testing push/pop operations
 */
void test_pop() {
    forward_list<int> l1 { 10, 20, 30, 40 };
    display(l1);
    l1.push_front(1);
    display(l1);

    while (!l1.empty()) {
        l1.pop_front();
        display(l1);
    }
}

/**
 * How to get list size?
 */
void test_size() {
    forward_list<int> l1 {10, 20, 30, 40};
    cout << "List size: " << distance(l1.begin(), l1.end()) << endl;
    l1.push_front(1);
    cout << "List size: " << distance(l1.begin(), l1.end()) << endl;
}

/**
 * Testing if end iterator changes
 * with push/pop operations
 */
void test_end_changes() {
    forward_list<int> l1 { 20, 30, 40 };
    auto l1Begin = l1.begin();
    auto l1End = l1.end();
    cout << "Begin iterator: " << &(*l1Begin) << " End iterator: " << &(*l1End) << endl;
    for (int i: {1, 2, 3, 4, 5, 6, 7, 8, 9}) l1.push_front(i);
    
    l1Begin = l1.begin();
    l1End = l1.end();
    cout << "Begin iterator: " << &(*l1Begin) << " End iterator: " << &(*l1End) << endl;
}

/**
 * Testing comparison operators
 */
void compare_test() {
    forward_list<int> l1 {10, 20, 30};
    forward_list<int> l2 {10, 20, 30};
    cout << "Lists are equal: " << (l1 == l2) << endl;
    l2.resize(4, 0);
    display(l2);
    cout << "List l2 is bigger than l1: " << (l2 > l1) << endl;
}

int main() {
    // test_pop();
    // test_size();
    // test_end_changes();
    compare_test();
}