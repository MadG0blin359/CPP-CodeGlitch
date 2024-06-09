// Returning by Value
#include <iostream>
#include <string>
using namespace std;

class A {
    int n;
    string name;

    public:
    A(int n = 0, string setn = "NULL") {
        this->n = n;        // Data member = parameter
        name = setn;
    }

    A update() {
        return *this;       // Returns a copy of the current object (Return by value)
    }

    void display() {
        cout << n << endl;
        cout << name;
    }
};

int main() {

    A obj1(5, "Test0X"), obj2, obj3[5];

    // cout << &obj3 << endl;   // Default zeroth index
    cout << &obj3[3] << endl;

    obj2 = obj1.update();
    // obj2 = obj1;

    obj2.display();

    return 0;
}