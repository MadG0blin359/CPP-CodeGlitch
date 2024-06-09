#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    int a = 5, b = 14, c = 1234;

    cout << "\nDefault Format Value : " << a;
    cout << "\nDefault Format Value : " << b;
    cout << "\nDefault Format Value : " << c;
    cout << endl;
    cout << "\nRight Justified Value : " << setw(4) << a;
    cout << "\nRight Justified Value : " << setw(4) << b;
    cout << "\nRight Justified Value : " << setw(4) << c;

    return 0;
}