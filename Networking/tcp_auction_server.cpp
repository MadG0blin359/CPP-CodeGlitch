#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <string>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
using namespace std;

#define PORT 8080
#define SIZE 1024
	
struct User {
	string username;
	string password;
};

struct AuctionItem {
    string code;
    string name;
    int starting_bid;
    int current_highest_bid;
};

vector<User> users = { {"admin", "123"}, {"user1", "pass"}, {"user2", "abc"} };
vector<AuctionItem> items = {
	{"001", "Antique Watch", 500, 0}, 
	{"002", "Vintage Camera", 200, 0}, 
	{"003", "Rate Book", 150, 0}
};

void log_bid(string client, string code, int amount) {
    ofstream logFile("bids_record.txt", ios::app);
    if (logFile.is_open()) {
        logFile << "Client: " << client << " | Item: " << code << " | Bid: " << amount << endl;
        logFile.close();
    }
}

void aution_details(int client_fd) {
	// --- Auction Initialization ---
	string welcome = "\nCode | Name | Starting Bid | Current Highest Bid\n";
	for (int i = 0; i < items.size(); i++) {
		welcome += items[i].code + " | " + items[i].name + " | " + to_string(items[i].starting_bid) + " | " + to_string(items[i].current_highest_bid) + "\n";
	}
	welcome += "\nEnter 'code amount' to bid (e.g., 001 800) or 'exit':\n";
	send(client_fd, welcome.c_str(), welcome.length(), 0);
}

bool user_authentication(int client_fd, string &username, string &password) {
	char buffer[SIZE];
	int bytes;

	// --- User Authentication ---
	send(client_fd, "Enter username: ", sizeof("Enter username: "), 0);
	memset(buffer, 0, SIZE);
	bytes = recv(client_fd, buffer, SIZE, 0);
	if (bytes <= 0) {
		cerr << "Connection Closed with Client " << client_fd << endl;
		return false;
	}
	username = buffer;
	
	send(client_fd, "Enter password: ", sizeof("Enter password: "), 0);
	memset(buffer, 0, SIZE);
	bytes = recv(client_fd, buffer, SIZE, 0);
	
	if (bytes <= 0) {
		cerr << "Connection Closed with Client " << client_fd << endl;
		return false;
	}
	password = buffer;
	
	bool auth = false;
	for (int i = 0; i < users.size(); i++) {
		if (username == users[i].username && password == users[i].password) {
			auth = true;
			break;
		}
	}
	return auth;
}

void handle_client(int client_fd, struct sockaddr_in clientAddr, socklen_t clientAddrLen) {
	string username, password;

	if (!user_authentication(client_fd, username, password)) {
		send(client_fd, "Authentication Failed! Connection Closed.", sizeof("Authentication Failed! Connection Closed."), 0);
		cout << "Authentication Failed! Connection Closed with Client " << client_fd << endl;
		close(client_fd);
		return;
	}

	// --- Auction Initialization ---
	string welcome = "\nWelcome " + username + "!\nOngoing Auctions:\n";
	send(client_fd, welcome.c_str(), welcome.length(), 0);
	aution_details(client_fd);
	
	// --- Auction Bidding Loop ---
	char buffer[SIZE];
	int bytes;
	while (1) {
		memset(buffer, 0, SIZE);
		int bytes = recv(client_fd, buffer, SIZE, 0);
		if (bytes <= 0 || strcmp(buffer, "exit") == 0) break;
		
		char req_code[5];
        	int bid_amt;
        	sscanf(buffer, "%s %d", req_code, &bid_amt);
        	
        	string response = "Item not found.";
        	for (int i = 0; i < items.size(); i++) {
        		if (req_code == items[i].code) {
        			if (bid_amt > items[i].starting_bid) {
		  			if (bid_amt > items[i].current_highest_bid) {
		  				items[i].current_highest_bid = bid_amt;
		  				log_bid(username, items[i].code, bid_amt);
		  				response = "SUCCESS: You are the highest bidder for " + items[i].name + "!";
		  			} else {
		  				response = "WARNING: Bid too low! Must be higher than " + to_string(items[i].current_highest_bid);
		  			}
		  		} else {
		  			response = "WARNING: Bid too low! Must be higher than starting bid " + to_string(items[i].starting_bid);
		  		}
		  		break;
        		}
        	}
        	send(client_fd, response.c_str(), response.length(), 0);
        	aution_details(client_fd);
	}
	
	cout << "[System] " << username << " logged out." << endl;
	close(client_fd);
}

int main() {
	int server_fd = socket(AF_INET, SOCK_STREAM, 0);
	
	int opt = 1;
	setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
	
	struct sockaddr_in serverAddr = {AF_INET, htons(PORT), INADDR_ANY}, clientAddr;
	socklen_t clientAddrLen = sizeof(clientAddr);
	bind(server_fd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	listen(server_fd, 5);
	
	cout << "Auction Server is now live! Waiting for clients..." << endl;

	while (1) {
		int client_fd = accept(server_fd, (struct sockaddr*)&clientAddr, &clientAddrLen);
		if (client_fd < 0) {
			cerr << "Connection Establishment Failed!" << endl;
			continue;
		} else {
			cout << "Connection Established with Client " << client_fd << "!" << endl;
		}
		
		thread(handle_client, client_fd, clientAddr, clientAddrLen).detach();
	}

	close(server_fd);

	return 0;
}
