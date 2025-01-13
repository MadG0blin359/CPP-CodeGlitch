#include <iostream>
#include <string>
using namespace std;

class Assignment {
    int data, *ptr;

    public:
    Assignment(int d = 0, int *p = nullptr) : data(d) {
        ptr = p;
    }

    Assignment& operator=(Assignment &other) {
        if (this != &other) {
            data = other.data;
            *ptr = *other.ptr;
        }
        return *this;
    }

    void display() {
        cout << "Data : " << data << endl;
        cout << "Ptr : " << *ptr << endl;
        cout << "Address in Ptr : " << ptr << endl;
    }

};

int main() {

    int num = 10;
    Assignment obj1(5, &num), obj2;

    obj1.display();

    cout << "\nObj2 Before : " << endl;
    obj2.display();
    
    obj2 = obj1;
    
    cout << "\nObj2 After : " << endl;
    obj2.display();

    return 0;
}