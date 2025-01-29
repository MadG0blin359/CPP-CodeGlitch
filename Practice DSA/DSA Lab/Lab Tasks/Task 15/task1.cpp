#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class SeparateChaining {
    vector<Node*> table; // Array of linked list heads
    int size;

    int hashFunction(int key) {
        return key % size;
    }

public:
    SeparateChaining(int s) : size(s) {
        table.resize(size, nullptr);
    }

    void insert(int key) {
        int index = hashFunction(key);
        Node* newNode = new Node(key);

        if (table[index] == nullptr) {
            table[index] = newNode;
        }
        else {
            Node* temp = table[index];
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void remove(int key) {
        int index = hashFunction(key);
        Node* temp = table[index];
        Node* prev = nullptr;

        while (temp != nullptr && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Key not found: " << key << endl;
            return;
        }

        if (prev == nullptr) { // Key is at the head
            table[index] = temp->next;
        }
        else {
            prev->next = temp->next;
        }

        delete temp;
    }

    bool search(int key) {
        int index = hashFunction(key);
        Node* temp = table[index];

        while (temp != nullptr) {
            if (temp->data == key) return true;
            temp = temp->next;
        }
        return false;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            Node* temp = table[i];
            while (temp != nullptr) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "nullptr\n";
        }
    }

    ~SeparateChaining() {
        for (int i = 0; i < size; i++) {
            Node* temp = table[i];
            while (temp != nullptr) {
                Node* next = temp->next;
                delete temp;
                temp = next;
            }
        }
    }
};

class LinearProbing {
    vector<int> table;
    vector<bool> filled;
    int size;

    int hashFunction(int key) {
        return key % size;
    }

public:
    LinearProbing(int s) : size(s) {
        table.resize(size, -1);
        filled.resize(size, false);
    }

    void insert(int key) {
        int index = hashFunction(key);
        while (filled[index]) {
            index = (index + 1) % size;
        }
        table[index] = key;
        filled[index] = true;
    }

    void remove(int key) {
        int index = hashFunction(key);
        while (filled[index]) {
            if (table[index] == key) {
                table[index] = -1;
                filled[index] = false;
                return;
            }
            index = (index + 1) % size;
        }
    }

    bool search(int key) {
        int index = hashFunction(key);
        while (filled[index]) {
            if (table[index] == key) return true;
            index = (index + 1) % size;
        }
        return false;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            if (filled[i]) {
                cout << table[i]; 
            }
            else {
                cout << "null"; 
            }
            cout << endl;
        }
    }
};

class QuadraticProbing {
    vector<int> table;
    vector<bool> filled;
    int size;

    int hashFunction(int key) {
        return key % size;
    }

public:
    QuadraticProbing(int s) : size(s) {
        table.resize(size, -1);
        filled.resize(size, false);
    }

    void insert(int key) {
        int index = hashFunction(key);
        int i = 0;
        while (filled[(index + i * i) % size]) {
            i++;
        }
        table[(index + i * i) % size] = key;
        filled[(index + i * i) % size] = true;
    }

    void remove(int key) {
        int index = hashFunction(key);
        int i = 0;
        while (filled[(index + i * i) % size]) {
            if (table[(index + i * i) % size] == key) {
                table[(index + i * i) % size] = -1;
                filled[(index + i * i) % size] = false;
                return;
            }
            i++;
        }
    }

    bool search(int key) {
        int index = hashFunction(key);
        int i = 0;
        while (filled[(index + i * i) % size]) {
            if (table[(index + i * i) % size] == key) return true;
            i++;
        }
        return false;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            if (filled[i]) {
                cout << table[i];
            }
            else {
                cout << "null"; 
            }
            cout << endl;
        }
    }
};


int main() {
    char choice;
    int tableSize, key;
    cout << "Enter the size of the hash table: ";
    cin >> tableSize;

    SeparateChaining sc(tableSize);
    LinearProbing lp(tableSize);
    QuadraticProbing qp(tableSize);

    while (true) {
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
