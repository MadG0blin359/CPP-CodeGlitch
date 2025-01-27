#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* left, * right;
	Node(int d) : data(d), left(NULL), right(NULL) {}
};

class BST {
	Node* root;

	bool insert(Node* &node, int data) {
		if (node == NULL) {
			node = new Node(data);
			return true;
		}

		if (data < node->data)
			insert(node->left, data);
		else if (data > node->data)
			insert(node->right, data);
		else if (data == node->data)
			return false;
		
		return true;
	}

	bool kthSmallest(Node* node, int k) {
		if (node == NULL)
			return;


	}

public:
	BST() : root(NULL) {}

	bool insert(int data) {
		return insert(root, data);
	}

	bool kthSmallest(int k) {
		return kthSmallest(root, k);
	}
};

int main() {
	BST tree;

	system("pause");
	return 0;
}