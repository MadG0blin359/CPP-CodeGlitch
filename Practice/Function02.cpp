#include <iostream>
using namespace std;

void swap(int*, int*);

int main() {

    int x = 5, y = 9;

    cout << "Before Swaping :\nx = " << x << " and y = " << y;
    // Call by reference
    swap(&x, &y);
    
    cout << "\nAfter Swaping : \nx = " << x << " and y = " << y;

    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;  // temp = *a (value at address of a)
    *a = *b;
    *b = temp;
}