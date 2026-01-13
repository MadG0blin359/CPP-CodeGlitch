#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string>  // Required for std::string
#include <cstring> // Required for strlen

using namespace std;

int main() {
    int client_fd;
    struct sockaddr_in serverAddr;
    
    client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd < 0) {
        perror("Socket creation failed");
        return -1;
    }
    
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    
    if (inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr) <= 0) {
        perror("Invalid address");
        return -1;
    }
    
    if (connect(client_fd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Connection Failed");
        return -1;
    }
    
    // --- Communication Section ---
    string message = "Testing...";
    send(client_fd, message.c_str(), message.length(), 0);
    
    char temp_buffer[1024] = {0}; // 1. Use a char array for receiving
    ssize_t count = recv(client_fd, temp_buffer, 1024 - 1, 0); // 2. Receive into array
    
    if (count > 0) {
        string response(temp_buffer); // 3. Convert to string safely
        cout << "Server said: " << response << endl;
    }
    
    close(client_fd);
    return 0;
}
