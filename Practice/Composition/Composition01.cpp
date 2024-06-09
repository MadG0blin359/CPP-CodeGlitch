#include <iostream>
using namespace std;

class A {
    private:
    int num1, num2;

    public:
    A(int a, int b) : num1(a), num2(b) {}

    void display() {
        cout << "\nThe value of num1 is : " << num1 << ", num2 is : " << num2;
    }
};

class B {
    private:
    A obj1;
    int num3;

    public:
    B(int a = 0, int b = 0, int c = 0) : obj1(a, b), num3(c) {}

    void displayAll() {
        obj1.display();
        cout << " & num3 is : " << num3;
    }
};

int main() {

    B obj(3, 6, 9);

    obj.displayAll();

    return 0;
}