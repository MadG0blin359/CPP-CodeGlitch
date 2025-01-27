//#include <iostream>
//using namespace std;
//
//struct Node {
//	int data;
//	Node* left, *right;
//public:
//	Node(int d) : data(d), left(NULL), right(NULL) {}
//};
//
//class Tree {
//	Node* insertRecursive(Node* node, int val) {
//		if (node == NULL) {
//			node = new Node(val);
//			return node;
//		}
//
//		else if (val < node->data) {
//			node->left = insertRecursive(node->left, val);
//		}
//
//		else if (val > node->data) {
//			node->right = insertRecursive(node->right, val);
//		}
//
//		return node;
//	}
//
//	void inorderRecursive(Node* node) {
//		if (node != nullptr) {
//			inorderRecursive(node->left);      
//			cout << node->data << " ";        
//			inorderRecursive(node->right);    
//		}
//	}
//public:
//	Node* root;
//	Tree() : root(NULL) {}
//
//	void insert(int val) {
//		root = insertRecursive(root, val);
//	}
//
//	void inorderTraversal() {
//		inorderRecursive(root);
//		cout << endl;
//	}
//};
//
//int main() {
//	Tree tree;
//	char choice;
//	int val;
//
//	do {
//		cout << "\n1. Create Node"
//			<< "\n2. Display Inorder"
//			<< "\n3. Exit Program"
//			<< "\n--Enter choice : ";
//		cin >> choice;
//
//		switch (choice)
//		{
//		case '1':
//			cout << "\n--Enter value : ";
//			cin >> val;
//			tree.insert(val);
//			cout << "\nSuccessfully Implemented Using Recursion." << endl;
//			break;
//
//		case '2':
//			tree.inorderTraversal();
//			break;
//		case '3':
//			cout << "\nProgram Terminated\n";
//			break;
//		default:
//			break;
//		}
//	} while (choice != '3');
//
//
//
//	cout << "\nEnter any key to exit..." << endl;
//	cin.get();
//	return 0;
//}