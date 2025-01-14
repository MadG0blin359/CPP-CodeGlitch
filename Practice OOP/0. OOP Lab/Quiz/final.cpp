#include <iostream>
#include <string>

using namespace std;

// Base class Product
class Product {
private:
    string productName;
    int productID;
    float price;
    int quantityAvailable;

public:
    Product(string name, int id, float p, int quantity) : productName(name), productID(id), price(p), quantityAvailable(quantity) {}

    virtual void displayDetails() {
        cout << "Product Name: " << productName << endl;
        cout << "Product ID: " << productID << endl;
        cout << "Price: $" << price << endl;
        cout << "Quantity Available: " << quantityAvailable << endl;
    }

    friend float calculateProfit(Product &product, int);
};

// Derived class Electronics
class Electronics : public Product {
private:
    int warrantyPeriod;
    float powerConsumption;

public:
    Electronics(string name, int id, float p, int quantity, int warranty, float consumption)
        : Product(name, id, p, quantity), warrantyPeriod(warranty), powerConsumption(consumption) {}

    // Override displayDetails function to display electronics-specific details
    void displayDetails() {
        Product::displayDetails(); 
        cout << "Warranty Period: " << warrantyPeriod << " months" << endl;
        cout << "Power Consumption: " << powerConsumption << " Watts" << endl;
    }
};

// Derived class Clothing
class Clothing : public Product {
private:
    string size;
    string material;

public:
    Clothing(string name, int id, float p, int quantity, string s, string m)
        : Product(name, id, p, quantity), size(s), material(m) {}

    // Override displayDetails function to display clothing-specific details
    void displayDetails() {
        Product::displayDetails();
        cout << "Size: " << size << endl;
        cout << "Material: " << material << endl;
    }
};


float calculateProfit(Product &product, int salesQuantity) {
    float profit = product.price * salesQuantity;
    return profit;
}

// Operator overloading for comparing products based on profit
bool operator<(Product& p1, Product& p2) {
    return p1 < p2;
}

int main() {
    Electronics laptop("Laptop", 101, 800.0, 10, 12, 65.0);
    Clothing shirt("Shirt", 201, 25.0, 50, "Medium", "Cotton");

    // Display details of products
    cout << "Electronics Details:" << endl;
    laptop.displayDetails();
    cout << endl;

    cout << "Clothing Details:" << endl;
    shirt.displayDetails();
    cout << endl;

    // Calculate profit for a sale of 5 laptops
    int salesQuantity = 5;
    float profit = calculateProfit(laptop, salesQuantity);
    cout << "Profit from selling " << salesQuantity << " laptops: $" << profit/10 << endl;

    // Compare products based on profit
    if (laptop < shirt) {
        cout << "Laptop generates less profit compared to Shirt." << endl;
    } 
    
    else {
        cout << "Laptop generates more profit compared to Shirt." << endl;
    }

    return 0;
}
