#include <iostream>
#include <string>
using namespace std;

class Address {
    int n = 0;

    public:
    Address() {}
    Address(int n) {
        this->n = n;
    }
    
    void print() {
        cout << "n = " << n << endl;
    }

    Address& getAddress() {
        ++n;
        return *this;
    }
};

int main() {

    Address obj(5), obj1;

    obj.getAddress().getAddress().getAddress().print();

    obj1 = obj;
    
    cout << "\nobj2" << endl;
    obj1.print();

    return 0;
}