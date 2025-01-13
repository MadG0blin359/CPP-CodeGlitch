#include "Message.h"

Message::Message()
{
    content = "";
    timestamp = "";
    sender = "";
    receiver = "";
}

Message::Message(const string& content, const string& timestamp, const string& sender, const string& receiver) {
    this->content = content;
    this->timestamp = timestamp;
    this->sender = sender;
    this->receiver = receiver;
}

void Message::display() const {
    cout << "[" << timestamp << "] " << sender << " to " << receiver << ": " << content << endl;
}

string Message::getContent() const {
    return content;
}

string Message::getTimestamp() const {
    return timestamp;
}

string Message::getSender() const {
    return sender;
}

string Message::getReceiver() const {
    return receiver;
}

void Message::serialize(ofstream& ofs) const {
    ofs << content << "\n" << timestamp << "\n" << sender << "\n" << receiver << "\n";
}

bool Message::deserialize(ifstream& ifs) {
    getline(ifs, content);
    getline(ifs, timestamp);
    getline(ifs, sender);
    getline(ifs, receiver);
    return !ifs.fail();
}