#include "LinkedList.h"

// Constructor
template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr) {}

// Add an element to the list
template <typename T>
void LinkedList<T>::add(const T& data) {
    Node<T>* newNode = new Node<T>(data);
    if (tail) {
        tail->next = newNode;
    }
    else {
        head = newNode;
    }
    tail = newNode;
}

// Check if the list contains an element
template <typename T>
bool LinkedList<T>::contains(const T& data) const {
    Node<T>* current = head;
    while (current) {
        if (current->data == data) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Display the elements of the list
template <typename T>
void LinkedList<T>::display() const {
    Node<T>* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Get the head of the list
template <typename T>
Node<T>* LinkedList<T>::getHead() const {
    return head;
}

// Destructor
template <typename T>
LinkedList<T>::~LinkedList() {
    Node<T>* current = head;
    while (current) {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
}