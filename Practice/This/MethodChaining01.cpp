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

    Address getAddress() {
        ++n;
        return Address();
    }
};

int main() {

    Address obj(5);

    // The getAddress will increment n to 6, and returns a new object with n = 0.
    // The second one will make previous n = 0 to n = 1, and return a new object with n = 0.
    // The third one will make previos n = 0 to n = 1, and returns a new object with n = 0. 
    obj.getAddress().getAddress().getAddress().print();     // Final output : n = 0

    return 0;
}