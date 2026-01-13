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

void receive_message(int server_fd, struct sockaddr_in* clientAddr, socklen_t* clientAddrLen) {
	char tempBuffer[SIZE];
	ssize_t count;
	
	while(1) {
		memset(tempBuffer, 0, sizeof(tempBuffer));
		count = recvfrom(server_fd, tempBuffer, sizeof(tempBuffer), 0, (struct sockaddr*)clientAddr, clientAddrLen);
		
		if (count > 0) {
            	cout << "\r[" << ntohs(clientAddr->sin_port) << "]: " << tempBuffer << endl;
            	cout << "[Server]: " << flush;
            }
	}

}

int main() {
	int server_fd;
	struct sockaddr_in serverAddr, clientAddr;
	socklen_t clientAddrLen = sizeof(clientAddr);
	
	server_fd = socket(AF_INET, SOCK_DGRAM, 0);
	if (server_fd < 0) {
		cout << "Socket Failed!" << endl;
		return -1;
	}

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = INADDR_ANY;
	serverAddr.sin_port = htons(PORT);
	
	if (bind(server_fd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
		cout << "Bind Failed!" << endl;
		return -2;
	}
	
	cout << "UDP Server listening on port " << PORT << "..." << endl;
	
	thread receive_thread(receive_message, server_fd, &clientAddr, &clientAddrLen);
	receive_thread.detach();
	
	string msg;
	
	while(1) {
		cout << "[Server]: ";
		getline(cin >> ws, msg);
	
		// Check if we actually have a client address yet
		if (clientAddr.sin_port == 0) {
			cout << "[System] Cannot send: No client has messaged us yet!" << endl;
			continue;
		}
	
		sendto(server_fd, msg.c_str(), msg.length(), 0, (struct sockaddr*)&clientAddr, clientAddrLen);
	}

	close(server_fd);	
	
	return 0;
}
