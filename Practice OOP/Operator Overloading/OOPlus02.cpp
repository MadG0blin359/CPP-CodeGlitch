#include <iostream>
#include <string>
using namespace std;

class Plus {
    double num;

    public:
    Plus(double n = 0) : num(n) {}

    double operator+(double n) {
        return num + n;
    }

    void display() {
        cout << "\nobj1 + n = " << num; 
    }
};

int main() {

    Plus obj1(8.5), obj2;
    double n = 3.25;

    obj2 = obj1 + n + n + n;

    obj2.display();

    return 0;
}