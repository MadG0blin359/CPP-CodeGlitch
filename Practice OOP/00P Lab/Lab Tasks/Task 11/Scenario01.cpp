#include <iostream>
#include <cmath> // For mathematical functions like pow() & sqrt()
using namespace std;

// Abstract base class for Shapes
class Shape {
public:
    virtual double area() const = 0; // Pure virtual function for area calculation - pure specifier ( = 0 )
    virtual ~Shape() { // Virtual destructor
        // cout << "\nShape Destructor Called.\n";
    }
};

// Abstract base class for 2D Shapes
class Shape2D : public Shape {
public:
    virtual ~Shape2D() { // Virtual destructor
        // cout << "\nShape2D Destructor Called.\n";
    }
};

// Abstract base class for 3D Shapes
class Shape3D : public Shape {
public:
    virtual double volume() const = 0; // Pure virtual function for volume calculation - pure specifier ( = 0 )
    virtual ~Shape3D() { // Virtual destructor
        // cout << "\nShape3D Destructor Called.\n";
    }
};

// Derived class for Circle
class Circle : public Shape2D {
private:
    double radius;

public:
    Circle(double r) : radius(r) {} // Constructor

    double area() const {
        return 3.14 * radius * radius;
    }

    ~Circle() { // destructor
        // cout << "\nCircle Destructor Called.\n";
    }
};

// Derived class for Square
class Square : public Shape2D {
private:
    double side;

public:
    Square(double s) : side(s) {} // Constructor

    double area() const {
        return side * side;
    }

    ~Square() { // destructor
        // cout << "\nSquare Destructor Called.\n";
    }
};

// Derived class for Cube
class Cube : public Shape3D {
private:
    double length, width, height;

public:
    Cube(double l, double w, double h) : length(l), width(w), height(h) {} // Constructor

    double area() const {
        return 2 * (length * width + length * height + width * height);
    }

    double volume() const {
        return length * width * height;
    }

    ~Cube() { // Virtual destructor
        // cout << "\nCube Destructor Called.\n";
    }
};

// Derived class for Pyramid
class Pyramid : public Shape3D {
private:
    double base, height;

public:
    Pyramid(double b, double h) : base(b), height(h) {} // Constructor

    double area() const {
        return base * base + 2 * base * sqrt(pow(base / 2, 2) + pow(height, 2)); // Surface area of pyramid
    }

    double volume() const {
        return (1.0 / 3.0) * base * base * height; // Volume of pyramid
    }

    ~Pyramid() { // Virtual destructor
        // cout << "\nPyramid Destructor Called.\n";
    }
};

int main() {
    // Array size variable
    const int size = 2;

    // Array of pointers to 2D shapes
    // Method 1: Shape2D* shapes2D[size] = {new Circle(5.0), new Square(4.0)};
    Shape2D* shapes2D[size];
    shapes2D[0] = new Circle(5.0);
    shapes2D[1] = new Square(4.0);

    // Array of pointers to 3D shapes
    // Method 1: Shape3D* shapes3D[size] = {new Cube(3.0, 3.0, 3.0), new Pyramid(4.0, 5.0)};
    Shape3D* shapes3D[size];
    shapes3D[0] = new Cube(3.0, 3.0, 3.0); 
    shapes3D[1] = new Pyramid(4.0, 5.0);

    // Calculate and display the area of each shape
    cout << "2D Shapes:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "Area: " << shapes2D[i]->area() << endl;
        delete shapes2D[i]; // Deallocate memory
    }

    // Calculate and display the area & volume of each shape
    cout << "\n3D Shapes:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "Area: " << shapes3D[i]->area() << ", Volume: " << shapes3D[i]->volume() << endl;
        delete shapes3D[i]; // Deallocate memory
    }

    return 0;
}
