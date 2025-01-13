#include <iostream>
#include <string>
using namespace std;

const int size = 10;

class Array {
    int *ptr;

    public:
    Array() {
        ptr = new int[size];
        for (int i = 0; i < size; i++) {
            ptr[i] = i;
        }
    }

    int& operator[](int index) {
        if (index < 0 || index >= size) {
            cout << "\nIndex out of bound!" << endl;
            static int dummy = -1;
            return dummy;
        }
        return ptr[index];
    }

    const int& operator[](int index) const {
        if (index < 0 || index >= size) {
            cout << "\nIndex Out Of Bound!" << endl;
            static int dummy = -1;
            return dummy;
        }
        return ptr[index];
    }

    ~Array() {
        delete[] ptr;
    }
};

int main() {

    Array obj;

    for (int i = 0; i <= size; i++) {
        cout << "Index " << i << " : " << obj[i] << endl;
    }

    const Array constObj;
    
    cout << "\nConstant Obj" << endl;
    for (int i = 0; i <= size; i++) {
        cout << "Index " << i << " : " << obj[i] << endl;
    }

    return 0;
}