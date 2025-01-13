#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Post {
    string content;           
    string timestamp;         
    string username;          

public:
    Post();
    Post(string content, string timestamp, string username); 
    string getContent();
    string getTimestamp();
    string getUsername();
    void display();
    void serialize(ofstream& ofs) const;
    bool deserialize(ifstream& ifs);
};