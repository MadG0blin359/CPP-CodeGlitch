#include <iostream>
#include <string>
using namespace std;

class Node {
protected:
	Node* next;
	string title, artist;

public:
	Node(string t = "NULL", string a = "NULL") : title(t), artist(a), next(NULL) {}

	friend class List;
};

class List {
	Node* head = NULL;
	int max_songs = 50;
public:
	void addSong();
	void removeSong();
	void displayPlaylist();
};

// Function to add a song at a specified position
void List::addSong() {
	char choice;
	string t, a;
	int position = 0;

	do {
		cout << "--Enter Song Title : ";
		cin.ignore();
		getline(cin, t);

		cout << "--Enter Song Artist : ";
		getline(cin, a);

		Node* newSong = new Node(t, a);

		// If the playlist is empty, add the first song
		if (head == NULL) {
			head = newSong;
			cout << "\nFirst Song Added in the Playlist.\n";
		}
		else {
			// Prompt user to enter the position for adding the song
			int user_position;
			do {
				cout << "\n--Enter Position to add the song (1-" << max_songs << "): ";
				cin >> user_position;

				if (user_position < 1 || user_position > max_songs) {
					cout << "\n-----Invalid Input! Please enter a valid position.-----\n";
				}
			} while (user_position < 1 || user_position > max_songs);

			// Case: Adding the song at the first position (head)
			if (user_position == 1) {
				newSong->next = head;
				head = newSong;
			}

			else {
				// Case: Adding the song at a position other than the first
				Node* current = head;
				for (int i = 1; i < user_position - 1 && current->next != NULL; i++) {
					current = current->next;
				}

				// Insert the new song at the desired position
				newSong->next = current->next;
				current->next = newSong;
			}

			cout << "\nSong Added to Playlist.\n";
		}

		// Ask the user if they want to add more songs
		do {
			cout << "\nAdd more songs? (Y/N) : ";
			cin >> choice;

			if (choice != 'N' && choice != 'n' && choice != 'Y' && choice != 'y') {
				cout << "\n-----Invalid Input!-----\n";
			}
		} while (choice != 'N' && choice != 'n' && choice != 'Y' && choice != 'y');
	} while (choice == 'Y' || choice == 'y');
}

// Function to remove a song from a specific position
void List::removeSong() {
	if (head == NULL) {
		cout << "\n-----Playlist is Empty! No Songs to Remove.-----\n";
		return;
	}

	int user_position;
	cout << "\n--Enter Position to remove the song: ";
	cin >> user_position;

	// Case: Remove the first song
	if (user_position == 1) {
		head = head->next;
		cout << "\nFirst Song Removed.\n";
	}
	else {
		Node* current = head;
		for (int i = 1; i < user_position - 1 && current->next != NULL; i++) {
			current = current->next;
		}

		if (current->next == NULL) {
			cout << "\n-----Invalid Position!-----\n";
		}
		else {
			Node* temp = current->next;
			current->next = temp->next;
			delete temp;
			cout << "\nSong Removed from Playlist.\n";
		}
	}
}


void List::displayPlaylist() {
	Node* current = head;

	if (head == NULL) {
		cout << "\nPlaylist is Empty! No Songs Found.\n" << endl;
		return;
	}

	for (int i = 1; current != NULL; i++) {
		cout << "\n" << i << ". Title : " << current->title
			<< "\nArtist : " << current->artist << "\n\n";
		current = current->next;
	}

	cout << endl;
}

int main() {
	List songs;
	char choice;

	do {
		cout << "\n\t-----My Playlist-----"
			<< "\n1. Add Songs"
			<< "\n2. Remove Songs"
			<< "\n3. Display Playlist"
			<< "\n4. Exit"
			<< "\n--Enter choice: ";
		cin >> choice;

		switch (choice)
		{
		case '1':
			cout << "\n-----Add Songs-----\n";
			songs.addSong();
			break;
		case '2':
			cout << "\n-----Remove Songs-----\n";
			songs.removeSong();
			break;
		case '3':
			cout << "\n-----My Playlist-----\n";
			songs.displayPlaylist();
			break;
		case '4':
			cout << "\n-----Have a Nice Day!-----\n";
			break;
		default:
			cout << "\n-----Invalid Input!-----\n";
			break;
		}
	}

	while (choice != '4');

	system("pause");
	return 0;
}