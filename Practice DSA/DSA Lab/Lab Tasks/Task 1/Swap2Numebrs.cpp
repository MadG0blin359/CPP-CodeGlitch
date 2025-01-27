#include <iostream>
using namespace std;

// Function to swap the values of two integers using pointers
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

    swap(ptrX, ptrY);     // Call the swap function to swap the values of the integers
    cout << "After swapping:" << endl;
    cout << "First integer: " << *ptrX << endl; // Print the swapped value of the first integer
    cout << "Second integer: " << *ptrY << endl; // Print the swapped value of the second integer
    
    system("pause");
    return 0;
}