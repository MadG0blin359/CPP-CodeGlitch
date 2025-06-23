#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
using namespace std;

int main() {
	int fd;
	char buffer[256];
	ssize_t bytes_read;
	
	if (mkfifo("chat", 0666) < 0) {
		perror("Error! Make fifo failed.\n");
		return 1;
	}
	
	while (true) {
		fd = open("chat", O_WRONLY);
		write(1, "You: ", 5);
		bytes_read = read(0, buffer, sizeof(buffer));
		write(fd, buffer, bytes_read);
		close(fd);
	
		fd = open("chat", O_RDONLY);		
		bytes_read = read(fd, buffer, sizeof(buffer));
		write(1, "User: ", 6);
		write(1, buffer, bytes_read);
		close(fd);
	}

	return 0;
}
