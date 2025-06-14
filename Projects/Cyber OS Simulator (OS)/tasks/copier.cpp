#include <iostream>
#include <fstream>
#include <filesystem>
#include <unistd.h>
#include <string>

using namespace std;
namespace fs = filesystem;

int main() {
    string source_str, dest_str;

    cout << "Enter the source file path: ";
    getline(cin, source_str);
    fs::path source = source_str;

    cout << "Enter the destination file path: ";
    getline(cin, dest_str);
    fs::path dest = dest_str;

    try {
        if (!fs::exists(source)) {
            throw runtime_error("Source file does not exist");
        }

        if (fs::exists(dest)) {
            cerr << "Warning: Destination file exists. Overwriting...\n";
        }

        // Perform copy operation
        ifstream src_file(source, ios::binary);
        ofstream dest_file(dest, ios::binary);

        dest_file << src_file.rdbuf();

        if (!dest_file) {
            throw runtime_error("Failed to complete copy operation");
        }

        cout << "Successfully copied:\n"
             << "  From: " << source << "\n"
             << "  To:   " << dest << "\n"
             << "  Size: " << fs::file_size(source) << " bytes\n";

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
