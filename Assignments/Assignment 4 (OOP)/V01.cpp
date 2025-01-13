#include <iostream>
#include <string>
using namespace std;

int const max_books = 5;            // Max capacity for the list of books written by an author and borrowed by a library member

// Class to manage books
class Book {
    string title, author, isbn;     // Book name, author, and isbn
    bool status;                    // Book availability status
    int day, month, year;           // Vairables to track due date

    public:
    Book() : title(""), author(""), isbn("") {}

    // Getters
    string getTitle() {
        return title;
    }

    string getAuthor() {
        return author;
    }

    string getISBN() {
        return isbn;
    }

    bool getStatus() {
        return status;
    }

    int getDay() {
        return day;
    }

    int getMonth() {
        return month;
    }

    int getYear() {
        return year;
    }

    // Setters
    void setTitle(string bTitle) {
        title = bTitle;
    }

    void setAuthor(string bAuthor) {
        author = bAuthor;
    }

    void setISBN(string bIsbn) {
        isbn = bIsbn;
    }

    void setStatus(bool bStatus) {
        status = bStatus;
    }

    void setDueDate() {
        cout << "\n-----Due Date-----\n";
        
        do {
            cout << "--Day (1-31) : ";
            cin >> day;

            if (day < 1 || day > 31)
                cout << "\n\t-----Invlaid Input!-----\n";
        }
        // Condition to handle invalid inputs for day
        while (day < 1 || day > 31);

        do {
            cout << "--Month (1-12) : ";
            cin >> month;
        
            if (month < 1 || month > 12)
                cout << "\n\t-----Invlaid Input!-----\n";
        }
        // Condition to handle invalid inputs for month
        while (month < 1 || month > 12);

        do {
            cout << "--Year : ";
            cin >> year;
        
            if (year < 2024)
                cout << "\n\t-----Invlaid Input!-----\n";
        }
        // Condition to handle invalid inputs for year
        while (year < 2024 || year > 2025);     // Max one year allowed
    }
};

// Class to manage authors
class Author {
    string author_name, written_books[max_books];      // Author name and the list of books they have written

    public:
    Author() : author_name("") {}

    // Getters
    string getAuthorName() {
        return author_name;
    }

    string* getWrittenBooks() {
        return written_books;               // Returns a pointer to the first element
    }

    // Setters
    void setAuthorName() {
        cout << "--Author Name : ";
        getline(cin, author_name);
    }

    void setWrittenBooks() {
        cin.ignore();           // Clear the input buffer before using getline function
        char choice;
        for (int i = 0; i < max_books ; i++) {
            cout << "\n-----Book " << i + 1 << "-----\n";
            cout << "--Title : ";
            getline(cin, written_books[i]);

            // Handling choice invalid inputs
            do {
                cout << "\n--Do you want to add another book? (y/n) : ";
                cin >> choice;

                if (choice != 'n' && choice != 'N' && choice != 'y' && choice != 'Y')
                    cout << "\n\t-----Invlaid Input!-----\n";
            }
            
            while (choice != 'n' || choice != 'N');

            if (choice == 'n' || choice == 'N')
                break;
        }
    }
};

// Class to manage Library Members
class LibraryMember {
    string member_name, borrowed_books[max_books];
    double late_fee;

    public:
    LibraryMember() : member_name("") {}

    // Getters
    string getName() {
        return member_name;
    }

    string* getBorrowedBooks() {
        return borrowed_books;      // Returns a pointer to the first element
    }

    double getLateFee() {
        return late_fee;
    }

    // Setters
    void setName() {
        cout << "--Name : ";
        cin.ignore();
        getline(cin, member_name);
    }

    // void setBorrowedBooks() {

    // }

    void setLateFee() {
        cout << "--Late Fee : ";
        cin >> late_fee;
    }
};

// Class to manage Librarian
class Librarian {
    string librarian_name, login_username, login_password;      // Variables to store administrative credentials
};

// Class to perform all tasks
class Library {
    // Aggregation
    Book *books;
    Author *authors;
    LibraryMember *members;
    // Composition
    Librarian administrator;
    // Private in-class variables
    int const capacity;         // Max capacity in the library to store books, authors & max number of members of library
    int track_books;              // Count/Track the total books in the library
    int track_authors;              // Count/Track the total authors in the library
    int track_members;              // Count/Track the total members in the library

    public:
    // Default constructor to initialize various types of private variables
    Library() : capacity(50), track_books(0), track_authors(0), track_members(0) {
        books = new Book[capacity]; 
        authors = new Author[capacity];
        members = new LibraryMember[capacity];
    }

    // Function declarations
    void addBook();
    void addAuthor();
    void registerNewMember();
    int verfiyMembership(string);
    // Function overloading for searching book
    int searchBook(string, bool);
    int searchBook(string);
    friend void borrowBooks(Library &, string);      // Declaration of friend function to borrow books 
    friend void returnBooks(Library &, string);      // Declaration of friend function to return books 

    // Destructor to deallocate memory for the pointers
    ~Library() {
        delete[] books, authors, members;
    }
};

// Function to add a book in the library
void Library::addBook() {
    string bTitle, bAuthor, bIsbn;
    bool bStatus;
    bool found = 0;
    // Condition to look for an empty element in the array after removing a specific book from the library
    for (int i = 0; i < capacity; i++) {
        if (books[i].getTitle() == "") {
            track_books = i;
            found = true;
            break;
        }
    }
    // if found true
    if (found) {
        cout << "\n-------------------------\n"
                << "--------Book " << track_books + 1 << "---------\n"
                << "-------------------------\n";

        // Get the title of the book
        cout << "--Title : ";
        cin.ignore();           // Clear the input buffer before using getline function
        getline(cin, bTitle);
    

        // Get the author of the book
        cout << "--Author : ";
        getline(cin, bAuthor);
    

        // Get the isbn of the book
        cout << "--ISBN : ";
        getline(cin, bIsbn);
    

        // Get the status of the book
        cout << "\n--Is the book available? (1 for yes, 0 for no) : ";
        cin >> bStatus;
        cout << "\n\t-----Book added successfully!-----\n";
    
        books[track_books].setTitle(bTitle);
        books[track_books].setAuthor(bAuthor);
        books[track_books].setISBN(bIsbn);
        books[track_books].setStatus(bStatus);

        track_books++;        // Incremenet the track_books variable
    }

    else {
        cout << "\n\t-----Max " << capacity << " Books Limit Reached!-----\n";
    }
}

// Function to add an author in the library
void Library::addAuthor() {
    bool found = 0;
    // Condition to look for an empty element in the array after removing a specific author from the library
    for (int i = 0; i < capacity; i++) {
        if (authors[i].getAuthorName() == "") {
            track_authors = i;
            found = true;
            break;
        }
    }
    // if found true
    if (found) {
        cout << "-------------------------\n"
            << "-----Author " << track_authors + 1 <<"-----\n"
            << "-------------------------\n";

        authors[track_authors].setAuthorName();
        authors[track_authors].setWrittenBooks();

        track_authors++;    // Incremenet the track_authors variable
    }

    else {
        cout << "\n\t-----Max " << capacity << " Authors Limit Reached!-----\n";
    }
}

// Function to register new library members 
void Library::registerNewMember() {
    bool found = 0;
    // Condition to look for an empty element in the array after removing a specific member from the library
    for (int i = 0; i < capacity; i++) {
        if (members[i].getName() == "") {
            track_members = i;
            found = true;
            break;
        }
    }
    // if found true
    if (found) {
        cout << "\n-------------------------\n"
                << "--------Member " << track_members + 1 <<"---------\n"
            << "-------------------------\n";
    
        members[track_members].setName();
        cout << "\n\t-----Member Registered Successfully!-----\n";

        track_members++;    // Incremenet the track_members variable
    }

    else {
        cout << "\n\t-----Max " << capacity << " Members Limit Reached!-----\n";
    }
}

// Function to determine library membership
int Library::verfiyMembership(string loginName) {
    bool found = 0;
    // Condition to determine whether a person is a member of the library or not
    for (int i = 0; i < capacity; i++) {
        if (members[i].getName() == loginName) {
            cout << "\n-----Signed In Successfully!-----\n";
            track_members = i;              // Setting the track_members variable to the current member using the system
            found = true;
            break;
        }
    }

    if (found) {
        return track_members;       // Returning the index at which the member details are stored
    }

    else {
        cout << "\n-----ID Not Found!-----\n";
        return -1;
    }
}

// Definition of function overloading for searching book
int Library::searchBook(string bTitle, bool bookType) {   // Search by book title, booktype = 0 for borrowing & 1 for returning
    bool found = 0;
    for (int i = 0; i < capacity; i++) {
        if (books[i].getTitle() == bTitle) {
            found = true;
            cout << "\n-----Book Record Found!-----\n";
            track_books = i;

            if (books[track_books].getStatus() == true && bookType == 0) {
                return track_books;         // Returning the index at which the particular book is stored and available
            }

            else if (bookType == 1) {
                return track_books;
            }
            
            break;
        }
    }

    if (found == false) {
        cout << "\n-----Book Record Not Found!-----\n";
        return -1;
    }
}

int Library::searchBook(string bAuthor) {   // Search by book author

}

// Function to borrow books
void borrowBooks(Library &Borrow, string borrowBook) {
    int borrow_index;
    int count_borrowed = 0;
    bool found = 0;

    string *ptr = Borrow.members[Borrow.track_members].getBorrowedBooks();      // Get the address of the member borrowedbooks array

    // Count how many books has the member already borrowed
    for (int i = 0; i < max_books; i++) {
        if (ptr[i] != "") {
            count_borrowed++;
        } 
    }

    // Condition to look for an empty element in the array after removing a specific book from the library
    for (int i = 0; i < max_books; i++) {
        if (ptr[i] == "") {
            cout << "\n-----Borrowing Book " << count_borrowed + 1 << "-----\n";
            Borrow.books[Borrow.track_books].setDueDate();      // Setting due date
            ptr[i] = borrowBook;        // Updating the borrowed book array
            cout << "\n-----Book Borrowed Successfully-----\n";
            found = true;
            Borrow.books[Borrow.track_books].setStatus(false);       // Updating the book status
            break;
        }
    }
    // if found false
    if (found == false) {
        cout << "\n-----Error! Max " << max_books << " Borrowed-----\n";
    }
}

// Function to return borrowed books
void returnBooks(Library &Return, string returnBook) {
    bool found;
    string *ptr = Return.members[Return.track_members].getBorrowedBooks();      // Get the address of the member borrowedbooks array

    for (int i = 0; i < max_books; i++) {
        if (ptr[i] == returnBook) {
            found = true;
            Return.books[Return.track_books].setStatus(true);         // Updating the book status
            ptr[i] = "";
            cout << "\n-----Book Return Successfully!-----\n";
        }
    }

    if (found == false) {
        cout << "\n-----Borrowing Record Not Found!-----\n";
    }
}

int main() {

    Library Nuces;
    // Variables to take user input
    int current_day, current_month, current_year;  
    char menu_choice; 
    int option_choice;
    string name, bTitle;
    int track_members, track_books;

    cout << "\n\t-----Library Management System-----\n";

    do {
        track_members = -1, track_books = -1;       // Variables to keep track when a different user is interacting

        cout << "\n-----Menu-----"
             << "\n1) Librarian"
             << "\n2) Member"
             << "\n3) Exit"
             << "\n--Enter Choice : ";
        cin >> menu_choice;

        if (menu_choice == '1') {
            
        }

        else if (menu_choice == '2') {
            cout << "\n-----Member Sign In-----\n"
                 << "\n--Enter ID Name : ";
            cin.ignore();
            getline(cin, name);

            track_members = Nuces.verfiyMembership(name);       // Getting the index number at which the member details are stored

            if (track_members == -1) {
                continue;           // The member is not found in the library database
            }
        }

        else if (menu_choice != '3') {
            cout << "\n\t-----Invlaid Input!-----\n";
            continue;
        }

        switch (menu_choice) {
            case '1':       // Librarian
                cout << "\n-----Options-----"
                     << "\n1) Add a Book"
                     << "\n2) Add an Author"
                     << "\n3) Register a new Library Member"
                     << "\n4) Display all Books"
                     << "\n5) Display all Authors"
                     << "\n6) Display all Library Members"
                     << "\n7) Remove Books"
                     << "\n8) Remove Authors"
                     << "\n9) View late fees for Library Members"
                     << "\n10) Back to Menu"
                     << "\n--Enter choice : ";
                cin >> option_choice;

                switch (option_choice) {
                    case 1:
                        Nuces.addBook();
                    break;
                    
                    case 2:
                        Nuces.addAuthor();
                    break;
                    
                    case 3:
                        Nuces.registerNewMember();
                    break;
                    
                    case 4:
                        
                    break;
                    
                    case 5:
                        
                    break;
                    
                    case 6:
                        
                    break;
                    
                    case 7:
                        
                    break;
                    
                    case 8:
                        
                    break;
                    
                    case 9:
                        
                    break;
                    
                    case 10:
                        // Back to menu
                    break;
                    
                    default:
                        cout << "\n\t-----Invlaid Input!-----\n";
                    break;
                }

            break;
            
            case '2':       // Library Member
                cout << "\n\t\t\t\t-----Rules-----"
                     << "\n--Users must have a valid library membership to borrow books."
                     << "\n--Users may borrow a limited number of books at a time, typically defined by the library's borrowing policy (5)."
                     << "\n--Borrowed books must be returned to the library by the due date specified during borrowing."
                     << "\n--Books returned after the due date may incur fines or penalties, depending on the library's policy."
                     << "\n--Users may be required to settle fines before borrowing additional books or using other library services.";
                    
                    do {     
                        cout << "\n\n-----Options-----"
                            << "\n1) Search for books by 'Title'"
                            << "\n2) Search for books by 'Author'"
                            << "\n3) Borrow a book"
                            << "\n4) Return a book"
                            << "\n5) Back to Menu"
                            << "\n--Enter Choice : ";
                        cin >> option_choice;
                        
                        switch(option_choice) {
                            case 1:
                                cout << "\n\t-----Search Books by Title-----\n"
                                    << "\n--Enter Title : ";
                                cin.ignore();
                                getline(cin, bTitle);

                                track_books = Nuces.searchBook(bTitle, 0);     // Search if the particular book is available or not

                                if (track_books != -1) {        // If the book is available
                                    cout << "\n-----Book Status : Available!-----\n";
                                }

                                else {      // If not
                                    cout << "\n-----Book Status : Not Available!-----\n";
                                    continue;
                                }

                            break;
                            
                            case 2:

                            break;
                            
                            case 3:
                                
                                cout << "\n-----Borrow Books-----\n"
                                        << "--Enter Title : ";
                                cin.ignore();
                                getline(cin, bTitle);

                                track_books = Nuces.searchBook(bTitle, 0);     // Search if the asked book is available or not

                                if (track_books != -1) {        // If the book is available
                                    cout << "\n-----Book Status : Available!-----\n";
                                    borrowBooks(Nuces, bTitle);
                                }

                                else {      // If not
                                    cout << "\n-----Book Status : Not Available!-----\n";
                                    continue;
                                }

                            break;
                            
                            case 4:
                                
                                cout << "\n-----Return Books-----\n"
                                        << "--Enter Title : ";
                                cin.ignore();
                                getline(cin, bTitle);

                                track_books = Nuces.searchBook(bTitle, 1);     // Search if the asked book is available or not

                                if (track_books != -1) {
                                    returnBooks(Nuces, bTitle);
                                }

                                else {
                                    continue;
                                }

                            break;

                            case 5:
                                // Back to menu
                            break;

                            default:
                                cout << "\n\t-----Invlaid Input!-----\n";
                            break;
                        }
                    }

                while (option_choice != 5);

            break;
            
            case '3':
                // Exit the program
            break;
            
            default:
                cout << "\n\t-----Invlaid Input!-----\n";
            break;
        }
    }

    while (menu_choice != '3');

    return 0;
}