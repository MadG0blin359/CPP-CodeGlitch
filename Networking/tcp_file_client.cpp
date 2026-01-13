#include <iostream>
#include <cstring>
#include <fstream>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
using namespace std;

#define PORT 8080
#define SIZE 1024

int main() {
	int client_fd = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in serverAddr = {AF_INET, htons(PORT)};
	inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);
	
	int status = connect(client_fd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	if (status >= 0) {
		cout << "Connection Established with Server." << endl
			<< "Server IP: " << inet_ntoa(serverAddr.sin_addr) << endl
			<< "Server Port: " << ntohs(serverAddr.sin_port) << endl; 
	} else {
		perror("Connection to Server Failed!\n");
		return -1;
	}
	
	ifstream file("local_app.log");
	if (!file.is_open()) {
		perror("File Could Not Be Opened!\n");
		return -2;
	}
	
	string line;
	cout << "Transfering ERROR & CRITICAL logs to Server..." << endl;
	
	while (getline(file, line, '\n')) {
        // Check if the line contains the required keywords
        if (line.find("ERROR") != string::npos || line.find("CRITICAL") != string::npos) {
            line += '\n';
            if (send(client_fd, line.c_str(), line.length(), 0) < 0) {
                perror("Send failed");
                break;
            }
            sleep(1);
        }
    }
	
	char buffer[SIZE] = {0};
	recv(client_fd, buffer, SIZE, 0);
	cout << "[Server]: " << buffer << endl;
	
	cout << "Transfer complete. Closing connection." << endl;
	close(client_fd);
	file.close();
	
	return 0;	
}
