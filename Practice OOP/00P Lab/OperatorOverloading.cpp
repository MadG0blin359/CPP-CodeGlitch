#include <iostream>
using namespace std;

// Unary Operators (++) (--)
class OperatorOverloading {
    int num = 5;

    public:
    // Pre-increment
    void operator ++() {
        ++num;
        cout << "\n-->Pre-increment : " << num;
    }
    
    // Post-increment
    void operator ++(int) {         // int is not an argument, it's there just to differentiate b/w pre and post increment function
        num++;
        cout << "\n-->Post-increment : " << num;
    }
    
    // Pre-decrement
    void operator --() {
        --num;
        cout << "\n-->Pre-decrement : " << num;
    }
    
    // Post-decrement
    void operator --(int) {         // int is not an argument, it's there just to differentiate b/w pre and post decrement function
        num--;
        cout << "\n-->Post-decrement : " << num;
    }
};

int main() {

    OperatorOverloading obj;

    ++obj;      // Pre-increment
    obj++;      // Post-increment
    obj--;      // Pre-decrement
    --obj;      // Post-decrement

    return 0;
}