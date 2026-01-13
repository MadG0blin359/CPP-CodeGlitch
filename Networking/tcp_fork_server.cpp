#include <iostream>
#include <unistd.h>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
using namespace std;

#define PORT 8080
#define SIZE 1024

void handleClient(int client_fd, struct sockaddr_in clientAddr, socklen_t clientAddrLen) {
	char buffer[SIZE];
	ssize_t bytes;
	string res = "Your request was serviced";
	while (1) {
		memset(buffer, 0, sizeof(buffer));
		bytes = recv(client_fd, buffer, sizeof(buffer), 0);
		
		if (bytes <= 0) {
			cout << "Connection Closed with Client: " << client_fd << endl;
			break;
		} else {
			cout << "[Client " << client_fd << "]: " << buffer << endl;
		}
		
		if (strcmp(buffer, "exit") == 0) {
			cout << "Connection Closed with Client: " << client_fd << endl;
			break;
		}
		
		send(client_fd, res.c_str(), res.length(), 0);
		cout << "Request Serviced for Client " << client_fd << " by Child " << getpid() << endl;
	}
	
	close(client_fd);
	exit(0);
}

int main() {
	int server_fd, client_fd;
	struct sockaddr_in serverAddr, clientAddr;
	socklen_t clientAddrLen = sizeof(clientAddr);
	
	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = INADDR_ANY;
	serverAddr.sin_port = htons(PORT);
	
	bind(server_fd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	
	listen(server_fd, 2);
	cout << "Listening on Port " << PORT << endl;
	
	pid_t pid;
	
	while (1) {
		client_fd = accept(server_fd, (struct sockaddr*)&clientAddr, &clientAddrLen);
		if (client_fd < 0) {
			cout << "Connection accept() Failed!" << endl;
			continue;
		} else {
			cout << "--------------------------------------------------------------" << endl;
			cout << "Connection Established with Client " << client_fd << endl;
			cout << "--------------------------------------------------------------" << endl;
		}
		
		pid = fork();
		if (pid == 0) { 	// child
			close(server_fd);
			handleClient(client_fd, clientAddr, clientAddrLen);
		}
	}
	
	close(server_fd);
	
	return 0;
}
