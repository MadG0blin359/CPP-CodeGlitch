#include<iostream>
#include<string>
using namespace std;

template <class T = int, class U = double, class V = bool, class W = string>
class Data {
    T age;
    U height;
    V isMale;
    W name;

    public:
    Data(T age, U height, V isMale, W name) {
        this->age = age;
        this->height = height;
        this->isMale = isMale;
        this->name = name;
    }

    void display() {
        cout << "Name : " << name << endl
             << "Gender : " << isMale << endl
             << "Age : " << age << endl
             << "Height : " << height << endl; 
    }
};

int main() {

    Data <> person(21, 1.79, true, "Shawaiz");

    person.display();

    return 0;
}