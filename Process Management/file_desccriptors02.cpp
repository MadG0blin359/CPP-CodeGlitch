#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <cstring>
#include <string>
using namespace std;

int main() {
	void* shm;
	string buffer;
	int shmid;
	
	shmid = shmget((key_t)1425, 1024, 0666 | IPC_CREAT);
	shm = shmat(shmid, NULL, 0);
	
	char* temp = (char*)shm;
	
	cout << "Enter data: ";
	getline(cin, buffer);
	
	for (int i = 0; i < buffer.length(); i++) {
		temp[i] = buffer[i];
		// cout << i << ". " << temp[i] << endl;	// Print data on each byte/index of shared memory
	}
	
	cout << "\nData in shared memory:\n";
	cout << (char*) shm;
	
	shmctl(shmid, IPC_RMID, NULL);
	shmdt(shm);

	return 0;
}
