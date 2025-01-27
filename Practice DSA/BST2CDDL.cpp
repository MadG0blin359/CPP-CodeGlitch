#include <iostream>
using namespace std;

// Node class representing a node in the binary search tree
class Node {
public:
   int data; // Data stored in the node
   Node* left, * right; // Pointers to left and right child nodes

   // Constructor to initialize node with data and NULL children
   Node(int d) : data(d), left(NULL), right(NULL) {}
};

// Binary Search Tree (BST) class
class BST {
   Node* root; // Root node of the BST
   Node* prev; // Pointer to keep track of the previous node during DLL conversion

   // Recursive function to insert a node into the BST
   bool insertNode(Node*& node, int data) {
       if (node == NULL) {
           node = new Node(data);
           return true;
       }

       if (data < node->data)
           insertNode(node->left, data);
       else if (data > node->data)
           insertNode(node->right, data);
       else
           return false;
       return true;
   }

   // Recursive function for inorder traversal of the BST
   void inorderTraversal(Node* root) {
       if (root == NULL) return;

       inorderTraversal(root->left);
       cout << root->data << " ";
       inorderTraversal(root->right);
   }

   // Recursive function to convert BST to a circular doubly linked list (CDLL)
   void ConvertToDLL(Node*& root) {
       if (root == NULL) {
           return;
       }

       ConvertToDLL(root->left);

       if (prev != nullptr) {
           prev->right = root;
           root->left = prev;
       }

       prev = root;

       ConvertToDLL(root->right);
   }

   // Function to display the Circular Doubly Linked List (CDLL)
   void DisplayCDLL(Node* head) {
       cout << "\nDisplaying Circular Doubly Linked List: ";
       Node* temp = head;
       if (temp == NULL) return;

       do {
           cout << temp->data << " ";
           temp = temp->right;
       } while (temp != head);
       cout << endl;
   }

public:
   // Constructor to initialize an empty BST
   BST() : root(NULL), prev(NULL) {}

   // Public function to insert a value into the BST
   bool insert(int data) {
       return insertNode(root, data);
   }

   // Public function to convert BST to Circular Doubly Linked List (CDLL)
   bool bstToCDLL() {
       if (root == NULL) {
           return false;
       }

       ConvertToDLL(root);

       Node* head = root;
       while (head->left != NULL)
           head = head->left;

       root = head;

       root->left = prev;
       prev->right = root;

       return true;
   }

    // Public function to display the BST in inorder traversal
   void DisplayInOrder() {
       cout << "\nDisplaying InOrder: ";
       inorderTraversal(root);
   }

   // Public function to display the CDLL
   void DisplayCDLL() {
       DisplayCDLL(root);
   }
};

int main() {
   BST T1; // Create an instance of the BST class
   int value = 0; // Variable to store input values

   cout << "Enter Values to Store (-1 To Exit): " << endl;
   while (value != -1) { // Loop until the user enters -1
       cin >> value;
       if (value != -1) {
           T1.insert(value); // Insert the value into the BST
       }
   }

   T1.DisplayInOrder(); // Display the BST in inorder traversal

   T1.bstToCDLL(); // Convert the BST to CDLL
   T1.DisplayCDLL(); // Display the CDLL

   return 0;
}
