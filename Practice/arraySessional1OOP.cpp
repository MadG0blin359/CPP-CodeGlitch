#include <iostream>
using namespace std;

int main() {

    int list[7] = {10, 8, 15, 14, 16, 24, 36};
    int *ptr = list;
    *ptr = *ptr + 2;
    
    ptr++;

    *ptr = (*ptr/2) - 2;
    
    int *ptr2;

    for (int j = *ptr; j < 6; j++) {
        ptr2 = &list[j];
        ptr++;
        *ptr = *ptr2 * 2;
    }

    for (int i = 0; i < 7; i++) {
        cout << list[i] << endl;
    }

    return 0;
}