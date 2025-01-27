#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int data;
	Node* left, * right;
	Node(int d) : data(d), left(NULL), right(NULL) {}
};

class BST {
	Node* root;

	bool search(Node* node, int key) {
		if (node == NULL)
			return false;

		if (key < node->data)
			search(node->left, key);
		else if (key > node->data)
			search(node->right, key);
		
		return true;
	}

	Node* insert(Node* node, int value) {
		if (node == NULL) {
			node = new Node(value);
			return node;
		}

		if (value < node->data)
			node->left = insert(node->left, value);
		else if (value > node->data)
			node->right = insert(node->right, value);

		return node;
	}

	int height(Node* node) {
		if (node == NULL)
			return -1;
		
		int leftHeight = height(node->left);
		int rightHeight = height(node->right);

		if (leftHeight > rightHeight)
			return 1 + leftHeight;
		return 1 + rightHeight;
	}

	int countNodes(Node* node) {
		if (node == NULL)
			return 0;
		return 1 + countNodes(node->left) + countNodes(node->right);
	}

	int countLeafs(Node* node) {
		if (node == NULL)
			return 0;
		if (node->left == NULL && node->right == NULL)
			return 1;
		return countLeafs(node->left) + countLeafs(node->right);
	}

	bool breadthTraversal(Node* root) {
		if (isEmpty())
			return false;
		
		queue<Node*> q;
		q.push(root);

		Node* current = NULL;

		while (!q.empty()) {
			current = q.front();
			q.pop();

			cout << current->data << " ";

			if (current->left != NULL)
				q.push(current->left);

			if (current->right != NULL)
				q.push(current->right);
		}

		return true;
	}

	void preorderTraversal(Node* node) {
		if (node != NULL) {
			cout << node->data << " ";
			preorderTraversal(node->left);
			preorderTraversal(node->right);
		}
	}

	void inorderTraversal(Node* node) {
		if (node != NULL) {
			inorderTraversal(node->left);
			cout << node->data << " ";
			inorderTraversal(node->right);
		}
	}

	void postorderTraversal(Node* node) {
		if (node != NULL) {
			postorderTraversal(node->left);
			postorderTraversal(node->right);
			cout << node->data << " ";
		}
	}

	Node* copyTree(Node* node) {
		if (node == NULL)
			return NULL;

		Node* newNode = new Node(node->data);
		newNode->left = copyTree(node->left);
		newNode->right = copyTree(node->right);
		return newNode;
	}

	Node* mirrorTreeNew(Node* node) {
		if (node == NULL)
			return NULL;

		Node* newNode = new Node(node->data);

		newNode->left = mirrorTreeNew(node->right);
		newNode->right = mirrorTreeNew(node->left);

		return newNode;
	}

	void mirrorThisTree(Node* node) {
		if (node == NULL)
			return;

		Node* temp = node->left;
		node->left = node->right;
		node->right = temp;

		if (node->left != NULL)
			mirrorThisTree(node->left);
		if (node->right != NULL)
			mirrorThisTree(node->right);
	}

	void deleteNode(Node* node, int key) {
		if (node == NULL)
			return;

		if (key < node->data)
			deleteNode(node->left, key);
		if (key > node->data)
			deleteNode(node->right, key);
		else
			makeDeletion(node);
	}

	void makeDeletion(Node* &temp) {
		Node* temp2;
		// case for leaf and one (left) child
		if (temp->right == NULL) {
			temp2 = temp;
			temp = temp->left;
			delete temp2;
		}
		// case for one (right) child
		else if (temp->left == NULL) {
			temp2 = temp;
			temp = temp->right;
			delete temp2;
		}
		else {	// case for two children
			temp2 = temp->right;
			while (temp2->left != NULL) {
				temp2 = temp2->left;
			}

			temp2->left = temp->left;
			temp2 = temp;
			temp = temp->right;
			delete temp2;
		}
	}

public:
	BST() : root(NULL) {}

	bool isEmpty() {
		return (root == NULL);
	}

	bool search(int key) {
		return (search(root, key));
	}

	void insert(int value) {
		root = insert(root, value);
	}

	int getHeight() {
		return height(root);
	}

	int getTotalNode() {
		return countNodes(root);
	}

	bool breadthTraversal() {
		return (breadthTraversal(root));
	}

	bool depthTraversal() {
		if (isEmpty())
			return false;

		cout << "\nPre-Order : ";
		preorderTraversal(root);

		cout << "\nIn-Order : ";
		inorderTraversal(root);

		cout << "\nPost-Order : ";
		postorderTraversal(root);

		return true;
	}

	void copyTree(const BST& tree) {
		this->root = copyTree(tree.root);
	}

	Node* mirrorTreeNew() {
		return mirrorTreeNew(root);
	}

	void mirrorThisTree() {
		mirrorThisTree(root);
	}

	void deleteNode(int key) {
		deleteNode(root, key);
	}

	void clear(Node* node) {
		if (node != NULL) {
			clear(node->left);
			clear(node->right);
			delete node;
		}
	}

	~BST() {
		clear(root);
	}
};

int main() {

	system("pause");
	return 0;
}