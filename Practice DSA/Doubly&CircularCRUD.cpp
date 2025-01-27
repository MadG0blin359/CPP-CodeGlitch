//#include <iostream>
//using namespace std;
//
//class Node {
//public:
//	Node* prev, *next;
//	int data;
//
//	Node(int d) : data(d), prev(NULL), next(NULL) {}
//};
//
//// Doubly Linked List
//class DoublyList {
//	Node* head;
//public:
//	DoublyList() : head(NULL) {}
//
//	void insertNodeAtBeginning(int data);				// O(1)
//	void insertNodeInMiddle(int data, int key);			// O(n)
//	void insertNodeAtEnd(int data);						// O(n)
//	bool deleteFirstNode();								// O(1)
//	bool deleteNode(int key);							// O(n)
//	bool deleteLastNode();								// O(n)
//	void display();										// O(n)
//	bool search(int data);								// O(n)
//};
//
//// Circular Singly Linked List
//class CircularList {
//	Node* head;
//public:
//	CircularList() : head(NULL) {}
//
//	void insertNodeAtBeginning(int data);				// O(1)
//	void insertNodeInMiddle(int data, int key);			// O(n)
//	void insertNodeAtEnd(int data);						// O(n)
//	bool deleteFirstNode();								// O(n)
//	bool deleteNode(int key);							// O(n)
//	bool deleteLastNode();								// O(n)
//	void display();										// O(n)
//	bool search(int data);								// O(n)
//};
//
//// Function to insert a new node at the beginning of the doubly linked list
//void DoublyList::insertNodeAtBeginning(int data) {
//	Node* newNode = new Node(data);
//	if (head == NULL) {
//		head = newNode;
//		cout << "\n-----First Node Created Successfully!-----\n";
//		return;
//	}
//
//	// If head not empty, new node added
//	head->prev = newNode;
//	newNode->next = head;
//	head = newNode;
//
//	cout << "\n-----New Node Inserted Successfully!-----\n";
//}
//
//// Function to find a node whose data member matches the provided key
//void DoublyList::insertNodeInMiddle(int data, int key) {
//	if (head == NULL) {
//		cout << "\n-----List is Empty! Key Cannot Be Found-----\n";
//		return;
//	}
//
//	Node* current = head;
//	
//	// Find and compare the data with key
//	while (current != NULL) {
//		if (current->data == key) {
//			Node* newNode = new Node(data);
//			newNode->next = current->next;
//			newNode->prev = current;
//			current->next->prev = newNode;
//			current->next = newNode;
//
//			cout << "\n-----Key Found! New Node Inserted-----\n";
//			
//			return;
//		}
//		current = current->next;
//	}
//	cout << "\n-----Key Does Not Exist! New Node Not Inserted-----\n";
//}
//
//// Function to insert a new node at the end of the doubly linked list
//void DoublyList::insertNodeAtEnd(int data) {
//	// If the list is empty, insert at the beginning
//	if (head == NULL) {
//		insertNodeAtBeginning(data);
//		return;
//	}
//
//	// If the list is not empty, traverse the list to the end
//	Node* current = head;
//
//	while (current->next != NULL) {
//		current = current->next;
//	}
//
//	// Add a new node at the end of the list
//	Node* newNode = new Node(data);
//	current->next = newNode;
//	newNode->prev = current;
//
//	cout << "\n-----New Node Inserted At End Successfully!-----\n";
//
//}
//
//// Function to delete first node in the doubly linked list
//bool DoublyList::deleteFirstNode() {
//	if (head == NULL) {
//		cout << "\n-----List is Empty! Node Cannot Be Found-----\n";
//		return false;
//	}
//
//	Node* temp = head;
//	head = head->next;
//	head->prev = NULL;
//
//	delete temp;		// Node deleted
//
//	return true;
//}
//
//// Function to delete any node in the doubly list
//bool DoublyList::deleteNode(int key) {
//	if (head == NULL) {
//		cout << "\n-----List is Empty! Node Cannot Be Found-----\n";
//		return false;
//	}
//
//	Node* current = head;
//
//	while (current != NULL) {
//		if (current->data == key) {
//
//			if (current->prev != NULL)
//				current->prev->next = current->next;
//
//			if (current->next != NULL)
//				current->next->prev = current->prev;
//
//			if (current == head) 
//				head = current->next;
//
//			delete current;
//			return true;
//		}
//		current = current->next;
//	}
//	return false;
//}
//
//// Function to delete the last node in the doubly list
//bool DoublyList::deleteLastNode() {
//	if (head == NULL) {
//		cout << "\n-----List is Empty! Node Cannot Be Found-----\n";
//		return false;
//	}
//
//	Node* current = head;
//	while (current->next != NULL) {
//		current = current->next;
//	}
//
//	// When there is only one node
//	if (current == head) 
//		head = current->next;
//
//	else {
//		Node* temp = current->prev;
//		temp->next = NULL;			// Previous node's next is NULL
//	}
//
//	delete current;				// Last node deleted
//	return true;
//}
//
//// Function to display complete doubly linked list data
//void DoublyList::display() {
//	if (head == NULL) {
//		cout << "\n-----List is Empty! Data Cannot Be Found-----\n";
//		return;
//	}
//
//	cout << "\n-----Data List-----\n";
//
//	Node* current = head;
//
//	while (current != NULL) {
//		cout << current->data << "->";
//
//		current = current->next;
//	}
//
//	cout << "NULL" << endl;
//
//}
//
//// Function to search the doubly linked list
//bool DoublyList::search(int data) {
//	if (head == NULL) {
//		cout << "\n-----List is Empty! Data Cannot Be Found-----\n";
//		return false;
//	}
//
//	Node* current = head;
//
//	while (current != NULL) {
//		if (current->data == data) {
//			return true;
//		}
//		current = current->next;
//	}
//	return false;
//}
//
//// Function to insert a new node at the beginning of the circular linked list
//void CircularList::insertNodeAtBeginning(int data) {
//	Node* newNode = new Node(data);
//
//	if (head == NULL) {
//		head = newNode;
//		newNode->next = head;
//		cout << "\n-----First Node Created Successfully!-----\n";
//		return;
//	}
//
//	Node* current = head;
//
//	while (current->next != head) {
//		current = current->next;
//	}
//
//	current->next = newNode;
//	newNode->next = head;
//	head = newNode;
//
//	cout << "\n-----New Node Inserted Successfully!-----\n";
//
//}
//
//// Function to find a node whose data member matches the provided key
//void CircularList::insertNodeInMiddle(int data, int key) {
//	if (head == NULL) {
//		cout << "\n-----List is Empty! Key Cannot Be Found-----\n";
//		return;
//	}
//
//	Node* current = head;
//
//	 do {
//		if (current->data == key) {
//			Node* newNode = new Node(data);
//			newNode->next = current->next;
//			current->next = newNode;
//
//			cout << "\n-----Key Found! New Node Inserted-----\n";
//
//			return;
//		}
//		current = current->next;
//	 } while (current != head);
//
//	 cout << "\n-----Key Does Not Exist! New Node Not Inserted-----\n";
//
//}
//
//// Function to insert a new node at the end of the circular linked list
//void CircularList::insertNodeAtEnd(int data) {
//	Node* newNode = new Node(data);
//
//	if (head == NULL) {
//		insertNodeAtBeginning(data);
//		return;
//	}
//
//	Node* current = head;
//
//	do {
//		current = current->next;
//	} while (current->next != head);
//
//	newNode->next = head;
//	current->next = newNode;
//
//	cout << "\n-----New Node Inserted At End Successfully!-----\n";
//
//}
//
//// Function to delete first node in the circular linked list
//bool CircularList::deleteFirstNode() {
//	if (head == NULL) {
//		cout << "\n-----List is Empty! Node Cannot Be Found-----\n";
//		return false;
//	}
//
//	// When there is only one node
//	else if (head->next == head) {
//		delete head;
//		head = NULL;
//		return true;
//	}
//
//	Node* temp = head;
//	Node* current = head;
//
//	do {
//		current = current->next;
//	} while (current->next != head);
//
//
//	head = head->next;
//
//	// Where there are only two nodes
//	if (current == head) {
//		delete temp;
//		current->next = head;
//		return true;
//	}
//
//	// Where there are n number of nodes
//	current->next = head;
//
//	delete temp;
//	return true;
//	
//}
//
//// Function to delete any node in the circular list
//bool CircularList::deleteNode(int key) {
//	if (head == NULL) {
//		cout << "\n-----List is Empty! Node Cannot Be Found-----\n";
//		return false;
//	}
//
//	// When there is only one node
//	if (head->data == key && head->next == NULL) {
//		delete head;
//		head = NULL;
//		return true;
//	}
//
//	Node* current = head;
//
//	// When key matches with head (first node)
//	if (current->data == key) {
//		if (deleteFirstNode())
//			return true;
//		else
//			return false;
//	}
//
//	// Where there are n number of nodes
//	Node* temp = NULL;
//	Node* prev = NULL;
//
//	do {
//		if (current->data == key) {
//			break;
//		}
//		prev = current;
//		current = current->next;
//	} while (current != head);
//
//	// When its the last node
//	if (current->next == head) {
//		if (deleteLastNode())
//			return true;
//		else
//			return false;
//	}
//
//	// When its any other node in the middle
//	else {
//		prev->next = current->next;
//		delete current;
//		return true;
//	}
//
//	return false;
//}
//
//// Function to delete the last node in the circular list
//bool CircularList::deleteLastNode() {
//	// When the list is empty
//	if (head == NULL) {
//		cout << "\n-----List is Empty! Node Cannot Be Found-----\n";
//		return false;
//	}
//
//	// When there is only one node
//	else if (head->next == head) {
//		delete head;
//		head = NULL;
//		return true;
//	}
//
//	// When there are n number of nodes
//	Node* current = head;
//	Node* prev = NULL;
//
//	do {
//		prev = current;
//		current = current->next;
//	} while (current->next != head);
//
//	prev->next = head;
//	delete current;
//	return true;
//}
//
//// Function to display complete circular linked list data
//void CircularList::display() {
//	if (head == NULL) {
//		cout << "\n-----List is Empty! Data Cannot Be Found-----\n";
//		return;
//	}
//
//	cout << "\n-----Data List-----\n";
//
//	Node* current = head;
//
//	do {
//		cout << current->data << "->";
//		current = current->next;
//	} while (current != head);
//
//	cout << "HEAD" << endl;
//
//}
//
//// Function to search the circular linked list
//bool CircularList::search(int data) {
//	if (head == NULL) {
//		cout << "\n-----List is Empty! Data Cannot Be Found-----\n";
//		return false;
//	}
//
//	Node* current = head;
//
//	do {
//		if (current->data == data) {
//			return true;
//		}
//		current = current->next;
//	} while (current->next != head);
//
//	return false;
//}
//
//// Menu based main function to demonstrate both Doubly List and Circular List
//int main() {
//
//	DoublyList list;
//	CircularList list2;
//	char choice;
//	int data, key;
//
//	do {
//		cout << "\n-----Linked Lists-----"
//			<< "\n1. Doubly Linked List"
//			<< "\n2. Circular Linked List"
//			<< "\n3. Exit"
//			<< "\n--Enter choice (1-3) : ";
//		cin >> choice;
//
//		switch (choice)
//		{
//		case '1':
//			do {		// Interactive Menu
//				cout << "\n\t-----Doubly Node Menu-----"
//					<< "\n1. Insert at Beginning"
//					<< "\n2. Insert in Middle"
//					<< "\n3. Insert at End"
//					<< "\n4. Delete First Node"
//					<< "\n5. Delete any Node"
//					<< "\n6. Delete Last Node"
//					<< "\n7. Display Nodes"
//					<< "\n8. Search Nodes"
//					<< "\n9. Go Back"
//					<< "\n--Enter choice (1-9) : ";
//				cin >> choice;
//
//				// Calling functions according to the user choice
//				switch (choice)
//				{
//				case '1':
//					cout << "\n-----Adding a Node at Beginning-----\n"
//						<< "--Enter Data : ";
//					cin >> data;
//					list.insertNodeAtBeginning(data);
//					break;
//
//				case '2':
//					cout << "\n-----Adding a Node in Middle-----\n"
//						<< "--Enter Data : ";
//					cin >> data;
//
//					cout << "--Enter Key : ";
//					cin >> key;
//
//					list.insertNodeInMiddle(data, key);
//					break;
//
//				case '3':
//					cout << "\n-----Adding a Node at End-----\n"
//						<< "--Enter Data : ";
//					cin >> data;
//
//					list.insertNodeAtEnd(data);
//					break;
//
//				case '4':
//					cout << "\n-----Deleting First Node-----\n";
//					if (list.deleteFirstNode()) {
//						cout << "\n-----First Node Deleted Successfully!-----\n";
//					}
//
//					break;
//
//				case '5':
//					cout << "\n-----Deleting a Node-----\n"
//						<< "--Enter Key : ";
//					cin >> key;
//
//					if (list.deleteNode(key)) {
//						cout << "\n-----Key Found! Node Deleted Successfully-----\n";
//					}
//
//					else {
//						cout << "\n-----Key Not Found! Data Does Not Exist!-----\n";
//					}
//
//					break;
//
//				case '6':
//					cout << "\n-----Deleting Last Node-----\n";
//					if (list.deleteLastNode()) {
//						cout << "\n-----Last Node Deleted Successfully!-----\n";
//					}
//					break;
//
//				case '7':
//					cout << "\n-----Doubly Linked List Nodes-----\n";
//					list.display();
//					break;
//
//				case '8':
//					cout << "\n-----Searching Node-----\n"
//						<< "--Enter Data : ";
//					cin >> data;
//
//					if (list.search(data)) {
//						cout << "\n-----Data " << data << " Found!-----\n";
//					}
//
//					else {
//						cout << "\n-----Data Does Not Exist!-----\n";
//					}
//					break;
//
//				case '9':
//					cout << "\n-----Going Back to the Linked List Menu-----\n";
//					break;
//
//				default:
//					cout << "\n-----Invalid Input!-----\n";
//					break;
//				}
//			} while (choice != '9');
//			break;
//
//		case '2':
//			do {		// Interactive Menu
//				cout << "\n\t-----Circular Node Menu-----"
//					<< "\n1. Insert at Beginning"
//					<< "\n2. Insert in Middle"
//					<< "\n3. Insert at End"
//					<< "\n4. Delete First Node"
//					<< "\n5. Delete any Node"
//					<< "\n6. Delete Last Node"
//					<< "\n7. Display Nodes"
//					<< "\n8. Search Nodes"
//					<< "\n9. Go Back"
//					<< "\n--Enter choice (1-9) : ";
//				cin >> choice;
//
//				// Calling functions according to the user choice
//				switch (choice)
//				{
//				case '1':
//					cout << "\n-----Adding a Node at Beginning-----\n"
//						<< "--Enter Data : ";
//					cin >> data;
//					list2.insertNodeAtBeginning(data);
//					break;
//
//				case '2':
//					cout << "\n-----Adding a Node in Middle-----\n"
//						<< "--Enter Data : ";
//					cin >> data;
//
//					cout << "--Enter Key : ";
//					cin >> key;
//
//					list2.insertNodeInMiddle(data, key);
//					break;
//
//				case '3':
//					cout << "\n-----Adding a Node at End-----\n"
//						<< "--Enter Data : ";
//					cin >> data;
//
//					list2.insertNodeAtEnd(data);
//					break;
//
//				case '4':
//					cout << "\n-----Deleting First Node-----\n";
//					if (list2.deleteFirstNode()) {
//						cout << "\n-----First Node Deleted Successfully!-----\n";
//					}
//
//					break;
//
//				case '5':
//					cout << "\n-----Deleting a Node-----\n"
//						<< "--Enter Key : ";
//					cin >> key;
//
//					if (list2.deleteNode(key)) {
//						cout << "\n-----Key Found! Node Deleted Successfully-----\n";
//					}
//
//					else {
//						cout << "\n-----Key Not Found! Data Does Not Exist!-----\n";
//					}
//
//					break;
//
//				case '6':
//					cout << "\n-----Deleting Last Node-----\n";
//					if (list2.deleteLastNode()) {
//						cout << "\n-----Last Node Deleted Successfully!-----\n";
//					}
//					break;
//
//				case '7':
//					cout << "\n-----Circular Linked List Nodes-----\n";
//					list2.display();
//					break;
//
//				case '8':
//					cout << "\n-----Searching Node-----\n"
//						<< "--Enter Data : ";
//					cin >> data;
//
//					if (list2.search(data)) {
//						cout << "\n-----Data " << data << " Found!-----\n";
//					}
//
//					else {
//						cout << "\n-----Data Does Not Exist!-----\n";
//					}
//					break;
//
//				case '9':
//					cout << "\n-----Going Back to the Linked List Menu-----\n";
//					break;
//
//				default:
//					cout << "\n-----Invalid Input!-----\n";
//					break;
//				}
//			} while (choice != '9');
//			break;
//
//		case '3':
//			cout << "\n-----Program Terminated-----\n";
//			break;
//
//		default:
//			break;
//		}
//	} while (choice != '3');
//
//
//	system("pause");
//	return 0;
//}