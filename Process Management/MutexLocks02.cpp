#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

// Define two mutex locks
pthread_mutex_t resource1;
pthread_mutex_t resource2;

// Function where a thread acquires resources in increasing order
void* safe_work(void* param) {
    int thread_id = *(int*)param;

    // Always lock in increasing order
    pthread_mutex_lock(&resource1);
    cout << "Thread " << thread_id << " acquired first lock" << endl;
    sleep(1);  // Simulate work
    pthread_mutex_lock(&resource2);
    cout << "Thread " << thread_id << " acquired second lock" << endl;

    cout << "Thread " << thread_id << " acquired both resources safely." << endl;

    pthread_mutex_unlock(&resource2);
    pthread_mutex_unlock(&resource1);

    pthread_exit(0);
}

int main() {
    pthread_t thread1, thread2;
    int id1 = 1, id2 = 2;

    // Initialize mutexes
    pthread_mutex_init(&resource1, NULL);
    pthread_mutex_init(&resource2, NULL);

    // Create threadswith the strict ordering rule
    pthread_create(&thread1, NULL, safe_work, &id1);
    pthread_create(&thread2, NULL, safe_work, &id2);

    // Join threads
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Destroy mutexes
    pthread_mutex_destroy(&resource1);
    pthread_mutex_destroy(&resource2);

    return 0;
}

