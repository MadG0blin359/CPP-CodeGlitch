#include <iostream>
using namespace std;

void swap(int &, int &);

int main() {

    int x = 6, y = 9;

    cout << "Before Swaping : x = " << x << " and y = " << y;
    swap(x, y);
    cout << "\nAfter Swaping : x = " << x << " and y = " << y;
    
    return 0;
}

// Swaping by C++ reference variables
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}