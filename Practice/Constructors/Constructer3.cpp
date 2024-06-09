#include <iostream>
using namespace std;

class Constructer {
    public:
    
    Constructer(int x, double y, char z) {
        cout << x << endl;
        cout << y << endl;
        cout << z << endl;
    }

};

int main() {

    Constructer e(22, 1.22, 'G');

    return 0;
}