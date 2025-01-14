#include <iostream>
using namespace std;

class BankAccount {
    protected:
    long account_number;
    double balance;

    public:
    // Default constructor
    BankAccount() {
        account_number = 0;
        balance = 0;
    }
    
    // Setter
    void setAccountNumber() {
        cout << "\n--Enter Account Number : ";
        cin >> account_number;
    }

    // Getters
    long getAccoutNumber() {
        return account_number;
    }

    double getBalance() {
        return balance;
    }

    // Member Functions
    void depositMoney(double amount) {
        balance += amount; 
    }

    void withdrawMoney(double amount) {
        do {
            cout << "\n--Enter amount : ";
            cin >> amount;

            if (amount > balance) {
                cout << "\n--Invalid Input! Available balance is : " << balance << endl;
            }

            else {
                cout << "\n-----Amount Withdrawn Successfully!-----\n";
            }
        }

        while (amount > balance);

        balance -= amount;

    }

    void displayAccountInfo() {
        cout << "\n\t-----Account Information-----\n";

        cout << "\n-------------------------------\n";
        cout << "--Account Type : Current";
        cout << "\n-------------------------------\n";
        cout << "--Account Number : " << account_number;
        cout << "\n-------------------------------\n";
        cout << "--Balance : " << balance;
        cout << "\n-------------------------------\n";
    }

};

class SavingsAccount : public BankAccount {
    double interest_rate;
    double interest;

    public:
    // Default constructor
    SavingsAccount() {
        interest_rate = 0;
        interest = 0;
    }

    // Setters
    void setInterestRate() {
        cout << "\n--Enter interest rate : ";
        cin >> interest_rate;
    }

    // Getters
    double getInterestRate() {
        return interest_rate;
    }

    // Member Functions
    void postInterest() {
        interest = (interest_rate/100) * balance;
        balance += interest;
    }

    void withdrawMoney(double amount) {
        do {
            cout << "\n--Enter amount : ";
            cin >> amount;

            if (amount > balance) {
                cout << "\n--Invalid Input! Available balance is : " << balance << endl;
            }

            else {
                cout << "\n-----Amount Withdrawn Successfully!-----\n";
            }
        }

        while (amount > balance);

        balance -= amount;

    }

    void displayAccountInfo() {
        cout << "\n\t-----Account Information-----\n";

        cout << "\n-----------------------------\n";
        cout << "--Account Type : Savings";
        cout << "\n-----------------------------\n";
        cout << "--Account Number : " << account_number;
        cout << "\n-----------------------------\n";
        cout << "--Balance : " << balance;
        cout << "\n-----------------------------\n";
        cout << "--Interest Rate : " << interest_rate;
        cout << "\n-----------------------------\n";
    }
};

// Function to find the account
void findAccount(long account_number);

int main() {

    int const numOfCustomers = 5;
    int i = 0, j = 0;
    char menu_choice, options_choice;
    double amount;
    long account_number;
    BankAccount current_arr[numOfCustomers];
    SavingsAccount savings_arr[numOfCustomers];

    cout << "\n-----Bank Application-----";

    do {
        cout << "\n-----Menu-----";
        cout << "\n1. Create Account";
        cout << "\n2. Display Account";
        cout << "\n3. Deposit";
        cout << "\n4. Withraw";
        cout << "\n5. Exit";
        cout << "\n--Enter choice : ";
        cin >> menu_choice;
        
        switch (menu_choice) {
            case '1':
                cout << "\n\t*****Create Account*****\n";
                cout << "\n-----Options-----";
                cout << "\n1. Current Account";
                cout << "\n2. Savings Account";
                cout << "\n--Enter Choice : ";
                cin >> options_choice;

                switch (options_choice) {
                    case '1':
                        cout << "\n*****Current Account*****\n";
                        current_arr[i].setAccountNumber();

                        do {
                            cout << "\n--Enter amount : ";
                            cin >> amount;

                            if (amount < 1) {
                                cout << "\n--Invalid Input!\n";
                            }

                            else {
                                cout << "\n-----Amount Deposited Successfully!-----\n";
                            }
                        }

                        while (amount < 0);
                        current_arr[i].depositMoney(amount);    
                    break;
                    
                    case '2':
                        cout << "\n*****Savings Account*****\n";
                        savings_arr[j].setAccountNumber();
                        savings_arr[j].setInterestRate();
                        savings_arr[j].depositMoney(amount);
                    break;
                    
                    default:
                        cout << "\n-----Invalid Input!-----\n";
                    break;
                }
                
            break;

            case '2':
                cout << "\n\t*****Display Account*****\n";

                cout << "\n-----Options-----";
                cout << "\n1. Current Account";
                cout << "\n2. Savings Account";
                cout << "\n--Enter Choice : ";
                cin >> options_choice;

                switch (options_choice) {
                    case '1':

                    break;
                    
                    default:
                        cout << "\n-----Invalid Input!-----\n";
                    break;
                }

            break;

            case '3':

            break;

            case '4':

            break;

            case '5':
                cout << "\n-----Thank You For Choosing Us-----" << endl;
            break;
            
            default:
                cout << "\n-----Invalid Input!-----\n";
            break;
        }
        
    }

    while (menu_choice != '5');

    return 0;
}

void findAccount(long account_number) {
    // for (int i = 0; i < )
}