#include <iostream>
#include <string>
using namespace std;

class A {
    int age;

    public:
    A(int age) {
        this->age = age;
    }

    void increment() {
        this->age++;
    }

    void display() {
        this->increment();
        cout << "Age : " << age; 
    }

};

int main() {

    A obj(5);

    obj.display();

    return 0;
}