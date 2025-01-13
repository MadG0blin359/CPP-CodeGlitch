#include <iostream>
#include <string>
using namespace std;

class Assignment {
    int data, *ptr;

    public:
    Assignment(int d = 0, int p = 0) : data(d) {
        ptr = new int(p);
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

    ~Assignment() {
        delete ptr;
    }
};

int main() {

    Assignment obj1(5, 10), obj2;

    obj1.display();

    cout << "\nObj2 Before : " << endl;
    obj2.display();
    
    obj2 = obj1;
    
    cout << "\nObj2 After : " << endl;
    obj2.display();

    return 0;
}