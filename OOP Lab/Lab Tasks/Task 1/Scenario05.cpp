#include <iostream>
using namespace std;

int main() {

    const double pi = 3.14;
    double radius, cir_area;
    double length, width, rec_area;

    cout << "\n\t******Area of Circle******\n";
    cout << "Enter Radius to calculate : ";
    cin >> radius;

    cir_area = pi*radius*radius;

    cout << "Area of Circle is : " << cir_area;

    cout << "\n\n\t******Area of Rectangle******\n";
    cout << "Enter Lenthg : ";
    cin >> length;

    cout << "Enter Width : ";
    cin >> width;

    rec_area = length * width;

    cout << "Area of Rectangle is : " << rec_area << endl;

    return 0;
}