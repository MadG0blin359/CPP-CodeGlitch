#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <string>
using namespace std;

sem_t S;
string dataset = "Synchronization tool that provides more sophisticated ways (than Mutex locks) for processes to synchronize their activities is called semaphores. Semaphore S – an integer variable can only be accessed via two indivisible (atomic) operations. ";

void wait(sem_t* S) {
    sem_wait(S);
}

void signal(sem_t* S) {
    sem_post(S);
}

void* writer(void* arg) {
	string local;
	do {
		wait(&S);
		cout << "\n--Write Data In:\n" << dataset << endl;		

		cout << "\n-> Write data: ";
		getline(cin, local);
		
		if (local == "exit") {
			cout << "\nWriter Terminating!\n";
			signal(&S);
			break;
		}

		dataset += local;
		signal(&S);
		sleep(1);

	} while (1);

	return nullptr;
}

void* reader(void* arg) {
	do {
		wait(&S);
		cout << "\n--Reader Reading Data:\n" << dataset << endl;
		signal(&S);
		sleep(1);

	} while (1);

	return nullptr;
}

int main() {
    pthread_t read1, read2, write;

    sem_init(&S, 0, 1);

    pthread_create(&write, nullptr, writer, nullptr);
    pthread_create(&read1, nullptr, reader, nullptr);
    pthread_create(&read2, nullptr, reader, nullptr);

    pthread_join(write, nullptr);
    pthread_join(read1, nullptr);
    pthread_join(read2, nullptr);

    cout << "\n--Final Updated Dataset:\n" << dataset << endl;

    sem_destroy(&S);

    return 0;
}
