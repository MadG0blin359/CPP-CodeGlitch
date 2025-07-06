#include <iostream>  // For input/output operations (cout)
#include <unistd.h>  // For sleep()
#include <pthread.h> // For POSIX threads (pthread_create, pthread_join, mutexes)
#include <sys/types.h> // For types like pid_t (though not directly used for process IDs here)
#include <stdlib.h>  // For rand(), srand(), atoi()
#include <time.h>    // For time() to seed rand()
using namespace std;

pthread_mutex_t counter_lock; // Mutex to protect read_count
pthread_mutex_t rw_lock;      // Mutex for read-write access to shared_data

int read_count = 0;   // Number of readers currently reading
int shared_data = 0;  // The shared resource

// Writer thread function
void* writer(void* arg) {
    int wid = *((int*)arg); // Get writer ID
    
    while (true) { // Loop indefinitely
        pthread_mutex_lock(&rw_lock); // Acquire write lock (exclusive access)
        
        cout << "Writer: " << wid << " is now updating data.\n";
        shared_data++; // Modify shared data
        cout << "Writer: " << wid << " wrote new data " << shared_data << "\n";
        pthread_mutex_unlock(&rw_lock); // Release write lock
        sleep(rand() % 3); // Simulate work
    }
    
    return NULL; // Thread exit (unreachable in infinite loop)
}

// Reader thread function
void* reader(void* arg) {
    int rid = *((int*)arg); // Get reader ID

    while (true) { // Loop indefinitely
        pthread_mutex_lock(&counter_lock); // Acquire lock for read_count
        read_count++; // Increment reader count
        
        if (read_count == 1) { // If this is the first reader
            cout << "Reader: " << rid << " is first reader. Now trying to acquire rw_lock.\n";
            pthread_mutex_lock(&rw_lock); // Acquire read lock (blocks writers)
            cout << "Reader: " << rid << " is first reader. Now acquired rw_lock.\n";
        }
        
        pthread_mutex_unlock(&counter_lock); // Release lock for read_count
        
        cout << "Reader: " << rid << " is reading... Shared Data: " << shared_data << endl; // Read shared data
        
        pthread_mutex_lock(&counter_lock); // Acquire lock for read_count
        read_count--; // Decrement reader count
        if (read_count == 0) { // If this is the last reader
            cout << "Reader: " << rid << " is last reader. Now releasing rw_lock.\n";
            pthread_mutex_unlock(&rw_lock); // Release read lock (allows writers)
        }
        pthread_mutex_unlock(&counter_lock); // Release lock for read_count
        sleep(rand() % 20); // Simulate work
    }

    return NULL; // Thread exit (unreachable in infinite loop)
}

// Main function
int main(int argc, char* argv[]) {
    // Get number of readers and writers from command-line arguments
    int num_of_reader = atoi(argv[1]);
    int num_of_writer = atoi(argv[2]);

    // Initialize mutexes
    pthread_mutex_init(&counter_lock, NULL);
    pthread_mutex_init(&rw_lock, NULL);

    // Declare arrays for thread IDs
    pthread_t reader_tid[num_of_reader];
    pthread_t writer_tid[num_of_writer];
    srand(time(NULL)); // Seed random number generator
    
    // Create reader threads
    int rid[num_of_reader]; // Array to hold reader IDs
    for (int i = 0; i < num_of_reader; i++) {
        rid[i] = i; // Assign ID
        if (pthread_create(&reader_tid[i], NULL, reader, &rid[i]) != 0) {
            cout << "\nFailed to create reader thread " << rid[i] << endl;
        }
    }

    // Create writer threads
    int wid[num_of_writer]; // Array to hold writer IDs
    for (int i = 0; i < num_of_writer; i++) {
        wid[i] = i; // Assign ID
        if (pthread_create(&writer_tid[i], NULL, writer, &wid[i]) != 0) {
            cout << "\nFailed to create writer thread " << wid[i] << endl;
        }
    }
    
    // Join reader threads (will block indefinitely as threads loop infinitely)
    for (int i = 0; i < num_of_reader; i++) {
        pthread_join(reader_tid[i], NULL);
    }
    
    // Join writer threads (will block indefinitely as threads loop infinitely)
    for (int i = 0; i < num_of_writer; i++) {
        pthread_join(writer_tid[i], NULL);
    }

    // Destroy mutexes
    pthread_mutex_destroy(&counter_lock);
    pthread_mutex_destroy(&rw_lock);
    
    return 0; // Program exit (unreachable due to infinite loops)
}