//#include <iostream>
//using namespace std;
//
//struct Node {
//	int data;
//	Node* left, *right;
//
//	Node(int val) : data(val), left(NULL), right(NULL) {}
//};
//
//class Tree {
//public:
//	Node* root;
//
//	Tree() : root(NULL) {}
//
//	void insert(int val) {
//		root = insertRec(root, val);
//	}
//
//	void preOrder(Node* node) {
//		if (node == NULL) return;
//
//		cout << node->data << " ";   
//		preOrder(node->left);        
//		preOrder(node->right);       
//	}
//
//	void inOrder(Node* node) {
//		if (node == NULL) return;
//
//		inOrder(node->left);         
//		cout << node->data << " ";   
//		inOrder(node->right);        
//	}
//
//	void postOrder(Node* node) {
//		if (node == NULL) return;
//
//		postOrder(node->left);       
//		postOrder(node->right);      
//		cout << node->data << " ";   
//	}
//
//private:
//	Node* insertRec(Node* node, int val) {
//		if (node == NULL) {
//			return new Node(val); 
//		}
//
//		if (val < node->data) {
//			node->left = insertRec(node->left, val);  
//		}
//		else if (val > node->data) {
//			node->right = insertRec(node->right, val); 
//		}
//
//		return node; 
//	}
//};
//
//int main() {
//	Tree tree;
//	tree.insert(50);
//	tree.insert(30);
//	tree.insert(70);
//	tree.insert(20);
//	tree.insert(40);
//	tree.insert(60);
//	tree.insert(80);
//
//	cout << "Pre-order Traversal: ";
//	tree.preOrder(tree.root);
//	cout << endl;
//
//	cout << "In-order Traversal: ";
//	tree.inOrder(tree.root);
//	cout << endl;
//
//	cout << "Post-order Traversal: ";
//	tree.postOrder(tree.root);
//	cout << endl;
//
//	cin.get();
//	return 0;
//}
