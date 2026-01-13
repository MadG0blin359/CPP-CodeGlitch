#include <iostream>
#include <fstream>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
using namespace std;

#define PORT 8080
#define SIZE 1024

int main() {
	int client_fd;
	struct sockaddr_in serverAddr;
	socklen_t serverAddrLen = sizeof(serverAddr);
	
	client_fd = socket(AF_INET, SOCK_DGRAM, 0);
	
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);
	
	string src, dst;
	
	cout << "Source File Name: ";
	cin >> src;
	
	sendto(client_fd, src.c_str(), src.length(), 0, (struct sockaddr*)&serverAddr, serverAddrLen);
	
	cout << "Destination File Name (on Server): ";
	cin >> dst;
	
	sendto(client_fd, dst.c_str(), dst.length(), 0, (struct sockaddr*)&serverAddr, serverAddrLen);
	
	ifstream file(src, ios::binary);
	if (!file.is_open()) {
		cout << "Could not open source file!" << endl;
		return -1;
	}
	
	char buffer[SIZE];
	memset(buffer, 0, sizeof(buffer));
	cout << "Transferring content..." << endl;
	
	while (file.read(buffer, SIZE) || file.gcount() > 0) {
		sendto(client_fd, buffer, file.gcount(), 0, (struct sockaddr*)&serverAddr, serverAddrLen);
	}
	
	// Send Termination Signal
    	sendto(client_fd, "END_OF_FILE", 11, 0, (struct sockaddr*)&serverAddr, serverAddrLen);
	
	recvfrom(client_fd, buffer, sizeof(buffer), 0, (struct sockaddr*)&serverAddr, &serverAddrLen);
	cout << "[Server]: " << buffer << endl;
	
	cout << "Finished sending." << endl;
	file.close();
	close(client_fd);
	
	return 0;
}
