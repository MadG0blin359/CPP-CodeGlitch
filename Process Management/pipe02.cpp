#include <iostream>   // For input/output operations (cout, cin)
#include <string>     // For std::string (though not heavily used here)
#include <unistd.h>   // For fork(), pipe(), close(), read(), write(), sleep(), getpid()
#include <sys/wait.h> // For wait()
#include <sys/types.h> // For pid_t
#include <stdlib.h>   // For general utilities (e.g., exit)
using namespace std;

int main() {
    int fd[2];        // File descriptors for pipe: fd[0] for read, fd[1] for write
    char buffer[5];   // Buffer to hold 5 characters (e.g., integers as chars)
    
    // Create pipe
    if ((pipe(fd) < 0)) {
        perror("Error! Pipe failed.\n");
        return 1;
    }

    pid_t pid; // Variable to store child process ID
    
    // Create child process
    if ((pid = fork()) < 0) {
        perror("Error! Fork failed.\n");
        return 1;
    } else if (pid > 0) { // Parent process
        close(fd[0]); // Close read end of pipe in parent
        
        cout << "Enter 5 integers (as characters): " << endl; // Prompt for input
        // Read 5 characters from user into buffer
        for (int i = 0; i < sizeof(buffer); i++) {
            cin >> buffer[i];
        }
        
        // Write buffer content to pipe
        ssize_t bytes_written = write(fd[1], buffer, sizeof(buffer));
        cout << getpid() << ": Parent wrote " << bytes_written << " bytes.\n";
        close(fd[1]); // Close write end of pipe in parent
        
        wait(NULL); // Wait for child process to terminate
        
        cout << "Child Terminated!" << endl;
    } else { // Child process
        sleep(1);     // Wait for parent to write first (demonstrative)
        close(fd[1]); // Close write end of pipe in child
        
        // Read bytes from pipe into buffer
        ssize_t bytes_read = read(fd[0], buffer, sizeof(buffer));
        
        // Print each character read from the buffer
        for (int i = 0; i < bytes_read; i++) {
            cout << buffer[i] << endl;
        }
        
        close(fd[0]); // Close read end of pipe in child
    }

    return 0;
}