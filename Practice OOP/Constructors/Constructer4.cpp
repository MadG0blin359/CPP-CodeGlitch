#include <iostream>
using namespace std;

class Constructer {
    int a, b, c;

    public:

    //Parameterized Constructer
    Constructer(int x, int y, int z) {
        a = x, b = y, c = z;
        cout << a << "\n";
        cout << b << "\n";
        cout << c << "\n";
    }

    // Copy Constructer
    Constructer(Constructer &CCO) {     //Copy_Constructer_Object
        a = CCO.a; b = CCO.b; c = CCO.c;
        cout << a << "\n";
        cout << b << "\n";
        cout << c << "\n";
    }

};

int main() {

    Constructer PC(22, 45, 78);
    Constructer CCOTest(PC);

    return 0;
}