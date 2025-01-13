#include <iostream>
using namespace std;

class Traingle {
    private:
    double side1, side2, side3;

    public:
    Traingle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {       // Initialize class variables to parametric values

    }

    void determineType() {
        if (side1 == side2 && side2 == side3)
            cout << "\nThe triangle is an Equilateral Traingle.";
        else if (side1 == side2 || side2 == side3 || side1 == side3)
            cout << "\nThe triangle is an Isosceles Triangle.";
        else
            cout << "\nThe triangle is an Scalene Traingle.";
    }
};

int main() {

    double s1, s2, s3;

    cout << "\nInput the lengths of the three sides of the triangle:\n\n";    // Prompt user to input side lengths
    
    cout << "--Side 1 : ";
    cin >> s1;

    cout << "--Side 2 : ";
    cin >> s2;

    cout << "--Side 3 : ";
    cin >> s3;

    Traingle triangle(s1, s2, s3);

    triangle.determineType();
    
    return 0;
}