#include <iostream>
#include <string>
using namespace std;

class Plus {
    int n;

    public:
    Plus(int n = 0) {
        this->n = n;
    }

    void display() {
        cout << "n = " << n << endl;
    }

    int operator+(Plus &other) {
        return this->n + other.n; 
    }
};

int main() {

    Plus obj1(5), obj2(5), obj3;

    obj3.display();

    obj3 = obj1 + obj2;

    obj3.display();

    return 0;
}