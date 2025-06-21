#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
using namespace std;

int main() {
	pid_t pid;
	
	// 2 level process tree
	if ((pid = fork()) == -1) {
		cout << "Error!" << endl;
	} else if (pid > 0) {
		cout << "I am parent: " << getpid() << endl;
		wait(NULL);
		pid = fork();
		if (pid > 0) {
			wait(NULL);
		} else {
			cout << "\n-> I am right child02: " << getpid() << ". My parent is " << getppid() << endl;
			int pid2 = fork();
			if (pid2 > 0) {
				wait(NULL);
				int pid3 = fork();
				if (pid3 > 0) {
					wait(NULL);
				} else {
					cout << "I am right child of child02: " << getpid() << ". My parent is " << getppid() << endl;
				}
			} else {
				cout << "I am left child of child02: " << getpid() << ". My parent is " << getppid() << endl;
			}
		}
	} else {
		cout << "\n-> I am left child01: " << getpid() << ". My parent is " << getppid() << endl;
		int pid2 = fork();
		if (pid2 > 0) {
			wait(NULL);
			int pid3 = fork();
			if (pid3 > 0) {		
				wait(NULL);
			} else {
				cout << "I am right child of child01: " << getpid() << ". My parent is " << getppid() << endl;
			}
		} else {
			cout << "I am left child of child01: " << getpid() << ". My parent is " << getppid() << endl;
		}
	}

	return 0;
}
