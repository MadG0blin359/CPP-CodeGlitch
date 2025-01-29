#include <iostream>
using namespace std;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x, y;
    int* ptrX = &x;
    int* ptrY = &y;

    cout << "Enter the first integer: ";

    cin >> *ptrX;

    cout << "Enter the second integer: ";

    cin >> *ptrY;

    swap(ptrX, ptrY);
    cout << "After swapping:" << endl;
    cout << "First integer: " << *ptrX << endl;
    cout << "Second integer: " << *ptrY << endl;
    
    system("pause");
    return 0;
}