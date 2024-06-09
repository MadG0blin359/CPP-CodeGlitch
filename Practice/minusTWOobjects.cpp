#include <iostream>
#include <string>
using namespace std;

class Minus {
    int n;

    public:
    Minus(int n = 0) {
        this->n = n;
    }

    int minus(Minus &other) {
        return this->n - other.n;
    }

    void display() {
        cout << "n = " << n << endl;
    }

    int getN() const {
        return n;
    }
};

int main() {

    Minus obj1(10), obj2(7), obj3;

    obj3 = obj1.minus(obj2);
    // obj3 = obj1.getN() - obj2.getN();
    obj3.display();   

    return 0;
}