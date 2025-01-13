#include <iostream>
#include <string>
using namespace std;

class Plus {
    double num;

    public:
    Plus(double n = 0) : num(n) {}

    void dislplay() {
        cout << "\nn + obj1 = " << num;
    }

    friend double operator+(double n, Plus &other);
};

double operator+(double n, Plus &other) {
    return n + other.num;
}

int main() {

    Plus obj1(5.5), obj2;
    double n = 2.69;

    obj2 = n + obj1;
    
    obj2.dislplay();

    return 0;
}