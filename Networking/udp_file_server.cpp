#include <iostream>
#include <cstring>
#include <fstream>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
using namespace std;

#define PORT 8080
#define SIZE 1024

int main() {
	int server_fd;
	struct sockaddr_in serverAddr, clientAddr;
	socklen_t clientAddrLen = sizeof(clientAddr);

	server_fd = socket(AF_INET, SOCK_DGRAM, 0);
	
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = INADDR_ANY;
	serverAddr.sin_port = htons(PORT);
	
	bind(server_fd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	
	char buffer[SIZE];
	char srcName[SIZE] = {0}, destName[SIZE] = {0};

    	cout << "Server Listening..." << endl;
    	
    	recvfrom(server_fd, srcName, sizeof(srcName), 0, (struct sockaddr*)&clientAddr, &clientAddrLen);
    	cout << "Source File specified by client: " << srcName << endl;
    	
    	recvfrom(server_fd, destName, sizeof(destName), 0, (struct sockaddr*)&clientAddr, &clientAddrLen);
    	cout << "Destination File will be: " << destName << endl;
    	
    	ofstream outFile(destName, ios::binary);
    	if (!outFile.is_open()) {
		cout << "Could not open destination file!" << endl;
		return -1;
	}
    	
    	while (1) {
    		memset(buffer, 0, sizeof(buffer));
    		ssize_t bytes = recvfrom(server_fd, buffer, SIZE, 0, (struct sockaddr*)&clientAddr, &clientAddrLen);
    		
    		if (strncmp(buffer, "END_OF_FILE", 11) == 0) {
    			cout << "Copy complete." << endl;
            	break;
    		}
    		
    		if (bytes > 0) {
    			outFile.write(buffer, bytes);
    		}
    	}

	outFile.close();
	close(server_fd);

	return 0;
}
