#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <string.h>
#include <unistd.h>
#include <poll.h>
#include <sys/socket.h>
#include <netinet/in.h>
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
	
	cout << "Server listening with Poll on Port " << PORT << "..." << endl;
	
	vector<struct pollfd> pfds;
	
	struct pollfd server_pfd;
	server_pfd.fd = server_fd;
	server_pfd.events = POLLIN;
	pfds.push_back(server_pfd);
	
	char buffer[SIZE];
	int bytes;
	string entry;
	
	ofstream file("master_logs.txt", ios::app);
	if (!file.is_open()) {
		perror("Error! File Could Not Be Opened.\n");
		return -1;
	}
	
	while (1) {
		int ret = poll(pfds.data(), pfds.size(), -1);
		if (ret < 0) {
			perror("Poll Failed!\n");
			break;
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
				memset(buffer, 0, SIZE);
				bytes = recv(pfds[i].fd, buffer, SIZE, 0);
				if (bytes <= 0 || strcmp(buffer, "exit") == 0) {
					cout << "Connection Closed with Client " << pfds[i].fd << endl;
					close(pfds[i].fd);
					pfds.erase(pfds.begin() + i);
					i--;
				} else {
					cout << "[Client " << pfds[i].fd << "]: " << buffer;
					
					entry = "[Client " + to_string(pfds[i].fd) + "]: " + buffer;
					
					file.write(entry.c_str(), entry.length());
					file.flush(); // Trigger write to file when buffer is not full
					cout << "(Written to master_logs.txt file.)\n" << endl;
					
					send(pfds[i].fd, "Your Request was Serviced.", sizeof("Your Request was Serviced."), 0);
				}
			}
		}
	}
	
	close(server_fd);

	return 0;
}
