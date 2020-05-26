#include <random>
#include <iostream>

using namespace std;

int main () {
    // random_device rd;
    mt19937 gen((random_device())());
    uniform_int_distribution<> dis(1, 13);
    cout << "Ints distribution: " << endl;
    for (int i = 0; i < 20; ++i) cout << "Number: " << dis(gen) << endl;

    uniform_real_distribution<> disR(1, 13);
    cout << "Real distribution: " << endl;
    for (int i = 0; i < 20; ++i) cout << "Number: " << disR(gen) << endl;
}