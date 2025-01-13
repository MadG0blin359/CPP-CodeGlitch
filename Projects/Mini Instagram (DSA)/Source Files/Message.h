#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Message {
public:
    Message();
    Message(const string& content, const string& timestamp, const string& sender, const string& receiver);

    void display() const;
    string getContent() const;
    string getTimestamp() const;
    string getSender() const;
    string getReceiver() const;
    void serialize(ofstream& ofs) const;
    bool deserialize(ifstream& ifs);

private:
    string content;
    string timestamp;
    string sender;
    string receiver;
};