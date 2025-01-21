#include <iostream>
#include <string>
using namespace std;

class list {
    const int size; // Size of the task list
    string* tasks;  // Dynamic array to store tasks
    string* status; // Dynamic array to store the status of each task

public:
    // Constructor to initialize size and allocate memory for tasks and status arrays
    list(int s) : size(s) {
        tasks = new string[size];
        status = new string[size];
    }

    // Function to add tasks to the list
    void addTasks();

    // Function to display all tasks with their statuses
    void display() const;

    // Function to mark a task as completed
    void markTasks();

    // Function to remove a task from the list
    void removeTasks();

    // Destructor to release the dynamically allocated memory
    ~list() {
        delete[] tasks;
        delete[] status;
    }
};

// Implementation of addTasks() function
void list::addTasks() {
    bool task_stored = false; // Flag to check if a task was stored
    int choice;               // Variable to store user choice for task status

    cout << "\n--Enter Task: ";

    // Loop through the task list to find an empty slot
    for (int i = 0; i < size; i++) {
        if (tasks[i].empty()) {
            cin.ignore();
            getline(cin, tasks[i]); // Get the task from the user

            // Loop to ensure a valid status choice is made
            do {
                cout << "\n-----Set Status-----"
                    << "\n1. Pending"
                    << "\n2. Completed"
                    << "\n--Enter: ";
                cin >> choice;

                // Set status based on user input
                if (choice == 1) {
                    status[i] = "Pending";
                }
                else if (choice == 2) {
                    status[i] = "Completed";
                }
                else {
                    cout << "\n-----Invalid Input!-----\n";
                }
            } while (choice != 1 && choice != 2);

            task_stored = true; // Set flag to indicate task was stored
            break;
        }
    }

    // Provide feedback to the user about the result of the operation
    if (task_stored) {
        cout << "\n-----Task Saved Successfully!-----\n";
    }
    else {
        cout << "\n-----Error! Maximum Number of Tasks Saved-----\n";
    }
}

// Implementation of display() function
void list::display() const {
    bool tasks_found = false; // Flag to check if any tasks were found

    // Loop through the tasks and display them with their statuses
    for (int i = 0; i < size; i++) {
        if (!tasks[i].empty()) {
            cout << "\n" << i + 1 << ". " << tasks[i] << "\t" << status[i];
            tasks_found = true;
        }
    }

    // If no tasks are found, display a message
    if (!tasks_found)
        cout << "\n-----No Tasks Found!-----\n";
}

// Implementation of markTasks() function
void list::markTasks() {
    display(); // Display the current list of tasks

    // Check if there are any tasks to mark
    if (tasks[0].empty()) return;  // No tasks to mark

    int choice;
    cout << "\n--Enter the number of the task to mark as completed: ";
    cin >> choice;

    // Validate the input and update the status of the selected task
    if (choice >= 1 && choice <= size && !tasks[choice - 1].empty()) {
        status[choice - 1] = "Completed";
        cout << "\n-----Task Marked as Completed!-----\n";
    }
    else {
        cout << "\n-----Invalid Task Number!-----\n";
    }
}

// Implementation of removeTasks() function
void list::removeTasks() {
    display(); // Display the current list of tasks

    // Check if there are any tasks to remove
    if (tasks[0].empty()) return;  // No tasks to remove

    int choice;
    cout << "\n--Enter the number of the task to remove: ";
    cin >> choice;

    // Validate the input and clear the selected task and its status
    if (choice >= 1 && choice <= size && !tasks[choice - 1].empty()) {
        tasks[choice - 1].clear();
        status[choice - 1].clear();
        cout << "\n-----Task Removed Successfully!-----\n";
    }
    else {
        cout << "\n-----Invalid Task Number!-----\n";
    }
}

int main() {
    list user(5);     // Create a list object with a maximum of 5 tasks
    char user_choice; // Variable to store user menu choice

    do {
        system("clear"); // Clear the console screen

        // Display a header with ASCII art
        cout << "                                             \n";
        cout << " _____         ____         __    _     _   \n";
        cout << "|_   _|___ ___|    \\ ___   |  |  |_|___| |_ \n";
        cout << "  | | | . |___|  |  | . |  |  |__| |_ -|  _|\n";
        cout << "  |_| |___|   |____/|___|  |_____|_|___|_|  \n";
        cout << "                                             \n";

        // Display menu options
        cout << "\n-----Menu-----"
            << "\n1. Add Tasks"
            << "\n2. View Tasks"
            << "\n3. Mark Tasks"
            << "\n4. Remove Tasks"
            << "\n5. Exit"
            << "\n--Enter choice: ";
        cin >> user_choice;

        // Process the user's menu choice
        switch (user_choice) {
        case '1':
            cout << "\n-----Add a Task-----\n";
            user.addTasks(); // Call function to add a task
            break;

        case '2':
            cout << "\n-----View Tasks-----\n";
            user.display(); // Call function to display tasks
            break;

        case '3':
            cout << "\n-----Mark Tasks-----\n";
            user.markTasks(); // Call function to mark a task as completed
            break;

        case '4':
            cout << "\n-----Remove Tasks-----\n";
            user.removeTasks(); // Call function to remove a task
            break;

        case '5':
            cout << "\n\t-----Thank You For Choosing Us!-----\n";
            break;

        default:
            cout << "\n-----Invalid Input!-----\n";
            break;
        }

        cout << endl;
        system("pause"); // Pause the screen before looping back to the menu

    } while (user_choice != '5'); // Continue until the user chooses to exit

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

class list {
    const int size; // Size of the task list
    string* tasks;  // Dynamic array to store tasks
    string* status; // Dynamic array to store the status of each task

public:
    // Constructor to initialize size and allocate memory for tasks and status arrays
    list(int s) : size(s) {
        tasks = new string[size];
        status = new string[size];
    }

    // Function to add tasks to the list
    void addTasks();

    // Function to display all tasks with their statuses
    void display() const;

    // Function to mark a task as completed
    void markTasks();

    // Function to remove a task from the list
    void removeTasks();

    // Destructor to release the dynamically allocated memory
    ~list() {
        delete[] tasks;
        delete[] status;
    }
};

// Implementation of addTasks() function
void list::addTasks() {
    bool task_stored = false; // Flag to check if a task was stored
    int choice;               // Variable to store user choice for task status

    cout << "\n--Enter Task: ";

    // Loop through the task list to find an empty slot
    for (int i = 0; i < size; i++) {
        if (tasks[i].empty()) {
            cin.ignore();
            getline(cin, tasks[i]); // Get the task from the user

            // Loop to ensure a valid status choice is made
            do {
                cout << "\n-----Set Status-----"
                    << "\n1. Pending"
                    << "\n2. Completed"
                    << "\n--Enter: ";
                cin >> choice;

                // Set status based on user input
                if (choice == 1) {
                    status[i] = "Pending";
                }
                else if (choice == 2) {
                    status[i] = "Completed";
                }
                else {
                    cout << "\n-----Invalid Input!-----\n";
                }
            } while (choice != 1 && choice != 2);

            task_stored = true; // Set flag to indicate task was stored
            break;
        }
    }

    // Provide feedback to the user about the result of the operation
    if (task_stored) {
        cout << "\n-----Task Saved Successfully!-----\n";
    }
    else {
        cout << "\n-----Error! Maximum Number of Tasks Saved-----\n";
    }
}

// Implementation of display() function
void list::display() const {
    bool tasks_found = false; // Flag to check if any tasks were found

    // Loop through the tasks and display them with their statuses
    for (int i = 0; i < size; i++) {
        if (!tasks[i].empty()) {
            cout << "\n" << i + 1 << ". " << tasks[i] << "\t" << status[i];
            tasks_found = true;
        }
    }

    // If no tasks are found, display a message
    if (!tasks_found)
        cout << "\n-----No Tasks Found!-----\n";
}

// Implementation of markTasks() function
void list::markTasks() {
    display(); // Display the current list of tasks

    // Check if there are any tasks to mark
    if (tasks[0].empty()) return;  // No tasks to mark

    int choice;
    cout << "\n--Enter the number of the task to mark as completed: ";
    cin >> choice;

    // Validate the input and update the status of the selected task
    if (choice >= 1 && choice <= size && !tasks[choice - 1].empty()) {
        status[choice - 1] = "Completed";
        cout << "\n-----Task Marked as Completed!-----\n";
    }
    else {
        cout << "\n-----Invalid Task Number!-----\n";
    }
}

// Implementation of removeTasks() function
void list::removeTasks() {
    display(); // Display the current list of tasks

    // Check if there are any tasks to remove
    if (tasks[0].empty()) return;  // No tasks to remove

    int choice;
    cout << "\n--Enter the number of the task to remove: ";
    cin >> choice;

    // Validate the input and clear the selected task and its status
    if (choice >= 1 && choice <= size && !tasks[choice - 1].empty()) {
        tasks[choice - 1].clear();
        status[choice - 1].clear();
        cout << "\n-----Task Removed Successfully!-----\n";
    }
    else {
        cout << "\n-----Invalid Task Number!-----\n";
    }
}

int main() {
    list user(5);     // Create a list object with a maximum of 5 tasks
    char user_choice; // Variable to store user menu choice

    do {
        system("clear"); // Clear the console screen

        // Display a header with ASCII art
        cout << "                                             \n";
        cout << " _____         ____         __    _     _   \n";
        cout << "|_   _|___ ___|    \\ ___   |  |  |_|___| |_ \n";
        cout << "  | | | . |___|  |  | . |  |  |__| |_ -|  _|\n";
        cout << "  |_| |___|   |____/|___|  |_____|_|___|_|  \n";
        cout << "                                             \n";

        // Display menu options
        cout << "\n-----Menu-----"
            << "\n1. Add Tasks"
            << "\n2. View Tasks"
            << "\n3. Mark Tasks"
            << "\n4. Remove Tasks"
            << "\n5. Exit"
            << "\n--Enter choice: ";
        cin >> user_choice;

        // Process the user's menu choice
        switch (user_choice) {
        case '1':
            cout << "\n-----Add a Task-----\n";
            user.addTasks(); // Call function to add a task
            break;

        case '2':
            cout << "\n-----View Tasks-----\n";
            user.display(); // Call function to display tasks
            break;

        case '3':
            cout << "\n-----Mark Tasks-----\n";
            user.markTasks(); // Call function to mark a task as completed
            break;

        case '4':
            cout << "\n-----Remove Tasks-----\n";
            user.removeTasks(); // Call function to remove a task
            break;

        case '5':
            cout << "\n\t-----Thank You For Choosing Us!-----\n";
            break;

        default:
            cout << "\n-----Invalid Input!-----\n";
            break;
        }

        cout << endl;
        system("pause"); // Pause the screen before looping back to the menu

    } while (user_choice != '5'); // Continue until the user chooses to exit

    return 0;
}
