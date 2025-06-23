#include <iostream>
#include <string>
#include <unistd.h>
using namespace std;

int main() {
	char buffer[256];
	cout << sizeof(buffer) << endl;
	
	read(0, buffer, 10);
	write(1, buffer, 10);

	return 0;
}
