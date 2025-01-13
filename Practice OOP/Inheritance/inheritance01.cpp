#include <iostream>
using namespace std;

class A {
    public:
    void test() {
        cout << "\nHello from A";
    }
    
    int a = 19;
};

class B {
    public:
    void test() {
        cout << "\nHello from B";
    }

    int a = 10;
};
// virtual keywords can only be used in hydrib inheritance. For simple multiple inheritance, use scope resolution operator
class C : public A, public B {

};

int main() {

    C obj;

    obj.B::test();
    cout << endl << obj.A::a;

    return 0;
}