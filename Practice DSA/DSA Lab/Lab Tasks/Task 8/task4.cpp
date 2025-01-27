#include <iostream>
#include <queue> 
using namespace std;

struct Node {
	int data;
	Node* left, *right;

	Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Tree {
public:
	Node* root;

	Tree() : root(NULL) {}

	void insert(int val) {
		root = insertRec(root, val);
	}

	void levelOrder() {
		if (root == NULL) return;

		queue<Node*> q; 
		q.push(root);   

		while (!q.empty()) {
			Node* current = q.front(); 
			q.pop();                   

			cout << current->data << " "; 

			if (current->left != NULL)
				q.push(current->left);

			if (current->right != NULL)
				q.push(current->right);
		}
		cout << endl; 
	}

private:
	Node* insertRec(Node* node, int val) {
		if (node == NULL) {
			return new Node(val); 
		}

		if (val < node->data) {
			node->left = insertRec(node->left, val);  
		}
		else if (val > node->data) {
			node->right = insertRec(node->right, val);
		}

		return node; 
	}
};

int main() {
	Tree tree;
	tree.insert(60);
	tree.insert(55);
	tree.insert(100);
	tree.insert(45);
	tree.insert(57);
	tree.insert(67);
	tree.insert(107);
	tree.insert(59);
	tree.insert(101);

	cout << "Level order: ";
	tree.levelOrder();

	cin.get();
	return 0;
}
