#include <iostream>
#include "Stack.h"
#include "Post.h"
#include "Message.h"
using namespace std;

template <class T> 
Stack<T>::Stack(const Stack<T>& other) : top(nullptr) { 
	copy(other); 
} 

template <class T> 
Stack<T>& Stack<T>::operator=(const Stack<T>& other) {
	if (this != &other) {
		clear();
		copy(other);
	}
	return *this;
}

// Function to insert a new node at the top
template <class T>
void Stack<T>::push(const T& element) {
	Node<T>* newptr = new Node<T>(element);
	if (isEmpty()) {
		top = newptr;
		return;
	}

	newptr->next = top;
	top = newptr;
}

// Function to delete the top node in the stack
template <class T>
bool Stack<T>::pop() {
	if (isEmpty()) {
		return false;
	}

	Node<T>* temp = top;
	top = top->next;

	delete temp;
	return true;
}

// Function to display the top element
template <class T>
bool Stack<T>::peek(T& returnValue) {
	if (isEmpty()) {
		return false;
	}

	returnValue = top->data;
	return true;
}

// Function to return the top element
template <class T>
T Stack<T>::getTop() {
	return top->data;
}

// Function to verify if the stack is empty
template <class T>
bool Stack<T>::isEmpty() {
	return (top == NULL);
}

// Function to display the stack
template <class T>
void Stack<T>::displayStack() {
	if (isEmpty()) {
		cout << "\n-----Stack Underflow Error!-----\n";
		return;
	}

	Node<T>* current = top;

	while (current != nullptr) {
		current->data.display();
		current = current->next;
	}
}

// Function to reset the stack to NULL
template <class T>
void Stack<T>::makeNULL() {
	while (!isEmpty())
		pop();
}

// Destructor resets everything to NULL
template <class T>
Stack<T>::~Stack() {
	makeNULL();
}

template <class T> 
void Stack<T>::copy(const Stack<T>& other) { 
	if (other.top == nullptr) { 
		top = nullptr; return; 
	} 
	
	Node<T>* current = other.top; 
	Node<T>* newTop = new Node<T>(current->data); 
	Node<T>* newCurrent = newTop; 
	
	while (current->next != nullptr) { 
		current = current->next; 
		newCurrent->next = new Node<T>(current->data); 
		newCurrent = newCurrent->next; 
	} 
	top = newTop; 
}

template <class T> 
void Stack<T>::clear() { 
	while (!isEmpty()) { 
		pop(); 
	} 
}

template class Stack<Post>;
template class Stack<Message>;