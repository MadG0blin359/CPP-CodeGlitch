#include <iostream>
using namespace std;

int main() {
    int rows = 5;    // Number of rows in the rectangle
    int cols = 5;    // Number of columns in the rectangle

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            
            if (i == 1 || i == rows || j == 1 || j == cols) {
                // Print asterisks for the first, last row, and first and last column
                cout << "*";
            } 
            
            else {
                // Print spaces for the interior of the rectangle
                cout << " ";
            }
        }
        
        // Move to the next line after each row is printed
        cout << endl;
    }

    return 0;
}
