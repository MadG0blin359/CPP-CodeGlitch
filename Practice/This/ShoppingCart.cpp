#include <iostream>
#include <string>
using namespace std;

class ShoppingCart {
    static int const size = 5;
    string *items; 
    float *price;

    public:
    ShoppingCart() {
        items = new string[size];
        price = new float[size];
        // Initialize all elements of items to empty strings
        for (int i = 0; i < size; ++i) {
            items[i] = "";
            price[i] = 0.0f; // Initialize prices to zero
        }
    }

    void addItem();
    void removeItem(string);
    void calculateTotal();
    void displayItems();

    ~ShoppingCart() {
        delete[] items;
        delete[] price;
    }
};

void ShoppingCart::addItem() {
    cout << "\n----Add Item----\n";

    for (int i = 0; i < size; i++) {
        if (this->items[i] != "") {
            continue;    
        }

        else {
            cout << "--Item Name : ";
            cin >> this->items[i];

            cout << "--Item Price : ";
            cin >> this->price[i];

            cout << "\n\t----Item Added to Cart Successfully!----\n";

            break;
        }
    }
}

void ShoppingCart::removeItem(string item) {
    cout << "\n----Remove Item----";

    for (int i = 0; i < size; i++) {
        if (this->items[i] == "") {
            continue;    
        }

        else if (this->items[i] == item) {
            this->items[i] = "";
            this->price[i] = 0.0f;

            cout << "\n\t----Item Removed from Cart Successfully!----\n";

            break;
        }
    }
}

void ShoppingCart::calculateTotal() {
    float total = 0;
    for (int i = 0; i < size; i++) {
        if (this->price[i] == 0.0f) {
            continue;
        }

        else {
            total += this->price[i];
        }
    }

    cout << "\nTotal Price of All Items : $" << total << endl;
}

void ShoppingCart::displayItems() {
    cout << "\n---------------"
         << "\nProduct  Price"
         << "\n---------------";

    for (int i = 0; i < size; i++) {
        if (this->items[i] == "") {
            continue;
        }

        else {
            cout << "\n " << this->items[i]
                 << "  :  $" << this->price[i];
        }
    }
    cout << endl;
}

int main() {

    ShoppingCart cart;
    char menu_choice;
    string item;

    do {
        cout << "\n-----Menu----"
            << "\n1. Add Item"
            << "\n2. Remove Item"
            << "\n3. Calculate Total"
            << "\n4. Display All Items"
            << "\n5. Exit"
            << "\n--Enter Choice : ";
        cin >> menu_choice;
    
        switch (menu_choice) {
            case '1':
                cart.addItem();
            break;
            
            case '2':
                cout << "\n--Item Name : ";
                cin >> item;

                cart.removeItem(item);
            break;

            case '3':
                cart.calculateTotal();
            break;

            case '4':
                cart.displayItems();
            break;

            case '5':
                cout << "\n\t----Thank You For Shopping----\n";
            break;

            default:
                cout << "\n----Invalid Input!----\n";
            break;
        }
    }

    while (menu_choice != '5');

    return 0;
}