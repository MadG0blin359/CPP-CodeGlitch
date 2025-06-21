#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

int main() {
	pid_t pid;
	
	pid = fork();
	
	if (pid == -1) {
		cout << "Error!";
		return 1;
	}
	
	if (pid > 0) {
		waitpid(pid, NULL, 0);
		cout << "I am parent " << getpid() << ", my child1 is " << pid << endl;
		pid = fork();
		if (pid > 0) {
			cout << "\nI am parent again " << getpid() << ", my parent is " << getppid() << endl;

		}
	} else {
		cout << "\nI am child1, my pid is " << getpid() << ", my parent is " << getppid() << endl;
	}

	return 0;
}
