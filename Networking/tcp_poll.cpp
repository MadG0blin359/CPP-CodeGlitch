#include <iostream>
#include <cstring>
#include <unistd.h>
#include <vector>
#include <sys/socket.h>
#include <netinet/in.h>
#include <poll.h>
using namespace std;

#define PORT 8080
#define SIZE 1024

int main() {
	int server_fd = socket(AF_INET, SOCK_STREAM, 0);
	
	int opt = 1;
	setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
	
	struct sockaddr_in serverAddr = {AF_INET, htons(PORT), INADDR_ANY};
	bind(server_fd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	listen(server_fd, 5);
	
	// Create a vector to manage our array of pollfd structures
	vector<struct pollfd> pfds;
	
	struct pollfd server_pfd;
	server_pfd.fd = server_fd;
	server_pfd.events = POLLIN;
	pfds.push_back(server_pfd);
	
	cout << "Server listening with poll() on port " << PORT << "..." << endl;
	
	char buffer[SIZE];
	int bytes;
	
	while (1) {
		// Wait for activity on any monitored socket
		// (pointer to the array, number of fds in the array, infinte timeout (-1))
		int ret = poll(pfds.data(), pfds.size(), -1);
		if (ret < 0) {
			perror("Poll Failed!");
			return -1;
		}
		
		if (pfds[0].revents & POLLIN) {
			int new_sock = accept(server_fd, NULL, NULL);
			if (new_sock > 0) {
				struct pollfd client_pfd;
				client_pfd.fd = new_sock;
				client_pfd.events = POLLIN;
				pfds.push_back(client_pfd);
				cout << "New client connected. FD: " << new_sock << endl;
			}
		}
		
		for (int i = 1; i < pfds.size(); i++) {
			if (pfds[i].revents & POLLIN) {
				memset(buffer, 0, sizeof(buffer));
				bytes = recv(pfds[i].fd, buffer, SIZE, 0);
				if (bytes <= 0) {
					cout << "Connection Closed with Client " << pfds[i].fd << endl;
					close(pfds[i].fd);
					pfds.erase(pfds.begin() + i);
					i--; // Adjust index after erasing
				} else {
					cout << "[Client " << pfds[i].fd << "]: " << buffer << endl;
					send(pfds[i].fd, "Your Request Was Serviced.", sizeof("Your Request Was Serviced."), 0);
				}
			}
		}
	}
	
	close(server_fd);
	
	return 0;
}
