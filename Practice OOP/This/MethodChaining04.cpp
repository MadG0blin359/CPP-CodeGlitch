#include <iostream>
using namespace std;

class Bank {
    double balance;

    public:
    Bank(double initialAmount) : balance(initialAmount) {}

    Bank& setDeposit(double amount) {
        balance += amount;
        return *this;
    }

    Bank& setWithdraw(double amount) {
        balance -= amount;
    }

    void display() {
        cout << "\nBalance : " << balance << endl;
    }
};

int main() {

    Bank client(500);

    client.setDeposit(600).setWithdraw(950).setDeposit(100).display();

    return 0;
}