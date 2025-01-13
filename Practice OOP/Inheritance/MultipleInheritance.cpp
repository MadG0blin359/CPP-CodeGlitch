#include <iostream>
using namespace std;

class A {
    public:

    void hello() {
        cout << "\nHello World!";
    }
};

class B {
    public:

    void hello() {
        cout << "\nHello Universe";
    }
};

class C : public A, public B {

};

int main() {

    C obj;
    obj.A::hello();
    obj.B::hello();

    return 0;
}