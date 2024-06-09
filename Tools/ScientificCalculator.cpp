#include <iostream>
#include <cmath>
using namespace std;

// Base Class
class SimpleCalculator {
    double num1, num2;

    public:
    void displayDivision();
    void displayMultiplication();
    void displayAddition();
    void displaySubtraction();

    // Setter
    void setNumbers() {
        cout << "--Enter the first number : ";
        cin >> num1;

        cout << "--Enter the second number : ";
        cin >> num2;
    }

};

// Function to calculate the Division of 2 numbers
void SimpleCalculator::displayDivision() {
    cout << "\n--" << num1 << " Divided by " << num2 << " is : " << num1/num2;
}

// Function to calculate the Multiplication of 2 numbers
void SimpleCalculator::displayMultiplication() {
    cout << "\n--" << num1 << " Multiplied by " << num2 << " : " << num1*num2;
}

// Function to calculate the Addition of 2 numbers
void SimpleCalculator::displayAddition() {
    cout << "\n--" << num1 << " Added with " << num2 << " : " << num1+num2;
}

// Function to calculate the Subtraction of 2 numbers
void SimpleCalculator::displaySubtraction() {
    cout << "\n--" << num2 << " Subtracted from " << num1 << " : " << num1-num2;
}

// Derived Class
class ScientificCalculator : public SimpleCalculator {
    double num1, num2;

    public:
    void displayBasePower();
    void displayRadical();
    void displayNaturalLog();
    void displayTrignometricFunctions(char choice);
    void displayInverseTrignometricFunctions(char choice);

    // Setters
    void setBasePower() {
        cout << "--Enter the Base : ";
        cin >> num1;
        
        cout << "--Enter the Power : ";
        cin >> num2;
    }

    void setRadical() {
        cout << "--Enter the Index : ";
        cin >> num1;
        
        cout << "--Enter the Radicand : ";
        cin >> num2;
    }

    void setNaturalLog() {
        cout << "--Enter a number : ";
        cin >> num1;
    }

    void setTrignometricFunctions() {
        cout << "--Enter a number : ";
        cin >> num1; 
    }
};

// Function to calculate the exponent
void ScientificCalculator::displayBasePower() {
    cout << "\n--Base " << num1 << " raised to the power " << num2 << " : " << pow(num1, num2);
}

// Function to calculate the radical of any index
void ScientificCalculator::displayRadical() {
    cout << "\n--Index " << num1 << " and radicand " << num2 << " : " << pow(num2, 1.0 / num1);
}

// Function to calculate the natural logarithm (ln) of a number
void ScientificCalculator::displayNaturalLog() {
    cout << "\n--The natural logarithm (ln) of " << num1 << " : " << log(num1);
}

// Function to calculate elementary trignometric function of a number
void ScientificCalculator::displayTrignometricFunctions(char choice) {
    if (choice == '1') {
        cout << "--The sine (sin) of " << num1 << " : " << sin(num1);
    }

    else if (choice == '2') {
        cout << "--The cosine (cos) of " << num1 << " : " << cos(num1);
    }

    else if (choice == '3') {
        cout << "--The tangent (tan) of " << num1 << " : " << tan(num1);
    }

    else {
        cout << "\n-----Invalid Input!-----\n";
    }
}

// Function to calculate inverse trignometric function of a number
void ScientificCalculator::displayInverseTrignometricFunctions(char choice) {
    if (choice == '1') {
        cout << "--The arcsine (inverse sin) " << num1 << " : " << asin(num1) << " radians.";
    }

    else if (choice == '2') {
        cout << "--The arccosine (inverse cos) " << num1 << " : " << acos(num1) << " radians.";
    }

    else if (choice == '3') {
        cout << "--The arctangent (inverse tan) " << num1 << " : " << atan(num1) << " radians.";
    }

    else {
        cout << "\n-----Invalid Input!-----\n";
    }
}

int main() {

    char menu_choice, option_choice, function_choice;
    double num1, num2;

    cout << "\n\t-----Calculator-----\n";

    cout << "\n-----Menu-----";
    cout << "\n1. Simple Arithmetic Operations";
    cout << "\n2. Scientific Operations";
    cout << "\n--Enter choice : ";
    cin >> menu_choice;

    switch(menu_choice) {
        case '1':

            SimpleCalculator obj1;       // Object of simple calculator

            cout << "\n-----Options-----";
            cout << "\n1. Division";
            cout << "\n2. Multiplication";
            cout << "\n3. Addition";
            cout << "\n4. Subtraction";
            cout << "\n5. Menu";
            cout << "\n--Enter choice : ";
            cin >> option_choice;

            obj1.setNumbers();

            switch (option_choice) {
                case '1':
                    obj1.displayDivision();
                break;
                
                case '2':
                    obj1.displayMultiplication();
                break;
                
                case '3':
                    obj1.displayAddition();
                break;
                
                case '4':
                    obj1.displaySubtraction();
                break;
                
                case '5':
                    // Go back to menu
                break;
                
                default:
                    cout << "\n-----Invalid Input!-----\n";
                break;
            }

        break;

        case '2':
            ScientificCalculator obj2;      // Object of scientific calculator
            
            cout << "\n-----Options-----";
            cout << "\n1. Division";
            cout << "\n2. Multiplication";
            cout << "\n3. Addition";
            cout << "\n4. Subtraction";
            cout << "\n5. Base & Power";
            cout << "\n6. Radical";
            cout << "\n7. Natural Log";
            cout << "\n8. Trignometric Functions";
            cout << "\n9. Menu";
            cout << "\n--Enter choice : ";
            cin >> option_choice;
            cout << endl;

            // Accessing the inherited function
            if (option_choice >= '1' && option_choice <= '4') {
                obj2.setNumbers();
            }

            switch (option_choice) {
                case '1':
                    obj2.displayDivision();
                break;
                
                case '2':
                    obj2.displayMultiplication();
                break;
                
                case '3':
                    obj2.displayAddition();
                break;
                
                case '4':
                    obj2.displaySubtraction();
                break;
                
                case '5':
                    obj2.setBasePower();
                    obj2.displayBasePower();
                break;
                
                case '6':
                    obj2.setRadical();
                    obj2.displayRadical();
                break;
                
                case '7':
                    obj2.setNaturalLog();
                    obj2.displayNaturalLog();
                break;
                
                case '8':
                    cout << "\n-----Functions-----";
                    cout << "\n1. Elementary";
                    cout << "\n2. Inverse";
                    cout << "\n--Enter choice : ";
                    cin >> function_choice;

                    cout << "\n-----Functions-----";
                    
                    if (function_choice == '1') {
                        cout << "\n1. Sin";
                        cout << "\n2. Cos";
                        cout << "\n3. Tan";
                        cout << "\n--Enter choice : ";
                        cin >> function_choice;

                        obj2.setTrignometricFunctions();
                        obj2.displayTrignometricFunctions(function_choice);
                    }
                    
                    else if (function_choice == '2') {
                        cout << "\n1. arcSin";
                        cout << "\n2. arcCos";
                        cout << "\n3. arcTan";
                        cout << "\n--Enter choice : ";
                        cin >> function_choice;

                        obj2.setTrignometricFunctions();
                        obj2.displayInverseTrignometricFunctions(function_choice);
                    }

                    else {
                        cout << "\n-----Invalid Input!-----\n";
                    }
                break;

                case '9':
                    // Go back to menu
                break;
                
                default:
                    cout << "\n-----Invalid Input!-----\n";
                break;
            }

        break;
        
        case '3':
            cout << "\n-----May you find inspiration in the infinite possibilities of mathematical imagination-----";
        break;

        default:
            cout << "\n-----Invalid Input!-----\n";
        break;

    }

    return 0;
}