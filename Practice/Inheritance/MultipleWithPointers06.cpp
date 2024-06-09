#include <iostream>
#include <string>
using namespace std;

class A {
    public:
    A() {
        cout << "\nConstructor of A";
    }

    ~A() {
        cout << "\nDestructor of A";
    }
};

class B : public A {
    public:
    B() {
        cout << "\ncontructor of B";
    }

    ~B() {
        cout << "\nDestructor of B";
    }
};

int main() {

    A *ptr;

    ptr = new B;

    delete ptr;

    // Contructor A & B is called
    // Destructor of only A is called

    return 0;
}