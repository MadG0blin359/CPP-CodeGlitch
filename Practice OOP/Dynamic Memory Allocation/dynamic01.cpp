#include <iostream>
using namespace std;

int main() {

    char letter;
    string name;

    cout << &letter << endl;
    cout << &name << endl;

    cout << "\n--Enter letter : ";
    cin >> letter;

    cout << "\n--Enter name : ";
    cin >> name;


    char *ptr = new char(letter);
    string *nam = new string(name);

    cout << "\n " << *ptr;
    cout << "\n " << *nam;

    delete ptr;
    delete nam;

    return 0;
}