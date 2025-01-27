#include <iostream>
using namespace std;

int main() {

    // cout << "Hello World" << endl;
    // cout << "Second Output" << endl;
    // cout << "Third Output" << endl;
    // cout << "Fourth Output" << endl;

    int $a = 5;
    const float _pi = 3.14;
    
    cout << "The value of pi : " << _pi << endl;
    cout << "The value of pi : " << int(_pi) << endl;   // Function style explicit type-casting
    cout << "The value of pi : " << (int)_pi << endl;   // C-style explicit type-casting

    int $b = _pi;   // Implicit type-casting

    cout << endl;
    cout << "char : " << sizeof(char) << endl;
    cout << "bool : " << sizeof(bool) << endl;
    cout << "short : " << sizeof(short) << endl;
    cout << "int : " << sizeof(int) << endl;
    cout << "long : " << sizeof(long) << endl;
    cout << "float : " << sizeof(float) << endl;
    cout << "double : " << sizeof(double) << endl;
    cout << "long long : " << sizeof(long long) << endl;
    cout << "long double : " << sizeof(long double) << endl;

    return 0;
}