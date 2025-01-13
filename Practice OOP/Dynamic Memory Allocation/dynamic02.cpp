#include <iostream>
#include <string>
using namespace std;

int main() {

    char *dynamicChar = new char;
    string *dynamicString = new string;

    cout << "--Enter char : ";
    cin >> *dynamicChar;

    cout << "--Enter string : ";
    cin.ignore();
    getline(cin, *dynamicString);

    cout << *dynamicChar << endl;
    cout << *dynamicString << endl;

    delete dynamicChar;
    delete dynamicString;

    return 0;
}