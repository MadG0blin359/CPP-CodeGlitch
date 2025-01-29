#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left, *right;

    Node(int d) : data(d), left(NULL), right(NULL) {}
};

class BST {
    Node* root;

    Node* insert(Node* p, int value) {
        if (p == NULL) {
            p = new Node(value);
            return p;
        }
        if (value < p->data) {
            p->left = insert(p->left, value);
        }
        else {
            p->right = insert(p->right, value);
        }
        return p;
    }

    Node* deleteNode(Node* p, int value) {
        if (p == NULL) {
            return p;
        }

        if (value < p->data) {
            p->left = deleteNode(p->left, value);
        }
        else if (value > p->data) {
            p->right = deleteNode(p->right, value);
        }
        else {
            if (p->left == NULL && p->right == NULL) {
                delete p;
                return NULL;
            }
            else if (p->left == NULL) {
                Node* temp = p->right;
                delete p;
                return temp;
            }
            else if (p->right == NULL) {
                Node* temp = p->left;
                delete p;
                return temp;
            }
            Node* temp = minValueNode(p->right);
            p->data = temp->data;
            p->right = deleteNode(p->right, temp->data);
        }
        return p;
    }

    Node* minValueNode(Node* p) {
        while (p && p->left != NULL) {
            p = p->left;
        }
        return p;
    }

    void inorder(Node* node) {
        if (node != NULL) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

public:
    BST() : root(NULL) {}

    void insert(int value) {
        root = insert(root, value);
    }

    void deleteNode(int value) {
        root = deleteNode(root, value);
    }

    void traverseInOrder() {
        cout << "Inorder: ";
        inorder(root);
        cout << endl;
    }
};

int main() {
    BST tree;
    char choice;
    int value;

    do {
        cout << "\n-----Tree Operations-----"
            << "\n1. Insert Data"
            << "\n2. Delete Data"
            << "\n3. Inorder Traversal"
            << "\n4. Exit Program"
            << "\n--Enter Choice (1-4) : ";
        cin >> choice;

        switch (choice) {
        case '1':
            cout << "\n--Enter value to insert : ";
            cin >> value;
            tree.insert(value);
            cout << "\n-----Value Inserted Successfully!-----\n";
            break;
        case '2':
            cout << "\n--Enter value to delete : ";
            cin >> value;
            tree.deleteNode(value);
            cout << "\n-----Value Deleted Successfully!-----\n";
            break;
        case '3':
            tree.traverseInOrder();
            break;
        case '4':
            cout << "\n-----Program Terminated-----\n";
            break;
        default:
            cout << "\n-----Invalid Input-----\n";
            break;
        }
    } while (choice != '4');

    return 0;
}
