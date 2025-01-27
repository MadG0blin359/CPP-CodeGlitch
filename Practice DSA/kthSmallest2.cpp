#include <iostream>
using namespace std;

// Node class representing a node in the binary search tree
class Node {
public:
	int data; // Data stored in the node
	Node* left, * right; // Pointers to left and right child nodes

	// Constructor to initialize node with data and NULL children
	Node(int d) : data(d), left(NULL), right(NULL) {}
};

// Binary Search Tree (BST) class
class BST {
	Node* root; // Root node of the BST

	// Recursive function to insert a node into the BST
	bool insert(Node* node, int d) {
		if (node == NULL) {
			node = new Node(d);
			return true;
		}
		
		if (d < node->data)
			insert(node->left, d);
		else if (d > node->data)
			insert(node->right, d);
		else if (d == node->data)
			return false;

		return true;
	}

	// Recursive function to find the kth smallest element in the BST
	void kthSmallest(Node* node, int& k, int& min) {
		if (node != NULL) {		// Inorder traversal method
			kthSmallest(node->left, k, min);
			--k;
			if (k == 0) {
				min = node->data;
				return;
			}
			kthSmallest(node->right, k, min);
		}
	}

public:
	// Constructor to initialize an empty BST
	BST() : root(NULL) {}

	// Public function to insert a value into the BST
	bool insert(int d) {
		return insert(root, d);
	}

	// Public function to find the kth smallest element in the BST
	int kthSmallest(int k) {
		int min;
		kthSmallest(root, k, min);
		return min;
	}

};

int main() {
	BST bst; // Create an instance of the BST class
	char choice; // Variable to store user menu choice
	int value, k; // Variables to store input values

	do {
		// Display menu options
		cout << "\n--- Menu ---\n";
		cout << "1. Insert a node\n";
		cout << "2. Find kth smallest element\n";
		cout << "3. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case '1':
			cout << "Enter value to insert: ";
			cin >> value;
			if (bst.insert(value)) {
				cout << "Node inserted successfully.\n";
			}
			else {
				cout << "Node with value " << value << " already exists.\n";
			}
			break;
		case '2':
			cout << "Enter the value of k: ";
			cin >> k;
			cout << "The " << k << "th smallest element is: " << bst.kthSmallest(k) << endl;
			break;
		case '3':
			cout << "Exiting...\n";
			break;
		default: // Handle invalid menu choices
			cout << "Invalid choice. Please try again.\n";
			break;
		}
	} while (choice != '3'); // Loop until the user chooses to exit

	system("pause");
	return 0;
}