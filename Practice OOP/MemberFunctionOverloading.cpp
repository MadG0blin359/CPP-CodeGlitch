#include <iostream>
using namespace std;

class A {
    protected:
    int salary;

    void showDetail(int s) {
        salary = s;
        cout << "\nsalary : " << salary;
    }

    void showDetail(int x, int y) {
        cout << "\n x : " << x << " & y : " << y;
    }

    void showDetail() {
        cout << "\nMy name is Jack";
    }
};

class B : A {
    public:
    // using A::showDetail;
    // Overloaded function overriding
    void showDetail() {
        cout << "\nMy name is Sparrow";
    }

    void showDetail(int s) {
        salary = 2 * s;
        cout << "\nsalary : " << salary;
    }
};

int main() {

    B obj1;
    obj1.showDetail();
    obj1.showDetail(50);

    return 0;
}