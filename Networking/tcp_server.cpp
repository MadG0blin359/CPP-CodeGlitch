#include <iostream>
#include <sys/socket.h>	// socket(), bind(), connect(), listen(), accept(), send(), recv()
#include <arpa/inet.h>	// htons(), htonl(), ntohs(), ntohl(), inet_pton(), inet_ntoa()
#include <netinet/in.h>	// struct sockaddr, struct sockaddr_in
#include <unistd.h>	// fork(), getpid(), close()
#include <string.h>	// strcmp(), memset()
#include <thread>
using namespace std;

#define PORT 8080

void receive_message(int client_socket) {
	char tempBuffer[1024];
	ssize_t count;
	while (1) {
		memset(tempBuffer, 0, sizeof(tempBuffer));
		count = 0;
		count = recv(client_socket, tempBuffer, sizeof(tempBuffer), 0);
		if (count > 0) {
			cout << "\r[Client]: " << tempBuffer << endl;
			// If the message arrives after this cout line is printed, /r will clear the previously printed "[Server]:"
			cout << "[Server]: " << flush;
		} else {
			cout << "Error! Connection Closed with Client."<< endl;
			close(client_socket);
			break;
		}
		
		if (strcmp(tempBuffer, "exit") == 0) {
			cout << "Error! Connection Closed with Client " << endl;
			close(client_socket);
			break;
		}
	}
}

int main (int argc, char const* argv[]) {
	if (argc < 2) {
		cout << "Arguments Required!" << endl;
		exit(0);
	}

	int server_fd, new_socket;
	struct sockaddr_in serverAddr;
	struct sockaddr_in clientAddr;
	socklen_t clientAddrLen = sizeof(clientAddr);
	
	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_fd < 0) {
		cout << "Server Socket Failed!" << endl;
		return -1;
	}
	
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = INADDR_ANY;	// Use all 3 IP addressess this machine currently owns. i.e. Wi-Fi, Ethernet, Loop back
	serverAddr.sin_port = htons(PORT);
	
	if (bind(server_fd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
		cout << "Function Call to bind() Failed!" << endl;
		return -2;
	}

	listen(server_fd, atoi(argv[1]));
	cout << "Server started. Waiting for connections..." << endl;
	
	new_socket = accept(server_fd, (struct sockaddr*)&clientAddr, &clientAddrLen);
	if (new_socket < 0) {
		cout << "Function Call to accept() Failed!" << endl;
		return -3;
	} else {
		cout << "- Client IP: " << inet_ntoa(clientAddr.sin_addr) << endl;
		cout << "- Client Port: " << ntohs(clientAddr.sin_port) << endl;
		cout << "--------------------------------------------------------------" << endl;
		thread receive_thread(receive_message, new_socket);
		receive_thread.detach(); // Allow it to run independently
	}
	
	string msg;
	
	while (1) {
		cout << "[Server]: ";
		getline(cin >> ws, msg);
		
		send(new_socket, msg.c_str(), msg.length(), 0);
	}

	close(new_socket);
	close(server_fd);

	return 0;
}
