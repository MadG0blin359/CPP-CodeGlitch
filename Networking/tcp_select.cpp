#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>
#include <vector>
using namespace std;

#define PORT 8080
#define SIZE 1024

struct Client {
	int fd;
	struct sockaddr_in addr;
	socklen_t len = sizeof(addr);
};

int main() {
	int server_fd = socket(AF_INET, SOCK_STREAM, 0);
	
	// Allow port reuse (good practice for testing)
	int opt = 1;
	setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
	
	struct sockaddr_in serverAddr = {AF_INET, htons(PORT), INADDR_ANY};
	bind(server_fd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	listen(server_fd, 5);
	
	fd_set read_fds;
	vector<Client> clients;
	int max_fd = server_fd;
	char buffer[SIZE];
	int bytes;
	
	cout << "Server listening using Select() on Port 8080..." << endl;
	
	while (1) {
		FD_ZERO(&read_fds);
		FD_SET(server_fd, &read_fds);
		
		int max_fd = server_fd; // Reset max_fd every loop
		
		for (auto client : clients) {
			FD_SET(client.fd, &read_fds);
			if (client.fd > max_fd) max_fd = client.fd;
		}
		
		int activity = select(max_fd + 1, &read_fds, NULL, NULL, NULL);
		if (activity < 0) perror("Select Error.");
	
		if (FD_ISSET(server_fd, &read_fds)) {
			Client client;
			client.fd = accept(server_fd, (struct sockaddr*)&client.addr, &client.len);
			clients.push_back(client);
			cout << "New client connected: FD " << client.fd << endl;
		}
		
		for (auto it = clients.begin(); it != clients.end(); ) {
			if (FD_ISSET(it->fd, &read_fds)) {
				memset(buffer, 0, SIZE);
				bytes = recv(it->fd, buffer, SIZE, 0);
				
				if (bytes <= 0 || strcmp(buffer, "exit") == 0) {
					cout << "Connection Closed with Client " << it->fd << endl;
					close(it->fd);
					it = clients.erase(it);
					continue;
				} else {
					cout << "[Client " << it->fd << "]: " << buffer << endl;	
					send(it->fd, "Your Request Was Serviced.", sizeof("Your Request Was Serviced."), 0);				
				}
			}
			++it;
		}
	}
	
	close(server_fd);

	return 0;
}
