#include <iostream>
#include <string>
using namespace std;

class Minus {
    double num;

    public:
    Minus(double n = 0) : num(n) {}

    void display() {
        cout << "\nn - obj1 = " << num;
    }

    friend double operator-(double, Minus&);
};

double operator-(double n, Minus &other) {
    return n - other.num;
}

int main() {

    Minus obj1(4.25), obj2;
    double n = 5.0;

    // obj2 = n - obj1 - obj1 - obj1;
    // obj2 = n - obj1 - n - obj1;
    obj2 = n - obj1 + n - obj1;
    obj2.display();

    return 0;
}