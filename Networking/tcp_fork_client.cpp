#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <thread>
using namespace std;

#define SIZE 1042

void receive_message(int client_fd) {
	char tempBuffer[SIZE] = {0};
	ssize_t count;
	
	while (1) {
		memset(tempBuffer, 0, sizeof(tempBuffer));
		count = 0;
		count = recv(client_fd, tempBuffer, sizeof(tempBuffer), 0);
		
		if (count > 0) {
			// \r clears the current line to help with messy terminal output
			cout << "\r[Server]: " << tempBuffer << endl;
			// If the message arrives after this cout line is printed, /r will clear the previously printed "[Client]:"
			cout << "[Client]: " << flush;
		} else {
			cout << "Connection Closed!" << endl;
			close(client_fd);
			exit(0);
		}
	}
}

int main(int argc, char const* argv[]) {
	int client_fd, status;
	struct sockaddr_in serverAddr;
	
	client_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (client_fd < 0) {
		cout << "Client Socket Failed!" << endl;
		return -1;
	}
	
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(8080);
	if (inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr) <= 0) {	// man inet_pton
		cout << "Function Call to inet_pton() Failed!" << endl;
		return -2;
	}

	cout << "Connecting to server..." << endl;
	status = connect(client_fd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	if (status < 0) {
		cout << "Connection to Server Failed!" << endl;
		return -3;
	} else {
		cout << "Connection to Server Successfull!" << endl;
		cout << "Server IP: " << inet_ntoa(serverAddr.sin_addr) << endl;
		cout << "Server Port: " << ntohs(serverAddr.sin_port) << endl;
		cout << "--------------------------------------------------------------" << endl;
		thread receive_thread(receive_message, client_fd);
		receive_thread.detach();
	}
	
	string msg;
	
	while (1) {
		cout << "[Client]: ";
		// Use ws to clear any leftover newlines
		getline(cin >> ws, msg);
		
		if (send(client_fd, msg.c_str(), msg.length(), 0) < 0) {
			cout << "Error! Message Not Sent." << endl;
			return -4;
		}
		
		if (msg == "exit") {
			cout << "Connection is Closing..." << endl;
			break;
		}
	}
	
	close(client_fd);
	
	return 0;
}
