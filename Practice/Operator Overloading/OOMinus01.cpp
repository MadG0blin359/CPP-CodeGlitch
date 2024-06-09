#include <iostream>
#include <string>
using namespace std;

class Minus {
    int n;

    public:
    Minus(int n = 0) {
        this->n = n;
    }

    void display() {
        cout << "n = " << n << endl;
    }

    int operator-(Minus &other) {
        return this->n - other.n;
    }
};

int main() {

    Minus obj1(5), obj2(3), obj3;

    obj3.display();
    obj3 = obj1 - obj2;
    obj3.display();

    return 0;
}