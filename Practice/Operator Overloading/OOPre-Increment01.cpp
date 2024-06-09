#include <iostream>
#include <string>
using namespace std;

class Increment {
    int n;

    public:
    Increment() {
        n = 0;
    }

    void display() {
        cout << "n = " << n << endl;
    }

    void operator++() {
        ++n;
    }
};

int main() {

    Increment obj;

    obj.display();
    ++obj;
    obj.display();

    return 0;
}