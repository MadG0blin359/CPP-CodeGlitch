#include <iostream>
#include <string>
using namespace std;

class Inventory {
    private:
    
    long ID;
    string name;
    double price;
    int quantity;

    public:

    Inventory() {       // Default Constructor

        ID = 0;
        name = "Default Name";
        price = 0.0;
        quantity = 0;

    }

    // Getters
    long getID() {
        return ID;
    }

    string getName() {
        return name;
    }

    double getPrice() {
        return price;
    }

    int getQuantity() {
        return quantity;
    }

    // Setters
    void setID(long itemID) {
        ID = itemID;
    }

    void setName(string itemName) {
        name = itemName;
    }

    void setPrice(double itemPrice) {
        price = itemPrice;
    }

    void setQuantity(int itemQuantity) {
        quantity = itemQuantity;
    }

    ~Inventory() {      // Destructor
        cout << "\n-----The Object is Destroyed and The Memory Has Been Deallocated-----\n";
    }
};

// Function to display all items in the inventory
void displayItems(Inventory item[], int numOfItems) {

    cout << "\n\t-----Displaying All Item-----\n";

    for (int i = 0; i < numOfItems; i++) {
        // Loop to iterate through the object and display the item details
        cout << "\n-----Item " << i + 1 << "-----";
        cout << "\n--ID : " << item[i].getID();
        cout << "\n--Name : " << item[i].getName();
        cout << "\n--Price : $" << item[i].getPrice();
        cout << "\n--Quantity : " << item[i].getQuantity() << endl;
    }
}

// Function to update item price and quantity
void updateItems(Inventory item[], int numOfItems) {
    
    // Variables to store user input
    char option_choice;
    int itemID;
    double itemPrice;
    int itemQuantity;
    
    int index = -1;     // -1 to indicate item not found

    do {
        cout << "\n-----Options-----";
        cout << "\n1. Price";
        cout << "\n2. Quantity";
        cout << "\n3. Back";
        cout << "\n--Select : ";
        cin >> option_choice;

        if (option_choice == '1' || option_choice == '2') {

            cout << "\n--Enter Item ID : ";         // Prompt the user to enter item ID
            cin >> itemID;

            // Loop to find the item index in the inventory
            for (int i = 0; i < numOfItems; i++) {
                if (item[i].getID() == itemID) {
                    index = i;
                }
            }
            
            // Display an error message if the item is not found
            if (index == -1) {
                cout << "\n-----Error! Item Not Found-----\n";
            }

        }

        if (option_choice == '1' || option_choice == '2' || option_choice == '3' && option_choice) {
            switch(option_choice) {
                case '1':
                    if (index != -1) {
                        cout << "\n--Current Price : $" << item[index].getPrice();
                        cout << "\n--Enter New Price : ";       // Prompt the user to enter the new price
                        cin >> itemPrice;                       // Read & Store the user input
                        item[index].setPrice(itemPrice);            // Update the price in the object
                        // Display the message to indicate successfull task completion
                        cout << "\n-----Item Price Successfully Updated!-----\n";
                    }
                break;

                case '2':
                    if (index != -1) {
                        cout << "\n--Current Quantity : " << item[index].getQuantity();
                        cout << "\n--Enter New Quantity : ";
                        cin >> itemQuantity;
                        item[index].setQuantity(itemQuantity);
                        // Display the message to indicate successfull task completion
                        cout << "\n-----Item Quantity Successfully Updated!-----\n";
                    }
                break;

                case '3':
                    // Going back to menu
                break;

            }
        
        }
        
        else {
            cout << "\n-----Invalid Input!-----\n";
        }
    }

    while (option_choice != '3');
}

// Function to search for items in the inventory
void searchItems(Inventory item[], int numOfItems) {
    
    int itemID;
    
    cout << "\n--Enter Item ID : ";         // Prompt the user to enter item ID
    cin >> itemID;

    int index = 0;

    // Loop to find the item index in the inventory
    for (int i = 0; i < numOfItems; i++) {
        if (item[i].getID() == itemID) {
            cout << "\n-----Item " << i + 1 << "-----";
            cout << "\n--ID : " << item[i].getID();
            cout << "\n--Name : " << item[i].getName();
            cout << "\n--Price : $" << item[i].getPrice();
            cout << "\n--Quantity : " << item[i].getQuantity() << endl;
            index++;
        }
    }

    if (index == 0) {
        cout << "\n-----Error! Item Not Found-----\n";
    }

}

int main() {

    char menu_choice = 0;       // Variable for menu choices
    int numOfItems = 0;         // Adjust the item array according to the user

    // Variable to store user input
    long itemID;
    string itemName;
    double itemPrice;
    int itemQuantity;

    cout << "\n\t-----Inventory Management System-----\n";

    cout << "\n--Enter the number of items : ";
    cin >> numOfItems;
    Inventory item[numOfItems];       // Array object of class

    do {

        cout << "\n-----Menu-----";
        
        cout << "\n1. Add Items";
        cout << "\n2. Display All Items";
        cout << "\n3. Update Item Details";
        cout << "\n4. Search For Items By ID";
        cout << "\n5. Exit";
        cout << "\n--Select : ";
        cin >> menu_choice;

        switch(menu_choice) {
            case '1':
                // Loop to take user input
                for (int i = 0; i < numOfItems; i++) {
                    cout << "\n-----Item " << i + 1 << "-----\n";
                    cout << "--ID : ";
                    cin >> itemID;
                    item[i].setID(itemID);

                    cout << "--Name : ";
                    cin >> itemName;
                    item[i].setName(itemName);

                    cout << "--Price : ";
                    cin >> itemPrice;
                    item[i].setPrice(itemPrice);

                    cout << "--Quantity : ";
                    cin >> itemQuantity;
                    item[i].setQuantity(itemQuantity);
                }

            break;

            case '2':
                displayItems(item, numOfItems);
            break;

            case '3':
                updateItems(item, numOfItems);
            break;

            case '4':
                searchItems(item, numOfItems);
            break;

            case '5':
                cout << "\n-----Thank You For Using Our Software!-----\n";
            break;

            default:
                cout << "\n-----Invalid Input!-----\n";
            break;
        }

    }

    while (menu_choice != '5');    

    return 0;
}