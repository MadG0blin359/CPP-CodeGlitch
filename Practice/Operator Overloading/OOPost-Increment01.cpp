#include <iostream>
#include <string>
using namespace std;

class Increment {
    int n;

    public:
    Increment(int n = 0) {
        this->n = n;
    }

    void display() {
        cout << "n = " << n << endl;
    }

    void operator++(int) {
        n++;
    }
};

int main() {

    Increment obj(5);

    obj.display();
    obj++;
    obj.display();

    return 0;
}