#include <iostream>
using namespace std;

// Binary Operators 
// Arithmetic Operators (+) (-) (*) (/) (%)
// Logical Operators (&&) (||) (!)
// Relational Operators (!=) (<) (<=) (>) (>=)
// Many more
class OperatorOverloading {
    int num1, num2;

    public:
    // Default parameterized constructor
    OperatorOverloading(int num01 = 2, int num02 = 5) {
        num1 = num01;
        num2 = num02;
    }
    
    // Just change the symbol, the rest of the syntax is same for every other operator
    
    // Division
    OperatorOverloading operator /(const OperatorOverloading &c) {
        OperatorOverloading temp;
        temp.num1 = num1 / c.num1;
        cout << "\n--Division -> " << num1 << " / " << c.num1 << " : " << num1 / c.num1;
        temp.num2 = num2 / c.num2;
        cout << "\n--Division -> " << num2 << " / " << c.num2 << " : " << num2 / c.num2;
        return temp;
    }

    void displayDivision() {
        cout << "\n--Result -> " << num1 << " / " << num2 << " : " << num1/num2;
    }
    
    // Multiplication
    OperatorOverloading operator *(const OperatorOverloading &c) {
        OperatorOverloading temp;
        temp.num1 = num1 * c.num1;
        cout << "\n--Multiplication -> " << num1 << " * " << c.num1 << " : " << num1 * c.num1;
        temp.num2 = num2 * c.num2;
        cout << "\n--Multiplication -> " << num2 << " * " << c.num2 << " : " << num2 * c.num2;
        return temp;
    }

    void displayMultiplication() {
        cout << "\n--Result -> " << num1 << " * " << num2 << " : " << num1*num2;
    }

    // Addition
    OperatorOverloading operator +(const OperatorOverloading &c) {
        OperatorOverloading temp;
        temp.num1 = num1 + c.num1;
        cout << "\n--Add -> " << num1 << " + " << c.num1 << " : " << num1 + c.num1;
        temp.num2 = num2 + c.num2;
        cout << "\n--Add -> " << num2 << " + " << c.num2 << " : " << num2 + c.num2;
        return temp;
    }

    void displayAddition() {
        cout << "\n--Result -> " << num1 << " + " << num2 << " : " << num1+num2;
        cout << "\n" << this;
    }
    
    // Subtraction
    OperatorOverloading operator -(const OperatorOverloading &c) {
        OperatorOverloading temp;
        temp.num1 = num1 - c.num1;
        cout << "\n--Subtract -> " << num1 << " - " << c.num1 << " : " << num1 - c.num1;
        temp.num2 = num2 - c.num2;
        cout << "\n--Subtract -> " << num2 << " - " << c.num2 << " : " << num2 - c.num2;
        return temp;
    }

    void displaySubtraction() {
        cout << "\n--Result -> " << num1 << " - " << num2 << " : " << num1-num2;
    }
    
    // Less than
    bool operator <(const OperatorOverloading &c) {
       bool check = false;
       if ( num1 < c.num1 && num2 < c.num2) {
            check = true;
       }
       return check;
    }
    
    // Greater than
    bool operator >(const OperatorOverloading &c) {
       bool check = false;
       if ( num1 > c.num1 && num2 > c.num2) {
            check = true;
       }
       return check;
    }

    ~OperatorOverloading() {
        cout << "\n---------------------------";
        cout << "\n--Object Destroyed!";
    }

};

int main() {

    char menu_choice;

    OperatorOverloading c1(2,3), c2(10,6), c3;

    cout << "\n-----Menu-----";
    cout << "\n1. Division Overloading";
    cout << "\n2. Multiplication Overloading";
    cout << "\n3. Addition Overloading";
    cout << "\n4. Subtraction Overloading";
    cout << "\n--Enter choice : ";
    cin >> menu_choice;

    switch (menu_choice) {
        case '1':
            cout << "\n---------------------------";
            c3 = c1 / c2;
            cout << "\n---------------------------";
            c3.displayDivision();
        break;

        case '2':
            cout << "\n---------------------------";
            c3 = c1 * c2;
            cout << "\n---------------------------";
            c3.displayMultiplication();
        break;
        
        case '3':
            cout << "\n---------------------------";
            c3 = c1 + c2;
            cout << "\n---------------------------";
            c3.displayAddition();
        break;

        case '4':
            cout << "\n---------------------------";
            c3 = c1 - c2;
            cout << "\n---------------------------";
            c3.displaySubtraction();
        break;
    
        default:
            cout << "\n-----Invalid Input!-----\n";
        break;
    }

    if ((c1 > c2) == true) {
        cout << "\n\n--c1 object is greater than c2 object.\n";
    }

    else if ((c1 < c2) == true) {
        cout << "\n\n--c2 object is greater than c1 object.\n";
    }

    return 0;
}