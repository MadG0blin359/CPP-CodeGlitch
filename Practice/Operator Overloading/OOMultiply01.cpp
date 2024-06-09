#include <iostream>
#include <string>
using namespace std;

class Multiply {
    int length, width;

    public:
    Multiply(int l = 0, int w = 0) : length(l), width(w) {}

    Multiply operator*(Multiply &other) {
        Multiply temp;
        temp.length = this->length * other.length;
        temp.width = this->width * other.width;
        return temp;
    }

    void display() {
        cout << "\nLenght : " << length
             << "\nWidth : " << width
             << endl;
    }
};

int main() {

    Multiply obj1(5, 3), obj2(3, 2), obj3;

    obj3 = obj1 * obj2;
    
    obj3.display();

    return 0;
}