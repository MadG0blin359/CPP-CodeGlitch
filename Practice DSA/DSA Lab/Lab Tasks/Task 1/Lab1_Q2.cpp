#include <iostream>
using namespace std;

int main() {
    int size, valueToFind;
    cout << "Enter the size of the array: ";
    cin >> size;

    int* arr = new int[size];

    cout << "Enter " << size << " integer values for the array:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "Enter the value to find: ";
    cin >> valueToFind;

    bool found = false;
    for (int i = 0; i < size; i++) {
        if (arr[i] == valueToFind) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "Value exists in the array." << endl;
    }
    else {
        cout << "Value does not exist in the array." << endl;
    }

    delete[] arr;
    system("pause");
    return 0;
}