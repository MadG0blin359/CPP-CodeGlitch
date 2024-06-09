#include <iostream>
#include <string>
using namespace std;

const int limit = 100;      // Maximum number of accounts that can be made in the bank 

// Global arrays to store account information
long accountNumbers[limit];
string accountFirstName[limit], accountLastName[limit], accountFullName[limit], accountTypes[limit];
double accountBalances[limit];

// Keeping track of the number of accounts stored in the records
int numOfAccounts = 0;

// Function prototypes to perform unique tasks
void displayMenu();
void openAccount();
void depositeFunds();
void withdrawFunds();
void displayAllAccounts();
void viewAccountBalance();

int main() {

    // Calling function to display the menu/home page
    displayMenu();

    return 0;
}

// Function for displaying menu/home page
void displayMenu() {
   
    char menu_choice;

    cout << "\n\tWelcome to Bank Account Management System\n";

    // Loop to keep displaying the menu after each task is performed successfully and until the number 6 is entered
    do {
        
        cout << "\n-----Menu-----";

        cout << "\n1. Open Account";
        cout << "\n2. Deposite Funds";
        cout << "\n3. Withdraw Funds";
        cout << "\n4. Display All Accounts";
        cout << "\n5. View Account Balance";
        cout << "\n6. Exit";
        
        cout << "\n\n--Enter your choice : ";
        cin >> menu_choice;

        // Switch case to avoid invalid inputs
        switch (menu_choice) {
        case '1':
            openAccount();
            break;
        
        case '2':
            depositeFunds();
            break;

        case '3':
            withdrawFunds();
            break;

        case '4':
            displayAllAccounts();
            break;
        
        case '5':
            viewAccountBalance();
            break;

        case '6':
            cout << "\n\t-----Thank You For Choosing Us!-----\n\n";
            break;
        
        default:
            cout << "\n-----Invalid Input!-----\n";
            break;
        }
    
    }

    while (menu_choice != '6');

}

// Function to open a new account in the bank 
void openAccount() {
    
    char account_type_menu_choice;
    
    cout << "\n\t-----Required Information-----\n\n";

    cout << "Enter First Name : ";
    cin >> accountFirstName[numOfAccounts];

    cout << "Enter Last Name : ";
    cin >> accountLastName[numOfAccounts];
    
    // Using concatenation to merge the first and last name with a space between them
    accountFullName[numOfAccounts] = accountFirstName[numOfAccounts] + " " + accountLastName[numOfAccounts];

    cout << "\nAccount types : ";
    cout << "\n1. Checking";
    cout << "\n2. Savings";
    
    cout << "\n\n--Select Your Account Type : ";
    cin >> account_type_menu_choice;

    // Switch case to avoid invalid inputs
    switch (account_type_menu_choice) {
    case '1':
        accountTypes[numOfAccounts] = "Checking";
        break;

    case '2':
        accountTypes[numOfAccounts] = "Savings";
        break;
    
    default:
        cout << "\nInvalid Input! Select From the Above.\n";
        break;
    }

    // Loop to keep taking input until the correct format of account number is entered
    do {
        cout << "\n--Create Your Custom 7-Digit Account Number : ";
        cin >> accountNumbers[numOfAccounts];

        if (accountNumbers[numOfAccounts] < 1000000 || accountNumbers[numOfAccounts] > 9999999) {      // 1000000 = Minimum 7-digit number
            cout << "\nInvalid Input! Account number must be of Positive 7-Digits.\n";
        }
    }

    while (accountNumbers[numOfAccounts] < 1000000 || accountNumbers[numOfAccounts] > 9999999);

    do {
        cout << "\n--Enter Initial Deposit : ";
        cin >> accountBalances[numOfAccounts];

        if (accountBalances[numOfAccounts] < 0) {
            cout << "\n-----Invalid Input! Enter a Positve Value.-----\n";
        }
    }

    while (accountBalances[numOfAccounts] < 0);

    numOfAccounts++;        // Increase the count for accounts in advance

    cout << "\n\tCongratulations! Your Account Has Been Created Successfully.\n";

}

// Function definition for depositing new funds
void depositeFunds() {

    long account_number = 0;     // Variable to take input for searching the account number in records
    double deposit_amount = 0;  // Variable to take input to update the current balance
    int accountFound = 0;       // Variable to indicate if the entered account number exists in the record or not

    // Loop to keep taking input until the correct format of account number is entered
    do {
        cout << "\n--Enter Your 7-Digit Account Number : ";
        cin >> account_number;

        if (account_number < 1000000 || account_number > 9999999) {
            cout << "\nInvalid Input! Account number must be of Positive 7-Digits.\n";
        }
    }

    // Condition to check for minimum and maximum 7-digit account number
    while (account_number < 1000000 || account_number > 9999999);
    
    // Loop to search for the provided account number
    for (int i = 0; i <= numOfAccounts; i++) {
        if (accountNumbers[i] == account_number) {      // Condition, if the account number is found

            accountFound++;

            // Loop to keep taking input until a positive number is entered
            do {
                cout << "\n--Enter Amount : ";
                cin >> deposit_amount;

                if (deposit_amount <= 0) {
                    cout << "\nInvalid Input! Enter a Positive Value.";
                }
            }

            while (deposit_amount <= 0);

            accountBalances[i] += deposit_amount;       // Update the current account balance

            cout << "\n\t-----Amount Deposited Successfully!-----";
            cout << "\nNew Balance : " << "$" << accountBalances[i];
            cout << endl;

            // Condition to break the loop before printing the last index, that is empty because of advance increment in numOfAccounts
            if (i == (numOfAccounts - 1)) {
                break;
            }
        }
    }

    // Display an error if the entered account number is not found in the records
    if (accountFound == 0) {
        cout << "\n-----Account Not Found!-----\n";
    }
}

// Function to withdraw funds from the current account balance
void withdrawFunds() {
    
    long account_number = 0;     // Variable to take input for searching the account number in records
    double withdraw_amount = 0;  // Variable to take input to update the current balance
    int accountFound = 0;       // Variable to indicate if the entered account number exists in the record or not

    // Loop to keep taking input until the correct format of account number is entered
    do {
        cout << "\n--Enter Your 7-Digit Account Number : ";
        cin >> account_number;

        if (account_number < 1000000 || account_number > 9999999) {
            cout << "\nInvalid Input! Account number must be of Positive 7-Digits.\n";
        }
    }

    // Condition to check for minimum and maximum 7-digit account number
    while (account_number < 1000000 || account_number > 9999999);

    for (int i = 0; i <= numOfAccounts; i++) {
        if (accountNumbers[i] == account_number) {      // Condition, if the account number is found
            
            accountFound++;

            do {
                cout << "\n--Enter Amount : ";
                cin >> withdraw_amount;

                if (withdraw_amount <= 0) {
                    cout << "\nInvalid Input! Enter a Positive Value.";
                }

                else if (withdraw_amount > accountBalances[i]) {
                    cout << "\nError! You Don't Have Enough Funds.\n";
                }
            }

            while (withdraw_amount <= 0 || withdraw_amount > accountBalances[i]);

            accountBalances[i] -= withdraw_amount;       // Update the current account balance

            cout << "\n\t-----Amount Withdrawn Successfully!-----";
            cout << "\nNew Balance : " << "$" << accountBalances[i];
            cout << endl;

        }
    }
    
    // Display an error if the entered account number is not found in the records
    if (accountFound == 0) {
        cout << "\n-----Account Not Found!-----\n";
    }

}

// Function Definition to display all accounts stored in the record
void displayAllAccounts() {
    
    for (int i = 0; i <= numOfAccounts; i++) {
        cout << "\n\t-----Accout " << i+1 << "-----\n";
        cout << "\nFull Name : " << accountFullName[i];
        cout << "\nAccount Number : " << accountNumbers[i];
        cout << "\nAccount Type : " << accountTypes[i];
        cout << "\nCurrent Balance : " << "$" << accountBalances[i];
        cout << endl;

        // Condition to break the loop before printing the last index, that is empty because of advance increment in numOfAccounts
        if (i == (numOfAccounts - 1)) {
            break;
        }
    }
}

// Function definition to view current account balance
void viewAccountBalance() {
    
    long account_number = 0;     // Variable to take input for searching the account number in records
    int accountFound = 0;       // Variable to indicate if the entered account number exists in the record or not
    
    // Loop to keep taking input until the correct format of account number is entered
    do {
        cout << "\n--Enter Your 7-Digit Account Number : ";
        cin >> account_number;

        if (account_number < 1000000 || account_number > 9999999) {
            cout << "\nInvalid Input! Account number must be of Positive 7-Digits.\n";
        }
    }

    // Condition to check for minimum and maximum 7-digit account number
    while (account_number < 1000000 || account_number > 9999999);

    for (int i = 0; i <= numOfAccounts; i++) {
        if (accountNumbers[i] == account_number) {      // Condition, if the account number is found
            accountFound++;
            cout << "\nCurrent Balance : " << "$" << accountBalances[i] << endl;
        }
    }

    // Display an error if the entered account number is not found in the records
    if (accountFound == 0) {
        cout << "\n-----Account Not Found!-----\n";
    }
}
