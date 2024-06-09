#include <iostream>
#include<string>
using namespace std;

class A {
    public :
    A() {
        cout << "\nHello from A";
    }
    void Hello() {
        cout << "\nHello from class A";
    }
};

class B: virtual public A {
    public:
    B() {
        cout << "\nHello from B";
    }
};

class C: virtual public A {
    public:
    C() {
        cout << "\nHello from C";
    }
};

class D: public B, public C{
    public:
    D() {
        cout << "\nHello from D";
    }
};

int main () {
    D Dobj;
    Dobj.Hello();

return 0;
}