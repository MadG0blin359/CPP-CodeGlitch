#include <iostream>
#include <string>
using namespace std;

const int size = 5;     // Global size variable for DMA

class bankAccount {
    protected:
    double balance;
    int num_of_deposits;
    int num_of_withdrawls;
    double annual_interest;
    double monthly_service_charge;

    public:
    bankAccount(double amount = 250, double interest = 1.5) : balance(amount), annual_interest(interest), num_of_deposits(0), num_of_withdrawls(0), monthly_service_charge(0.5) {}

    // Function to deposit funds
    virtual void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            num_of_deposits++;
            cout << "\n-----Funds Deposit Successfull!-----\n";
        }

        else
            cout << "\n-----Invalid Amount!-----";
    }

    // Function to withdraw funds
    virtual void withdraw(double amount) {
        if (amount > 0) {
            balance -= amount;
            num_of_withdrawls++;

            cout << "\n-----Funds Withdrawl Successfull!-----\n";
        }

        else
            cout << "\n-----Invalid Amount!-----";
    }
    
    // Function to calculate Monthly Interest
    virtual void calcInt() {
        balance += (balance * (annual_interest/12));
    }

    virtual void monthlyProc() {
        balance -= (balance * monthly_service_charge);      // Monthly Service Charges = 0.5% in constructor
        calcInt();
        num_of_deposits = 0;
        num_of_withdrawls = 0;
        monthly_service_charge = 0;
    }

};

class savingsAccount : public bankAccount {
    bool status;
    int const min_bal;

    public:
    savingsAccount() : min_bal(25) {}       // Constructor to initialize data members

    // Function to withdraw funds after verifying account status
    void withdraw() {
        if (balance >= min_bal) {
            status = 1;
        }

        else {
            status = 0;
        }

        if (status) {
            double amount;

            cout << "\n--Enter amount : ";
            cin >> amount;

            bankAccount::withdraw(amount);
        }

        else {
            cout << "\n-----Error! Account Inactive due to low funds!-----\n";
        }
    }

    // Function to deposit funds in savings account
    void deposit() {
        if (balance < min_bal) {
            status = 0;
        }

        else {
            status = 1;
        }

        double amount;

        cout << "\n--Enter amount : ";
        cin >> amount;

        bankAccount::deposit(amount);
        
        if (balance >= min_bal) {    // Condition to check if the new balance makes the account active or not
            status = true;
        }
        
    }

    // Monthly Procedure Function 
    void monthlyProc() {
        if (num_of_withdrawls > 4) {
            monthly_service_charge += 1;
        }

        bankAccount::monthlyProc();
        
        if (balance < min_bal) {
            status = 0;
        }
    }

    // Assignment Operator overloaded
    void operator=(savingsAccount &other) {
        balance = other.balance;
        num_of_deposits = other.num_of_deposits;
        num_of_withdrawls = other.num_of_withdrawls;
        status = other.status;
        annual_interest = other.annual_interest;
        monthly_service_charge = other.monthly_service_charge;
    }
};

int main() {

    // bankAccount *ptr;
    // ptr = new bankAccount[size];

    savingsAccount *ptr;
    ptr = new savingsAccount[size];

    char choice;

   do {
     cout << "\n\t-----Bank Account-----"
         << "\n-----Menu-----"
         << "\n1. Deposit Funds"
         << "\n2. Withdraw Funds"
         << "\n3. Monthly Procedure"
         << "\n4. Calculate Interest"
         << "\n5. Exit"
         << "\n--Enter Choice : ";
    cin >> choice;

    switch (choice) {
        case '1':
            ptr[0].deposit();
        break;

        case '2':
            ptr[0].withdraw();
        break;

        case '3':
            ptr[0].monthlyProc();
        break;

        case '4':       
            ptr[0].calcInt();
        break;

        case '5':       // Exit program
            return 0;    
        break;
        
        default:
            cout << "\n-----Invalid Input!-----\n";
        break;
    }

    }
    
    while (choice != '5');

    return 0;
}