#include <iostream>
using namespace std;

// Node class representing a node in the AVL tree
template <class T>
class Node {
public:
	T data; // Data stored in the node
	Node* left, * right; // Pointers to left and right child nodes

	// Constructor to initialize a node with data and NULL children
	Node(T d) : data(d), left(NULL), right(NULL) {}
};

// AVL class representing an AVL tree
template <class T>
class AVL {
	Node<T>* root; // Root node of the AVL tree

	// Recursive function to calculate the height of a node
	int getHeight(Node<T>* node) {
		if (node == NULL)
			return -1;			// Empty tree height = -1

		int leftHeight = getHeight(node->left);
		int rightHeight = getHeight(node->right);

		if (leftHeight > rightHeight)
			return 1 + leftHeight;

		return 1 + rightHeight;
	}

	// Function to calculate the balance factor of a node
	int getBalanceFactor(Node<T>* node) {
		if (node == NULL)
			return 0;
		return getHeight(node->left) - getHeight(node->right);
	}

	// Function to perform a right rotation on a node
	void rightRotation(Node<T>* &node) {
		Node<T>* leftChild = node->left; // Store the left child of the node
		Node<T>* childRight = leftChild->right; // Store the right child of the left child
		leftChild->right = node; // Make the current node the right child of its left child
		node->left = childRight; // Update the left child of the current node
		node = leftChild; // Update the node to the new root after rotation
		cout << "\n-----Right Rotation Successfully Performed!-----\n";
	}

	// Function to perform a left rotation on a node
	void leftRotation(Node<T>* &node) {
		Node<T>* rightChild = node->right; // Store the right child of the node
		Node<T>* childLeft = rightChild->left; // Store the left child of the right child
		rightChild->left = node; // Make the current node the left child of its right child
		node->right = childLeft; // Update the right child of the current node
		node = rightChild; // Update the node to the new root after rotation
		cout << "\n-----Left Rotation Successfully Performed!-----\n";
	}

	// Function to check and balance the AVL tree if needed
	void checkAVL(Node<T>* &node) {
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
	bool insertNode(Node<T>* &node, T data) {
		if (node == NULL) {
			node = new Node<T>(data);
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

	// Recursive function to delete a node from the AVL tree
	bool deleteNode(Node<T>* &node, T key) {
		if (node == NULL)
			return false;

		if (key < node->data)
			deleteNode(node->left, key);
		else if (key > node->data)
			deleteNode(node->right, key);
		else if (key == node->data) {			// Key found
			Node<T>* temp = node;
			
			// Case : 0-children & 1-children
			if (node->left == NULL || node->right == NULL) {
				if (node->left == NULL)
					node = node->right;
				else
					node = node->left;
				delete temp;
			}

			// Case : 2-children
			else if (node->left != NULL && node->right != NULL) {
				temp = node->right;

				while (temp->left != NULL) {
					temp = temp->left;
				}

				node->data = temp->data;
				deleteNode(node->right, temp->data); 	
			}

			// Check whether the tree is balanced or not
			if (node != NULL)
				checkAVL(node);

			return true;
		}

		return false;		// Key not found
	}

	// Recursive function for inorder traversal of the AVL tree
	void inorder(Node<T>* node) {
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
	bool insertNode(T data) {
		return insertNode(root, data);
	}

	// Public function to display the AVL tree using inorder traversal
	bool display() {
		if (root == NULL)
			return false;

		inorder(root);
		return true;
	}

	// Public function to delete a node from the AVL tree
	bool deleteNode(T key) {
		return deleteNode(root, key);
	}
};

int main() {
	AVL<int> tree; // Create an instance of the AVL tree
	int data, key;

	// Prompt the user to insert values into the AVL tree
	cout << "Enter values to insert (-1 to stop): ";
	while (true) {
		cin >> data;
		if (data == -1) // Stop input when -1 is entered
			break;
		tree.insertNode(data); // Insert the value into the AVL tree
	}

	// Display the AVL tree in inorder traversal
	cout << "\nInorder traversal : ";
	tree.display();

	// Prompt the user to delete a key from the AVL tree
	cout << "\nEnter key to delete : ";
	cin >> key;
	tree.deleteNode(key); // Delete the key from the AVL tree

	// Display the AVL tree after deletion in inorder traversal
	cout << "\nInorder traversal after deletion : ";
	tree.display();

	cout << endl;
	system("pause");
	return 0;
}