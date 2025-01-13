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

    ptr = new Shape;
    ptr->draw();

    ptr = new Line();       // () are used to call the constructor, constructor is automatically called without round brackets if there are no parameters 
    ptr->draw();

    ptr = new Circle;
    ptr->draw();
    
    ptr = new Triangle;
    ptr->draw();

    delete ptr;

    return 0;
}