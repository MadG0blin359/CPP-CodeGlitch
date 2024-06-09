#include <iostream>
using namespace std;

int main() {

    int size = 3;
    int *dynamicIntArray = new int[size];
    string *dynamicString = new string[size];

    dynamicIntArray[0] = 1;
    dynamicIntArray[1] = 2;
    dynamicIntArray[2] = 3;

    dynamicString[0] = "Dew";
    dynamicString[1] = "Cola";
    dynamicString[2] = "Fanta Jumbo";

    for (int i = 0; i < size; i++) {
        cout << dynamicIntArray[i];
        cout << "." << dynamicString[i] << endl;
    }

    delete[] dynamicIntArray;
    delete[] dynamicString;

    return 0;
}