#include <iostream>
#include <string>
using namespace std;

class Shape {
    public:
    virtual void draw() {
        cout << "\nDraw a Shape";
    }

    virtual void calcArea() {
        cout << "\nCalculate a Shape";
    }
};

class Line : public Shape {
    public:
    void draw() {
        cout << "\nDraw a Line";
    }

    void calcArea() {
        cout << "\nCalculate Line";
    }
};

class Circle : public Shape {
    public:
    void draw() {
        cout << "\nDraw a Cirle";
    }

    void calcArea() {
        cout << "\nCalculate Circle";
    }
};

class Triangle : public Shape {
    public:
    void draw() {
        cout << "\nDraw a Triangle";
    }

    void calcArea() {
        cout << "\nCalculate Triangle";
    }
};

int main() {

    Shape *ptr;
    Line obj1;
    Circle obj2;
    Triangle obj3;

    // ptr->draw();     Will give segmentation fault because pointer is not initialized, if theres a virtual function in the class you must initialize the pointer before using it

    ptr = &obj1;
    ptr->draw();

    ptr = &obj2;
    ptr->draw();

    ptr = &obj3;    
    ptr->draw();

    return 0;
}