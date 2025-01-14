#include <iostream>
using namespace std;

struct Customer {
    int num;
    // void function();
    char letter;

    void function() {
        cout << "Member Function";
    }
};

// void Customer::function() {
//     cout << "\nMember function";
// }

int main() {

    Customer test;

    test.function();

    return 0;
}