#include <iostream>
using namespace std;

class Deep {
    public:

    int *data;
    int a;
    // Copy Constructor
    Deep(Deep &other) {
        data = new int;
        *data = *other.data;    // Deep copy: Allocate new memory and copy
        cout << "\n--A : " << a;
    }

    Deep(int value) {
        *data = value;
        a = value;
        cout << "\n--Data : " << *data;
    }
};

int main() {

    Deep obj1(40);
    // Method 1
    // Deep obj2 = obj1;       // Deep Copy made by the copy constructor

    // Method 2
    Deep obj2(obj1);     // Deep Copy made by the copy constructor

    return 0;
}