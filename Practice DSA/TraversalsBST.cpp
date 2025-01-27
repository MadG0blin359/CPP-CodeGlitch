#include<iostream>
using namespace std;

class Node {
public:
	int data;               // Value stored in the node
	Node* left, * right;    // Pointers to left and right child nodes

	// Constructor to initialize a node with data and null child pointers
	Node(int d) : data(d), left(NULL), right(NULL) {}
};

class BST {
	Node* root;             // Root node of the BST

	// Helper function for in-order traversal
	void inorderTraversal(Node* root) {
		Node* temp = root;
		if (root == NULL) {
			return;
		}
		else {
			inorderTraversal(root->left);
			cout << root->data << " ";
			inorderTraversal(root->right);
		}
	}

	// Helper function for post-order traversal
	void PostorderTraversal(Node* root) {
		Node* temp = root;
		if (root == NULL) {
			return;
		}
		else {
			PostorderTraversal(root->left);
			PostorderTraversal(root->right);
			cout << root->data << " ";
		}
	}

	// Helper function for pre-order traversal
	void PreorderTraversal(Node* root) {
		Node* temp = root;
		if (root == NULL) {
			return;
		}
		else {
			cout << root->data << " ";
			PreorderTraversal(root->left);
			PreorderTraversal(root->right);
		}
	}

	// Helper function to insert a node into the BST
	bool insertNode(Node*& node, int data) {
		if (node == NULL) {
			node = new Node(data);
			return true;
		}

		if (data < node->data)
			insertNode(node->left, data);
		else if (data > node->data)
			insertNode(node->right, data);
		else
			return false;
		return true;
	}

public:
	// Constructor to initialize an empty BST
	BST() : root(NULL) {}

	// Public method to insert a value into the BST
	bool insert(int data) {
		return insertNode(root, data);
	}

	// Method to find if a value exists in the BST
	bool FindValue(int val) {
		Node* temp = root;
		while (temp != NULL) {
			if (temp->data == val) {
				return true;
			}

			else if (val < temp->data) {
				temp = temp->left;
			}
			else {
				temp = temp->right;
			}
		}
		return false;
	}

	// Method to display the tree in in-order traversal
	void DisplayInOrder() {
		cout << "\nDisplaying InOrder: ";
		inorderTraversal(root);
	}

	// Method to display the tree in pre-order traversal
	void DisplayPreOrder() {
		cout << "\nDisplaying PreOrder: ";
		PreorderTraversal(root);
	}

	// Method to display the tree in post-order traversal
	void DisplayPostOrder() {
		cout << "\nDisplaying PostOrder: ";
		PostorderTraversal(root);
	}

};

int main() {
	int value = 0;
	BST T1;                  // Create an instance of the BST class

	cout << "Enter Values to Store (-1 To Exit): " << endl;
	while (value != -1) {    // Loop until the user enters -1
		cin >> value;
		if (value != -1) {
			T1.insert(value);   // Insert only if value is not -1
		}
	}

	cout << "Enter Value to Find : ";
	cin >> value;
	if (T1.FindValue(value) == true) {  // Check if the value exists in the BST
		cout << "\nValue Found\n";
	}
	else {
		cout << "\nValue Not Found!\n";
	}

	// Display the tree in different traversal orders
	T1.DisplayInOrder();
	T1.DisplayPostOrder();
	T1.DisplayPreOrder();

	system("pause");
	return 0;
}