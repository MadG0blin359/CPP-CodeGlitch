#include <iostream>
#include <filesystem>
#include <vector>
#include <iomanip>
#include <unistd.h>
#include <sys/select.h>

using namespace std;
namespace fs = filesystem;

const string RED = "\033[31m";
const string BLUE = "\033[34m";
const string RESET = "\033[0m";

string format_size(uintmax_t size) {
    const char* units[] = {"B", "KB", "MB", "GB"};
    int unit = 0;
    double fsize = size;

    while (fsize >= 1024 && unit < 3) {
        fsize /= 1024;
        unit++;
    }

    stringstream ss;
    ss << fixed << setprecision(1) << fsize << " " << units[unit];
    return ss.str();
}

void display_header(const fs::path& current_dir) {
    cout << "\033[2J\033[1;1H"; // Clear screen
    cout << "╔══════════════════════════════════════════╗\n";
    cout << "║         CYBER-OS FILE EXPLORER          ║\n";
    cout << "╠══════════════════════════════════════════╣\n";
    cout << "║ Current: " << left << setw(33) << current_dir.string() << "║\n";
    cout << "╠══════════════════════════════╤═══════════╣\n";
    cout << "║          Name                │ Size      ║\n";
    cout << "╟──────────────────────────────┼───────────╢\n";
}

void display_footer() {
    cout << "╚══════════════════════════════╧═══════════╝\n";
    cout << " Commands: [number] Open  [u] Up  [q] Quit\n";
    cout << "> ";
    cout.flush();
}

void browse_directory(const fs::path& path) {
    vector<fs::directory_entry> entries;
    
    // Get directory contents
    if (fs::exists(path)) {
        for (const auto& entry : fs::directory_iterator(path)) {
            entries.push_back(entry);
        }
    }

    // Display interface
    display_header(path);
    
    // List contents
    for (size_t i = 0; i < entries.size(); i++) {
        string name = entries[i].path().filename();
        string color = entries[i].is_directory() ? BLUE : RED;
        string type = entries[i].is_directory() ? "<DIR> " : "";
        string size = entries[i].is_directory() ? "" : format_size(entries[i].file_size());

        cout << "║ " << left << setw(2) << i+1 << ". " 
             << color << setw(22) << name.substr(0, 22) << RESET
             << " │ " << setw(9) << (type + size) << "║\n";
    }
    
    display_footer();
}

int main(int argc, char* argv[]) {
    fs::path current_dir = fs::current_path();

    while (true) {
        browse_directory(current_dir);
        
        // Handle input
        string input;
        cin >> input;
        
        if (input == "q") {
            break;
        }
        else if (input == "u") {
            current_dir = current_dir.parent_path();
        }
        else if (isdigit(input[0])) {
            try {
                vector<fs::directory_entry> entries;
                for (const auto& entry : fs::directory_iterator(current_dir)) {
                    entries.push_back(entry);
                }
                
                int choice = stoi(input) - 1;
                if (choice >= 0 && choice < static_cast<int>(entries.size())) {
                    if (entries[choice].is_directory()) {
                        current_dir = entries[choice].path();
                    }
                }
            }
            catch (...) {
                // Handle invalid selection
            }
        }
    }

    return 0;
}
