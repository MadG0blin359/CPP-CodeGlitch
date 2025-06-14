#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/select.h>
#include <fcntl.h>
#include <limits>
#include <list>

using namespace std;

// CyberOS Version Information
const string OS_VERSION = "CyberOS v1.3.0";

// Structure to store system resources
struct SystemResources {
    float total_ram;
    float available_ram;
    float total_hd;
    float available_hd;
    int cpu_cores;
    int busy_cores = 0;  // Track actively used cores
};

// Process states and tracking
struct ProcessInfo {
    pid_t pid;
    float ram_usage;
    float hd_usage;
    bool minimized = false;
    int task_index;  // Track which task to restart
    bool has_terminal;  // Track if the process is active
};

// Task structure with metadata
struct Task {
    string name;
    string executable;
    float ram_required;
    float hd_required;
    bool auto_start;
    bool kernel_only;
};

// Global variables
unordered_map<int, ProcessInfo> running_processes;
list<pid_t> ready_queue;	// First Come First Serve (FCFS)
vector<Task> task_list;
SystemResources sys_res;

const int TIME_QUANTUM = 2; // Seconds per process
bool rr_enabled = false;    // Toggle for RR scheduling

bool kernel_mode = false;
string KERNEL_PASSWORD = "cyberos123";

void initialize_tasks() {
    task_list = {
        {"Notepad++ App",    "tasks/notepad",          0.2f, 0.2f, false, false},
        {"Calculator App",   "tasks/calculator",       0.1f, 0.5f, false, false},
        {"Snake Game Alpha", "tasks/snake",            0.5f, 1.2f, false, false},
        {"System Monitor",   "tasks/monitor",          0.2f, 0.5f, false, true},
        {"File Explorer",    "tasks/explorer",         0.2f, 0.1f, false, true},
        {"Music Player",     "tasks/music",            1.2f, 2.2f, false, false},
        {"Process Manager",  "tasks/process",          0.4f, 0.2f, true, false},
        {"Stop Watch   ",    "tasks/watch",            0.2f, 0.1f, false, false},
        {"Digital Clock",    "tasks/clock",            0.5f, 0.5f, true, false},
        {"Calendar App",     "tasks/calendar",         0.1f, 0.1f, true, false},
        {"File Copier",      "tasks/copier",           0.3f, 0.5f, false, true},
        {"Tic-Tac-Toe",      "tasks/tictactoe",        0.8f, 1.5f, false, false},
        {"ASCII Gallery",    "tasks/gallery",          1.5f, 0.8f, false, false},
        {"Fortune Teller",   "tasks/fortune",          1.2f, 2.5f, false, false},
        {"Maze Challenge",   "tasks/maze",             0.1f, 0.1f, false, true}
    };
}

void show_boot_screen() {
    system("clear");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t\t\t ██████╗██╗   ██╗██████╗ ███████╗██████╗        ██████╗ ███████╗\n";
    cout << "\t\t\t\t\t\t\t██╔════╝╚██╗ ██╔╝██╔══██╗██╔════╝██╔══██╗      ██╔═══██╗██╔════╝\n";
    cout << "\t\t\t\t\t\t\t██║      ╚████╔╝ ██████╔╝█████╗  ██████╔╝█████╗██║   ██║███████╗\n";
    cout << "\t\t\t\t\t\t\t██║       ╚██╔╝  ██╔══██╗██╔══╝  ██╔══██╗╚════╝██║   ██║╚════██║\n";
    cout << "\t\t\t\t\t\t\t╚██████╗   ██║   ██████╔╝███████╗██║  ██║      ╚██████╔╝███████║\n";
    cout << "\t\t\t\t\t\t\t ╚═════╝   ╚═╝   ╚═════╝ ╚══════╝╚═╝  ╚═╝       ╚═════╝ ╚══════╝\n";
    cout << "\n\t\t\t\t\t\t\t\t\t\t" << OS_VERSION << "\n";
    cout << "\n\t\t\t\t\t\t\t\t\t     System initializing...\n";
    sleep(5);
}

void display_main_menu() {
    cout << "\033[2J\033[1;1H"; // Clear screen
    cout << "\t\t\t\t\t\t\t\t\t========================================\n";
    cout << "\t\t\t\t\t\t\t\t\t       WELCOME TO CYBER-OS SIMULATOR\n";
    cout << "\t\t\t\t\t\t\t\t\t========================================\n\n";
    cout << "Available Resources:\n";
    cout << "RAM: " << sys_res.available_ram << "/" << sys_res.total_ram << " GB\n";
    cout << "HD:  " << sys_res.available_hd << "/" << sys_res.total_hd << " GB\n";
    
    // Calculate busy cores dynamically
    int busy = min((int)ready_queue.size(), sys_res.cpu_cores);
    cout << "CPU: " << sys_res.cpu_cores - busy << "/" << sys_res.cpu_cores << " cores\n\n";
    
    cout << "Available Tasks:\n";
    for(size_t i = 0; i < task_list.size(); ++i) {
        cout << " " << i+1 << ". " << task_list[i].name 
             << "\t(RAM: " << task_list[i].ram_required
             << "GB, HD: " << task_list[i].hd_required << "GB)";
             if(task_list[i].kernel_only) 
             cout << " (Kernel only)";
        	 cout << "\n";
    }
    cout << "\nOptions:\n";
    cout << " 0. Shutdown\n m. Manage Tasks\n k. Kernel Mode\n";
    cout << "\nEnter choice: ";
}

void toggle_kernel_mode() {
    if(!kernel_mode) {
        cout << "Enter kernel password: ";
        string password;
        cin >> password;
        if(password == KERNEL_PASSWORD) {
            kernel_mode = true;
            cout << "\n-----Kernel mode activated!-----\n";
        }
    }
    else {
        kernel_mode = false;
        cout << "\n-----Returned to user mode-----\n";
    }
}

// update the ready_queue handling
void schedule_processes() {
    list<pid_t> to_requeue;
    
    // check how many tasks can run in parallel
    int parallel_tasks = min((int)ready_queue.size(), sys_res.cpu_cores);
    sys_res.busy_cores = parallel_tasks; // Update busy cores
    
    // Process each task for this quantum (non-blocking)
    for(int i = 0; i < parallel_tasks; i++) {
        pid_t pid = ready_queue.front();
        ready_queue.pop_front();
        to_requeue.push_back(pid); // Requeue after processing
    }
    
    ready_queue.splice(ready_queue.end(), to_requeue);
}

void minimize_task(pid_t pid) {
    if(running_processes.count(pid)) {
        ProcessInfo& proc = running_processes[pid];
        
        if(proc.has_terminal) {
            kill(pid, SIGTERM);
        }
        
        proc.minimized = true;
        ready_queue.remove(pid); // Remove from scheduling queue
    }
}

void reclaim_resources(pid_t pid) {
    if(running_processes.count(pid)) {
        // Preserve resources if process is minimized
        if(!running_processes[pid].minimized) {
            sys_res.available_ram += running_processes[pid].ram_usage;
            sys_res.available_hd += running_processes[pid].hd_usage;
        }
        running_processes.erase(pid);
    }
}

void restore_task(pid_t old_pid) {
    if(running_processes.count(old_pid) && running_processes[old_pid].minimized) {
        ProcessInfo& proc = running_processes[old_pid];

        pid_t new_pid = fork();
        if(new_pid == 0) {
            execlp("gnome-terminal", "gnome-terminal", "--", 
                   task_list[proc.task_index].executable.c_str(), NULL);
            exit(EXIT_FAILURE);
        }
        else if(new_pid > 0) {
            running_processes[new_pid] = {
                new_pid,
                proc.ram_usage,
                proc.hd_usage,
                false,
                proc.task_index,
                true
            };
            
            reclaim_resources(old_pid);
            ready_queue.push_back(new_pid); // Add restored task to queue
        }
    } 
    else {
    	  cout << "\n-----Error: Process is already running!-----\n";
    }
}

bool launch_task(int task_index, bool auto_start = false) {
    // Check for existing instance
    for(const auto& [pid, proc] : running_processes) {
        if(proc.task_index == task_index) {
            if(proc.minimized) {
                restore_task(pid);
                return true;
            }
            cout << "Error: " << task_list[task_index].name 
                 << " is already running!\n";
                 //sleep(2);
            return false;
        }
    }

    if(task_list[task_index].kernel_only && !kernel_mode) {
        cout << "Error: Kernel mode required!\n";
        return false;
    }

    if(task_index < 0 || task_index >= task_list.size()) return false;
    
    Task& t = task_list[task_index];
    
    // Check resource validation
    if(t.ram_required > sys_res.available_ram || 
       t.hd_required > sys_res.available_hd) {
        cout << "Error: Insufficient resources!\n";
        return false;
    }

    pid_t pid = fork();
    if(pid == 0) {
        if(auto_start) {
            // Run in background without terminal
            close(STDIN_FILENO);
            close(STDOUT_FILENO);
            close(STDERR_FILENO);
            execlp(t.executable.c_str(), t.executable.c_str(), NULL);
        } else {
            // Run in new terminal
            execlp("gnome-terminal", "gnome-terminal", "--", 
                   t.executable.c_str(), NULL);
        }
        exit(EXIT_FAILURE);
    } 
    if(pid > 0) {
        sys_res.available_ram -= t.ram_required;
        sys_res.available_hd -= t.hd_required;

        running_processes[pid] = {
            pid, 
            t.ram_required,
            t.hd_required,
            auto_start,
            task_index,
            !auto_start
        };

        if(!auto_start) {
            ready_queue.push_back(pid); // Only queue non-minimized tasks
        }
        return true;
    }
    return false;
}

void auto_start_tasks() {
    for(size_t i = 0; i < task_list.size(); ++i) {
        if(task_list[i].auto_start) {
            launch_task(i, true);  // Pass true for auto-start
        }
    }
}

void manage_tasks() {
    vector<pair<pid_t, ProcessInfo>> process_list;

    while(true) {
        process_list = vector<pair<pid_t, ProcessInfo>>(running_processes.begin(), running_processes.end());
        
        cout << "\033[2J\033[1;1H"; // Clear screen
        cout << "\t\t=== Task Manager ===\n";
        cout << "ID  Status      Task Name          RAM  HD\n";
        cout << "------------------------------------------------\n";
        
        for(size_t i = 0; i < process_list.size(); ++i) {
            auto& [pid, proc] = process_list[i];
            cout << " " << i+1 << ". "
                 << (proc.minimized ? "[Minimized]" : "[Running]  ") << " "
                 << task_list[proc.task_index].name.substr(0, 15) << "\t"
                 << proc.ram_usage << " GB\t"
                 << proc.hd_usage << " GB\n";
        }

        cout << "\nOptions:\n"
             << " m <ID> - Minimize task\n"
             << " r <ID> - Restore task\n"
             << " k <ID> - Kill task\n"
             << " b       - Back to main menu\n"
             << "Enter command: ";

        string cmd;
        cin >> cmd;

        if(cmd == "b") break;

        if(cmd == "m" || cmd == "r" || cmd == "k") {
            int index;
            if(cin >> index) {
                index--; // Convert to 0-based index
                if(index >= 0 && index < static_cast<int>(process_list.size())) {
                    pid_t pid = process_list[index].first;
                    
                    if(cmd == "m") minimize_task(pid);
                    else if(cmd == "r") {
                    	restore_task(pid);
                    	sleep(2);
                    }
                    else if(cmd == "k" && !kernel_mode) {
    				cout << "\n-----Requires kernel mode!-----\n";
				sleep(2);
    			  	continue;
			  }
                    else if(cmd == "k") {
                        kill(pid, SIGTERM);
                        reclaim_resources(pid);
                    }
                    continue;
                }
            }
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid selection! Press enter to continue...";
            cin.get();
        }
        else {
            cout << "Invalid command! Press enter to continue...";
            cin.ignore();
            cin.get();
        }
    }
}

int main(int argc, char* argv[]) {
    if(argc != 4) {
        cout << "Provide Arguments: " << argv[0] << " <RAM_GB> <HD_GB> <CORES>\n";
        return 1;
    }

    // Initialize system resources
    sys_res = {
	    stof(argv[1]), stof(argv[1]),  // total_ram, available_ram
	    stof(argv[2]), stof(argv[2]),  // total_hd, available_hd
	    stoi(argv[3]),                 // cpu_cores
	    0                              // busy_cores (initialize to 0)
    };

    initialize_tasks();
    show_boot_screen();
    auto_start_tasks();

    string input;
    while(true) {
        
	  display_main_menu(); // Refresh UI
        
      // Handle user input
      cin >> input;
      if(input == "0") break;	// shutdown
      else if(input == "m") {
    		manage_tasks();  // Simplified call without inner loop
	  }
	  else if (input == "k") {
	  	toggle_kernel_mode();
	  	sleep(2);
	  }
      else if(isdigit(input[0])) {
          int choice = stoi(input);
          if(choice < 1 || choice > task_list.size()) {
                cout << "\n-----Invalid choice!-----\n";
                sleep(2);
                continue;
            }
          launch_task(choice-1) ? cout << "Task started!\n" : cout << "Start failed!\n";
            sleep(2);
            schedule_processes(); // Update scheduler after new task
            continue;
          }
      else {
        	cout << "\n-----Invalid choice!-----\n";
            sleep(2);
        }
      schedule_processes();
    }

    // Shutdown sequence
    cout << "Shutting down system...\n";
    for(auto& [pid, _] : running_processes) {
        kill(pid, SIGTERM);
        //reclaim_resources(pid);
    }
    sleep(2);
    cout << "System shutdown complete. Goodbye!\n";
    
    return 0;
}
