#include <iostream>
#include <string>
using namespace std;

class Equality {
    int num;

    public:
    Equality(int n = 0) : num(n) {}

    bool operator==(Equality &other) {
        if (this->num == other.num)
            return true;
        else
            return false;
    }

};

int main() {

    Equality obj1(8), obj2(8);

    if (obj1 == obj2)
        cout << "\nBoth are equal" << endl;
    else
        cout << "\nBoth are not equal" << endl;

    return 0;
}