#include <iostream>
#include <string>
using namespace std;

class Rectangle {
    private:
    double width;
    double height;

    public:
    Rectangle() : width(0), height(0) {}
    
    // Setters
    Rectangle& setWidth(double w) {
        width = w;
        return *this;
    }

    Rectangle& setHeight(double h) {
        height = h;
        return *this;
    }

    void print() {
        cout << "Width: " << width << ", Height: " << height << endl;
    }
};

int main() {

    Rectangle shape;

    shape.setWidth(5).setHeight(3).print();

    return 0;
}