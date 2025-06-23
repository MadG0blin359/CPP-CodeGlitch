#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
using namespace std;

sem_t S;
int counter = 0;

void wait(sem_t* S) {
    sem_wait(S);
}

void signal(sem_t* S) {
    sem_post(S);
}

void* worker1(void* arg) {
    int local = 0;
	do {
		// Entry Section
		wait(&S);

		// Critical Section
		counter++;
		cout << "Worker1 Updated Counter:" << counter << endl;
		
		// Exit Section
		signal(&S);
		local++;
		sleep(1);
		
		// Remainder Section
		if (local == 5)
			break;
	
	} while (true);

    return nullptr;
}

void* worker2(void* arg) {
    int local = 0;
	do {
		// Entry Section
		wait(&S);
		
		// Critical Section
		counter++;
		cout << "Worker2 Updated Counter:" << counter << endl;
		
		// Exit Section
		signal(&S);
		local++;
		sleep(1);
		
		// Remainder Section
		if (local == 5)
			break;
	
	} while (true);

    return nullptr;
}

int main() {
    pthread_t t1, t2;

    sem_init(&S, 0, 1);

    pthread_create(&t1, nullptr, worker1, nullptr);
    pthread_create(&t2, nullptr, worker2, nullptr);

    pthread_join(t1, nullptr);
    pthread_join(t2, nullptr);

    cout << "\n--Final Updated Counter:" << counter << endl;

    sem_destroy(&S);

    return 0;
}
