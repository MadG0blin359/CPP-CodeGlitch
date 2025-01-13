#include <iostream>
#include <string>
using namespace std;

const int size = 5;

class Array {
    const int arr[size] = {0,1,2,3,4};

    public:
    Array() {}

    const int& operator[](int index) {
        if (index < 0 || index >= size) {
            cout << "\nIndex Out Of Bound!" << endl;
            static int dummy = -1;
            return dummy;
        }
        return arr[index];
    }
};

int main() {

    Array obj;

    for (int i = 0; i <= size; i++) {
        cout << "Index " << i << " : " << obj[i] << endl;
    }

    return 0;
}