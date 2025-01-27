#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Node structure for the Binary Search Tree (BST)
struct Node {
    int data;              // Data value of the node
    Node* left, *right;    // Pointers to left and right child nodes
    Node(int d) : data(d), left(nullptr), right(nullptr) {} // Constructor
};

// Class representing the Binary Search Tree (BST)
class BST {
    Node* root;  // Pointer to the root of the BST

    // Recursive helper function for inserting a node
	bool insertNode(Node*& node, int data) {
		if (node == nullptr)
			node = new Node(data);

		else if (data < node->data)
			insertNode(node->left, data);
		else if (data > node->data)
			insertNode(node->right, data);
		else
			return false;
		return true;
	}

    // Recursive helper function for searching a node
	Node* searchNode(Node* node, int data) {
		if (node == nullptr)
			return nullptr;

		else if (node->data < data)
			searchNode(node->left, data);
		else if (node->data > data)
			searchNode(node->right, data);
		else
			return node;
	}

	// Breadth-First Traversal (Level-order traversal) to convert BST to an array
	vector<int> breadthFirst(Node* root) {
		if (root == nullptr)
			return {};			// Empty vector : Equivalent to vector<int>()

		vector<int> array;
		queue<Node*> q;
		q.push(root);

		while (!q.empty()) {
			Node* node = q.front();
			q.pop();

			array.push_back(node->data);

			if (node->left != nullptr)
				q.push(node->left);

			if (node->right != nullptr)
				q.push(node->right);
		}

		return array;
	}

public:
	BST() : root(nullptr) {} // Constructor initializes the root to null

	// Public interface for inserting a node
    bool insertNode(int data) {
        return insertNode(root, data);
    }

    // Public interface for searching a node
	bool searchNode(int data) {
		Node* found = searchNode(root, data);
		if (found == nullptr)
			return false;
		return true;
	}
	
	// Function to delete a node from the BST
	bool deleteNode(int data) {
		Node* temp = searchNode(root, data);
		Node* current = temp;
		
		if (temp == nullptr)
			return false;

		// Case 1
		else if (temp->right == nullptr) {
			temp = temp->left;
			delete current;
		}

		// Case 2
		else if (temp->left == nullptr) {
			temp = temp->right;
			delete current;
		}

		// Case 3
		else if (temp->left != nullptr && temp->right != nullptr) {
			current = temp->right;
			while (current->left != nullptr)
				current = current->left;

			// Replace with Successor
			temp->data = current->data;
			// Delete Successor
			Node* temp2 = current;
			current = current->right;
			delete temp2;
		}
		return true;
	}

	// Convert BST to an array using breadth-first traversal
    vector<int> BST2Array() {
        return breadthFirst(root);
    }

    // Recursive function to clear the tree
	void clearTree(Node* node) {
		if (node == nullptr)
			return;
		clearTree(node->left);
		clearTree(node->right);
		delete node;
	}

	~BST() { // Destructor to clear the tree and free memory
		clearTree(root);
	}
};


// Function to display the contents of a vector
void displayVector(const vector<int>&);

// Function to heapify a subtree rooted at index i in a vector
void heapify(vector<int>&, int);

int main() {
	BST tree;

	// Insert nodes into the BST
    tree.insertNode(5);
    tree.insertNode(3);
    tree.insertNode(8);
    tree.insertNode(2);
    tree.insertNode(4);
    tree.insertNode(6);
    tree.insertNode(10);

    // Convert BST to an array
    vector<int> arr = tree.BST2Array();
    cout << "BST 2 array : ";
    displayVector(arr);

    // Transform the array into a min-heap
    for (int i = (arr.size() - 1) / 2; i >= 0; i--) {
        heapify(arr, i);
    }

    // Display the transformed min-heap
    cout << "\nBST 2 Min Heap : ";
    displayVector(arr);

	system("pause");
	return 0;
}

// Function to display the elements of a vector
void displayVector(const vector<int>& arr) {
	for (auto& val : arr)
		cout << val << " ";
	cout << endl;
}

// Function to heapify a subtree rooted at index i in a vector (Min-Heap)
void heapify(vector<int>& minHeap, int i) {
	int temp;

	int smallest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < minHeap.size() && minHeap[left] < minHeap[smallest])
		smallest = left;

	else if (right < minHeap.size() && minHeap[right] < minHeap[smallest])
		smallest = right;

	else if (smallest == i)
		return;

	temp = minHeap[smallest];
	minHeap[smallest] = minHeap[i];
	minHeap[i] = temp;
	
	heapify(minHeap, smallest);			// Recursively heapify the affected subtree
}