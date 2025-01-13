#include <iostream>
#include <string>
using namespace std;

class NonEquality {
    int num;

    public:
    NonEquality(int n = 0) : num(n) {}

    bool operator!=(NonEquality &other) {
        if (this->num != other.num)
            return true;
        else
            return false;
    }

};

int main() {

    NonEquality obj1(8), obj2(3);

    if (obj1 != obj2)
        cout << "\nBoth are unequal" << endl;
    else
        cout << "\nBoth are equal" << endl;

    return 0;
}