#include <iostream>
using namespace std;

class DeepCopy {
    int *data;

    public:
    DeepCopy(int num) {
        data = new int(num);
    }

    DeepCopy(const DeepCopy &obj) {
        data = new int(*obj.data);      // Deep copy
    }

    // Getter function
    int getData() const {
        return *data;
    }
};

int main() {

    DeepCopy obj1(6);
    DeepCopy obj2(obj1);

    cout << obj2.getData();

    return 0;
}