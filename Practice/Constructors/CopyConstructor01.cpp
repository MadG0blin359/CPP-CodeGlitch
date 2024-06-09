#include <iostream>
#include <string>
using namespace std;

class Copy {
    public:
    string name;
    int age;

    Copy(int num) : age(num) {}

    Copy(const Copy &obj) {
        age = obj.age;
    }
};

int main() {

    Copy obj1(5);
    Copy obj2(obj1);

    cout << "\n--Age 1 : " << obj1.age;
    cout << "\n--Age 2 : " << obj2.age;

    return 0;
}