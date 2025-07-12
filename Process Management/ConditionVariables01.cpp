#include <iostream>
#include <unistd.h>  // For gettid()
#include <pthread.h> // For pthread functions
#include <sys/types.h> // For basic system types
#include <sys/wait.h>  // For wait (though not used for process wait in this thread example)
#include <vector>      // For vector (though not used in this example)
#include <string>      // For std::stoi
#include <stdlib.h>    // For rand, srand
using namespace std;

// Synchronization primitives
pthread_mutex_t my_lock; // Mutex for shared access
pthread_cond_t my_cond;  // Condition variable for signaling
int condition = 0;       // Shared variable representing a condition state

// Thread function 1 (sets condition and signals)
void* my_function1(void* arg) {
    pthread_mutex_lock(&my_lock); // Acquire lock
    // work on shared variable
    cout << "check" << gettid() << endl; // Output thread ID
    condition = 1; // Change condition
    pthread_mutex_unlock(&my_lock); // Release lock
    pthread_cond_signal(&my_cond); // Signal waiting threads
    return NULL;
}

// Thread function 2 (waits for condition)
void* my_function2(void* arg) {
    pthread_mutex_lock(&my_lock); // Acquire lock
    // Wait while condition is not met (releases lock and waits)
    while (condition <= 0)
        pthread_cond_wait(&my_cond, &my_lock);
    // work on shared variable (condition met, lock re-acquired)
    cout << "test" << gettid() << endl; // Output thread ID
    pthread_mutex_unlock(&my_lock); // Release lock
    return NULL;
}

int main(int argc, char* argv[]) {
    // Command line argument handling
    cout << "Total Arguments: " << argc << endl;
    cout << "File Name: " << argv[0] << endl;
    cout << "Argument 1: " << argv[1] << endl;
    cout << "Argument 2: " << argv[2] << endl;
    
    int arg1 = stoi(argv[1]);
    string arg2 = argv[2];
    
    cout << "\narg1: " << arg1;
    cout << "\narg2: " << arg2 << endl;
    
    // Initialize mutex and condition variable
    pthread_mutex_init(&my_lock, NULL);
    pthread_cond_init(&my_cond, NULL);
    
    pthread_t tid[2]; // Array for thread IDs
    
    // Unused random number and dynamic allocation code
    srand(time(NULL));
    cout << rand() % 15;
    int *id;
    id = new int[5];
    delete[] id;
    
    // Create threads
    pthread_create(&tid[0], NULL, &my_function1, NULL);
    pthread_create(&tid[1], NULL, &my_function2, NULL);
    
    // Join threads (wait for them to finish)
    for (int i = 0; i < 2; i++) {
        pthread_join(tid[i], NULL);
    }
    
    // Destroy mutex and condition variable
    pthread_mutex_destroy(&my_lock);
    pthread_cond_destroy(&my_cond);
    return 0; // Program exit
}