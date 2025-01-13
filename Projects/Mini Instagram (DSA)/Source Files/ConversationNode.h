#pragma once
#include <string>
#include "Stack.h"
#include "Message.h"
using namespace std;

class ConversationNode {
public:
    string friendUsername;    
    Stack<Message> messages;       
    ConversationNode* next;

    // Constructor to initialize a new conversation node
    ConversationNode(string& username) : friendUsername(username), next(nullptr) {}
};