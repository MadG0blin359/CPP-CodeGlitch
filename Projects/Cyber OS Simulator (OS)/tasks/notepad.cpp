#include <iostream>
#include <fstream>
#include <string>
#include <limits> // For numeric_limits

using namespace std;

int main() {
    cout << "Starting Basic Notepad...\n";
    cout << "Enter text below (type 'SAVE <filename>' to save, 'EXIT' to quit):\n";

    string line;
    string filename;

    while (getline(cin, line)) {
        if (line.rfind("SAVE ", 0) == 0) {
            filename = line.substr(5);
            ofstream outfile(filename);
            if (outfile.is_open()) {
                cout << "Enter content to save to '" << filename << "' (terminate with an empty line):\n";
                string content_line;
                while (getline(cin, content_line) && !content_line.empty()) {
                    outfile << content_line << endl;
                }
                outfile.close();
                cout << "File '" << filename << "' saved successfully.\n";
            } else {
                cerr << "Error: Could not open file '" << filename << "' for writing.\n";
            }
        } else if (line == "EXIT") {
            cout << "Exiting Notepad.\n";
            break;
        } else {
            cout << "You typed: " << line << endl;
        }
    }

    return 0;
}
