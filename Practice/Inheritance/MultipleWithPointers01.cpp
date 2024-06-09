#include <iostream>
#include <string>
using namespace std;

class A {
    public:
    void hello() {
        cout << "\nI'm from A";
    }
};

class B1 : public A {
    public:
    // void hello() {
    //     cout << "\nI'm from B1";
    // }

    void bye() {
        cout << "\nBye from B1";
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

    ptr->hello();

    ptr = &obj1;        // Cannot assign address of another class without public inheritance
    // Both are equivalent below
    ptr->hello();       // compiler determines the function to call based on the pointer's type, not the object's type.
    obj1.A::hello();

    ptr = &obj2;
    ptr->hello();

    return 0;
}