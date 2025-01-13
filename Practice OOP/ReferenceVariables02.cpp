#include <iostream>
using namespace std;

const int size = 10;

void countEvenOdd(int size, int arr[]);

int main() {

    int arr[size] = {2, 12, 5, 4, 3, 7, 8, 4, 8, 1};
    int sum = 0;

    for (int i : arr) {
        sum += i;
    }

    cout << "\nThe Sum is : " << sum;

    int even = 0, odd = 0;

    for (int i : arr) {
        if (i %2 == 0)
            even++;
        
        else
            odd++;

    }

    cout << "\nEven Values : " << even << "\nOdd Value : " << odd;

    return 0;
}
