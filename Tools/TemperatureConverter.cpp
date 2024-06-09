#include <iostream>
using namespace std;

int main() {

    float Cel, Fah, Kel;
    int choice;

    cout << "\n\t\t******Temperature Unit Converter******\n\n";
    cout << "\tMenu";
    cout << "\n1. Celcius To Fahrenheit";
    cout << "\n2. Fahrenheit To Celcius";
    cout << "\n3. Kelvin To Celcius";
    cout << "\n4. Celcius To Kelvin";
    cout << "\n5. Kelvin To Fahrenheit";
    cout << "\n6. Fahrenheit To Kelvin";
    cout << "\n\nSelect Your Desired Conversion : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Enter Temperature in Celcius : ";
        cin >> Cel;

        Fah = (Cel * 9/5) - 32;
        cout << "Temperature in Fahrenheit : " << Fah;
        break;

    case 2:
        cout << "Enter Temperature in Fahrenheit : ";
        cin >> Fah;

        Cel = (Fah - 32) * 5/9;
        cout << "Temperature in Celcius : " << Cel;
        break;

    case 3:
        cout << "Enter Temperature in Kelvin : ";
        cin >> Kel;

        Cel = Kel - 273.15;
        cout << "Temperature in Celcius : " << Cel;
        break;

    case 4:
        cout << "Enter Temperature in Celcius : ";
        cin >> Cel;

        Kel = Cel + 273.15;
        cout << "Temperature in Kelvin : " << Kel;
        break;

    case 5:
        cout << "Enter Temperature in Kelvin : ";
        cin >> Kel;

        Fah = (Kel - 273.15) * 9/5 + 32;
        cout << "Temperature in Fahrenheit : " << Fah;
        break;

    case 6:
        cout << "Enter Temperature in Fahrenheit : ";
        cin >> Fah;

        Kel = (Fah - 32) * 5/9 + 273.15;
        cout << "Temperature in Kelvin : " << Kel;
        break;
    
    default:
        cout << "Invalid Input!\n";
        break;
    }

    return 0;
}