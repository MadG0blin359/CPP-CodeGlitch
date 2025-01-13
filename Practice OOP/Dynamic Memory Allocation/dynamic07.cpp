#include <iostream>
using namespace std;

int main() {

    // 2-dimensional dynamic memory allocation
    int rows = 3, cols = 5;
    int *arr[rows];         // Non-dynamic array of 3 pointers

    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];     // Assignming an array of 5 elements to each pointer
    }

    /*
    arr[0] - 1 2 3 4 5
    arr[1] - 1 2 3 4 5
    arr[2] - 1 2 3 4 5
    */

   for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
        arr[i][j] = 1+j;            // Assigning value
        cout << arr[i][j] << " ";
    }
    cout << endl;
   }

   for (int i = 0; i < rows; i++) {
    delete[] arr[i];        // Delete each array allocated with new[]
   }

    return 0;
}