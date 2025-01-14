#include <iostream>
using namespace std;

int main() {

    float cTemp;
    float fTemp;

    cout << "Enter temperature in Centigrade : ";
    cin >> cTemp;

    fTemp = (cTemp * 9/5) + 32;

    cout << "Temperature in Fahrenhiet : " << fTemp << endl;

    return 0;
}