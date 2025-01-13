#include <iostream>
#include <string>
using namespace std;

class A {
    public:
    A() {
        cout << "\nConstructor of A";
    }

    void hello() {
        cout << "\nHello from A";
    }

    virtual ~A() {
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
    ptr->hello();

    ptr = new B;

    delete ptr;

    // Contructor A & B is called
    // Destructor of B & A is called

    return 0;
}