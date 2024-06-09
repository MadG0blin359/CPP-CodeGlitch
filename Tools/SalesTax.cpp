#include <iostream>

using namespace std;

int main() {
    // Delaring variables to store user input & calculated data
    float salePrice, stateSalesTax, citySalesTax, luxuryTax, salesTax, amountDue;
    const int luxuryItem = 50000;       // Luxury items more than 50,000, are taxable

    cout << "\n\t***********Sales Tax Calculator***********\n";

    cout << "\nEnter the Sale Price of an item : $";        // Prompt the user to enter the sale price of the item
    cin >> salePrice;                                       // Read and store user input

    // Calculating taxes based on fixed rates
    stateSalesTax = salePrice * 0.04;
    citySalesTax = salePrice * 0.015;

    // Determine if the item is in the luxury items category
    if (salePrice > luxuryItem) {
        luxuryTax = salePrice * 0.1;
    }

    else {
        luxuryTax = 0;
    }

    // Total sales tax and amount due
    salesTax = stateSalesTax + citySalesTax + luxuryTax;
    amountDue = salePrice + salesTax;

    // Display the final results
    cout << "\nSale Price : $" << salePrice;
    cout << "\nState Sales Tax : $" << stateSalesTax << "\nCity Sales Tax : $" << citySalesTax << "\nLuxury Tax : $" << luxuryTax;
    cout << "\nTotal Sales Tax : $" << salesTax;
    cout << "\nTotal Amount Due : $" << amountDue << endl;

    return 0;
}