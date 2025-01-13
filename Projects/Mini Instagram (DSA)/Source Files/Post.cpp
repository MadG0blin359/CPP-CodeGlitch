#include "Post.h"

// Default Constructor
Post::Post() : content(""), timestamp(""), username("") {}

// Constructor to initialize the post
Post::Post(string content, string timestamp, string username)
    : content(content), timestamp(timestamp), username(username) {}

// Getter for post content
string Post::getContent() {
    return content;
}

// Getter for post timestamp
string Post::getTimestamp() {
    return timestamp;
}

// Getter for the username of the poster
string Post::getUsername() {
    return username;
}

// Function to display the post content
void Post::display() {
    cout << "\nPost by: " << username << endl;
    cout << "Timestamp: " << timestamp << endl;
    cout << "Content: " << content << endl;
}

void Post::serialize(ofstream& ofs) const {
    ofs << content << "\n" << timestamp << "\n" << username << "\n";
}

bool Post::deserialize(std::ifstream& ifs) {
    getline(ifs, content);
    getline(ifs, timestamp);
    getline(ifs, username);
    return !ifs.fail();
}