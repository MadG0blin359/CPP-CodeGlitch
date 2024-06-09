#include <iostream>
using namespace std;

int main() {

    int *dynamicInt;
    dynamicInt = new int;       // Dynamically allocate an integer memory
    *dynamicInt = 11;

    cout << *dynamicInt << endl;

    // delete dynamicInt;

    dynamicInt = new int;           // Previously allocated Memory leaked
    *dynamicInt = 5;

    cout << *dynamicInt << endl;

    delete dynamicInt;

    return 0;
}