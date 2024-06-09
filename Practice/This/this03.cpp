// Returning by Referrence
#include <iostream>
#include <string>
using namespace std;

class A {
    int n;
    string name;

    public:
    int num;

    A(int n = 0, string setn = "NULL", int setNum = 0) {
        this->n = n;        // Data member = parameter
        name = setn;
        num = setNum;
    }

    A& update() {
        this->n++;
        return *this;       // Returns a referrence to the current object
    }

    void display() {
        cout << n << endl;
        cout << name << endl;
        cout << num << endl;
    }

    A& increment() {
        this->n++;
        return *this;
    }

};

int main() {

    A obj1(5, "Test0X", 10), obj2;

    obj2 = obj1.update();        // Both obj will be independent due to the assignment operator

    obj2.num = 15;

    // obj1.display();
    cout << endl;
    // obj2.display();

    cout << endl;
    obj1.increment().increment().increment().display();
    cout << endl;
    obj1.update().update().update().display();

    cout << endl;
    obj2.display();

    return 0;
}