#include<iostream>
using namespace std;

template <class T, class U, class V>
class Print {
    T data1;
    U data2;
    V data3;

    public:
    Print(T a, U b, V c) {
        data1 = a;
        data2 = b;
        data3 = c;
    }

    void display() {
        cout << "Data1: " << data1 << endl
             << "Data2: " << data2 << endl
             << "Data3: " << data3 << endl;
    }
};

int main() {

    Print <int, float, char> obj(5, 2.5, 'f');

    obj.display();

    return 0;
}