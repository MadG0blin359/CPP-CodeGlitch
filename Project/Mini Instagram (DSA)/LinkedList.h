#pragma once
#include <iostream>
#include "Node.h"
using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"

template <class T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    LinkedList();

    void add(const T& data);
    bool contains(const T& data) const;
    void display() const;
    Node<T>* getHead() const;

    ~LinkedList();
};

// Constructor
template <class T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr) {}

// Add an element to the list
template <class T>
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
template <class T>
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
template <class T>
void LinkedList<T>::display() const {
    Node<T>* current = head;

    if (current == nullptr) {
        cout << RED << "\n-----No Followers Found!-----" << RESET << endl;
    }

    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Get the head of the list
template <class T>
Node<T>* LinkedList<T>::getHead() const {
    return head;
}

// Destructor
template <class T>
LinkedList<T>::~LinkedList() {
    Node<T>* current = head;
    while (current) {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
}