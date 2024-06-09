#include <iostream>

using namespace std;

int main() {

    int i, j;
    i = 0;
    j = 0;

    cout << "\n-----------\n";
    cout << "num\tsum";
    cout << "\n-----------\n";

    while (i < 5) {
        
        i++;
        j += i;

        cout << i << "\t";
        cout << j << "\n";

    }

    cout << "-----------\n" << endl;

    return 0;
}