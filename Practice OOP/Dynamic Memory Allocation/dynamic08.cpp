#include <iostream>
using namespace std;

int main() {

    int rows, cols;

    cout << "--Enter rows : ";
    cin >> rows;

    cout << "--Enter colums : ";
    cin >> cols;

    int *arr[rows];     // Array of pointers

    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = 1+j;
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }

    return 0;
}