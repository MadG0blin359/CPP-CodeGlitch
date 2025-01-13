#include "FriendRequest.h"

FriendRequest::FriendRequest() {
    senderName = " ";
    requestTimestamp = " ";
    status = " ";
}

FriendRequest::FriendRequest(const string& sender) : senderName(sender), status("PENDING") {
    time_t now = time(0);
    char buffer[26];
    ctime_s(buffer, sizeof(buffer), &now);
    requestTimestamp = buffer;
}

void FriendRequest::acceptRequest() { 
    status = "ACCEPTED"; 
} 

void FriendRequest::rejectRequest() { 
    status = "REJECTED"; 
}

void FriendRequest::displayRequestInfo(){
    cout << "Sender: " << senderName << endl;
    cout << "Status: " << status << endl;
    cout << "Timestamp: " << requestTimestamp << endl;
}

string FriendRequest::getSender() const {
    return senderName;
}

string FriendRequest::getTimestamp() const {
    return requestTimestamp;
}

string FriendRequest::getStatus() {
    return status;
}

void FriendRequest::serialize(std::ofstream& ofs) const {
    ofs << senderName << "\n" << requestTimestamp << "\n" << status << "\n";
}

bool FriendRequest::deserialize(std::ifstream& ifs) {
    ifs >> senderName >> requestTimestamp >> status;
    return !ifs.fail();
}

FriendRequest::~FriendRequest() {}