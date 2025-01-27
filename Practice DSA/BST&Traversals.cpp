#include <iostream>
using namespace std;

class Node {
public:
   int data; // Data value of the node
   Node* left; // Pointer to the left child
   Node* right; // Pointer to the right child

   // Constructor to initialize the node with a value
   Node(int d) : data(d), left(NULL), right(NULL) {}
};

class BinaryTree {
   Node* root; // Pointer to the root of the tree

   // Function to search for a key in the postorder array within the given range
   int search(int postorder[], int key, int start, int end) {
       for (int i = start; i <= end; i++) {
           if (postorder[i] == key) {
               return i;
           }
       }
       return -1;
   }

   // Function to construct a binary tree from preorder and postorder arrays
   Node* construct(int preorder[], int postorder[], int& preIndex, int start, int end) {
       if (start > end)
           return NULL;

       root = new Node(preorder[preIndex]);
       ++preIndex;

       if (start == end)
           return root;

       int postIndex = search(postorder, preorder[preIndex], start, end);

       root->left = construct(preorder, postorder, preIndex, start, postIndex);
       root->right = construct(preorder, postorder, preIndex, postIndex + 1, end - 1);

       return root;
   }

   // Function to perform inorder traversal of the tree
   void inorderTraversal(Node* root) {
       if (root == NULL) 
           return;
       inorderTraversal(root->left);
       cout << root->data << " ";
       inorderTraversal(root->right);
   }

public:
   BinaryTree() : root(NULL) {} // Constructor to initialize an empty tree

   // Function to construct a binary tree from preorder and postorder arrays
   Node* constructFromPrePost(int preorder[], int postorder[], int size) {
       int preIdx = 0;
       root = construct(preorder, postorder, preIdx, 0, size - 1);
   }

    // Function to display the tree using inorder traversal
   void display() {
       inorderTraversal(root);
   }
};

int main() {
   int preorder[] = { 1, 2, 4, 5, 3, 6, 7 }; // Preorder traversal array
   int postorder[] = { 4, 5, 2, 6, 7, 3, 1 }; // Postorder traversal array
   int size = sizeof(preorder) / sizeof(preorder[0]); // Calculate the size of the arrays

   BinaryTree tree; // Create a BinaryTree object

   // Construct the binary tree using preorder and postorder arrays
   tree.constructFromPrePost(preorder, postorder, size);

   cout << "\nConstructed Tree : ";
   tree.display();  // Expected output: 4 2 5 1 6 3 7 (Inorder Traversal)
   
   cout << endl;
   system("pause");
   return 0;
}
