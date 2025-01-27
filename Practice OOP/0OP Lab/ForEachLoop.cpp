#include <iostream>
using namespace std;

int main() {

    int arr[] = {2,5,4,6,8,8,0,5};

    cout << "Traversing the array with foreach using array's data type: ";

    for (int i : arr) {
        cout << i << " ";
    }
    
    cout << "\nTraversing the array with foreach using auto keyword : ";

    for (auto i : arr) {
        cout << i << " ";
    }

    return 0;
}