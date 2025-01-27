#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;
	Node(int d) : data(d), left(NULL), right(NULL) {}
};

class AVL {
	Node* root;

	int getHeight(Node* node) {
		if (node == NULL)
			return -1;
		int leftHeight = getHeight(node->left);
		int rightHeight = getHeight(node->right);

		// Return the greater height plus one
		if (leftHeight > rightHeight) {
			return leftHeight + 1;
		}
		else {
			return rightHeight + 1;
		}
	}

	int getBalance(Node* node) {
		if (node == NULL)
			return 0;
		return getHeight(node->left) - getHeight(node->right);
	}

	Node* rotateRight(Node* y) {
		Node* x = y->left;
		Node* T2 = x->right;
		x->right = y;
		y->left = T2;
		return x;
	}

	Node* rotateLeft(Node* x) {
		Node* y = x->right;
		Node* T2 = y->left;
		y->left = x;
		x->right = T2;
		return y;
	}

	Node* insert(Node* node, int key) {
		if (node == NULL) {
			node = new Node(key);
			return node;
		}

		if (key < node->data)
			node->left = insert(node->left, key);
		else if (key > node->data)
			node->right = insert(node->right, key);
		else
			return node; // Duplicate keys

						 // Update height and balance
		int balance = getBalance(node);

		// Left Left Case
		if (balance > 1 && key < node->left->data)
			return rotateRight(node);

		// Right Right Case
		if (balance < -1 && key > node->right->data)
			return rotateLeft(node);

		// Left Right Case
		if (balance > 1 && key > node->left->data) {
			node->left = rotateLeft(node->left);
			return rotateRight(node);
		}

		// Right Left Case
		if (balance < -1 && key < node->right->data) {
			node->right = rotateRight(node->right);
			return rotateLeft(node);
		}

		return node;
	}

	void display(Node* node) {
		if (node != NULL) {  // Inorder
			display(node->left);
			cout << node->data << " ";
			display(node->right);
		}
	}

public:
	AVL() : root(NULL) {}

	void insert(int key) {
		root = insert(root, key);
	}

	void display() {
		cout << "AVL Tree (Inorder): ";
		display(root);
		cout << endl;
	}

	int getBalance() {
		return getBalance(root);
	}
};

int main() {
	AVL avl;
	int bstArray[] = { 30, 20, 40, 10, 50 };
	int const n = 5;

	for (int i = 0; i < n; i++) {
		avl.insert(bstArray[i]);
	}

	// Display the AVL tree
	avl.display();

	system("pause");
	return 0;
}
