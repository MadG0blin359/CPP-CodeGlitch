#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cctype>
#include <stdexcept>
using namespace std;

class FriendRequest {
    string senderName;     
    string requestTimestamp;
    string status;

public:
    //Default Constructor
    FriendRequest();
    // Constructor to initialize a new Friend Request
    FriendRequest(const string& sender);

    string getSender() const;
    string getTimestamp() const;
    string getStatus();

    // Fundtions to modify the status of the request
    void acceptRequest();
    void rejectRequest();

    // Fundtions to display the friend request information
    void displayRequestInfo();

    // Functions for file handling
    void serialize(ofstream& ofs) const;
    bool deserialize(ifstream& ifs);

    // Destructor
    ~FriendRequest();
};