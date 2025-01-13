#include <iostream>
#include <string>
using namespace std;

class Decrement {
    int n;

    public:
    Decrement() {
        n = 4;
    }

    void display() {
        cout << "n = " << n << endl;
    }

    void operator--() {
        n--;
    }
};

int main() {

    Decrement obj;

    obj.display();
    --obj;
    obj.display();

    return 0;
}