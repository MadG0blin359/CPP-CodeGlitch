#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

// Define two mutex locks
pthread_mutex_t first_mutex;
pthread_mutex_t second_mutex;

void* do_work_one(void* param) {
    pthread_mutex_lock(&first_mutex);
    cout << "Thread One acquired first lock" << endl;
    sleep(1); // Simulate some delay
    cout << "Thread One trying to acquire second lock" << endl;
    pthread_mutex_lock(&second_mutex);

    cout << "Thread One acquired both locks" << endl;

    pthread_mutex_unlock(&second_mutex);
    pthread_mutex_unlock(&first_mutex);

    pthread_exit(0);
}

void* do_work_two(void* param) {
    pthread_mutex_lock(&second_mutex);
    cout << "Thread Two acquired second lock" << endl;
    sleep(1); // Simulate some delay
    cout << "Thread Two trying to acquire first lock" << endl;
    pthread_mutex_lock(&first_mutex);

    cout << "Thread Two acquired both locks" << endl;

    pthread_mutex_unlock(&first_mutex);
    pthread_mutex_unlock(&second_mutex);

    pthread_exit(0);
}

int main() {
    pthread_t thread1, thread2;

    // Initialize mutexes
    pthread_mutex_init(&first_mutex, NULL);
    pthread_mutex_init(&second_mutex, NULL);

    // Create threads
    pthread_create(&thread1, NULL, do_work_one, NULL);
    pthread_create(&thread2, NULL, do_work_two, NULL);

    // Join threads
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Destroy mutexes
    pthread_mutex_destroy(&first_mutex);
    pthread_mutex_destroy(&second_mutex);

    return 0;
}

