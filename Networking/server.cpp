#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string> // Added for std::string

using namespace std;

int main() {
    int server_fd, new_socket;
    struct sockaddr_in serverAddr;
    socklen_t serverAddrLen = sizeof(serverAddr);
    
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("Server Socket Failed");
        return -1;
    }
    
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    
    // Check bind for errors
    if (bind(server_fd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Bind failed");
        return -1;
    }
    
    listen(server_fd, 3);
    cout << "Waiting for connection..." << endl;
    
    new_socket = accept(server_fd, (struct sockaddr*)&serverAddr, &serverAddrLen);
    if (new_socket < 0) {
        perror("Accept failed");
        return -1;
    }
    cout << "Connection Successful" << endl;

    // Fixed Communication Section
    char tempBuffer[1024] = {0}; // Use a char array for receiving
    ssize_t count;
    
    // 1. Receive into char array
    count = recv(new_socket, tempBuffer, 1024, 0);
    if (count > 0) {
        string message(tempBuffer); // Convert char array to C++ string
        cout << "Client said: " << message << endl;
    }
    
    // 2. Sending back
    string response = "\nMessage received! Server connection is closing...\n";
    // Use .c_str() for the pointer and .length() for the size
    send(new_socket, response.c_str(), response.length(), 0);
    
    close(new_socket);
    close(server_fd);

    return 0;
}
