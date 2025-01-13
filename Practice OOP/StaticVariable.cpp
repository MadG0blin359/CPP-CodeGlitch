#include <iostream>
using namespace std;

int sum(int, int);

int main() {

    int x = 1, y = 2;

    cout << "\nSum is " << sum(x, y);
    cout << "\nSum is " << sum(x, y);
    cout << "\nSum is " << sum(x, y);
    cout << "\nSum is " << sum(x, y);
    cout << "\nSum is " << sum(x, y);
    cout << "\nSum is " << sum(x, y);
    cout << "\nSum is " << sum(x, y);
    cout << "\nSum is " << sum(x, y);
    cout << "\nSum is " << sum(x, y);
    cout << "\nSum is " << sum(x, y);

    return 0;
}

// inline replaces the function call, in main function, with the below code.
// Use it when the function definitions are very small, and the functions are called several times in a program.
// inline functions usually make your code bigger because you have duplicated code for each invocation(call) of the function.
// It's better to leave this to compiler, it will automatically decide which fuction to use as inline.
inline int sum(int a, int b) {
    static int sum = 0;     // Static means initialize only once during the whole program execution, like the (int i = 0) in for loop.
    sum = sum + a + b;
}