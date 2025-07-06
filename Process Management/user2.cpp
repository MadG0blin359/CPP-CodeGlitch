#include <iostream>  // For input/output operations (not directly used for file I/O here)
#include <unistd.h>  // For read(), write(), close()
#include <fcntl.h>   // For open() flags (O_RDONLY, O_WRONLY)
#include <sys/types.h> // For mode_t (not directly used, but good practice for sys/stat)
#include <sys/stat.h>  // For mkfifo() (not directly used, but implies FIFO context)
using namespace std;

int main() {
    int fd;              // File descriptor for FIFO
    char buffer[256];    // Buffer for reading/writing data
    ssize_t bytes_read;  // Number of bytes read

    while (true) { // Loop indefinitely for chat
        fd = open("chat", O_RDONLY); // Open FIFO for reading (blocking until writer opens)
        bytes_read = read(fd, buffer, sizeof(buffer)); // Read data from FIFO
        write(1, "User: ", 6);       // Label received message (write to stdout)
        write(1, buffer, bytes_read); // Print received message to stdout
        close(fd);                   // Close FIFO read end
        
        fd = open("chat", O_WRONLY); // Open FIFO for writing (blocking until reader opens)
        write(1, "You: ", 5);         // Prompt user for input (write to stdout)
        bytes_read = read(0, buffer, sizeof(buffer)); // Read user input from stdin
        write(fd, buffer, bytes_read); // Write user input to FIFO
        close(fd);                     // Close FIFO write end
    }

    return 0; // Program exit (unreachable in this infinite loop)
}