#include <iostream>
#include <string>
using namespace std;

class A {
    public:
    virtual void hello() {
        cout << "\nI'm from A";
    }
};

class B1 : public A {
    public:
    void hello() {
        cout << "\nI'm from B1";
    }
};

class B2: public A {
    public:
    void hello() {
        cout << "\nI'm from B2";
    }
};

int main() {

    A *ptr;
    B1 obj1;
    B2 obj2;
    A obj3;

    ptr = &obj3;        // Pointer will give Segmentation fault if not initialiazed with any object
    ptr->hello();

    ptr = &obj1;        // Cannot assign address of another class without public inheritance
    ptr->hello();       // compiler determines the function to call based on the object's type, and not the pointer's type.

    ptr = &obj2;
    ptr->hello();

    return 0;
}