#include <iostream>
using namespace std;

// Overloaded Function Declaration
void areaOfShapes(const double, double);
void areaOfShapes(int, int);
void areaOfShapes(float, float);

int main() {

    char menu_choice;
    const double pi = 3.14159;

    cout << "\n\t*****Calculate Area Of Different Shapes*****\n";

    cout << "\n-----Menu-----";
    cout << "\n1. Circle";
    cout << "\n2. Rectangle";
    cout << "\n3. Triangle";
    cout << "\n--Select : ";
    cin >> menu_choice;

    switch (menu_choice) {
        case '1':
            double radius;
            
            cout << "\n--Enter the radius : ";
            cin >> radius;

            areaOfShapes(pi, radius);
            break;
        
        case '2':
            int length, width;
            
            cout << "\n--Enter the length : ";
            cin >> length;

            cout << "\n--Enter the width : ";
            cin >> width;

            areaOfShapes(length, width);
            break;

        case '3':
            float base, height;

            cout << "\n--Enter the base : ";
            cin >> base;

            cout << "--Enter the height : ";
            cin >> height;

            areaOfShapes(base, height);

            break;

        default:
            cout << "\n-----Invalid Input!-----\n";
            break;
    }

    return 0;
}

// Overloaded function to calculate the area of a Circle
void areaOfShapes(const double pi, double radius) {
    cout << "\n--Area of the Circle is : " << pi * radius * radius;
}

// Overloaded function to calculate the area of a Rectangle
void areaOfShapes(int length, int width) {
    cout << "\n--Area of the Rectangle is : " << length * width;
}

// Overloaded function to calculate the area of a Triangle
void areaOfShapes(float base, float height) {
    cout << "\n--Area of the Triangle is : " << (base * height) / 2.0;
}