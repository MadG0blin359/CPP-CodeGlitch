#include <iostream>
using namespace std;

class Constant {
    const int num;

    public:
    Constant() : num(8) {}      // Constructor constant initializer list

    // Getter
    int getNum() const {
        return num;
    }
};

int main() {

    const Constant number;
    cout << "Number: " << number.getNum() << endl; // Output the value returned by getNum()

    Constant number2;
    cout << "Number2: " << number.getNum() << endl; // Output the value returned by getNum()

    return 0;
}