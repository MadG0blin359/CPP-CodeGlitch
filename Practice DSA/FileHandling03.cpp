#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void programMenu(char&);
void writeToFile(string&);
void appendToFile(string&);
void readFromFile(string&);
void deleteFile(string&);

int main() {
    string path = "";
    char choice = 0;

    do {
        cout << "\n\t\t-----File System-----"
        << "\n-----Main Menu-----"
        << "\na. Open new file"
        << "\nb. Open previous file"
        << "\nc. Exit"
        << "\n\n--Enter your choice: ";
        cin >> choice;

        if (choice == 'c') {
            cout << "\n-----Program Terminated!-----" << endl;
            return 0;
        }

        else if (choice == 'a' || path == "") {
            cout << "\n--Enter the path of the file to access: ";
            cin.ignore();
            getline(cin, path);
        }

        programMenu(choice);

        switch(choice) {
            case '1':
                writeToFile(path);
            break;
            case '2':
                appendToFile(path);
            break;
            case '3':
                readFromFile(path);
            break;
            case '4':
                deleteFile(path);
            break;
            case '5':
                cout << "\n-----Back To Main Menu-----";
            break;
            default:
                cout << "\n-----Invalid Choice! Please try again.-----";
            break;
        }
    } while (true);
    
    return 0;
}

// Function to display action menu
void programMenu(char& choice) {
    cout << "\n-----File System-----"
        << "\n1. Write to file"
        << "\n2. Append to file"
        << "\n3. Read from file"
        << "\n4. Delete file"
        << "\n5. Main Menu"
        << "\n\n--Enter your choice: ";
        cin >> choice;
}

// Function to write data to a file
void writeToFile(string& path) {
    ofstream File;
    File.open(path);
    if (File.is_open()) {          // Check if the file is accessible
        string text;
        cin.ignore(); // Clear input buffer
        while (true) {
            getline(cin, text);
            if (text == "0")
                break;
            File << text << endl;
        }
        File << endl;
        File.close();
    } else {
        cout << "-----Failed to open the file at path: " << path << "-----" << endl;
    }
}

// Function to append date to a file
void appendToFile(string& path) {
    ofstream File;
    File.open(path, ios::app);
    if (File.is_open()) {
        string text;
        cin.ignore(); // Clear input buffer
        while (true) {
            getline(cin, text);
            if (text == "0")
                break;
            File << text << endl;
        }
        File << endl;
        File.close();
    } else {
        cout << "-----Failed to open the file at path: " << path << "-----" << endl;
    }
}

// Function to read data from a file
void readFromFile(string& path) {
    ifstream File;
    File.open(path);
    if (File.is_open()) {           // Check if the file exists
        cout << "\n-----File Opened Successfully!-----\n\n";
        string text;
        while (getline(File, text)) {       // While the file is not empty
            cout << text << endl;
        }
        cout << "-----END OF FILE!-----" << endl;
        File.close();
    } else {
        cout << "-----Failed to open the file at path: " << path << "-----" << endl;
    }
}

// Function to delete a file
void deleteFile(string& path) {
    if (remove(path.c_str()) == 0) {
        cout << "-----File deleted successfully!-----" << endl;
    } else {
        cout << "-----Failed to delete the file at path: " << path << "-----" << endl;
    }
}