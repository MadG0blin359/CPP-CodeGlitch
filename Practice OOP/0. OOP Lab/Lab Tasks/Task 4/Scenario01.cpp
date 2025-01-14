#include <iostream>
#include <string>
using namespace std;

struct ProductData {        // Product details structure
    string name;
    double price;
    int quantity;
};

// custom data type function to prompt the user 
ProductData createProductData() {

    ProductData product;
    
    cout << "\n\t-----Product Data-----\n";
    
    cout << "\n--Enter Name : ";
    cin >> product.name;

    cout << "\n--Enter Price : ";
    cin >> product.price;

    cout << "\n--Enter Quantity : ";
    cin >> product.quantity;

    return product;     // Return the structure
}

// Function to display the product details
void displayProductData(ProductData &product) {
    cout << "\n\t-----Product Information-----";
    cout << "\n--Name: " << product.name;
    cout << "--Price: $" << product.price;
    cout << "--Quantity in stock: " << product.quantity << endl;
}

int main() {

    ProductData p1, p2;
    
    // Calling functions to take input from the user and return the structure
    p1 = createProductData();
    p2 = createProductData();

    // Calling the functions to display the product information
    displayProductData(p1);
    displayProductData(p2);

    return 0;
}