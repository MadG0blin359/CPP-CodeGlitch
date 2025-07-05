#include <iostream>  // For input/output operations (cout)
#include <unistd.h>  // For read(), write()
#include <sys/types.h> // For key_t, shmid_ds
#include <sys/shm.h>   // For shmget(), shmat(), shmdt(), shmctl()
#include <sys/ipc.h>   // For IPC_CREAT, IPC_RMID
#include <cstring>   // For strcpy()
using namespace std;

int main() {
    void* shared_memory; // Pointer to the shared memory segment
    char buffer[100];    // Buffer for user input
    int shmid;           // Shared memory segment ID
    
    // Create shared memory segment (key 1235, size 1024 bytes, read/write permissions, create if not exists)
    shmid = shmget((key_t)1235, 1024, 0666 | IPC_CREAT);
    if (shmid < 0) {
        perror("Error! Segment creation failed.\n"); // Print error if creation fails
        return 1;
    }
    
    write(1, "Enter data: ", 12); // Prompt user to enter data (write to stdout)
    ssize_t bytes_read = read(0, buffer, sizeof(buffer) - 1); // Read user input from stdin
    buffer[bytes_read] = '\0'; // Null-terminate the input string

    // Attach shared memory segment to process's address space
    shared_memory = shmat(shmid, NULL, 0);
    // Copy content from buffer to shared memory
    strcpy((char*)shared_memory, buffer);

    cout << (char*)shared_memory; // Print content from shared memory to stdout
    shmdt(shared_memory); // Detach shared memory segment from process's address space
    shmctl(shmid, IPC_RMID,NULL); // Mark shared memory segment for deletion

    return 0; // Program exit
}