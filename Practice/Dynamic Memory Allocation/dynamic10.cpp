#include <iostream>
using namespace std;

int main() {
    int size = 4;
    int **ptr;
    ptr = new int*[size];  // Dynamic array of int pointers

    // Allocate memory for each row
    for (int i = 0; i < size; i++) {
        ptr[i] = new int[size];  // Allocate memory for each column in the row
    }

    // Assign values to the 2D array
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            ptr[i][j] = j+1;
            cout << ptr[i][j] << " ";       // Print the 2D array
        }
        cout << endl;
    }

    // Deallocate memory
    for (int i = 0; i < size; i++) {
        delete[] ptr[i];  // Delete each row
    }

    delete[] ptr;  // Delete the array of pointers

    return 0;
}
