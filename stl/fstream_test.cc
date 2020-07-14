#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void readByChar(string filename) {
    ifstream ifs;
    ifs.open(filename, ios::binary);
    if (!ifs.good()) cout << "Error!";
    
    char c;
    while (ifs.get(c)) {
        cout << c << " ";
    }
    cout << endl;

    ifs.close();
}

void readByLine(string filename) {
    ifstream ifs;
    ifs.open(filename, ios::binary);
    if (!ifs.good()) cout << "Error!";
    
    string str;
    while (getline(ifs, str)) {
        cout << str << "\n";
    }
    cout << endl;

    ifs.close();
}

int main () {
    readByChar("test_data/text1.txt");
    readByLine("test_data/text1.txt");

    ofstream ofs;
    ofs.open("test_data/text1_out.txt", ios::out | ios::app);
    
    ofs << "\nHello buddy!";

    ofs.close();
    return 0;
}