#include <iostream>
using namespace std;

class ShallowCopy {
    private:
    int *data;

    public:
    ShallowCopy(int num) {
        data = new int(num);
    }

    // Copy Constructor
    ShallowCopy(const ShallowCopy &obj) {
        data = obj.data;
    }

    // Getter function
    int getData() const {
        return *data;      // Dereference pointer to get data
    }

    ~ShallowCopy() {
        delete data;
        cout << "\nDestructor Called" << endl;
    }
};

int main() {

    ShallowCopy obj1(7);
    ShallowCopy obj2(obj1);

    cout << obj2.getData();

    return 0;
}