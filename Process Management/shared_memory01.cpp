#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <cstring>
using namespace std;

int main() {
	void* shared_memory;
	char buffer[100];
	int shmid;
	
	shmid = shmget((key_t)1235, 1024, 0666 | IPC_CREAT);
	if (shmid < 0) {
		perror("Error! Segment creation failed.\n");
		return 1;
	}
	
	write(1, "Enter data: ", 12);
	ssize_t bytes_read = read(0, buffer, sizeof(buffer) - 1);
	buffer[bytes_read] = '\0';

	shared_memory = shmat(shmid, NULL, 0);
	strcpy((char*)shared_memory, buffer);

	cout << (char*)shared_memory;
	shmdt(shared_memory);
	shmctl(shmid, IPC_RMID,NULL);

	return 0;
}
