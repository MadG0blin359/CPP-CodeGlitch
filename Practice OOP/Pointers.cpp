#include <iostream>
using namespace std;

int main() {

    int a = 8;
    int *ptr = &a;

    cout << "Address of a : " << &a;
    cout << "\nValue of ptr : " << ptr;
    cout << "\nDereference Value of a : " << *ptr;
    cout << "\nAddress of ptr : " << &ptr << endl << endl;

    int **cptr;
    cptr = &ptr;

    cout << "Value of cptr : " << cptr << endl;
    cout << "Address of cptr : " << &cptr << endl;
    cout << "Dereference value : " << *cptr << endl;
    cout << "Value at value_at(cptr) : " << **cptr << endl;

    return 0;
}