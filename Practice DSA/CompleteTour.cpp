#include <iostream>
using namespace std;

// Petrol Pump
struct Pump {
	int litres;			// Litre of petrol currently a pump have
	int distance;		// Distance to the next petrol station
	int pump;			// pump number
	Pump* next;			// Pointer to the next pump in the circular list

	// Constructor to initialize pump with litres, distance, and pump number
	Pump(int l, int d, int n) : litres(l), distance(d), pump(n), next(NULL) {}
};

class CircularList {
	Pump* head;			// Head pointer for the circular linked list
	int size;			// Keeps track of the number of pumps in the list

	// Function to calculate the starting pump for a successful round trip
	Pump* calculateStartPoint(Pump* head) {
		Pump* temp = head;

		do {
			int petrol = temp->litres;
			int distance = temp->distance;

			// Case 1: Not enough petrol to reach the next station
			if (distance > petrol) {
				temp = temp->next;		// Move to the next pump
				continue;
			}

			// Case 2: Enough petrol to reach the next station and possibly start the tour
			else if (petrol > distance) {
				petrol += temp->next->litres;
				distance += temp->next->distance;

				if (petrol > distance)
					return temp;

				temp = temp->next;
				continue;
			}
		} while (temp != head);
		
		return head;
	}

public:
	// Constructor to initialize an empty circular linked list
	CircularList() : head(NULL), size(0) {}

	// Function to insert a new pump into the circular list
	void insertPump(int litres, int distance) {
		Pump* newNode = new Pump(litres, distance, ++size);
		if (head == nullptr) {
			head = newNode;
			head->next = head;
			return;
		}

		Pump* temp = head;
		while (temp->next != head)
			temp = temp->next;

		temp->next = newNode;
		newNode->next = head;
	}

	// Function to calculate and display the truck's complete tour
	void completeTour() {
		Pump* start = calculateStartPoint(head);
		Pump* current = start;
		int petrol = 0, distance = 0;

		cout << "\nTruck starting point must be at pump " << start->pump << " for the roundtrip.\n";

		do {
			petrol += current->litres;
			distance = current->distance;
			cout << "\n->Tuck Currently at Pump " << current->pump << ": Fuel in tank " << petrol << " litres. Next Station in " << distance << " km.";

			petrol -= distance;

			if (petrol < 0) {
				cout << "\n<-----TRUCK OUT OF FUEL!----->" << endl;
				return;
			}

			current = current->next;
		} while (current != start);

		cout << "\n->Tuck Currently at Pump " << current->pump << ": Fuel in tank " << petrol << " litres.\n"
			<< "\n<-----ROUND TOUR COMPLETE!----->\n" << endl;
	}

	// Function to display the list of pumps and their details
	void displayList() {
		Pump* current = head;
		
		cout << "Petrol Stations along the journey:\n"
			<< "------------------------\n"
			<< "Pump\tLitres\tDistance\n"
			<< "------------------------\n";
		do {
			cout << " " << current->pump << "\t  " << current->litres << "\t   " << current->distance << endl;
			current = current->next;
		} while (current != head);
	}

};

int main() {
	CircularList list;

	// Insert pumps into the circular list
	list.insertPump(3, 5);
	list.insertPump(4, 2);		
	list.insertPump(6, 3);
	list.insertPump(2, 4);

	list.displayList();			// Display the list of pumps
	list.completeTour();		// Calculate and display the complete tour

	system("pause");
	return 0;
}