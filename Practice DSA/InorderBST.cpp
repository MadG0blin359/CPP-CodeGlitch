#include <iostream>
using namespace std;

// Structure to represent a node in the binary search tree
struct Node {
	int data; // Stores the data value of the node
	Node* left, * right; // Pointers to the left and right child nodes
	Node(int d) : data(d), left(NULL), right(NULL) {} // Constructor to initialize the node
};

// Class to represent a Binary Search Tree (BST)
class BST {
	Node* root; // Root node of the tree

	// Helper function to perform inorder traversal of the tree
	void inorder(Node* node) {
		if (node == NULL)
			return;
		inorder(node->left);
		cout << node->data << " ";
		inorder(node->right);
	}

	// Helper function to convert a sorted array to a balanced BST
	Node* array2BST(int arr[], int start, int end) {
		if (start > end)
			return NULL;

		int mid = (start + end) / 2;
		Node* newNode = new Node(arr[mid]);

		newNode->left = array2BST(arr, start, mid - 1);
		newNode->right = array2BST(arr, mid + 1, end);

		return newNode;
	}

public:
	// Constructor to initialize an empty BST
	BST() : root(NULL) {}

	// Function to create a balanced BST from a sorted array
	void insert(int arr[], int start, int end) {
		root = array2BST(arr, start, end); // Call the helper function to construct the tree
	}

	// Function to display the tree using inorder traversal
	void display() {
		inorder(root); // Call the inorder traversal function
	}
};

int main() {
	BST tree; // Create an object of the BST class
	int arr[] = { 1,2,3,4,5,6,7 }; // Define a sorted array
	int size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

	tree.insert(arr, 0, size-1); // Insert the array elements into the BST
	tree.display(); // Display the inorder traversal of the BST
	cout << endl;

	system("pause");
	return 0;
}