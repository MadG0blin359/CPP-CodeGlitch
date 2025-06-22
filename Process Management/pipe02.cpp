#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
using namespace std;

int main() {
	int fd[2];
	char buffer[5];
	
	if ((pipe(fd) < 0)) {
		perror("Error! Pipe failed.\n");
		return 1;
	}

	pid_t pid;
	
	if ((pid = fork()) < 0) {
		perror("Error! Fork failed.\n");
		return 1;
	} else if (pid > 0) {
		close(fd[0]);
		
		cout << "Enter 5 integers: " << endl;
		for (int i = 0; i < sizeof(buffer); i++) {
			cin >> buffer[i];
		}
		
		ssize_t bytes_written = write(fd[1], buffer, sizeof(buffer));
		cout << getpid() << ": Parent wrote " << bytes_written << " bytes.\n";
		close(fd[1]);
		
		wait(NULL);
		
		cout << "Child Terminated!" << endl;
	} else {
		sleep(1);
		close(fd[1]);
		
		ssize_t bytes_read = read(fd[0], buffer, sizeof(buffer));
		
		for (int i = 0; i < bytes_read; i++) {
			cout << buffer[i] << endl;
		}
		
		close(fd[0]);
	}

	return 0;
}
