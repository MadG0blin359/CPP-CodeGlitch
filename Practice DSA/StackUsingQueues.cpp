#include <iostream>
using namespace std;

// Node structure for linked list implementation
class Node {
public:
    int data;
    Node* next;
    // Constructor initializes data and sets next to NULL
    Node(int d) : data(d), next(NULL) {}
};

// Queue class implemented using a linked list
class Queue {
    int numOfItems;
    Node* front, * rear;
public:
    // Constructor initializes empty queue
    Queue() : numOfItems(0), front(NULL), rear(NULL) {}

    // Checks if the queue is empty
    bool isEmpty() {
        return (front == NULL);
    }

    // Returns the front element of the queue
    int getFront() {
        if (isEmpty())
            return -1; // Return -1 if empty
        return front->data;
    }

    // Adds an element to the back of the queue (enqueue)
    void push(int val) {
        if (isEmpty()) {
            front = rear = new Node(val);
            numOfItems++;
            return;
        }

        rear->next = new Node(val);
        rear = rear->next;
        numOfItems++;
    }

    // Removes the front element of the queue (dequeue)
    bool pop() {
        if (isEmpty())
            return false;

        Node* temp = front->next;
        delete front; // Deallocate front node
        front = temp;
        numOfItems--;
        // If front becomes NULL, rear should also be NULL (handled implicitly if numOfItems becomes 0, but explicit check for empty queue might be safer)
        if (front == NULL) rear = NULL; 
        return true;
    }

    // Swaps the contents of two queues by swapping pointers
    void swap(Queue& other) {
        Node* temp = other.front;
        other.front = this->front;
        this->front = temp;

        temp = other.rear;
        other.rear = this->rear;
        this->rear = temp;
        // Note: numOfItems is not swapped, which might cause issues
    }

};

// Stack implemented using two Queues (Push Expensive method)
class Stack {
    Queue q1, q2; // q1 is the main queue, q2 is the auxiliary queue
public:
    // Returns the top element of the stack (front of q1)
    int top() {
        if (q1.isEmpty())
            return -1;
        return q1.getFront();
    }

    // Adds element to stack (O(N) operation)
    void push(int val) {
        q2.push(val); // Push new element to auxiliary queue (q2)

        // Move all elements from q1 to q2
        while (!q1.isEmpty()) {
            q2.push(q1.getFront());
            q1.pop();
        }

        // Swap q1 and q2 so q1 holds elements in LIFO order
        q2.swap(q1); 
        // q2 is now empty, q1 contains the new element at the front
    }

    // Removes the top element from the stack (O(1) operation)
    int pop() {
        int temp = q1.getFront();
        q1.pop();
        return temp;
    }

    // Checks if the stack is empty
    bool isEmpty() {
        return (q1.isEmpty());
    }
};

int main() {
    Stack stack; // Create an instance of Stack
    int choice, value;

    // Menu-driven loop for stack operations
    while (choice != 5) {
        cout << "\n--- Stack Operations Menu ---" << endl;
        cout << "1. Push an element" << endl;
        cout << "2. Pop an element" << endl;
        cout << "3. View the top element" << endl;
        cout << "4. Check if the stack is empty" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter a value to push: ";
            cin >> value;
            stack.push(value);
            cout << value << " has been pushed to the stack." << endl;
            break;

        case 2:
            // Check if stack is empty before popping
            if (stack.top() == -1) {
                cout << "Stack is empty. Nothing to pop." << endl;
            }
            else {
                cout << "Popped element: " << stack.pop() << endl;
            }
            break;

        case 3:
            // View top element
            value = stack.top();
            if (value == -1) {
                cout << "Stack is empty. No top element." << endl;
            }
            else {
                cout << "Top element: " << value << endl;
            }
            break;

        case 4:
            // Check if empty
            if (stack.isEmpty()) {
                cout << "Stack is empty!" << endl;
            }
            else {
                cout << "Stack is NOT empty!" << endl;
            }
            break;

        case 5:
            cout << "-----Program Terminated!-----" << endl;
            break;

        default:
            cout << "-----Invalid Input!-----" << endl;
        }
    }

    system("pause"); 
    return 0; // return statement for the function
}