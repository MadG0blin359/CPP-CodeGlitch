#include <iostream>
using namespace std;

// Queue class implemented using a circular array
class Queue {
    int* queueArray;
    int capacity;
    int front, rear, size;
public:
    // Constructor initializes queue with a given capacity
    Queue(int c) {
        capacity = c;
        size = 0;
        front = rear = -1; // Initialize empty queue state
        queueArray = new int[capacity];
    }

    // Checks if the queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Checks if the queue is full (using circular array logic)
    bool isFull() {
        // Return true if the next position for rear is the front
        return ((rear + 1) % capacity == front);
    }

    // Returns the front element
    int getFront() {
        return (queueArray[front]);
    }

    // Adds an element to the queue (enqueue)
    bool enqueue(int val) {
        if (isFull())
            return false;

        // If queue is empty, set front and rear to 0
        if (isEmpty())
            front = rear = 0;
        else
            // Move rear circularly
            rear = (rear + 1) % capacity;

        queueArray[rear] = val;
        size++;
        return true;
    }

    // Removes the front element (dequeue)
    bool dequeue() {
        if (isEmpty())
            return false;

        // If it's the last element, reset front and rear to -1
        if (front == rear)
            front = rear = -1;
        else
            // Move front circularly
            front = (front + 1) % capacity;
        
        size--;
        return true;
    }

    // Destructor to deallocate array memory
    ~Queue() {
        delete[] queueArray;
    }
    
    // Copy constructor and assignment operator are needed for the swap() method in Stack to work correctly
    // (Omitted in the original code, leading to potential issues with dynamic memory)
    Queue(const Queue& other) = delete;
    Queue& operator=(const Queue& other) = delete;

};

// Stack implemented using two Queues (Push Expensive method)
class Stack {
    // Note: The Queue objects q1 and q2 are constructed using the default copy behavior in C++, 
    // which leads to issues because the Queue class manages dynamic memory (queueArray) and lacks a copy constructor.
    Queue q1, q2; 
public:
    // Constructor initializes queues with the given capacity
    Stack(int capacity) : q1(capacity), q2(capacity) {}

    // Swaps the two queues (note: this swap is problematic without a proper Queue copy constructor or swap implementation)
    void swap() {
        // The assignment `q1 = q2` here uses the compiler-generated assignment operator, 
        // which performs a shallow copy of pointers, leading to double-free issues in the destructor.
        Queue temp = q1; 
        q1 = q2;
        q2 = temp;
    }

    // Push operation (O(N) complexity)
    void push(int val) {
        q2.enqueue(val); // Add new element to q2

        // Move all elements from q1 to q2
        while (!q1.isEmpty()) {
            q2.enqueue(q1.getFront());
            q1.dequeue();
        }

        swap(); // Swap q1 and q2
    }

    // Pop operation (O(1) complexity)
    bool pop(int& data) {
        if (q1.isEmpty())
            return false;

        data = q1.getFront(); // Get the top element
        q1.dequeue();         // Remove the top element
        return true;
    }
};

int main() {
    Stack s1(10); // Create a stack with capacity 10

    // Program exits after initialization
    system("pause"); 
    return 0;
}