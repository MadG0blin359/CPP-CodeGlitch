#include <iostream>
using namespace std;

struct node {
	int data;
	node* left;
	node* right;
public:
	node(int value) {
		data = value;
		left = right = NULL;
	}
};

class BST {
public:
	node* root;

	BST() :root(NULL) {}

	void insert(node* temp, int value) {
		// if the tree is empty
		if (root == nullptr) {
			root = new node(value);
			return;
		}

		if (value < temp->data) {
			if (temp->left != nullptr)
				insert(temp->left, value);
			else
				temp->left = new node(value);
		}

		else if (value > temp->data) {
			if (temp->right != nullptr)
				insert(temp->right, value);
			else
				temp->right = new node(value);
		}
	}

	// in-order traversal (printing the tree)
	void inorder(node* temp) {
		if (temp != nullptr) {
			inorder(temp->left);
			cout << temp->data << " ";
			inorder(temp->right);
		}
	}
};

int main() {
	BST tree;
	
	tree.insert(tree.root, 50);
	tree.insert(tree.root, 30);
tree.insert(tree.root, 70);

cout << "In-order traversal of the BST: ";
		tree.inorder(tree.root);
	cin.get();
	return 0;
}

