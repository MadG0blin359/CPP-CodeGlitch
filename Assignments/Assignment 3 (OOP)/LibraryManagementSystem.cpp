#include <iostream>
#include <string>
using namespace std;

class Book {
    string title;
    string author;
    string genre;
    bool status;

    public:

    Book() {}

    // Setters
    void setTitle(string book_title) {
        title = book_title;
    }

    void setAuthor(string book_author) {
        author = book_author;
    }

    void setGenre(string book_genre) {
        genre = book_genre;
    }

    void setStatus(bool book_status) {
        status = book_status;
    }

    // Getters
    string getTitle() {
        return title;
    }

    // string getAuthor() {
    //     return author;
    // }
    
    string getGenre() {
        return genre;
    }

    bool getStatus() {
        return status;
    }
};

class Library {
    private:
    static const int capacity = 50;    // Capacity of the BookArray (The total capacity of the library)
    static int count;       // Count books and work as a size variable (Total books) for the dynamic array
    Book **BookArray;       // Declaring a pointer to pointer

    public:
    // Default constructor
    Library() {
        BookArray = new Book*[capacity];           // Dynamic array of Book pointers with capacity 50
        count = 0;              // Initializing the count variable
    }

    // Function to add books
    void addBook(string book_title, string book_author, string book_genre, bool book_status) {
        // *BookArray = new Book;
        BookArray[count] = new Book;
        
        BookArray[count]->setTitle(book_title);     // Dereferencing once to get to the element of the pointer array, a pointer stored in the array
        BookArray[count]->setAuthor(book_author);
        BookArray[count]->setGenre(book_genre);
        BookArray[count]->setStatus(book_status);

        count++;
    }

    // Function to display available book with a specific genre
    void displayBooks(string book_genre) {
        cout << "\nTotal Books in the Library System : " << count << "\n"
             << "\n-----Available Books in " << book_genre << "-----";
        for (int i = 0; i < count; i++) {
            if (BookArray[i]->getGenre() == book_genre) {
                if (BookArray[i]->getStatus() == 1) {
                    cout << "\n->Title : " << BookArray[i]->getTitle();
                }
            }
        }
    }

    // Destructor
    ~Library() {

        // Deallocate memory for each Book object
        for (int i = 0; i < capacity; i++) {
            delete BookArray[i];
        }

        delete[] BookArray;     // Deallocating the dynamic array of Book pointers
    }

};

int Library::count = 0;

int main() {

    Library library;
    string book_title, book_author, book_genre;
    bool book_status;
    char choice;

    cout << "\n\t\t-----Welcome to Library Management System-----\n\n";

    // Loop to add as much book as the user wants
    do {

        cout << "\n\t-----Add a Book-----";
        cout << "\n------------------------------------\n";

        cout << "--Enter book title : ";
        getline(cin, book_title);

        cout << "--Enter book author : ";
        getline(cin, book_author);
        
        cout << "--Enter book genre : ";
        getline(cin, book_genre);

        cout << "\n--Is the book available? (1 for yes, 0 for no) : ";
        cin >> book_status;
        cout << "\n\t-----Book added successfully!-----\n";
    
        library.addBook(book_title, book_author, book_genre, book_status);

        cout << "\n--Do you want to add another book? (y/n) : ";
        cin >> choice;
        cin.ignore();           // Using ignore function to clear the input buffer after using cin function

        if (choice != 'n' && choice != 'N' && choice != 'y' && choice != 'Y')
            cout << "\n\t-----Invlaid Input!-----\n";

    }

    while (choice != 'n' && choice != 'N');

    cout << "\n--Enter the genre to display available books : ";
    cin >> book_genre;      // Reusing the genre variable to look for specific books

    library.displayBooks(book_genre);

    return 0;
}