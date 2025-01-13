#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Stack.h"
#include "Queue.h"
#include "LinkedList.cpp"
#include "Post.h"
#include "FriendRequest.h"
#include "Message.h"
#include "ConversationNode.h"
#include "Notification.h"
using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"

class User {
private:
    // User Profile Data
    string username;
    string password;
    string city;
    string lastLogin;

    // Stacks for posts (Newsfeed and Messages)
    Stack<Post> posts;
    Stack<Message> messages;

    // Queue for friend requests
    Queue<FriendRequest> friendRequests;

    // Queue for notifications (friend requests, messages)
    Queue<Notification> notifications;

    // Linked List for follwers and following
    LinkedList<User*> followers;
    LinkedList<User*> following;    // Friends

    // Graph edges for user relationships (this could be a list of friends or an adjacency list)
    User* next;

    // Linked list head for managing conversations with other users
    ConversationNode* conversationHead;

public:
    // Default & Parametrized Constructor
    User();
    User(const string& name, const string& password, const string& city, const string& lastLogin);
    string getTime();

    // User Profile Methods
    void displayProfile();  
    bool validatePassword(string& inputPassword);  
    void resetPassword(string& pass);

    // Post & Followers Management
    void addPost(string& content, string& timestamp); 
    void viewNewsfeed() const;
    void viewPosts() const;
    void displayFollowers() const;

    // Messaging
    ConversationNode* findConversation(string& friendUsername); 
    void sendMessage(User& friendUser, Message& msg);
    void receiveMessage(Message& msg, string& senderUsername);  
    void displayMessages(string& friendUsername);

    // Friend Request Management
    bool hasPendingFriendRequests() const;
    void sendFriendRequest(User& receiver); 
    void acceptFriendRequest(User* sender);
    void rejectFriendRequest(string& senderUsername);
    void displayFriendRequests() const;
    bool isFriendOrFollower(const string& username) const; 
    bool hasPendingFriendRequestFrom(const string& senderUsername) const;
    void displayFriends() const;

    // Notifications
    void addNotification(Notification& notification);  
    void displayNotifications(); 

    // Accessors (Getters) for private member variables
    string getUsername();
    string getCity();
    string getLastLogin();

    // Getter and Setter for linked list node
    /*User* getNext();
    void setNext(User* nextUser);*/

    // File Handling
    void serialize(ofstream& ofs) const;
    bool deserialize(ifstream& ifs);

    // Destructor
    ~User();
};
