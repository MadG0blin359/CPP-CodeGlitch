#include <iostream>
using namespace std;

void swap(int &a, int &b);

int main() {

    int x, y;
    x = 5;
    y = 9;

    swap(x, y);

    cout << "After Swaping : " << x << " " << y;

    return 0;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}