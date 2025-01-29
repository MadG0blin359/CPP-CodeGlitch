#include <iostream>
using namespace std;

// Abstract class
class StackADT {
public:
	virtual void initializeStack() = 0;
	virtual bool isEmptyStack() const = 0;
	virtual bool isFullStack() const = 0;
	virtual void push(int element) = 0;
	virtual int top() const = 0;
	virtual void pop() = 0;
	virtual void reverseStack() = 0;
	virtual ~StackADT() {}
};

class Stack : public StackADT {
private:
	static const int MAX_SIZE = 10;
	int* stack;
	int topIndex;
public:
	Stack() : topIndex(-1) {
		stack = new int[MAX_SIZE];
	}

	void initializeStack() override {
		topIndex = -1;
	}

	bool isEmptyStack() const override {
		return (topIndex == -1);
	}

	bool isFullStack() const override {
		return (topIndex == MAX_SIZE - 1);
	}

	void push(int element) override {
		if (isFullStack()) {
			cout << "\n-----Stack is Full! Cannot push " << element << "-----\n" << endl;
			return;
		}
		stack[++topIndex] = element;
	}

	int top() const override {
		if (isEmptyStack()) {
			cout << "\n-----Stack is Empty! No Top Element Found-----\n" << endl;
			return -1;
		}
		return stack[topIndex];
	}

	void pop() override {
		if (isEmptyStack()) {
			cout << "\n-----Stack is Empty! No Element Found-----\n" << endl;
			return;
		}
		--topIndex;
	}

	void reverseStack() override {
		Stack tempStack; // Initialize the temporary stack

						 // Transfer all elements from the original stack to the temporary stack
		while (!isEmptyStack()) {
			int element = top(); // Get the top element
			pop();              // Remove it from the original stack
			tempStack.push(element); // Push it onto the temporary stack
		}

		// Transfer all elements back from the temporary stack to the original stack
		while (!tempStack.isEmptyStack()) {
			int element = tempStack.top(); // Get the top element from the temporary stack
			tempStack.pop();              // Remove it from the temporary stack
			push(element);               // Push it back onto the original stack
		}
	}

	// Function to print stack contents
	void printStack() const {
		cout << "Stack : ";
		for (int i = topIndex; i >= 0; --i) {
			cout << stack[i] << " ";
		}
		cout << endl;
	}

	// Deallocating memory
	~Stack() {
		delete[] stack;
	}
};

int main() {
	Stack myStack;

	myStack.initializeStack();
	cout << "Stack initialized.\n";

	myStack.push(1);
	myStack.push(2);
	myStack.push(3);
	myStack.push(4);
	myStack.push(5);

	cout << "\nOriginal stack: " << endl;
	myStack.printStack();

	myStack.reverseStack();

	cout << "\nReversed stack: " << endl;
	myStack.printStack();

	system("pause");
	return 0;
}
