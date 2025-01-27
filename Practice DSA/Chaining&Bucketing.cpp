#include <iostream>
#include <vector>
using namespace std;

// Structure representing a node in the chaining hash table
struct HashNode {
	int SKU;
	HashNode* next;

	// Default constructor initializing SKU and next
    HashNode() : SKU(-1), next(NULL) {}
    // Constructor initializing SKU with a value
    HashNode(int sku) : SKU(sku), next(NULL) {}
};

class CatalogChaining {
	int size, capacity;             // Size: number of elements, Capacity: size of hash table
    vector<HashNode*> table;        // Hash table represented as a vector of pointers to HashNode

    // Calculates the load factor of the hash table
	double loadFactor() const {		// Explicity Type Casting
		return ((double)size / capacity);
	}

    // Computes the primary hash for a given key
	int primaryHash(int key) {
		int hash = key % capacity;
		if (hash < 0)
			return (hash + capacity);
		else
			return hash;
	}

    // Rehashes the table when load factor exceeds threshold
	void rehash() {
		int oldCapacity = capacity;
		vector<HashNode*> oldTable = table;

		capacity *= 2;
		size = 0;
		table.clear();
		table.resize(capacity, NULL);

		for (int i = 0; i < oldTable.size(); i++) {
			HashNode* current = oldTable[i];
			while (current != NULL) {
				insertChain(current->SKU);  
				current = current->next;
			}
		}

		// Clean Old Table Memory
		for (int i = 0; i < oldCapacity; i++) {
			HashNode* current = oldTable[i];
			while (current != NULL) {
				HashNode* temp = current;
				current = current->next;
				delete temp;
			}
		}
	}

	// Inserts a key into the chain at the hashed index
	bool insertChain(int key) {
		int index = primaryHash(key);
		HashNode* newNode = new HashNode(key);
		if (table[index] == NULL) {
			table[index] = newNode;
			size++;
			return true;
		}
		
		HashNode* current = table[index];
		while (current != NULL) {
			if (current->SKU == key) {
				return false;
			}
			if (current->next == NULL) {
				current->next = newNode;
				size++;
				return true;
			}
			current = current->next;
		}
		return false;
	}

public:
    // Constructor initializing hash table with given capacity
	CatalogChaining(int c) {
		capacity = c;
		size = 0;
		table.resize(capacity, NULL);
	}

    // Inserts a key into the hash table with rehashing if needed
	bool insert(int key) {
		if (loadFactor() > 0.70) {
			rehash();
			cout << "\nRehashing Successful!\n";
		}

		return insertChain(key);
		
	}

    // Searches for a key in the hash table and returns its index
	bool search(int key, int& returnIndex) {
		int index = primaryHash(key);
		HashNode* current = table[index];
		returnIndex = index;

		while (current != NULL) {
			if (current->SKU == key)
				return true;
			current = current->next;
		}
		return false;
	}

    // Displays the entire hash table
	void display() {
		for (int i = 0; i < capacity; i++) {
			cout << i << ": ";
			HashNode* current = table[i];
			while (current != NULL) {
				cout << current->SKU << " -> ";
				current = current->next;
			}
			cout << "NULL\n";
		}
	}

    // Destructor to free allocated memory
	~CatalogChaining() {
		for (int i = 0; i < capacity; i++) {
			HashNode* current = table[i];
			while (current != NULL) {
				HashNode* temp = current;
				current = current->next;
				delete temp;
			}
		}
	}
};

// Class implementing a bucketing hash table
class CatalogBucketing {
    vector<vector<int>> table;  // Hash table using vectors to store buckets
    int numBuckets;             // Number of buckets in the hash table
    int numElements;            // Number of elements in the hash table

    // Calculates the load factor of the hash table
	double loadFactor() const {
		return ((double)numElements / numBuckets);
	}

    // Computes the primary hash for a given key
	int primaryHash(int key) {
		int hash = key % numBuckets;
		if (hash < 0)
			return (hash + numBuckets);
		else
			return hash;
	}

    // Rehashes the table when load factor exceeds threshold
	void rehash() {
		vector<vector<int>> oldTable = table;

		numBuckets *= 2;
		table.clear();
		table.resize(numBuckets);

		for (int i = 0; i < oldTable.size(); i++) {
			for (int sku : oldTable[i]) {
				insert(sku);
			}
		}
	}

public:
	// Constructor initializing table with default number of buckets
	CatalogBucketing() : numBuckets(3), numElements(0) {
		table.resize(numBuckets);
	}

	// Inserts a key into the appropriate bucket
	void insert(int key) {
		int index = primaryHash(key);

		// Check for duplicate values in the bucket
		for (int sku : table[index]) {
			if (sku == key) {
				return;
			}
		}

		table[index].push_back(key);
		numElements++;

		if (loadFactor() > 0.7) {
			rehash();
		}
	}

    // Displays the entire hash table
	void display() {
		for (int i = 0; i < numBuckets; ++i) {
			cout << "Bucket " << i << ": ";
			for (int sku : table[i]) {
				cout << sku << " ";
			}
			cout << endl;
		}
	}
};

int main() {
	CatalogChaining cc(15);  // Create a chaining hash table with capacity 15
    vector<int> SKUs = {17, 26, 15, 9, 11, 43, 75, 19, 35, 45, 55, 9, 10, 21, 61, 23};

    for (int p : SKUs) {
        cc.insert(p);        // Insert SKUs into the chaining hash table
    }

	CatalogBucketing cb;

	cout << "\nChaining Hash Table:\n";
	cc.display();            // Display chaining hash table

    for (int p : SKUs) {
        cb.insert(p);        // Insert SKUs into the bucketing hash table
    }


	cout << "\nBucketing Hash Table:\n";
	cb.display();			// Display bucketing hash table

	system("pause");
	return 0;
}