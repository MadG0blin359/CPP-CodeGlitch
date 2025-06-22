#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
using namespace std;

int main() {
	int w_fd;
	char buffer[256];
	ssize_t bytes_read;
	
	w_fd = open("test.txt", O_CREAT | O_WRONLY, 0644);
	
	cout << "Enter data to store in file: " << endl;
	bytes_read = read(0, buffer, sizeof(buffer));
	cout << "\nYou wrote: " << buffer << endl;
	
	write(w_fd, buffer, bytes_read);
	close(w_fd);
	
	int r_fd;
	r_fd = open("test.txt", O_RDONLY);
	
	bytes_read = read(r_fd, buffer, bytes_read);
	cout << "\nYou read: " << buffer << endl;
	
	close(r_fd);
	
	int a_fd;
	a_fd = open("test.txt", O_RDWR | O_APPEND);
	
	// Read the entire content of the file
	// If the end of the file (EOF) is reached and no more bytes can be read, read() returns 0.
	// If an error occurs, read() returns -1, and the global variable errno is set to indicate the type of error.
	// If bytes_read is 0, it means EOF has been reached, and the loop terminates.
	// If bytes_read is -1, it means an error occurred
	cout << "Data in file:" << endl;	
	while ((bytes_read = read(a_fd, buffer, sizeof(buffer)-1)) > 0) {
		buffer[bytes_read] = '\0';
		write(1, buffer, bytes_read);
	}
	
	cout << "\n\nEnter data to append: ";
	write(1, "Enter data to append: ", 22);
	bytes_read = read(0, buffer, sizeof(buffer));
	
	write(a_fd, buffer, bytes_read);
	close(a_fd);
	
	r_fd = open("test.txt", O_RDONLY);
	cout << "Updated data in file:" << endl;	
	while ((bytes_read = read(a_fd, buffer, sizeof(buffer)-1)) > 0) {
		buffer[bytes_read] = '\0';
		write(1, buffer, bytes_read);
	}
	
	close(r_fd);
	
	return 0;
}
