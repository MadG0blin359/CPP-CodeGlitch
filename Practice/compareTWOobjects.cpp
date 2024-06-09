#include <iostream>
#include <string>
using namespace std;

class Compare {
    int n;

    public:
    Compare(int n = 0) {
        this->n = n;
    }

    int compare(Compare &other) {
        if (this->n == other.n)
            cout << "Objects are equal" << endl;
        else
            cout << "Objects are not equal" << endl;
    }
};

int main() {

    Compare obj1(4), obj2(2);

    obj1.compare(obj2);

    return 0;
}