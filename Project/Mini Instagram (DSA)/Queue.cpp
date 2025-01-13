#include "Queue.h"
#include "Node.h"
#include "FriendRequest.h"
#include "Notification.h"

// Function to copy the queue 
 template <class T> 
 void Queue<T>::copyQueue(const Queue<T>& other) { 
 Node<T>* current = other.front; 
     while (current) { 
     enqueue(current->data); 
     current = current->next; 
     } 
 } 
 
 // Function to clear the queue 
 template <class T> 
 void Queue<T>::clearQueue() { 
     while (!isEmpty()) { 
     dequeue();
     }
}

// Constructor to initialize an empty queue
template <class T>
Queue<T>::Queue() : front(nullptr), rear(nullptr), currentSize(0) {}

// Copy constructor 
 template <class T> 
 Queue<T>::Queue(const Queue<T>& other) : front(nullptr), rear(nullptr), currentSize(0) { 
    copyQueue(other); 
 } 
 
 // Copy assignment operator 
 template <class T> 
 Queue<T>& Queue<T>::operator=(const Queue<T>& other) { 
     if (this != &other) { 
     clearQueue(); 
     copyQueue(other); 
     } 
 return *this; 
 }

// Function to check if the queue is empty
template <class T>
bool Queue<T>::isEmpty() const {
    return (front == nullptr);
}

// Function to enqueue an element to the queue
template <class T>
bool Queue<T>::enqueue(T value) {
    Node<T>* newNode = new Node<T>(value);

    if (isEmpty()) {
        front = rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }

    currentSize++;
    return true;
}

// Function to dequeue an element from the queue
template <class T>
bool Queue<T>::dequeue() {
    if (isEmpty()) {
        return false;
    }

    Node<T>* temp = front;
    front = front->next;

    if (front == nullptr) {
        rear = nullptr;
    }

    delete temp;
    currentSize--;
    return true;
}

// Function to get the front element
template <class T>
T* Queue<T>::getFront() {
    if (isEmpty()) {
        cout << "\nNo Data Found!" << endl;
        return nullptr;     
    }
    return &(front->data);
}

// Destructor to clear the queue and free memory
template <class T>
Queue<T>::~Queue() {
    while (!isEmpty())
        dequeue();
}

template class Queue<FriendRequest>;
template class Queue<Notification>;