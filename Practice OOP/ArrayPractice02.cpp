#include <iostream>
using namespace std;

int main() {

    const int size = 7;
    int arr[size][size] = {0};

    arr[0][0] = 1;
    arr[1][0] = 1;
    arr[1][1] = 1;

    // Pascal Triangle
    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= i; j++) {

            if (j >= 1) {
                if (arr[i-1][j] >= 1 && arr[i-1][j-1] >= 1) {
                    arr[i][j] = arr[i-1][j] + arr[i-1][j-1]; 
                }

                else {
                    arr[i][j] = 1;
                }
            }

            else {
                arr[i][j] = 1;
            }

            cout << arr[i][j] << " ";

        }

        cout << endl;

    }

    return 0;

}