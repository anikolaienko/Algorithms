#include <iostream>
#include <vector>
#include <unordered_set>
#include <cstdlib>
#include <iterator>
#include <algorithm>

using namespace std;

void display(unordered_set<int> s) {
    cout << "Printing: s" << endl;
    for (auto item: s) cout << item << " ";
    cout << endl;
}

void test_fillout_with_vector() {
    vector<int> v { 1, 2, 3 ,4, 6, 7};
    unordered_set<int> s(v.begin(), v.end());
    display(s);
    s = unordered_set<int> ({1, 2, 3, 4, 5});
    display(s);
    int a[] {3, 5, 7, 2};
    s = unordered_set<int> (a, a + sizeof(a) / sizeof(int));
    display(s);
}

void test_default_hash_function() {
    unordered_set<int> s;

    for (int i = 0; i < 200; ++i) {
        auto it = s.insert(i);
        cout << "Buckets: " << s.bucket_count() << " positions: " << distance(s.begin(), it.first) << 
                " f(" << i << ") = " << s.hash_function()(i) << endl;
    }
}

void test_with_random_values() {
    unordered_set<int> s;

    for (int i = 0; i < 200; ++i) {
        int num = rand();
        auto it = s.insert(num);
        cout << i << ": Buckets: " << s.bucket_count() << " positions: " << distance(s.begin(), it.first) << 
                " f(" << num << ") = " << s.hash_function()(i) << endl;
    }
}

int main() {
    // test_default_hash_function();
    // test_with_random_values();
    test_fillout_with_vector();
}