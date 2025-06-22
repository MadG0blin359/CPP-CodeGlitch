#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <string>
#include <sys/wait.h>
using namespace std;

int main() {
	char buffer[256];
	int fd[2];
	string msg = "Hello from parent: " + to_string(getpid());
	
	if (pipe(fd) == -1) {
		perror("Error! Create file descriptors failed.\n");
		return 1;
	}

	pid_t pid;
	if ((pid = fork()) < 0) {
		perror("Error! Fork failed.\n");
		return 2;
	} else if (pid > 0) {
		close(fd[0]);
		cout << "Waiting for child" << endl;
		
		ssize_t bytes_written = write(fd[1], msg.c_str(), msg.length());
		if (bytes_written < 0) {
			perror("Error! Parent fd[1] failed.\n");
			return 3;
		}
		close(fd[1]);
		cout << "Parent (" << getpid() << "): Message was successfully sent to child." << endl;
		
		wait(NULL);
		cout << "Parent (" << getpid() << "): My child (" << pid << ") was successfully terminated." << endl;
	} else {
		sleep(1);	// execute parent first
		close(fd[1]);
		ssize_t bytes_read = read(fd[0], buffer, sizeof(buffer));
		if (bytes_read < 0) {
			perror("Error! Child fd[0] failed.\n");
			return 4;
		} else {
			cout << "Bytes read from parent: " << bytes_read << endl;
		}	
		
		cout << "Child (" << getpid() << "): Message recieved - " << buffer << endl;
		
		close(fd[0]);
	}

	return 0;
}
