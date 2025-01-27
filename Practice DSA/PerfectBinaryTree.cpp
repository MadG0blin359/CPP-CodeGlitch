#include <iostream>
using namespace std;

template <typename K = int, typename V = int>
struct TNode {
	K key;
	V value;
	int nodeCount;
	TNode<K, V>* left, * right;

	TNode(K k, V v) : key(k), value(v), nodeCount(1), left(NULL), right(NULL) {}
};

template <typename K = int, typename V = int>
class BinaryTree {
	TNode<K, V>* root;

	int getHeight(TNode<K,V>* node) {
		if (node == NULL)
			return 0;

		int leftHeight = getHeight(node->left);
		int rightHeight = getHeight(node->right);

		if (leftHeight > rightHeight)
			return 1 + leftHeight;
		return 1 + rightHeight;
	}

	// Helper function to update node count 
	void updateNodeCount(TNode<K, V>* node) {
		if (node != NULL) {
			int leftCount = 0, rightCount = 0;
			if (node->left != NULL)
				leftCount = node->left->nodeCount;
			if (node->right != NULL)
				rightCount = node->right->nodeCount;

			node->nodeCount = leftCount + rightCount + 1;
		}
	}

	void insertNode(TNode<K,V>*& node, const K key, const V value) {
		if (node == NULL) {
			node = new TNode<K, V>(key, value);
			return;
		}

		int leftCount = 0, rightCount = 0;
		if (node->left != NULL)
			leftCount = node->left->nodeCount;
		if (node->right != NULL)
			rightCount = node->right->nodeCount;

		int balance = leftCount - rightCount;

		if (balance <= 1)		// Prioritize inserting left when balance less than 2
			insertNode(node->left, key, value);
		else if (balance > 1)	// Else right
			insertNode(node->right, key, value);
			
		updateNodeCount(node);
	}

	int search(TNode<K, V>* node, const K key) {
		if (node == NULL)
			return 0;
		
		int count = 0;
		if (node->key == key)
			count = 1;

		int leftCount = search(node->left, key); // Recurse on left subtree
		int rightCount = search(node->right, key); // Recurse on right subtree

		return count + leftCount + rightCount; // Return total count
	}

	// Recursive function to check if the tree is perfect
	bool isPerfectUtil(TNode<K,V>* node, int depth, int level) {
		if (node == nullptr) {
			return true; // Base case: an empty tree is perfect
		}

		// Check if the node is a leaf
		if (node->left == nullptr && node->right == nullptr) {
			return (depth == level + 1); // Leaf nodes should be at the same depth
		}

		// Check if the node has two children
		if (node->left == nullptr || node->right == nullptr) {
			return false;
		}

		// Recursively check the left and right subtrees
		return isPerfectUtil(node->left, depth, level + 1) && isPerfectUtil(node->right, depth, level + 1);
	}

public:
	BinaryTree() : root(nullptr) {}

	void insertNode(const K key, const V value) {
		insertNode(root, key, value);
	}

	int search(const K key) {
		return search(root, key);
	}

	// Wrapper function
	bool isPerfect(TNode* root) {
		int depth = getHeight(root);
		return isPerfectUtil(root, depth, 0);
	}

};

int main() {
	BinaryTree<int, int> tree;

	cout << "Inserting Nodes...\n";
	tree.insertNode(5, 12);
	tree.insertNode(8, 6);
	tree.insertNode(7, 69);
	tree.insertNode(3, 17);
	tree.insertNode(3, 9);
	tree.insertNode(2, 89);
	tree.insertNode(8, 8);
	tree.insertNode(8, 13);

	cout << tree.search(8) << endl;

	system("pause");
	return 0;
}