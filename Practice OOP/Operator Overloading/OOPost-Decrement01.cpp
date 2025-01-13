#include <iostream>
#include <string>
using namespace std;

class Decrement {
    int n;

    public:
    Decrement(int n = 0) {
        this->n = n;
    }

    void display() {
        cout << "n = " << n << endl;
    }

    void operator--(int) {
        n--;
    }
};

int main() {

    Decrement obj(9);
    obj.display();
    obj--;
    obj.display();

    return 0;
}