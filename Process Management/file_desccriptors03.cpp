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
	
	shmid = shmget((key_t)1234, 1024, 0666 | IPC_CREAT);		// Create segment
	shm = shmat(shmid, NULL, 0);		// Add segment into process address space
	
	// Prompt for data input
	cout << "Enter data: ";
	getline(cin, buffer);
	
	// Store in memory
	char* temp_shm = (char*) shm;
	const char* temp_buffer = buffer.c_str();
	strcpy(temp_shm, temp_buffer);
	
	// Read from memory
	cout << "Data in memory: " << (char*) shm << endl;
	
	// Cleanup
	shmdt(shm);
	shmctl(shmid, IPC_RMID, NULL);
	
	return 0;
}
