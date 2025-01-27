#include<iostream>
using namespace std;


// Node class representing each node in the binary tree
class Node {
public:
	int data; // Data stored in the node
	Node* left, * right; // Pointers to the left and right child nodes

	// Constructor to initialize the node with data and NULL children
	Node(int d) : data(d), left(NULL), right(NULL) {}
};

// BinaryTree class for creating and managing a binary tree
class BinaryTree {
	Node* root; // Root node of the binary tree
	int sum = 0; // Variable to store the sum of node values (if required)

	// Helper function to calculate the maximum path sum in the tree
	int maxPathsum(Node* node) {
		if (node == NULL) { 
			return 0;
		}

		int ans = -277000; //minimum value for comparing 

		// Case 1: store node data
		int one = node->data;

		// Case 2: store node's left data + node's data
		int two = maxPathsum(node->left) + node->data;
		
		// Case 3: store node's right data + node's data
		int three = maxPathsum(node->right) + node->data; 
		
		// Case 4: store node's left data + node's right + node's data
		int four = maxPathsum(node->left) + maxPathsum(node->right) + node->data;

		int temp = max(max(one, two), max(three, four)); //calculate the maximum of 4 of the cases above
		ans = max(ans, temp); //store the one maximum case in ans

		return ans;
	}

	// Helper function to insert a node into the tree
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

	// Helper function for inorder traversal of the tree
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

public:
	// Constructor to initialize the binary tree with an empty root
	BinaryTree() : root(NULL) {}

	// Function to insert a value into the binary tree
	bool insert(int data) {
		return insertNode(root, data);
	}

	// Function to calculate and return the maximum path sum
	int callMaxSum() {
		return maxPathsum(root);
	}

	// Function to display the tree using inorder traversal
	void DisplayInOrder() {
		cout << "\nDisplaying InOrder: ";
		inorderTraversal(root);
	}

};

int main() {
	int value = 0; // Variable to store input values
	BinaryTree T1; // Create an instance of the BinaryTree class

	cout << "Enter Values to Store (-1 To Exit): " << endl;
	while (value != -1) { // Loop until the user enters -1
		cin >> value; // Input value
		if (value != -1) {
			T1.insert(value); // Insert only if value is not -1
		}
	}

	T1.DisplayInOrder(); // Display the tree using inorder traversal

	cout << "\n==> Maximum Sum in BST: ";
	cout << T1.callMaxSum() << endl; // Display the maximum path sum

	system("pause");
	return 0;
}