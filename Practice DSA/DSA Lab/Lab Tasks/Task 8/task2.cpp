//#include <iostream>
//using namespace std;
//
//struct Node {
//	int data;
//	Node* left, *right;
//public:
//	Node (int d) : data(d), left(NULL), right(NULL) {}
//};
//
//class Tree {
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
//		Node* current = root;
//		Node* prev = NULL;
//		
//		if (current == NULL) {
//			current = new Node(val);
//			return;
//		}
//		
//		while (current != NULL) {
//			prev = current;
//			if (val < current->data) {
//				current = current->left;
//			}
//			else if (val > current->data) {
//				current = current->right;
//			}
//		}
//
//		current = new Node(val);
//		root = prev;
//		return;
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
//			cout << "\nSuccessfully Implemented!" << endl;
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
//	cout << "\nEnter any key to exit..." << endl;
//	cin.get();
//	return 0;
//}