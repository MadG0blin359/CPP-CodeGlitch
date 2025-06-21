#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/types.h>
using namespace std;

int *philosophers = nullptr;
pthread_mutex_t *chopsticks = nullptr;
sem_t eating;		// Only N-1 philosophers are allowed to eat at a time

void* philosopher(void* arg) {
	int p_id = *((int*)arg);

	while (true) {
		cout << "Philosopher: " << p_id << " is thinking.\n";
		sleep(rand() % 6);
		sem_wait(&eating);
		
		pthread_mutex_lock(&chopsticks[p_id]);	// Acquire left chopstick
		cout << "Philosopher: " << p_id << " acquired left chopstick.\n";
		pthread_mutex_lock(&chopsticks[(p_id+1) % *philosophers]);	// Acqurie right chopstick
		cout << "Philosopher: " << p_id << " acquired right chopstick.\n";
		
		cout << "Philosopher: " << p_id << " has started eating.\n";
		
		pthread_mutex_unlock(&chopsticks[p_id]);
		cout << "Philosopher: " << p_id << " released left chopstick.\n";
		pthread_mutex_unlock(&chopsticks[(p_id+1) % *philosophers]);
		cout << "Philosopher: " << p_id << " released right chopstick.\n";
		
		sem_post(&eating);
		sleep(rand() % 15);
	}
	
	return NULL;
}

int main(int argc, char* argv[]) {
	int num_of_philosophers = atoi(argv[1]);
	philosophers = new int(num_of_philosophers);
	chopsticks = new pthread_mutex_t[num_of_philosophers];
	
	cout << "There are total " << num_of_philosophers << " Philosophers." << endl;
	
	for (int i = 0; i < num_of_philosophers; i++) {
		pthread_mutex_init(&chopsticks[i], NULL);
	}
	sem_init(&eating, 0, num_of_philosophers - 1);
	
	pthread_t p_tid[num_of_philosophers];
	
	srand(time(NULL));
	
	int p_id[num_of_philosophers];
	for (int i = 0; i < num_of_philosophers; i++) {
		p_id[i] = i;
		pthread_create(&p_tid[i], NULL, philosopher, &p_id[i]);
	}
	
	for (int i = 0; i < num_of_philosophers; i++) {
		pthread_join(p_tid[i], NULL);
	}

	for (int i = 0; i < num_of_philosophers; i++) {
    		pthread_mutex_destroy(&chopsticks[i]);
	}
	sem_destroy(&eating);

	delete philosophers;
	delete[] chopsticks;

	return 0;
}
