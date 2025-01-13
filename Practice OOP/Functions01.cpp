#include <iostream>
using std::cout;

int sum(int, int);
void hello();

int main() {

    hello();
    // Call by value
    cout << "Sum is : " << sum(2,3);

    return 0;
}

int sum(int a, int b) {
    return a+b;
}

void hello() {
    cout << "Hello\n";
}