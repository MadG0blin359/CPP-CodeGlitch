#include <iostream>
#include <string>

using namespace std;

// Base class Product
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
        Product::displayDetails(); // Call base class displayDetails
        cout << "Warranty Period: " << warrantyPeriod << " months" << endl;
        cout << "Power Consumption: " << powerConsumption << " Watts" << endl;
    }

    // Override calculateProfit function to calculate profit for electronics
    float calculateProfit() {
        // Assuming a profit margin of 10%
        return price * 0.1;
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

// Friend function to calculate profit
float Profit_Calculator(Product &product, int salesQuantity) {
    float profit = product.calculateProfit() * salesQuantity;
    return profit;
}

// Operator overloading for comparing products based on profit
bool operator<(Product& p1, Product& p2) {
    return p1.calculateProfit() < p2.calculateProfit();
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
    float profit = Profit_Calculator(laptop, salesQuantity);
    cout << "Profit from selling " << salesQuantity << " laptops: $" << profit << endl;

    // Compare products based on profit
    if (laptop < shirt) {
        cout << "Laptop generates less profit compared to Shirt." << endl;
    } 
    
    else {
        cout << "Laptop generates more profit compared to Shirt." << endl;
    }

    return 0;
}
