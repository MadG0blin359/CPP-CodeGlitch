#include<iostream>
using namespace std;
struct myList {
	int data;
	myList* next;
};
int main() {
	myList* head;
	myList* cur;
	myList* previous = NULL;
	for (int i = 0; i < 4; i++) {
		head = new myList;
		head->data = 0;
		head->next = previous;
		for (cur = previous; cur != NULL; cur = cur->next)
			head->data += 1 + 2 * cur->data;
		previous = head;
	}
	while (previous != NULL) {
		cout << previous->data << endl;
		cur = previous;
		previous = previous->next;
		delete cur;
	}
	system("pause");
	return 0;
}