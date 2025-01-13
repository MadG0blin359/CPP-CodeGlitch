#pragma once
#include <iostream>
#include "Node.h"

template <class T>
class Stack {
	Node<T>* top;
public:
	Stack() : top(NULL) {}
    Stack(const Stack<T>& other); // Copy constructor 
    Stack<T>& operator=(const Stack<T>& other); // Copy assignment operator

    void push(const T& data);
    bool pop();
    bool peek(T&);
    bool isEmpty();
    void displayStack();
    void makeNULL();
    T getTop();

    ~Stack();

private:
    void copy(const Stack<T>& other); 
    void clear();
};