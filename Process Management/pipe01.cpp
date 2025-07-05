#include <iostream>  // For input/output operations (cout, cin)
#include <unistd.h>  // For fork(), pipe(), close(), read(), write(), sleep(), getpid()
#include <stdlib.h>  // For general utilities (e.g., exit, though not explicitly used for exit in main)
#include <string>    // For std::string
#include <sys/wait.h> // For wait()
using namespace std;

int main() {
    char buffer[256]; // Buffer for reading data from pipe
    int fd[2];        // File descriptors for pipe: fd[0] for read, fd[1] for write
    string msg = "Hello from parent: " + to_string(getpid()); // Message for child
    
    // Create pipe
    if (pipe(fd) == -1) {
        perror("Error! Create file descriptors failed.\n");
        return 1;
    }

    pid_t pid; // Variable to store child process ID
    // Create child process
    if ((pid = fork()) < 0) {
        perror("Error! Fork failed.\n");
        return 2;
    } else if (pid > 0) { // Parent process
        close(fd[0]); // Close read end of pipe in parent
        cout << "Waiting for child" << endl;
        
        // Write message to pipe
        ssize_t bytes_written = write(fd[1], msg.c_str(), msg.length());
        if (bytes_written < 0) {
            perror("Error! Parent fd[1] failed.\n");
            return 3;
        }
        close(fd[1]); // Close write end of pipe in parent
        cout << "Parent (" << getpid() << "): Message was successfully sent to child." << endl;
        
        wait(NULL); // Wait for child process to terminate
        cout << "Parent (" << getpid() << "): My child (" << pid << ") was successfully terminated." << endl;
    } else { // Child process
        sleep(1);   // Wait for parent to write first (demonstrative)
        close(fd[1]); // Close write end of pipe in child
        // Read message from pipe
        ssize_t bytes_read = read(fd[0], buffer, sizeof(buffer));
        if (bytes_read < 0) {
            perror("Error! Child fd[0] failed.\n");
            return 4;
        } else {
            cout << "Bytes read from parent: " << bytes_read << endl;
        } 
        
        // Null-terminate the received string to print it correctly
        buffer[bytes_read] = '\0'; 
        cout << "Child (" << getpid() << "): Message recieved - " << buffer << endl;
        
        close(fd[0]); // Close read end of pipe in child
    }

    return 0;
}