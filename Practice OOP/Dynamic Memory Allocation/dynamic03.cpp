#include <iostream>
using namespace std;

int main() {

    int *dynamicInt = new int;
    char *dynamicChar = new char;
    string *dynamicString = new string;

    *dynamicInt = 8;
    *dynamicChar = 'X';
    *dynamicString = "Dew";

    cout << *dynamicInt << endl;
    cout << *dynamicChar << endl;
    cout << *dynamicString << endl;

    delete dynamicInt;
    delete dynamicChar;
    delete dynamicString;

    return 0;
}