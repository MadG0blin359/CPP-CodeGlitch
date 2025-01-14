#include <iostream>
#include <string>
using namespace std;

class Product {
    protected:
    string productName;
    int productID;
    float price;
    int quantityAvailable;

    public:
    Product(string name, int id, float p, int quantity) : productName(name), productID(id), price(p), quantityAvailable(quantity) {}

    // Virtual function to display product details
    virtual void displayDetails() {
        cout << "Product Name: " << productName << endl;
        cout << "Product ID: " << productID << endl;
        cout << "Price: $" << price << endl;
        cout << "Quantity Available: " << quantityAvailable << endl;
    }

    // Virtual function to calculate profit
    virtual float calculateProfit() = 0;

};

class Electronics : public Product {
    int warrantyPeriod;
    float powerConsumption;

    public:
    Electronics(string name, int id, float p, int quantity, int warranty, float consumption)
        : Product(name, id, p, quantity), warrantyPeriod(warranty), powerConsumption(consumption) {}

    // Override displayDetails function to display electronics-specific details
    void displayDetails() {
        Product::displayDetails(); // Call base class displayDetails
        cout << "Warranty Period: " << warrantyPeriod << " months" << endl;
        cout << "Power Consumption: " << powerConsumption << " Watts" << endl;
    }

    // Override calculateProfit function to calculate profit for electronics
    float calculateProfit() override {
        // Assuming a profit margin of 10%
        return price * 0.1;
    }
    
};

class Clothing : public Product {
    string size;
    string material;

    public:
    Clothing(string name, int id, float p, int quantity, string s, string m)
        : Product(name, id, p, quantity), size(s), material(m) {}

    // Override displayDetails function to display clothing-specific details
    void displayDetails() {
        Product::displayDetails(); // Call base class displayDetails
        cout << "Size: " << size << endl;
        cout << "Material: " << material << endl;
    }

    // Override calculateProfit function to calculate profit for clothing
    float calculateProfit() {
        // Assuming a profit margin of 30%
        return price * 0.3;
    }
    
};



int main() {

    

    return 0;
}