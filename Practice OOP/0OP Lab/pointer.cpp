#include <iostream>
using namespace std;

int main() {

    int *ptr;

    int a;

    ptr = &a;

    a = 78;

    cout << *ptr;

    return 0;
}