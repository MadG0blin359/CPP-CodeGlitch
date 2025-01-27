//#include <iostream>
//#include <queue>
//using namespace std;
//
//class Node {
//public:
//	int data;
//	Node* left, * right;
//
//	Node(int d) : data(d), left(NULL), right(NULL) {}
//};
//
//class BST {
//	Node* root;
//
//	Node* searchTree(Node* p, int value) {
//		if (root == NULL) {
//			return NULL;
//		}
//
//		if (value < p->data) {
//			p = searchTree(p->left, value);
//		}
//
//		else if (value > p->data) {
//			p = searchTree(p->right, value);
//		}
//
//		else if (value == p->data) {
//			return p;
//		}
//
//		return NULL;
//	}
//
//	void insertData(Node* p, int value) {
//		if (p == NULL) {
//			p = new Node(value);
//			return;
//		}
//
//		else if (value < p->data) {
//			insertData(p->left, value);
//		}
//
//		else {
//			insertData(p->right, value);
//		}
//	}
//
//	int height(Node* node) {
//		if (node == nullptr) return -1;
//		int leftHeight = height(node->left);
//		int rightHeight = height(node->right);
//		if (leftHeight > rightHeight) {
//			return leftHeight + 1;
//		}
//		else {
//			return rightHeight + 1;
//		}
//	}
//
//	int countNodes(Node* p) {
//		if (p == NULL) {
//			return 0;
//		}
//		return 1 + countNodes(p->left) + countNodes(p->right);
//	}
//
//	int countLeaves(Node* node) {
//		if (node == NULL) {
//			return 0;
//		}
//
//		if (node->left == NULL && node->right == NULL) {
//			return 1;
//		}
//
//		return countLeaves(node->left) + countLeaves(node->right);
//	}
//
//	void inorder(Node* node) {
//		if (node != nullptr) {
//			inorder(node->left);
//			cout << node->data << " ";
//			inorder(node->right);
//		}
//	}
//
//	void preorder(Node* node) {
//		if (node != nullptr) {
//			cout << node->data << " ";
//			preorder(node->left);
//			preorder(node->right);
//		}
//	}
//
//	void postorder(Node* node) {
//		if (node != nullptr) {
//			postorder(node->left);
//			postorder(node->right);
//			cout << node->data << " ";
//		}
//	}
//
//	void Breadth() {
//		if (root == nullptr) {
//			return;
//		}
//
//		queue<Node*> q;
//		q.push(root);
//
//		while (!q.empty()) {
//			Node* node = q.front();
//			cout << node->data << " ";
//			q.pop();
//			if (node->left) {
//				q.push(node->left);
//			}
//
//			if (node->right) {
//				q.push(node->right);
//			}
//		}
//	}
//
//	Node* copyTree(Node* p) {
//		if (p == NULL) {
//			return NULL;
//		}
//
//		Node* newNode = new Node(p->data);
//		newNode->left = copyTree(p->left);
//		newNode->right = copyTree(p->right);
//		return newNode;
//	}
//
//public:
//	BST() : root(NULL) {}
//
//	bool isEmpty() {
//		return (root == NULL);
//	}
//
//	bool searchTree(int value) {
//		if (searchTree(root, value) != NULL) {
//			return true;
//		}
//		return false;
//	}
//
//	void insertData(int value) {
//		insertData(root, value);
//	}
//
//	int height() {
//		return height(root);
//	}
//
//	int countNodes() {
//		return countNodes(root);
//	}
//
//	int countLeaves() {
//		return countLeaves(root);
//	}
//
//	void traverseDepth() {
//		cout << "Inorder: ";
//		inorder(root);
//		cout << endl;
//		cout << "Preorder: ";
//		preorder(root);
//		cout << endl;
//		cout << "Postorder: ";
//		postorder(root);
//		cout << endl;
//	}
//
//	void traverseBreadth() {
//		cout << "Traverse Breadth : ";
//		Breadth();
//		cout << endl;
//	}
//
//	BST* copy() {
//		BST* newTree = new BST();
//		newTree->root = copyTree(root);
//		return newTree;
//	}
//};
//
//int main() {
//	BST tree;
//	BST* newTree = NULL;
//	char choice;
//	int value;
//
//	do {
//		cout << "\n-----Tree Operations-----"
//			<< "\n1. isEmpty"
//			<< "\n2. Search Tree"
//			<< "\n3. Insert Data"
//			<< "\n4. Find Height"
//			<< "\n5. Total Nodes"
//			<< "\n6. Total Leafs"
//			<< "\n7. Breadth & Depth"
//			<< "\n8. Copy Binary Tree"
//			<< "\n9. Exit Program"
//			<< "\n--Enter Choice (1-9) : ";
//		cin >> choice;
//
//		switch (choice) {
//		case '1':
//			if (tree.isEmpty()) {
//				cout << "\n-----Tree is Empty!-----\n";
//			}
//			else {
//				cout << "\n-----Tree is NOT Empty!-----\n";
//			}
//			break;
//		case '2':
//			cout << "\n--Enter value to search : ";
//			cin >> value;
//
//			if (tree.searchTree(value))
//				cout << value << " Found!\n";
//			else
//				cout << value << " NOT Found!\n";
//			break;
//		case '3':
//			cout << "\n--Enter value to insert : ";
//			cin >> value;
//
//			tree.insertData(value);
//			cout << "\n-----Value Inserted Successfully!-----\n";
//			break;
//		case '4':
//			cout << "\nHeight of Tree : " << tree.height();
//			break;
//		case '5':
//			cout << "\nNumber of Nodes : " << tree.countNodes();
//			break;
//		case '6':
//			cout << "\nNumber of Leaves : " << tree.countLeaves();
//			break;
//		case '7':
//			tree.traverseBreadth();
//			tree.traverseDepth();
//			break;
//		case '8':
//			newTree = tree.copy();
//			cout << "\n-----Deep Copy Performed. Tree Copied Successfully!-----\\n";
//			delete newTree;
//			break;
//		case '9':
//			cout << "\n-----Program Terminated-----\n";
//			break;
//		default:
//			cout << "\n-----Invalid Input-----\n";
//			break;
//		}
//	} while (choice != '9');
//
//	system("pause");
//	return 0;
//}