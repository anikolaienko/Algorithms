#include <array>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    int arr[] {1, 2, 3};
    vector<int> vect(arr, arr + sizeof(arr) / sizeof(int));

    cout << "Arr: start = " << arr << " end = " << (arr + sizeof(arr) / sizeof(int)) << endl;

    cout << "Vect: start = " << &(*(vect.begin())) << " end = " << &(*(vect.end())) << endl;
    cout << "Vect: front = " << &vect.front() << " last: " << (&vect.back()) + 1 << endl;

    cout << "Vect: size: " << vect.size() << " max_size: " << vect.max_size() << " capacity: " << vect.capacity() << endl;
    
    vector<int>::iterator it = vect.end();
    cout << "Iterator &: " << &(*it) << endl;

    vect.push_back(4);
    cout << "Vect: size: " << vect.size() << " max_size: " << vect.max_size() << " capacity: " << vect.capacity() << endl;

    cout << "Iterator &: " << &(*it) << endl;
}