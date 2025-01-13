#include <iostream>
using namespace std;

// int product(int a, int b);       // If declared a prototype of the function, then the default armgument concept will not work.
// Do it without the prototype, before main function
int product(int a, int b = 2) {
    return a*b;
}

int sum(int a, int const b = 5) {
    return a+b;
}

int main() {

    cout << "The Product is : " << product(5);  // No need to send second argument, as it is initialized by default, however, if sended, then it will replace the value at default parameter.
    
    // See the const variable manipulation here, b is constant in the function but still it can be replaced with any other value from main.
    // Variable is only constant in the sum function, so when it is getting initialized by 5, the number 5 gets replaced by the argument 8.
    cout << "\nThe Sum is : " << sum(4, 8);

    return 0;
}
