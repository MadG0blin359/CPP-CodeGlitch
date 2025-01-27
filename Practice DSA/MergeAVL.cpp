#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;
	Node(int d) : data(d), left(NULL), right(NULL) {} // Constructor to initialize node with data and set children to NULL
};

class AVL {
	Node* root;

	int getHeight(Node* node) {
		if (node == NULL)
			return -1;			// If the node is NULL, height is -1 (empty tree)
		
		// Recursively calculate the height of left and right subtrees
		int leftHeight = getHeight(node->left);
		int rightHeight = getHeight(node->right);

		// Return the greater height of the two subtrees plus one
		if (leftHeight > rightHeight)
			return 1 + leftHeight;

		return 1 + rightHeight;
	}

	// Function to calculate the balance factor of a node
	int getBalanceFactor(Node* node) {
		if (node == NULL)
			return 0;
		return getHeight(node->left) - getHeight(node->right);
	}

	// Function to perform a right rotation on a node
	void rightRotation(Node* &node) {
		Node* leftChild = node->left; // Store the left child of the node
		Node* childRight = leftChild->right; // Store the right child of the left child
		leftChild->right = node; // Make the current node the right child of its left child
		node->left = childRight; // Update the left child of the current node
		node = leftChild; // Update the node to the new root after rotation
		cout << "\n-----Right Rotation Successfully Performed!-----\n";
	}

	// Function to perform a left rotation on a node
	void leftRotation(Node* &node) {
		Node* rightChild = node->right; // Store the right child of the node
		Node* childLeft = rightChild->left; // Store the left child of the right child
		rightChild->left = node; // Make the current node the left child of its right child
		node->right = childLeft; // Update the right child of the current node
		node = rightChild; // Update the node to the new root after rotation
		cout << "\n-----Left Rotation Successfully Performed!-----\n";
	}

	// Function to check and balance the AVL tree if needed
	void checkAVL(Node* &node) {
		int rootBF = getBalanceFactor(node);

		// Check for left-heavy imbalance
		if (rootBF > 1) {
			int childBF = getBalanceFactor(node->left); // Balance factor of the left child

			// Left-Right (LR) case
			if (childBF < 0)
				leftRotation(node->left);

			// Left-Left (LL) case
			rightRotation(node);
		}

		// Check for right-heavy imbalance
		else if (rootBF < -1) {
			int childBF = getBalanceFactor(node->right); // Balance factor of the right child

			// Right-Left (RL) case
			if (childBF >= 0)
				rightRotation(node->right);

			// Right-Right (RR) case
			leftRotation(node->right);
		}
	}

	// Recursive function to insert a node into the AVL tree
	bool insertNode(Node* &node, int data) {
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
		
		// Check whether the tree is balanced or not
		checkAVL(node);
			
		return true;
	}

	// Helper function to merge two AVL trees
	void join(Node* node) {
		if (node == NULL)
			return;
		join(node->left);
		insertNode(this->root, node->data); // Insert every node from the second tree into first tree
		join(node->right);
	}

	// Recursive function for inorder traversal of the AVL tree
	void inorder(Node* node) {
		if (node == NULL)
			return;
		inorder(node->left);
		cout << node->data << " ";
		inorder(node->right);
	}

public:
	// Constructor to initialize an empty AVL tree
	AVL() : root(NULL) {}

	// Public function to insert a node into the AVL tree
	bool insert(int data) {
		return insertNode(root, data);
	}

	// Public function to display the AVL tree using inorder traversal
	bool display() {
		if (root == NULL)
			return false;

		inorder(root);
		return true;
	}

	// Function to merge another AVL tree into the current tree
	void join(AVL& secondTree) {
		join(secondTree.root);
	}
};

int main() {
	AVL T1, T2;

	// Insert predefined values into T1
	int valuesT1[] = { 3,5,7,10,15,20 };
	int const n1 = sizeof(valuesT1) / sizeof(valuesT1[0]);

	for (int i = 0; i < n1; i++) 
		T1.insert(valuesT1[i]); // Insert each value into T1
	cout << endl;

	// Insert predefined values into T2
	int valuesT2[] = { 22,25,28,30,35 };
	int const n2 = sizeof(valuesT2) / sizeof(valuesT2[0]);

	for (int i = 0; i < n2; i++)
		T2.insert(valuesT2[i]); // Insert each value into T2
	cout << endl;


	cout << "\nT1: ";
	T1.display();
	cout << "\nT2: ";
	T2.display();
	cout << endl;

	// Join T1 with T2
	cout << "\n-----Merging T1 & T2-----\n";
	T1.join(T2);

	// Display the merged AVL tree
	cout << "\nMerged AVL Tree: ";
	T1.display();

	cout << endl;
	system("pause");
	return 0;
}