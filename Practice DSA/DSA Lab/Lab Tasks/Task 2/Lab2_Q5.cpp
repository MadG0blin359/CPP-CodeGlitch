#include <iostream>
using namespace std;

void inputMatrix(int* matrix, int rows, int cols) {
    cout << "Enter the elements of the matrix (" << rows << "x" << cols << "):\n";


    for (int i = 0; i < rows; i++) {
    
        for (int j = 0; j < cols; j++) {

            cin >> *(matrix + i * cols + j);
        }
    }
}

void printMatrix(int* matrix, int rows, int cols) {
    cout << "Matrix (" << rows << "x" << cols << "):\n";
    
    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < cols; j++) {

            cout << *(matrix + i * cols + j) << " ";
        }

        cout << endl;
    
    }

}

void addMatrices(int* matrix1, int* matrix2, int* resultMatrix, int rows, int cols) {
    
    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < cols; j++) {

            *(resultMatrix + i * cols + j) = *(matrix1 + i * cols + j) + *(matrix2 + i * cols + j);
        }
    }


}

int main() {

    int rows = 3, cols = 3;

    // memory for three 3x3 matrices
    int* matrix1 = new int[rows * cols];
    int* matrix2 = new int[rows * cols];

    int* resultMatrix = new int[rows * cols];

    // values for the two matrices
    cout << "Matrix 1:\n";
    inputMatrix(matrix1, rows, cols);

    cout << "\nMatrix 2:\n";
    inputMatrix(matrix2, rows, cols);

    
    addMatrices(matrix1, matrix2, resultMatrix, rows, cols);

    // Print matrices
    cout << "\nMatrix 1:\n";
    printMatrix(matrix1, rows, cols);

    cout << "\nMatrix 2:\n";
    printMatrix(matrix2, rows, cols);

    cout << "\nResult Matrix (After Addition):\n";
    printMatrix(resultMatrix, rows, cols);

    // Free memory
    delete[] matrix1;
    delete[] matrix2;
    delete[] resultMatrix;
    system("pause");

    return 0;
}