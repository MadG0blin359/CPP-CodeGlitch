#include <iostream>
using namespace std;

class A {
    public:
    void fun1() {
        cout << "Fun1 of A\n";
    }
    virtual void fun2() {
        cout << "Fun2 of A\n";
    }
 void fun3() {
        cout << "Fun3 of A\n";
    }
    
    virtual ~A() {
        cout << "Destructor of A\n";
    }
};

class B : public A {
    public:
    virtual void fun1() {
        cout << "Fun1 of B\n";
    }
    void fun2() {
        cout << "Fun2 of B\n";
    }
 void fun3() {
        cout << "Fun3 of B\n";
    }
    ~B() {
        cout << "Destructor of B\n";
    }
};

class C : public B {
    public:
    void fun1() {
        cout << "Fun1 of C\n";
    }
    void fun2() {
        cout << "Fun2 of C\n";
    }
 virtual void fun3() {
        cout << "Fun3 of C\n";
    }
    ~C() {
        cout << "\nDestructor of C\n";
    }
};

void OutFun(B &obj) {
    obj.fun1();
    obj.fun2();
    obj.fun3();
}

int main() {
    // Write C++ code here
C obj;
OutFun(obj);
B *ptr = new C;
delete ptr;
    return 0;
}