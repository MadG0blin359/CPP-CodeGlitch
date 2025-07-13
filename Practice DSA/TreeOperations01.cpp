#include <iostream>
#include <queue> // For std::queue, used in breadth-first traversal
using namespace std;

// Structure for a node in the Binary Search Tree
struct Node {
    int data;
    Node* left, * right;
    // Constructor initializes data and sets children pointers to NULL
    Node(int d) : data(d), left(NULL), right(NULL) {}
};

// Binary Search Tree (BST) class
class BST {
    Node* root; // Pointer to the root of the tree

    // Recursive private search function
    bool search(Node* node, int key) {
        if (node == NULL)
            return false; // Key not found

        if (key < node->data)
            search(node->left, key); // Search left subtree
        else if (key > node->data)
            search(node->right, key); // Search right subtree
        
        return true; // Key found (if reached here, key == node->data)
    }

    // Recursive private insert function
    Node* insert(Node* node, int value) {
        if (node == NULL) {
            node = new Node(value); // Create new node if current is NULL
            return node;
        }

        if (value < node->data)
            node->left = insert(node->left, value); // Insert in left subtree
        else if (value > node->data)
            node->right = insert(node->right, value); // Insert in right subtree

        return node; // Return the node pointer
    }

    // Recursive private function to calculate height of the tree
    int height(Node* node) {
        if (node == NULL)
            return -1; // Height of an empty tree is -1
        
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        // Return the greater height + 1 (for the current node)
        if (leftHeight > rightHeight)
            return 1 + leftHeight;
        return 1 + rightHeight;
    }

    // Recursive private function to count total nodes
    int countNodes(Node* node) {
        if (node == NULL)
            return 0;
        // Count current node + nodes in left subtree + nodes in right subtree
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    // Recursive private function to count leaf nodes
    int countLeafs(Node* node) {
        if (node == NULL)
            return 0;
        if (node->left == NULL && node->right == NULL)
            return 1; // It is a leaf
        // Count leaves in left and right subtrees
        return countLeafs(node->left) + countLeafs(node->right);
    }

    // Private function for Breadth-First Traversal (Level Order Traversal)
    bool breadthTraversal(Node* root) {
        if (isEmpty())
            return false;
        
        queue<Node*> q; // Queue for level order traversal
        q.push(root);

        Node* current = NULL;

        while (!q.empty()) {
            current = q.front();
            q.pop();

            cout << current->data << " "; // Print current node data

            // Enqueue left child if it exists
            if (current->left != NULL)
                q.push(current->left);

            // Enqueue right child if it exists
            if (current->right != NULL)
                q.push(current->right);
        }

        return true;
    }

    // Private function for Pre-order traversal (Root, Left, Right)
    void preorderTraversal(Node* node) {
        if (node != NULL) {
            cout << node->data << " ";
            preorderTraversal(node->left);
            preorderTraversal(node->right);
        }
    }

    // Private function for In-order traversal (Left, Root, Right) - yields sorted order in BST
    void inorderTraversal(Node* node) {
        if (node != NULL) {
            inorderTraversal(node->left);
            cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

    // Private function for Post-order traversal (Left, Right, Root)
    void postorderTraversal(Node* node) {
        if (node != NULL) {
            postorderTraversal(node->left);
            postorderTraversal(node->right);
            cout << node->data << " ";
        }
    }

    // Recursive private function to create a deep copy of the tree
    Node* copyTree(Node* node) {
        if (node == NULL)
            return NULL;

        Node* newNode = new Node(node->data);
        newNode->left = copyTree(node->left);
        newNode->right = copyTree(node->right);
        return newNode;
    }

    // Recursive private function to create a new mirrored tree
    Node* mirrorTreeNew(Node* node) {
        if (node == NULL)
            return NULL;

        Node* newNode = new Node(node->data);
        // Swap left and right subtrees during recursion
        newNode->left = mirrorTreeNew(node->right);
        newNode->right = mirrorTreeNew(node->left);

        return newNode;
    }

    // Recursive private function to mirror the current tree in-place
    void mirrorThisTree(Node* node) {
        if (node == NULL)
            return;

        // Swap children pointers of the current node
        Node* temp = node->left;
        node->left = node->right;
        node->right = temp;

        // Recursively mirror subtrees
        if (node->left != NULL)
            mirrorThisTree(node->left);
        if (node->right != NULL)
            mirrorThisTree(node->right);
    }

    // Private function for recursive deletion (incomplete implementation for BST deletion)
    void deleteNode(Node* node, int key) {
        if (node == NULL)
            return;

        // Navigate to the node to be deleted
        if (key < node->data)
            deleteNode(node->left, key);
        else if (key > node->data)
            deleteNode(node->right, key);
        else
            makeDeletion(node); // Found the node, perform deletion
    }

    // Helper function to handle deletion logic (reference parameter &temp is unusual for standard BST deletion)
    void makeDeletion(Node* &temp) {
        Node* temp2;
        // Case 1: Node has 0 or 1 child (specifically, 0 or only a left child)
        if (temp->right == NULL) {
            temp2 = temp;
            temp = temp->left; // Replace node with left child
            delete temp2;
        }
        // Case 2: Node has only a right child
        else if (temp->left == NULL) {
            temp2 = temp;
            temp = temp->right; // Replace node with right child
            delete temp2;
        }
        else { // Case 3: Node has two children
            temp2 = temp->right;
            // Find the minimum node in the right subtree (inorder successor)
            while (temp2->left != NULL) {
                temp2 = temp2->left;
            }

            // Replace data of node to be deleted with successor's data
            // (Note: The provided logic seems to be swapping pointers and deleting incorrectly, leading to a potential memory leak or dangling pointer if not careful)
            temp2->left = temp->left;
            temp2 = temp;
            temp = temp->right;
            delete temp2;
        }
    }

public:
    // Public constructor
    BST() : root(NULL) {}

    // Public interface to check if tree is empty
    bool isEmpty() {
        return (root == NULL);
    }

    // Public interface for search
    bool search(int key) {
        return (search(root, key));
    }

    // Public interface for insert
    void insert(int value) {
        root = insert(root, value);
    }

    // Public interface to get height
    int getHeight() {
        return height(root);
    }

    // Public interface to get total node count
    int getTotalNode() {
        return countNodes(root);
    }

    // Public interface for Breadth-First Traversal
    bool breadthTraversal() {
        return (breadthTraversal(root));
    }

    // Public interface for Depth-First Traversals (Pre, In, Post)
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

    // Public interface to copy a tree from another BST object
    void copyTree(const BST& tree) {
        this->root = copyTree(tree.root);
    }

    // Public interface to create a new mirrored tree
    Node* mirrorTreeNew() {
        return mirrorTreeNew(root);
    }

    // Public interface to mirror the current tree in-place
    void mirrorThisTree() {
        mirrorThisTree(root);
    }

    // Public interface for delete node
    void deleteNode(int key) {
        deleteNode(root, key);
    }

    // Recursive function to deallocate memory (post-order traversal)
    void clear(Node* node) {
        if (node != NULL) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

    // Destructor to clear the tree and free memory
    ~BST() {
        clear(root);
    }
};

int main() {

    // Program execution starts here, but the main function only contains system("pause").
    system("pause"); 
    return 0;
}