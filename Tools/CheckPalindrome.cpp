#include <iostream>
#include <string>
using namespace std;

// Node class to represent a single element in both Stack and Queue
class Node {
    Node* next;     // Pointer to the next node
    char data;      // Character data stored in the node
public:
    // Constructor to initialize node with data and set next pointer to NULL
    Node(char d) : data(d), next(NULL) {}

    // Stack and Queue classes are friends to access private members of Node
    friend class Stack;
    friend class Queue;
};

// Stack class using linked list to store characters
class Stack {
    Node* top;  // Pointer to the top of the stack
public:
    // Constructor to initialize an empty stack
    Stack() : top(NULL) {}

    // Function to check if the stack is empty
    bool isEmpty() {
        return (top == NULL);
    }

    // Function to push a character onto the stack
    void push(char ch) {
        Node* newptr = new Node(ch);  // Create a new node with the given character
        if (isEmpty()) {
            top = newptr;  // If stack is empty, set top to the new node
            return;
        }

        newptr->next = top;  // Set the new node's next to the current top
        top = newptr;        // Update top to point to the new node
    }

    // Function to pop the top character from the stack
    bool pop(char& ch) {
        if (isEmpty()) {
            cout << "\n-----Stack is Empty!-----\n";
            return false;   // Return false if the stack is empty
        }

        Node* temp = top;   // Temporarily store the top node
        ch = top->data;     // Extract data from the top node
        top = top->next;    // Move top to the next node
        delete temp;        // Delete the old top node
        return true;
    }
};

// Queue class using linked list to store characters
class Queue {
    Node* front;   // Pointer to the front of the queue
    Node* rear;    // Pointer to the rear of the queue
public:
    // Constructor to initialize an empty queue
    Queue() : front(NULL), rear(NULL) {}

    // Function to check if the queue is empty
    bool isEmpty() {
        return (front == NULL);
    }

    // Function to enqueue (insert) a character at the rear of the queue
    void enqueue(char ch) {
        Node* newptr = new Node(ch);  // Create a new node with the given character
        if (isEmpty()) {
            front = rear = newptr;    // If queue is empty, set both front and rear to the new node
            return;
        }

        rear->next = newptr;  // Link the new node to the rear
        rear = newptr;        // Update rear to point to the new node
    }

    // Function to dequeue (remove) a character from the front of the queue
    bool dequeue(char& ch) {
        if (isEmpty()) {
            cout << "\n-----Queue is Empty!-----\n";
            return false;     // Return false if the queue is empty
        }

        Node* temp = front;   // Temporarily store the front node
        ch = front->data;     // Extract data from the front node
        front = front->next;  // Move front to the next node
        delete temp;          // Delete the old front node
        return true;
    }
};

// Function to check if the input string is a palindrome using stack and queue
bool isPalindrome(string, Stack&, Queue&);

int main() {
    Stack backwardData;   // Stack to store the characters in reverse order
    Queue forwardData;    // Queue to store the characters in original order
    string input;

    cout << "\n-----Check Palindrome-----"
        << "\n--Enter string : ";
    cin >> input;         // Prompt the user to enter a string

    cout << "\nProcessing Elements in Stack..."
        << "\nProcessing Elements in Queue..." << endl;

    // Push each character of the input into the stack and enqueue it into the queue
    for (char ch : input) {
        backwardData.push(ch);
        forwardData.enqueue(ch);
    }

    // Check if the input is a palindrome by comparing stack and queue
    if (isPalindrome(input, backwardData, forwardData))
        cout << input << " is Palindrome!" << endl;
    else
        cout << input << " is NOT Palindrome!" << endl;

    system("pause");
    return 0;
}

// Function to determine if the string is a palindrome
bool isPalindrome(string input, Stack& backwardData, Queue& forwardData) {
    char backwardChar, forwardChar;

    // Compare characters from the stack (reverse order) and queue (original order)
    while (!backwardData.isEmpty()) {
        backwardData.pop(backwardChar);     
        forwardData.dequeue(forwardChar);   

        if (backwardChar != forwardChar) {   // If any character doesn't match
            return false;                    // The string is not a palindrome
        }
    }

    return true;  // If all characters match, the string is a palindrome
}
