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
        
            if (year < 2024 || year > 2025)
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
        do {
            cout << "--Author Name : ";
            cin.ignore();
            getline(cin, author_name);

            // Trim leading and trailing whitespace
            author_name.erase(0, author_name.find_first_not_of(" \t"));
            author_name.erase(author_name.find_last_not_of(" \t") + 1);

            if (author_name.empty()) {
                cout << "\n\t-----Invlaid Input!-----\n\n";
            }
        }
        // Condition to handle invalid empty & whitespaces containing inputs
        while (author_name.empty());
    }
    
    // Overloaded setter for author name
    void setAuthorName(string name) {
        author_name = name;
    }

    void setWrittenBooks() {
        char choice;

        cout << "\n\t-----Books Written by the Author-----\n";

        for (int i = 0; i < max_books ; i++) {
            
            do {
                cout << "\n-----Book " << i + 1 << "-----\n";
                cout << "--Title : ";
                getline(cin, written_books[i]);

                // Trim leading and trailing whitespace
                written_books[i].erase(0, written_books[i].find_first_not_of(" \t"));
                written_books[i].erase(written_books[i].find_last_not_of(" \t") + 1);

                if (written_books[i].empty()) {
                    cout << "\n\t-----Invlaid Input!-----\n\n";
                }
            
            }
            // Condition to handle invalid empty & whitespaces containing inputs
            while (written_books[i].empty());

            cout << "\n-----Record Saved Successfully!-----\n";

            do {
                cout << "\n--Do you want to add another book? (y/n) : ";
                cin >> choice;

                if (choice != 'n' && choice != 'N' && choice != 'y' && choice != 'Y')
                    cout << "\n\t-----Invlaid Input!-----\n";
            }
            // Handle invalid inputs
            while (choice != 'n' && choice != 'N' && choice != 'y' && choice != 'Y');

            cin.ignore();       // Clear the input buffer after using cin function

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
        do {
            cout << "--Name : ";
            cin.ignore();
            getline(cin, member_name);

            if (member_name == "" || member_name == " ") {
                cout << "\n\t-----Invlaid Input!-----\n";
            }
        }
        // Condition to handle invalid inputs
        while (member_name == "" || member_name == " ");
    }

    void setLateFee() {
        cout << "--Late Fee : ";
        cin >> late_fee;
    }
};

// Class to manage Librarian
class Librarian {
    string librarian_name, login_username, login_password;      // Variables to store administrative credentials

    public:
    // Setters
    void setName() {
        do {
            cout << "--Name : ";
            getline(cin, librarian_name);

            // Trim leading and trailing whitespace
            librarian_name.erase(0, librarian_name.find_first_not_of(" \t"));
            librarian_name.erase(librarian_name.find_last_not_of(" \t") + 1);

            if (librarian_name.empty()) {
                cout << "\n\t-----Invlaid Input!-----\n\n";
            }
        }
        // Condition to handle invalid empty & whitespaces containing inputs
        while (librarian_name.empty());
    }

    void setUsername() {
        do {
            cout << "--Username : ";
            getline(cin, login_username);

            // Trim leading and trailing whitespace
            login_username.erase(0, login_username.find_first_not_of(" \t"));
            login_username.erase(login_username.find_last_not_of(" \t") + 1);

            if (login_username.empty()) {
                cout << "\n\t-----Invlaid Input!-----\n\n";
            }
        }
        // Condition to handle invalid empty & whitespaces containing inputs
        while (login_username.empty());
    }

    void setPassword() {
        do {
            cout << "--Password : ";
            getline(cin, login_password);

            // Trim leading and trailing whitespace
            login_password.erase(0, login_password.find_first_not_of(" \t"));
            login_password.erase(login_password.find_last_not_of(" \t") + 1);

            if (login_password.empty()) {
                cout << "\n\t-----Invlaid Input!-----\n\n";
            }
        }
        // Condition to handle invalid empty & whitespaces containing inputs
        while (login_password.empty());
    }

    // Getter
    string getName() {
        return librarian_name;
    }

    string getUsername() {
        return login_username;
    }

    string getPassword() {
        return login_password;
    }
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
    void adminLibrarian(int);
    void addBook();
    void addAuthor();
    void registerNewMember();
    int verfiyMembership(string);
    // Function overloading for searching book
    int searchBook(string);
    int searchBook(string, int);
    friend void borrowBooks(Library &, string);      // Declaration of friend function to borrow books 
    friend void returnBooks(Library &, string);      // Declaration of friend function to return books
    void displayBooks();
    void displayAuthors();
    void displayMembers();
    void removeBooks(string);
    void removeAuthors(string);
    void calculateLateFee(int);

    // Destructor to deallocate memory for the pointers
    ~Library() {
        delete[] books, authors, members;
    }
};

// Function to register an admin accout for librarian
void Library::adminLibrarian(int account) {     // if account already created = 1 else 0
    string username, password;

    if (account == 0) {
        cout << "\n\t\t-----SignUp Page-----\n"
            << "---------------------------------------------"
            << "\nCreate an Administrator Account for Librarian\n"
            << "---------------------------------------------\n";
        
        administrator.setName();
        administrator.setUsername();
        administrator.setPassword();

        cout << "\n\t-----Account Created Successfully!-----\n\n";
    }

    // Display a SignIn screen
    cout << "\n\t\t-----SignIn Page-----\n";

    do {
        cout << "-----------------------"
            << "\nSignIn to Admin Account\n" 
            << "-----------------------\n"
            << "--Enter Username : ";
            getline(cin, username);

        if (username != administrator.getUsername()) {
            cout << "\n\t-----Error! Username Doesn't Match-----\n";
            continue;
        }

        cout << "--Enter Password : ";
        getline(cin, password);

        if (password != administrator.getPassword()) {
            cout << "\n\t-----Error! Password Doesn't Match-----\n";
        }
    }

    // Condition to verify login credentials
    while (username != administrator.getUsername() || password != administrator.getPassword());

    cout << "\n\t-----SignedIn Successfully!-----\n\n";

    // Displaying a Welcome screen
    cout << "\n\t\t-----------"
        << "\n\t\tAdmin Panel"
        << "\n\t\t-----------"
        << "\n\nWelcome! " << administrator.getName()
        << "\n--What would you like to do today?\n";
        
}

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
        do {
            cout << "--Title : ";
            cin.ignore();           // Clear the input buffer before using getline function
            getline(cin, bTitle);
            
            // Trim leading and trailing whitespace
            bTitle.erase(0, bTitle.find_first_not_of(" \t"));
            bTitle.erase(bTitle.find_last_not_of(" \t") + 1);

            if (bTitle.empty()) {
                cout << "\n\t-----Invlaid Input!-----\n\n";
            }
        
        }
        // Condition to handle invalid empty & whitespaces containing inputs
        while (bTitle.empty());
    

        // Get the author of the book
        do {
            cout << "--Author : ";
            getline(cin, bAuthor);
            
            // Trim leading and trailing whitespace
            bAuthor.erase(0, bAuthor.find_first_not_of(" \t"));
            bAuthor.erase(bAuthor.find_last_not_of(" \t") + 1);

            if (bAuthor.empty()) {
                cout << "\n\t-----Invlaid Input!-----\n\n";
            }
        
        }
        // Condition to handle invalid empty & whitespaces containing inputs
        while (bAuthor.empty());

        // Get the isbn of the book
        do {
            cout << "--ISBN : ";
            getline(cin, bIsbn);

            // Trim leading and trailing whitespace
            bIsbn.erase(0, bIsbn.find_first_not_of(" \t"));
            bIsbn.erase(bIsbn.find_last_not_of(" \t") + 1);

            if (bIsbn.empty()) {
                cout << "\n\t-----Invlaid Input!-----\n\n";
            }
        
        }
        // Condition to handle invalid empty & whitespaces containing inputs
        while (bIsbn.empty());
    

        // Get the status of the book
        do {
            cout << "\n--Is the book available? (1 for yes, 0 for no) : ";
            cin >> bStatus;

            if (bStatus != 0 && bStatus != 1) {
                cout << "\n\t-----Invlaid Input!-----\n";
            }
        }

        while (bStatus != 0 && bStatus != 1);

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
        return 1;       // Returning 1 if found registered
    }

    else {
        cout << "\n-----ID Not Found!-----\n";
        return 0;
    }
}

// Definition of function overloading for searching book
int Library::searchBook(string bTitle) {   // Search by book title, return = 0 for borrowing & 1 for returning
    bool found = 0;
    for (int i = 0; i < capacity; i++) {
        if (books[i].getTitle() == bTitle) {
            found = true;
            cout << "\n-----Book Record Found!-----\n";
            track_books = i;

            if (books[track_books].getStatus()) {
                return 1;         // Returning 1 = the particular book is stored and available
            }

            else {          // Book status = not available = false
                return 0;
            }
        }
    }

    if (found == false) {
        cout << "\n-----Book Record Not Found!-----\n";
        return 0;
    }
}

int Library::searchBook(string bAuthor, int a) {   // Search by book author
    bool found = 0;
    for (int i = 0; i < capacity; i++) {
        if (books[i].getAuthor() == bAuthor) {
            found = true;
            cout << "\n-----Book Record Found!-----\n";
            track_authors = i;
            cout << "\n-----Book Title : " << books[i].getTitle() << "-----\n";

            if (books[i].getStatus()) {
                return 1;         // Returning 1 = the particular book is stored and available
            }

            else {          // Book status = not available = false
                return 0;
            }
        }
    }

    if (found == false) {
        cout << "\n-----Book Record Not Found!-----\n";
        return 0;
    }
}

// Friend function to borrow books
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

// Friend function to return borrowed books
void returnBooks(Library &Return, string returnBook) {
    bool found;
    string *ptr = Return.members[Return.track_members].getBorrowedBooks();      // Get the address of the member borrowedbooks array

    for (int i = 0; i < max_books; i++) {
        if (ptr[i] == returnBook) {
            found = true;
            Return.books[Return.track_books].setStatus(true);         // Updating the book status
            ptr[i] = "";
            cout << "\n-----Book Returned Successfully!-----\n";
        }
    }

    if (found) {        // if found true
        Return.calculateLateFee(0);      // Calling function to determine whether the members gets a late return fine or not 
    }

    else {
        cout << "\n-----Borrowing Record Not Found!-----\n";
    }
}

// Function to display all the books in the library
void Library::displayBooks() {
    int total = 0;

    cout << "\n\t-----Books Record-----\n";

    for (int i = 0; i < capacity; i++) {
        if (books[i].getTitle().empty() == false) {
            total++;
            cout << i+1 << ") " << books[i].getTitle() << "\n";
        }
    }

    if (total == 0) {
        cout << "\n-----No Record Found!-----\n";
    }

    else {
        cout << "\n-----Total Books : " << total << "-----\n";
    }
}

// Function to display all the authors in the library
void Library::displayAuthors() {
    int total = 0;

    cout << "\n\t-----Authors Record-----\n";

    for (int i = 0; i < capacity; i++) {
        if (authors[i].getAuthorName().empty() == false) {
            total++;
            cout << i+1 << ") " << authors[i].getAuthorName() << "\n";
        }
    }

    if (total == 0) {
        cout << "\n-----No Record Found!-----\n";
    }

    else {
        cout << "\n-----Total Authors : " << total << "-----\n";
    }
}

// Function to display all the members in the library
void Library::displayMembers() {
    int total = 0;
    cout << "\n\t-----Members Record-----\n";

    for (int i = 0; i < capacity; i++) {
        if (members[i].getName().empty() == false) {
            total++;
            cout << i+1 << ") " << members[i].getName() << "\n";
        }
    }

    if (total == 0) {
        cout << "\n-----No Record Found!-----\n";
    }

    else {
        cout << "\n-----Total Members : " << total << "-----\n";
    }
}

// Function to remove books from the library
void Library::removeBooks(string removeTitle) {
    bool found = false;
    for (int i = 0; i < capacity; i++) {
        if  (books[i].getTitle() == removeTitle) {
            found = true;
            // Updating the database to empty strings
            books[i].setTitle("");
            books[i].setAuthor("");
            books[i].setISBN("");
            books[i].setStatus(0);

            cout << "\n\t-----Book Removed Successfully!-----\n";
        }
    }

    if (found == false)
        cout << "\n-----Book Record Not Found!-----\n";
}

// Function to remove authors from the library
void Library::removeAuthors(string removeAuthor) {
    bool found = false;
    for (int i = 0; i < capacity; i++) {
        if  (authors[i].getAuthorName() == removeAuthor) {
            found = true;
            // Updating the database to empty string
            authors[i].setAuthorName("");

            cout << "\n\t-----Author Removed Successfully!-----\n";
        }
    }

    if (found == false)
        cout << "\n-----Author Record Not Found!-----\n";
}

// Function to display a fix late book return fee
void Library::calculateLateFee(int a = 0) {     // 0 = determine fine for the particular book which is being returned, 1 = calculate fine for all the borrowed books
    int current_day, current_month, current_year;
    double fine = 50;

    cout << "\n\t-----Calculate Late Return Fee-----\n";

    do {
        cout << "--Current Day (1-31) : ";
        cin >> current_day;

        if (current_day < 1 || current_day > 31) {
            cout << "\n\t-----Invlaid Input!-----\n";
            continue;
        }

        cout << "--Current Month (1-12) : ";
        cin >> current_month;
    
        if (current_month < 1 || current_month > 12) {
            cout << "\n\t-----Invlaid Input!-----\n";
            continue;
        }

        cout << "--Current Year : ";
        cin >> current_year;
    
        if (current_year < 2024 || current_year > 2025) {
            cout << "\n\t-----Invlaid Input!-----\n";
            continue;
        }
    }

    // Condition to handle invalid inputs for day, month, year
    while (current_day < 1 || current_day > 31 || current_month < 1 || current_month > 12 || current_year < 2024 || current_year > 2025);     // Max one year allowed

    if (a == 0) {
        // Condition to determine if the book's date is before the current date
        if (books[track_books].getYear() < current_year || 
        (books[track_books].getYear() == current_year && books[track_books].getMonth() < current_month) || 
        (books[track_books].getYear() == current_year && books[track_books].getMonth() == current_month && books[track_books].getDay() < current_day)) {
            cout << "\n-----Book Return Due Date Exceeded-----\n"
                 << "--Total Fine/Penalties : " << fine;
        }

        else {
            cout << "\n-----Book Returned Within Due Date-----\n";
        }
    }

    else {
        int late = 0;
        cout << "\n| Member |"
             << "\t| Book Title |"
             << "\t\t| Total Fine/Penalties |";

        // Nested loops to calculate late fee for all members that have passed the due date
        for (int i = 0; i < capacity; i++) {
            
            if ((books[i].getYear() < current_year) || 
            (books[i].getYear() == current_year && books[i].getMonth() < current_month) || 
            (books[i].getYear() == current_year && books[i].getMonth() == current_month && books[i].getDay() < current_day)) {
                
                for (int j = 0; j < capacity; j++) {
                    string *ptr = members[j].getBorrowedBooks();
                    
                    if (members[j].getName() != "") {
                        
                        for (int k = 0; k < max_books; k++) {       // Loop to check if a member borrowed a book
                            
                            if (ptr[k] == books[i].getTitle() && books[i].getTitle() != "") {
                                late++;
                                cout << "\n-" << members[j].getName()
                                     << "\t\t " << books[i].getTitle()
                                     << "\t\t\t " << fine << " PKR";
                            }
                        }
                    }
                }
            }
        }

        if (late == 0) {
            cout << "\n\n\t\t-----No Record Found!-----\n\n";
        }

    }

}

int main() {

    Library Nuces;
    // Variables to take user input
    char menu_choice; 
    int option_choice;
    string name, bTitle, bAuthor;
    int track_admin, track_members, track_books;
    track_admin = 0;

    cout << "\n\t-----Library Management System-----\n";

    do {
        cout << "\n-----Menu-----"
             << "\n1) Librarian"
             << "\n2) Member"
             << "\n3) Exit"
             << "\n--Enter Choice : ";
        cin >> menu_choice;

        if (menu_choice == '1') {       // Calling the function to register an admin account for managing library
            cin.ignore();
            Nuces.adminLibrarian(track_admin);
            track_admin++;
        }

        else if (menu_choice == '2') {
            do {
                cout << "\n-----Member Sign In-----\n"
                     << "\n--Enter ID Name : ";
                cin.ignore();           // Clear the input buffer before using getline function
                getline(cin, name);
                
                // Trim leading and trailing whitespace
                name.erase(0, name.find_first_not_of(" \t"));
                name.erase(name.find_last_not_of(" \t") + 1);

                if (name.empty()) {
                    cout << "\n\t-----Invlaid Input!-----\n\n";
                }
        
            }
            // Condition to handle invalid empty & whitespaces containing inputs
            while (name.empty());

            track_members = Nuces.verfiyMembership(name);       // Getting the index number at which the member details are stored

            if (track_members == 0) {
                continue;           // The member is not found in the library database
            }
        }

        else if (menu_choice != '3') {
            cout << "\n\t-----Invlaid Input!-----\n";
            continue;
        }

        switch (menu_choice) {
            case '1':       // Librarian

                do {
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
                        case 1:     // Calling the function to add a book
                            Nuces.addBook();
                        break;
                        
                        case 2:     // Calling the function to add an author
                            Nuces.addAuthor();
                        break;
                        
                        case 3:     // Calling the function to register a new member
                            Nuces.registerNewMember();
                        break;
                        
                        case 4:          // Calling the function to display all books registered in the library
                            Nuces.displayBooks();
                        break;
                        
                        case 5:          // Calling the function to display all authors registered in the library
                            Nuces.displayAuthors();
                        break;
                        
                        case 6:          // Calling the function to display all members registered in the library
                            Nuces.displayMembers();
                        break;
                        
                        case 7:          // Calling the function to remove a book from the library
                            cout << "\n\t-----Remove Books-----\n"
                                << "\n--Enter Book Title : ";
                            cin.ignore();
                            getline(cin, bTitle);

                            Nuces.removeBooks(bTitle);
                        break;
                        
                        case 8:          // Calling the function to remove an author from the library
                            cout << "\n\t-----Remove Authors-----\n"
                                << "\n--Enter Author Title : ";
                            cin.ignore();
                            getline(cin, bAuthor);

                            Nuces.removeAuthors(bAuthor);
                        break;
                        
                        case 9:
                            Nuces.calculateLateFee(1);
                        break;
                        
                        case 10:
                            // Back to menu
                        break;
                        
                        default:
                            cout << "\n\t-----Invlaid Input!-----\n";
                        break;
                    }

                }

                while (option_choice != 10);

            break;
            
            case '2':       // Library Member
                cout << "\n\t\t\t\t-----Rules-----"
                     << "\n--Users must have a valid library membership to borrow books."
                     << "\n--Users may borrow a limited number of books at a time, typically defined by the library's borrowing policy (5)."
                     << "\n--Borrowed books must be returned to the library by the due date specified during borrowing."
                     << "\n--Books returned after the due date may incur fines or penalties, depending on the library's policy, which states that a fixed fine of 50 rupees will be imposed if the due date has passed."
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

                                track_books = Nuces.searchBook(bTitle);     // Search if the particular book is available or not

                                if (track_books == 1) {        // If the book is available
                                    cout << "\n-----Book Status : Available!-----\n";
                                }

                                else {      // If not
                                    cout << "\n-----Book Status : Not Available!-----\n";
                                }

                            break;
                            
                            case 2:
                                cout << "\n\t-----Search Books by Author-----\n"
                                    << "\n--Enter Author : ";
                                cin.ignore();
                                getline(cin, bAuthor);

                                track_books = Nuces.searchBook(bAuthor, 1);     // Search if the particular book is available or not, 1 to differentiate b/w the overloaded functions

                                if (track_books == 1) {        // If the book is available
                                    cout << "\n-----Book Status : Available!-----\n";
                                }

                                else {      // If not
                                    cout << "\n-----Book Status : Not Available!-----\n";
                                }

                            break;
                            
                            case 3:
                                
                                cout << "\n-----Borrow Books-----\n"
                                        << "--Enter Title : ";
                                cin.ignore();
                                getline(cin, bTitle);

                                track_books = Nuces.searchBook(bTitle);     // Search if the asked book is available or not

                                if (track_books == 1) {        // If the book is available
                                    cout << "\n-----Book Status : Available!-----\n";
                                    borrowBooks(Nuces, bTitle);
                                }

                                else {      // If not
                                    cout << "\n-----Book Status : Not Available!-----\n";
                                }

                            break;
                            
                            case 4:
                                
                                cout << "\n-----Return Books-----\n"
                                        << "--Enter Title : ";
                                cin.ignore();
                                getline(cin, bTitle);

                                track_books = Nuces.searchBook(bTitle);     // Search if the asked book is available or not

                                if (track_books == 0) {
                                    returnBooks(Nuces, bTitle);
                                }

                                else {
                                    cout << "\n-----Error! Book Already Available-----\n";
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