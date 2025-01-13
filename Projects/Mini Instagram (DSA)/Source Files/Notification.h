#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "FriendRequest.h"
#include "Message.h"
using namespace std;

class Notification {
public:
    Notification();
    Notification(const string& content, const string& timestamp, const string& type); 
    Notification(const FriendRequest& friendRequest, const string& type); 
    Notification(const Message& message, const string& type);

    void displayNotification();
    string getMessage();
    string getTimestamp();
    string getType();

    void serialize(ofstream& ofs) const;
    bool deserialize(ifstream& ifs);

private:
    string content;
    string timestamp;
    string type;
    string status;
    FriendRequest friendRequest;
    Message msg;
};
