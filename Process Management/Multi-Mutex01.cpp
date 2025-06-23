#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
using namespace std;

pthread_mutex_t counter_lock;
pthread_mutex_t rw_lock;

int read_count = 0;
int shared_data = 0;

void* writer(void* arg) {
	int wid = *((int*)arg);
	
	while (true) {
		pthread_mutex_lock(&rw_lock);
		
		cout << "Writer: " << wid << " is now updating data.\n";
		shared_data++;
		cout << "Writer: " << wid << " wrote new data " << shared_data << "\n";
		pthread_mutex_unlock(&rw_lock);
		sleep(rand() % 3);
	}
	
	return NULL;
}

void* reader(void* arg) {
	int rid = *((int*)arg);

	while (true) {
		pthread_mutex_lock(&counter_lock);
		read_count++;
		
		if (read_count == 1) {
			cout << "Reader: " << rid << " is first reader. Now trying to acquire rw_lock.\n";
			pthread_mutex_lock(&rw_lock);
			cout << "Reader: " << rid << " is first reader. Now acquired rw_lock.\n";
		}
		
		pthread_mutex_unlock(&counter_lock);
		
		cout << "Reader: " << rid << " is reading... Shared Data: " << shared_data << endl;
		
		pthread_mutex_lock(&counter_lock);
		read_count--;
		if (read_count == 0) {
			cout << "Reader: " << rid << " is last reader. Now releasing rw_lock.\n";
			pthread_mutex_unlock(&rw_lock);
		}
		pthread_mutex_unlock(&counter_lock);
		sleep(rand() % 20);
	}

	return NULL;
}

int main(int argc, char* argv[]) {
	int num_of_reader = atoi(argv[1]);
	int num_of_writer = atoi(argv[2]);

	pthread_mutex_init(&counter_lock, NULL);
	pthread_mutex_init(&rw_lock, NULL);

	pthread_t reader_tid[num_of_reader], writer_tid[num_of_writer];
	srand(time(NULL));
	
	int rid[num_of_reader];
	for (int i = 0; i < num_of_reader; i++) {
		rid[i] = i;
		if (pthread_create(&reader_tid[i], NULL, reader, &rid[i]) != 0) {
			cout << "\nFailed to create thread " << rid[i] << endl;
		}
	}

	int wid[num_of_writer];
	for (int i = 0; i < num_of_writer; i++) {
		wid[i] = i;
		if (pthread_create(&writer_tid[i], NULL, writer, &wid[i]) != 0) {
			cout << "\nFailed to create thread " << wid[i] << endl;
		}
	}
	
	for (int i = 0; i < num_of_reader; i++) {
		pthread_join(reader_tid[i], NULL);
	}
	
	for (int i = 0; i < num_of_writer; i++) {
		pthread_join(writer_tid[i], NULL);
	}

	pthread_mutex_destroy(&counter_lock);
	pthread_mutex_destroy(&rw_lock);
	
	return 0;
}
