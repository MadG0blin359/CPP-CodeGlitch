#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unistd.h>   // For sleep, fork, exec
#include <sys/wait.h> // For waitpid
#include <signal.h>  // For kill
#include <dirent.h>  // For directory listing (simulated on non-Linux)
#include <iomanip>   // For formatted output
#include <algorithm> // For std::find
#include <limits>    // Include for numeric_limits

using namespace std;

// Function to simulate getting a list of processes (Ubuntu)
vector<pair<int, string>> getProcesses() {
    vector<pair<int, string>> processes;
    // In a real Ubuntu system, you would typically read process information
    // from the /proc directory.  For this simulation, we'll return a hardcoded list.

    // Simulated processes (PID, Name)
    processes.push_back({1234, "init"});
    processes.push_back({2345, "gnome-terminal"});
    processes.push_back({3456, "gedit"});
    processes.push_back({4567, "firefox"});
    processes.push_back({5678, "system_monitor"});
    processes.push_back({5679, "process_manager"});
    return processes;
}

// Function to simulate killing a process (Ubuntu)
bool killProcess(int pid, int signal) {
    // In a real Ubuntu system, you would use the kill() system call.
    // This is inherently a privileged operation, so in a real OS,
    // you'd need to handle permissions.
    if (kill(pid, signal) == 0) {
        cout << "Signal " << signal << " sent to process " << pid << endl;
        return true;
    } else {
        perror("kill"); // Print the error message from the kill() syscall
        return false;
    }
}

// Function to simulate launching a new process (Ubuntu)
int launchProcess(const string& command) {
    // In a real Ubuntu system, you'd use fork() and exec().
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        // Use a system() call for simplicity in this simulation.  In a real
        // application, you'd typically parse the command and use exec().
        // VERY IMPORTANT:  Using system() can be a security risk if you're
        // not careful about the input.  Never use it with untrusted input.
        int result = system(command.c_str());
        if (result == -1)
        {
           perror("system");
           exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS); // Important: Exit the child process after exec
    } else if (pid > 0) {
        // Parent process
        cout << "Launched process with PID " << pid << " (Command: " << command << ")\n";
        return pid;
    } else {
        // Error
        perror("fork");
        return -1;
    }
}

int main() {
    cout << "Starting Process Manager...\n";

    while (true) {
        // Clear the screen
        cout << "\033[2J\033[1;1H";

        cout << "╔══════════════════════════════════════════════╗\n";
        cout << "║                Process Manager                 ║\n";
        cout << "╚══════════════════════════════════════════════╝\n";

        // Get and display the list of processes
        vector<pair<int, string>> processes = getProcesses();
        cout << "Current Processes:\n";
        cout << "------------------------------------------------------\n";
        cout << "PID\tName\n";
        cout << "------------------------------------------------------\n";
        for (const auto& process : processes) {
            cout << setw(8) << process.first << "\t" << process.second << endl;
        }
        cout << "------------------------------------------------------\n";

        cout << "\nOptions:\n";
        cout << " l <command>\tLaunch a new process\n";
        cout << " k <pid> <signal>\tKill a process (signal: 1-15, or 9 for KILL)\n";
        cout << " q\t\tQuit\n";
        cout << "Enter command: ";

        string command;
        cin >> command;

        if (command == "q") {
            break;
        } else if (command == "l") {
            string cmd_to_launch;
            cin.ignore(); // Clear the newline character left by the previous cin
            getline(cin, cmd_to_launch); // Read the whole command
            if (cmd_to_launch.empty())
            {
                cout << "No command provided to launch.\n";
                sleep(1);
                continue;
            }
            int new_pid = launchProcess(cmd_to_launch);
            if (new_pid > 0)
            {
                 //waitpid(new_pid, NULL, 0);  // Don't wait, let it run in the "background"
            }
            sleep(1);
        } else if (command == "k") {
            int pid_to_kill;
            int signal_to_send;
            if (cin >> pid_to_kill >> signal_to_send) {
                if (signal_to_send < 1 || signal_to_send > 15 && signal_to_send != 9) {
                    cout << "Invalid signal number.  Use 1-15, or 9 (SIGKILL).\n";
                    sleep(1);
                    continue;
                }
                if (!killProcess(pid_to_kill, signal_to_send)) {
                    cout << "Failed to kill process.\n";
                }
                sleep(1);

            } else {
                cout << "Invalid kill command format.  Use: k <pid> <signal>\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                sleep(1);
            }
        } else {
            cout << "Invalid command.  Please try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            sleep(1);
        }
    }

    cout << "Exiting Process Manager.\n";
    return 0;
}


