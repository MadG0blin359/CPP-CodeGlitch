#include <iostream>   // For input/output operations (cout, cin, getline)
#include <pthread.h>  // For POSIX threads (pthread_create, pthread_join)
#include <semaphore.h> // For POSIX semaphores (sem_init, sem_wait, sem_post, sem_destroy)
#include <unistd.h>   // For sleep()
#include <string>     // For std::string
using namespace std;

sem_t S; // Global semaphore for mutual exclusion
// Global shared data that multiple threads will access
string dataset = "Synchronization tool that provides more sophisticated ways (than Mutex locks) for processes to synchronize their activities is called semaphores. Semaphore S – an integer variable can only be accessed via two indivisible (atomic) operations. ";

// Wrapper function for sem_wait
void wait(sem_t* S) {
    sem_wait(S);
}

// Wrapper function for sem_post
void signal(sem_t* S) {
    sem_post(S);
}

// Writer thread function
void* writer(void* arg) {
    string local; // Local buffer for user input
    do {
        wait(&S); // Acquire semaphore to enter critical section
        cout << "\n--Write Data In:\n" << dataset << endl; // Display current dataset      

        cout << "\n-> Write data: ";
        getline(cin, local); // Get input from user
        
        if (local == "exit") { // Check for exit command
            cout << "\nWriter Terminating!\n";
            signal(&S); // Release semaphore before exiting
            break;      // Exit loop
        }

        dataset += local; // Append local input to shared dataset
        signal(&S); // Release semaphore to exit critical section
        sleep(1);   // Simulate work
    } while (1); // Loop indefinitely until 'exit' is entered

    return nullptr; // Thread exit
}

// Reader thread function
void* reader(void* arg) {
    do {
        wait(&S); // Acquire semaphore to enter critical section
        cout << "\n--Reader Reading Data:\n" << dataset << endl; // Display shared dataset
        signal(&S); // Release semaphore to exit critical section
        sleep(1);   // Simulate work
    } while (1); // Loop indefinitely

    return nullptr; // Thread exit
}

int main() {
    pthread_t read1, read2, write_thread; // Thread identifiers

    sem_init(&S, 0, 1); // Initialize semaphore S with initial value 1 (for mutual exclusion)

    // Create threads: one writer and two readers
    pthread_create(&write_thread, nullptr, writer, nullptr);
    pthread_create(&read1, nullptr, reader, nullptr);
    pthread_create(&read2, nullptr, reader, nullptr);

    // Wait for all threads to complete (writer thread will terminate on "exit" input)
    pthread_join(write_thread, nullptr);
    // Note: Reader threads have an infinite loop, so pthread_join for them will block
    // indefinitely unless they are cancelled or have a condition to exit.
    // In this specific code, the main thread will wait for 'write_thread' to join,
    // but read1 and read2 will likely make the program hang here because they loop infinitely.
    // For a practical example, readers would also need an exit condition or be cancelled.
    // For this example's intent, the joins for readers demonstrate waiting for them if they were to finish.
    pthread_join(read1, nullptr); 
    pthread_join(read2, nullptr);

    cout << "\n--Final Updated Dataset:\n" << dataset << endl; // Print final dataset after threads finish

    sem_destroy(&S); // Destroy the semaphore resource

    return 0; // Program exit
}