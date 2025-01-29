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
			return -1; // Sentinel value to indicate empty stack
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

	// Deallocating memory
	~Stack() {
		delete[] stack;
	}
};

int main() {
	Stack myStack;

	myStack.initializeStack();
	cout << "Stack initialized.\n";

	myStack.push(10);
	myStack.push(20);
	myStack.push(30);

	cout << "Top element: " << myStack.top() << endl; // Should print 30

	myStack.pop();
	cout << "Top element after pop: " << myStack.top() << endl; // Should print 20

	if (myStack.isFullStack()) {
		cout << "Stack is full.\n";
	}
	else {
		cout << "Stack is not full.\n";
	}

	if (myStack.isEmptyStack()) {
		cout << "Stack is empty.\n";
	}
	else {
		cout << "Stack is not empty.\n";
	}

	system("pause");
	return 0;
}
