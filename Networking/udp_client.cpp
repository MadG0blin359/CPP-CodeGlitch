#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <cstring>
#include <thread>
using namespace std;

#define PORT 8080
#define SIZE 1024

void receive_message(int client_fd, struct sockaddr_in* serverAddr, socklen_t* serverAddrLen) {
	char tempBuffer[SIZE];
	ssize_t count;
	
	while (1) {
		memset(tempBuffer, 0, sizeof(tempBuffer));
		
		count = recvfrom(client_fd, tempBuffer, sizeof(tempBuffer), 0, (struct sockaddr*)serverAddr, serverAddrLen);
		
		if (count > 0) {
            	cout << "\r[Server]: " << tempBuffer << endl;
            	cout << "[Client]: " << flush;
            }
	}
}

int main() {
	int client_fd;
	struct sockaddr_in serverAddr;
	socklen_t serverAddrLen = sizeof(serverAddr);
	
	client_fd = socket(AF_INET, SOCK_DGRAM, 0);
	if (client_fd < 0) {
		cout << "Socket Failed!" << endl;
		return -1;
	}
	
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	if (inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr) <= 0) {
		cout << "Function Call to inet_pton() Failed!" << endl;
		return -2;
	}
	
	thread receive_thread(receive_message, client_fd, &serverAddr, &serverAddrLen);
	receive_thread.detach();
	
	string msg;
	
	while (1) {
		cout << "[Client]: ";
		getline(cin >> ws, msg);
		
		sendto(client_fd, msg.c_str(), msg.length(), 0, (struct sockaddr*)&serverAddr, serverAddrLen);
		if (msg == "exit") break;
	}

	close(client_fd);

	return 0;
}
