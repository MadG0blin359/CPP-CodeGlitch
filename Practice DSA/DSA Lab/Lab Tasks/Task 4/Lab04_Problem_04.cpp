#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
	int data;
	Node* next;

	Node(int value) : data(value), next(nullptr) {}
};

// Stack class using a linked list
class Stack {
private:
	Node* top; // Pointer to the top of the stack

public:
	Stack() : top(nullptr) {}

	// Push an element onto the stack
	void Push(int element) {
		Node* newNode = new Node(element);
		newNode->next = top;
		top = newNode;
		cout << "Pushed " << element << " onto the stack." << endl;
	}

	// Pop the top element from the stack
	void Pop() {
		if (IsEmpty()) {
			cout << "Stack is empty. Nothing to pop." << endl;
			return;
		}
		Node* temp = top;
		top = top->next;
		cout << "Popped " << temp->data << " from the stack." << endl;
		delete temp;
	}

	// Display the stack
	void Display_stack() const {
		if (IsEmpty()) {
			cout << "Stack is empty." << endl;
			return;
		}
		Node* current = top;
		cout << "Stack contents: ";
		while (current != nullptr) {
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}

	// Reverse the stack without recursion
	void Reverse_stack() {
		Node* prev = nullptr;
		Node* current = top;
		Node* next = nullptr;
		while (current != nullptr) {
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		top = prev;
		cout << "Stack reversed." << endl;
	}

	// Check if the stack is empty
	bool IsEmpty() const {
		return top == nullptr;
	}

	// Destructor to clean up memory
	~Stack() {
		while (!IsEmpty()) {
			Pop();
		}
	}
};

int main() {
	Stack myStack;

	// Push elements onto the stack
	myStack.Push(10);
	myStack.Push(20);
	myStack.Push(30);
	myStack.Push(40);
	myStack.Push(50);

	// Display the stack
	cout << "Original ";
	myStack.Display_stack();

	// Reverse the stack
	myStack.Reverse_stack();

	// Display the reversed stack
	cout << "Reversed ";
	myStack.Display_stack();

	// Pop elements from the stack
	myStack.Pop();
	myStack.Pop();

	// Display the stack after popping
	cout << "Stack after popping elements: ";
	myStack.Display_stack();

	system("pause");
	return 0;
}
