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
		if (node != NULL) { // Inorder
			display(node->left);
			cout << node->data << " ";
			display(node->right);
		}
	}

	Node* join(Node* root1, Node* root2) {
		if (root1 == NULL) 
			return root2;
		if (root2 == NULL) 
			return root1;

		
		root2 = insert(root2, root1->data);
		root2 = join(root1->left, root2);
		root2 = join(root1->right, root2);

		return root2;
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

	Node* getRoot() {
		return root; 
	}

	void join(AVL& other) {
		root = join(this->root, other.root);
	}
};

int main() {
	AVL T1, T2;

	
	int valuesT1[] = { 10, 5, 20, 15, 25, 22 };
	int const n1 = 6;
	for (int i = 0; i < n1; i++) {
		T1.insert(valuesT1[i]);
	}

	
	int valuesT2[] = { 30, 28, 35, 26, 29 };
	int const n2 = 5;
	for (int i = 0; i < n2; i++) {
		T2.insert(valuesT2[i]);
	}

	
	cout << "T1: ";
	T1.display();
	cout << "T2: ";
	T2.display();

	// Join T1 and T2
	T1.join(T2); 
	cout << "Joined AVL Tree: ";
	T1.display();

	system("pause");
	return 0;
}
