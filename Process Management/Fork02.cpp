#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;

int main() {
	pid_t pid;

	pid = fork();
	
	if (pid == -1) {
		return 1;
	} else if (pid > 0) {
		wait(NULL);
		cout << "I am parent " << getpid() << ". My child01 is " << pid << endl;
		pid = fork();
		if (pid == 0) {
			cout << "I am child02: " << getpid() << ". My parent is " << getppid() << endl;
		} else {
			wait(NULL);
			cout << "I am parent " << getpid() << ". My child02 is " << pid << endl;	
		}
		
	} else {
		cout << "I am child01: " << getpid() << ". My parent is " << getppid() << endl;
	}

	return 0;
}
