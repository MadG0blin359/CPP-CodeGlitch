#include <iostream>
#include <vector>
using namespace std;

// Library class representing a hash table with double hashing and rehashing capabilities.
class Library {
	vector<int> table;		// Vector to store the hash table
	int size, 		// Size of the hash table (number of elements)
	capacity;		// Capacity of the hash table (total number of slots)

	// Primary hash function to calculate the initial index for a given key.
	int primaryHash(int key) {
		int hash = key % capacity;
		if (hash < 0)
			return (hash + capacity);
		else
			return hash;
	}

	// Secondary hash function to calculate the offset for a given key.
	int secondaryHash(int key) {
		int hash = 1 + (key % (capacity - 1));
		if (hash < 0)
			return (hash + capacity);
		else
			return hash;
	}

public:
	// Constructor to initialize the hash table with a given capacity.
	Library(int c) {
		size = 0;
		capacity = c;
		table.resize(c, -1);
	}

	// Function to insert a key into the hash table using linear probing.
	bool insertLinearHash(int key) {
		int index = primaryHash(key);
		int start = index;
		while (true) {
			if (table[start] == key)
				return false;
			if (table[start] == -1 || table[start] == -2) {
				table[start] = key;
				size++;
				return true;
			}
			start = (start + 1) % capacity;
			if (start == index)
				return false;
		}
	}

	// Funtion to insert a key into the hash table using double hashing
	bool insertDoubleHash(int key) {
		int index = primaryHash(key);
		int start = index;
		int i = 0;
		while (true) {
			if (i == capacity)
				return false;
			if (table[start] == key)
				return false;
			if (table[start] == -1 || table[start] == -2) {
				table[start] = key;
				size++;
				return true;
			}
			start = (index + i * secondaryHash(key)) % capacity;
			i++;
		}
	}

	// Function to display the contents of the hash table.
	void display() {
		for (int i = 0; i < capacity; i++) {
			if (table[i] == -1) 
				cout << i << ": Empty\n";
			else 
				cout << i << ": " << table[i] << "\n";
		}
	}

	// Function to rehash the hash table to a new capacity and reinsert all existing keys.
	void rehashing() {
		vector<int> oldTable = table;

		capacity *= 2;
		table.clear();
		table.resize(capacity, -1);

		for (int key : oldTable) {
			if (key != -1 && key != -2)
				insertDoubleHash(key);
		}
	}

	double loadFactor() {
		return (double)size / capacity;		// Explicit Type Casting from int to double
	}
};

int main() {
	int fixSize = 15;
	Library hashTable(fixSize);
	vector<int> ISBNs = { 17, 26, 15, 9, 11, 43, 75, 19, 35, 45, 55, 9, 10, 21, 61, 23 };
	
	cout << "Using Linear Probing:\n";
	int i = 0;
	for (i; i < fixSize; i++) {
		if (hashTable.loadFactor() < 0.7) {
			hashTable.insertLinearHash(ISBNs[i]);
			continue;
		}
		break;
	}
	
	hashTable.display();
	cout << "\nTable is 70% Full. Rehashing...";
	
	hashTable.rehashing();

	cout << "\nRehashing Successfull!\n";
	hashTable.display();

	cout << "\nUsing Double Hashing:\n";
	for (i; i < fixSize; i++) {
		hashTable.insertDoubleHash(ISBNs[i]);
	}

	hashTable.display();

	system("pause");
	return 0;
}