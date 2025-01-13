#include "Notification.h"

string Notification::getMessage() {
    return content;
}

string Notification::getTimestamp() {
    return timestamp;
}

string Notification::getType() {
    return type;
}

Notification::Notification() {}

Notification::Notification(const string& content, const string& timestamp, const string& type) {
    this->content = content;
    this->timestamp = timestamp;
    this->type = type;
    status = "[NEW]";
}

Notification::Notification(const FriendRequest& friendRequest, const string& type) {
    this->friendRequest = friendRequest;
    this->content = "Friend request from " + friendRequest.getSender();
    this->timestamp = friendRequest.getTimestamp();
    this->type = type;
    status = "[NEW]";
}

Notification::Notification(const Message& message, const string& type) {
    this->msg = message;
    this->content = "Message from " + message.getSender();
    this->timestamp = message.getTimestamp();
    this->type = type;
    status = "[NEW]";
}

void Notification::displayNotification() {
    cout << "Status: " << status << endl;
    cout << "Type: " << type << endl;
    cout << "Notification: " << content << endl;
    cout << "Timestamp: " << timestamp << endl;
    
    /*if (type == "FRIEND_REQUEST") {
        cout << "Sender: " << friendRequest.getSender() << endl; 
    }
    else if (type == "MESSAGE") { 
        cout << "Sender: " << msg.getSender() << endl;
        cout << "Content: " << msg.getContent() << endl;
    }*/
}

void Notification::serialize(std::ofstream& ofs) const {
    ofs << content << "\n" << timestamp << "\n" << type << "\n";
    if (type == "FRIEND_REQUEST") {
        friendRequest.serialize(ofs);
    }
    else if (type == "MESSAGE") {
        msg.serialize(ofs);
    }
}

bool Notification::deserialize(std::ifstream& ifs) {
    ifs >> content >> timestamp >> type;
    if (type == "FRIEND_REQUEST") {
        return friendRequest.deserialize(ifs);
    }
    else if (type == "MESSAGE") {
        return msg.deserialize(ifs);
    }
    return !ifs.fail();
}