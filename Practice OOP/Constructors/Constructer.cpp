#include <iostream>
using namespace std;

class Constructer {

    public:
    int a, b, c;

    Constructer() {
        a = 5;
        b = 4;
        c = 10;
    }

    void displayData() {
        cout << a << "\n";
        cout << b << "\n";
        cout << c << "\n";
    }

};

int main() {

    Constructer c1;
    c1.displayData();

    return 0;
}