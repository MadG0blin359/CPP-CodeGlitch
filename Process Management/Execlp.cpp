#include <iostream>
#include <unistd.h>
using namespace std;

int main() {
	
	cout << "7 is going to execute 3" << endl;
	execlp("./3", "file name: 3.cpp", "8", NULL);

	return 0;
}
