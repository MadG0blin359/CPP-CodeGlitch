#include <iostream>
using namespace std;

// Forward declaration of Stack template class
template <class T>
class Stack;

// Node template class for linked list implementation of Stack
template <class W>
class Node {
    Node<W>* next;
    W data;
public:
    // Constructor initializes data and sets next to NULL
    Node(W d) : next(NULL), data(d) {}
    // Stack class is a friend to access Node's private members
    friend class Stack<W>;
};

// Stack template class (implemented using linked list of Nodes)
template <class T>
class Stack {
    Node<T>* topptr; // Pointer to the top of the stack
public:
    // Constructor initializes stack as empty
    Stack() : topptr(NULL) {}

    // Checks if stack is empty
    bool isEmpty() {
        return (topptr == NULL);
    }

    // Returns the top element of the stack
    T top() {
        return topptr->data;
    }

    // Pushes a new element onto the stack
    bool push(T data) {
        Node<T>* newptr = new Node<T>(data);
        if (isEmpty()) {
            topptr = newptr;
            return true;
        }

        newptr->next = topptr;
        topptr = newptr;
        return true;
    }

    // Removes the top element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "\nStack Underflow!\n";
            return;
        }

        Node<T>* temp = topptr->next;
        delete topptr;
        topptr = temp;
    }
};

// Queue template class implemented using two stacks (input and output)
template <class T>
class Queue {
    Stack<T> input, output; // Composition: two stacks used for queue operations
public:
    // Checks if the queue is empty
    bool isEmpty() {
        return (input.isEmpty() && output.isEmpty());
    }

    // Returns the front element of the queue
    T front() {
        if (isEmpty()) {
            cout << "\nQueue is Empty!\n";
            return T();
        }

        // Move elements from input to output stack if output is empty
        if (output.isEmpty()) {
            while (!input.isEmpty()) {
                output.push(input.top());
                input.pop();
            }
        }

        return output.top(); // Return the top of the output stack (FIFO order)
    }

    // Adds an element to the queue (pushed onto input stack)
    void enqueue(T data) {
        input.push(data);
    }

    // Removes and returns the front element of the queue
    T dequeue() {
        if (isEmpty()) {
            cout << "\nQueue Underflow!\n";
            return T();
        }

        // Move elements from input to output stack if output is empty
        if (output.isEmpty()) {
            while (!input.isEmpty()) {
                output.push(input.top());
                input.pop();
            }
        }

        T temp = output.top();
        output.pop(); // Pop from output stack (FIFO)
        return temp;
    }
};

int main() {
    Queue<int> line; // Create a Queue of integers

    cout << "\nEnqueing Elements...";
    line.enqueue(1); // Enqueue 1
    line.enqueue(2); // Enqueue 2
    line.enqueue(3); // Enqueue 3

    cout << "\nFront element is : " << line.front(); // Get front element (1)

    cout << "\nEnqueing More Elements...";
    line.enqueue(4); // Enqueue 4
    line.enqueue(5); // Enqueue 5

    // Dequeue and print elements until the queue is empty
    while (!line.isEmpty()) {
        cout << "\nDequeing Elements : " << line.dequeue() << " ";
    }

    cout << "\nPress any key to exit...";
    cin.get();
    return 0;
}