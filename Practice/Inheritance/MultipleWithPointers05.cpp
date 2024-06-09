#include <iostream>
#include <string>
using namespace std;

class A {
    public:
    A() {
        cout << "\nConstructor of A";
    }

    virtual void hello() = 0;

    void show() {
        cout << "\nShow from A";
    }
};

class B : public A {
    public:
    B() {
        cout << "\nConstructor of B";
    }

    void hello() {
        cout << "\nHello from B";
    }

    void display() {
        cout << "\nDisplaying from B";
    }
};

int main() {

    A *ptr;

    ptr = new B;
    ptr->hello();
    ptr->show();
    B obj;
    obj.hello();

    delete ptr;    

    return 0;
}