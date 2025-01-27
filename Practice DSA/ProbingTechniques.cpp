#include <iostream>
#include <vector>
using namespace std;

// Node class for Separate Chaining linked list nodes
class Node {
public:
    int data; // Data value stored in the node
    Node* next; // Pointer to the next node in the linked list

    Node(int val) : data(val), next(nullptr) {} // Constructor to initialize node
};

// Separate Chaining Hashing class
class SeparateChaining {
    vector<Node*> table; // Array of linked list heads for hash table
    int size; // Size of the hash table

    // Hash function to determine the index
    int hashFunction(int key) {
        return key % size;
    }

public:
    // Constructor to initialize hash table
    SeparateChaining(int s) : size(s) {
        table.resize(size, nullptr);
    }

    // Function to insert a key into the hash table
    void insert(int key) {
        int index = hashFunction(key); // Calculate hash index
        Node* newNode = new Node(key); // Create a new node for the key

        if (table[index] == nullptr) {
            // If no collision, insert the node directly
            table[index] = newNode;
        }
        else {
            // If collision, add the node at the end of the linked list
            Node* temp = table[index];
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Function to remove a key from the hash table
    void remove(int key) {
        int index = hashFunction(key); // Calculate hash index
        Node* temp = table[index];
        Node* prev = nullptr;

        // Traverse the linked list to find the key
        while (temp != nullptr && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            // If key not found, print a message
            cout << "Key not found: " << key << endl;
            return;
        }

        if (prev == nullptr) {
            // Key is at the head of the linked list
            table[index] = temp->next;
        }
        else {
            // Key is in the middle or end of the linked list
            prev->next = temp->next;
        }

        delete temp; // Free memory of the removed node
    }

    // Function to search for a key in the hash table
    bool search(int key) {
        int index = hashFunction(key); // Calculate hash index
        Node* temp = table[index];

        // Traverse the linked list to find the key
        while (temp != nullptr) {
            if (temp->data == key) return true; // Key found
            temp = temp->next;
        }
        return false; // Key not found
    }

    // Function to display the hash table
    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            Node* temp = table[i];
            while (temp != nullptr) {
                cout << temp->data << " -> "; // Print each node in the linked list
                temp = temp->next;
            }
            cout << "nullptr\n"; // End of linked list
        }
    }

    // Destructor to clean up dynamically allocated memory
    ~SeparateChaining() {
        for (int i = 0; i < size; i++) {
            Node* temp = table[i];
            while (temp != nullptr) {
                Node* next = temp->next;
                delete temp; // Delete each node
                temp = next;
            }
        }
    }
};

// Linear Probing Hashing class
class LinearProbing {
    vector<int> table; // Hash table
    vector<bool> filled; // Array to track if a slot is filled
    int size; // Size of the hash table

    // Hash function to determine the index
    int hashFunction(int key) {
        return key % size;
    }

public:
    // Constructor to initialize hash table
    LinearProbing(int s) : size(s) {
        table.resize(size, -1); // Initialize table with -1
        filled.resize(size, false); // Initialize filled array with false
    }

    // Function to insert a key using linear probing
    void insert(int key) {
        int index = hashFunction(key); // Calculate hash index
        while (filled[index]) { // Find the next available slot
            index = (index + 1) % size;
        }
        table[index] = key; // Insert the key
        filled[index] = true; // Mark the slot as filled
    }

    // Function to remove a key using linear probing
    void remove(int key) {
        int index = hashFunction(key); // Calculate hash index
        while (filled[index]) {
            if (table[index] == key) {
                // Key found, mark slot as empty
                table[index] = -1;
                filled[index] = false;
                return;
            }
            index = (index + 1) % size;
        }
    }

    // Function to search for a key using linear probing
    bool search(int key) {
        int index = hashFunction(key); // Calculate hash index
        while (filled[index]) {
            if (table[index] == key) return true; // Key found
            index = (index + 1) % size;
        }
        return false; // Key not found
    }

    // Function to display the hash table
    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            if (filled[i]) {
                cout << table[i]; // Print key if slot is filled
            }
            else {
                cout << "null"; // Print null if slot is empty
            }
            cout << endl;
        }
    }
};

// Quadratic Probing Hashing class
class QuadraticProbing {
    vector<int> table; // Hash table
    vector<bool> filled; // Array to track if a slot is filled
    int size; // Size of the hash table

    // Hash function to determine the index
    int hashFunction(int key) {
        return key % size;
    }

public:
    // Constructor to initialize hash table
    QuadraticProbing(int s) : size(s) {
        table.resize(size, -1); // Initialize table with -1
        filled.resize(size, false); // Initialize filled array with false
    }

    // Function to insert a key using quadratic probing
    void insert(int key) {
        int index = hashFunction(key); // Calculate hash index
        int i = 0; // Quadratic probing factor
        while (filled[(index + i * i) % size]) { // Find next available slot
            i++;
        }
        table[(index + i * i) % size] = key; // Insert the key
        filled[(index + i * i) % size] = true; // Mark slot as filled
    }

    // Function to remove a key using quadratic probing
    void remove(int key) {
        int index = hashFunction(key); // Calculate hash index
        int i = 0; // Quadratic probing factor
        while (filled[(index + i * i) % size]) {
            if (table[(index + i * i) % size] == key) {
                // Key found, mark slot as empty
                table[(index + i * i) % size] = -1;
                filled[(index + i * i) % size] = false;
                return;
            }
            i++;
        }
    }

    // Function to search for a key using quadratic probing
    bool search(int key) {
        int index = hashFunction(key); // Calculate hash index
        int i = 0; // Quadratic probing factor
        while (filled[(index + i * i) % size]) {
            if (table[(index + i * i) % size] == key) return true; // Key found
            i++;
        }
        return false; // Key not found
    }

    // Function to display the hash table
    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            if (filled[i]) {
                cout << table[i]; // Print key if slot is filled
            }
            else {
                cout << "null"; // Print null if slot is empty
            }
            cout << endl;
        }
    }
};

int main() {
    char choice;
    int tableSize, key;
    
    // Get the size of the hash table from the user
    cout << "Enter the size of the hash table: ";
    cin >> tableSize;

    // Create objects for each hashing technique
    SeparateChaining sc(tableSize);
    LinearProbing lp(tableSize);
    QuadraticProbing qp(tableSize);

    while (true) {
        // Display menu for hashing techniques
        cout << "\nHashing Techniques Menu:\n";
        cout << "1. Use Separate Chaining\n";
        cout << "2. Use Linear Probing\n";
        cout << "3. Use Quadratic Probing\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == '4') {
            cout << "Exiting...\n";
            break;
        }

        char operation;
        // Display menu for hash table operations
        cout << "\nOperations Menu:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Display\n";
        cout << "Enter your operation choice: ";
        cin >> operation;

        if (choice == '1') { // Separate Chaining
            switch (operation) {
            case '1': // Insert
                cout << "Enter the key to insert: ";
                cin >> key;
                sc.insert(key);
                break;
            case '2': // Delete
                cout << "Enter the key to delete: ";
                cin >> key;
                // Check if the table is empty
                if (sc.search(key)) {
                    sc.remove(key);
                }
                else {
                    cout << "Hash table is empty or key not found.\n";
                }
                break;
            case '3': // Search
                cout << "Enter the key to search: ";
                cin >> key;
                if (sc.search(key))
                    cout << "Key found in the hash table.\n";
                else
                    cout << "Key not found.\n";
                break;
            case '4': // Display
                sc.display();
                break;
            default:
                cout << "Invalid operation choice.\n";
            }
        }
        else if (choice == '2') { // Linear Probing
            switch (operation) {
            case '1':
                cout << "Enter the key to insert: ";
                cin >> key;
                lp.insert(key);
                break;
            case '2':
                cout << "Enter the key to delete: ";
                cin >> key;
                if (lp.search(key)) {
                    lp.remove(key);
                }
                else {
                    cout << "Hash table is empty or key not found.\n";
                }
                break;
            case '3':
                cout << "Enter the key to search: ";
                cin >> key;
                if (lp.search(key))
                    cout << "Key found in the hash table.\n";
                else
                    cout << "Key not found.\n";
                break;
            case '4':
                lp.display();
                break;
            default:
                cout << "Invalid operation choice.\n";
            }
        }
        else if (choice == '3') { // Quadratic Probing
            switch (operation) {
            case '1':
                cout << "Enter the key to insert: ";
                cin >> key;
                qp.insert(key);
                break;
            case '2':
                cout << "Enter the key to delete: ";
                cin >> key;
                if (qp.search(key)) {
                    qp.remove(key);
                }
                else {
                    cout << "Hash table is empty or key not found.\n";
                }
                break;
            case '3':
                cout << "Enter the key to search: ";
                cin >> key;
                if (qp.search(key))
                    cout << "Key found in the hash table.\n";
                else
                    cout << "Key not found.\n";
                break;
            case '4':
                qp.display();
                break;
            default:
                cout << "Invalid operation choice.\n";
            }
        }
        else {
            cout << "Invalid hashing technique choice.\n";
        }
    }

    system("pause");

    return 0;
}
