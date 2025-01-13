#include <iostream>
using namespace std;

int main() {

    double *dynamicDouble = new double(5.5);

    cout << dynamicDouble << endl;
    cout << *dynamicDouble;

    delete dynamicDouble;

    dynamicDouble = new double;     // Allocate new memory address

    cout << "\n--Enter double : ";
    cin >> *dynamicDouble;

    cout << dynamicDouble << endl;
    cout << *dynamicDouble << endl;

    delete dynamicDouble;

    return 0;
}