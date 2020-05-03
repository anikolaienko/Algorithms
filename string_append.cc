#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    ostringstream out;
    out << "hello";
    cout << out.str().size() << out.str().capacity() << endl;
    out << " world! And Andrii sends hello as well";
    cout << out.str().size() << out.str().capacity() << endl;
    string s = "hello";
    cout << s.size() << s.capacity() << endl;
    s.append(" world! And Andrii sends hello as well");
    cout << s.size() << s.capacity() << endl;
    
    return 0;
}