#include "User.h"
using namespace std;

// Default Constructor
User::User() : next(nullptr), conversationHead(nullptr) {}

// Constructor to initialize a User object
User::User(const string& name, const string& password, const string& city, const string& lastLogin) : username(name), password(password), city(city), lastLogin(lastLogin), next(nullptr), conversationHead(nullptr) {}

string User::getTime() {
    time_t now = time(0);
    char buffer[26];
    ctime_s(buffer, sizeof(buffer), &now);
    return buffer;
}

// Method to display the user profile information
void User::displayProfile() {
    cout << "\n=== User Profile ===";
    cout << "\nUsername: " << username;
    cout << "\nCity: " << city;
    cout << "\nLast Login: " << lastLogin << endl;
}

// Method to validate the user's password during login
bool User::validatePassword(string& inputPassword) {
    return inputPassword == password;
}

// Method to reset the password (after login)
void User::resetPassword(string& pass) {
    password = pass;
    cout << GREEN << "\n-----Password Updated Successfully!-----" << RESET << endl;
}

// Method to add a post to the user's posts stack
void User::addPost(string& content, string& timestamp) {
    Post newPost(content, timestamp, username);
    posts.push(newPost);
}

void User::viewNewsfeed() const {
    Node<User*>* current = following.getHead();

    if (current == nullptr) {
        cout << RED << "\n-----Newsfeed is Empty!-----" << RESET << endl;
    }
    
    while (current) {
    
        Stack<Post> temp = current->data->posts;

        while (!temp.isEmpty()) {
            temp.getTop().display();       // Display Post
            temp.pop();
        }
    current = current->next;
    }
}

void User::viewPosts() const {
    Stack<Post> temp = posts;

    if (temp.isEmpty()) {
        cout << RED << "\n-----No Posts Found!-----" << RESET << endl;
    }

    while (!temp.isEmpty()) {
        temp.getTop().display();        // Display Post
        temp.pop();
    }
}

void User::displayFollowers() const {
    followers.display();
}

// Method to find an existing conversation with a specific friend
ConversationNode* User::findConversation(string& friendUsername) {
    ConversationNode* current = conversationHead;

    if (current == nullptr) {
        cout << RED << "\n-----No Conversations Found!-----" << RESET << endl;
    }

    while (current != nullptr) {
        if (current->friendUsername == friendUsername) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

// Method to send a message to a friend
void User::sendMessage(User& friendUser, Message& msg) {
    friendUser.messages.push(msg);
    string type = "MESSAGE";
    Notification notification(msg, type);
    friendUser.notifications.enqueue(notification);
}

// Method to receive a message from a friend
void User::receiveMessage(Message& msg, string& senderUsername) {
    ConversationNode* conversation = findConversation(senderUsername);
    if (conversation == nullptr) {
        // If the conversation does not exist, create a new one
        conversation = new ConversationNode(senderUsername);
        conversation->next = conversationHead;
        conversationHead = conversation;
    }
    // Now it is safe to use conversation
    conversation->messages.push(msg);
}


// Method to display all messages with a specific friend
void User::displayMessages(string& friendUsername) {

    ConversationNode* conversation = findConversation(friendUsername);
    if (conversation != nullptr) {
        cout << "\n=== Messages with " << friendUsername << " ===" << endl;
        Stack<Message> tempMessages = conversation->messages; 
        while (!tempMessages.isEmpty()) {
            tempMessages.getTop().display();
            tempMessages.pop();
        }
    }
    else {
        cout << RED << "No conversation with " << friendUsername << " found." << RESET << endl;
    }
}

// Method to check if there are pending friend requests 
 bool User::hasPendingFriendRequests() const { 
 return (!friendRequests.isEmpty());
 }

// Method to send a friend request to another user
void User::sendFriendRequest(User& receiver) {
    if (receiver.hasPendingFriendRequestFrom(username)) { 
        cout << RED << "\n-----You have already sent a friend request to " << receiver.getUsername() << "-----" << RESET << endl;
        return; 
    }

    FriendRequest request(username);
    receiver.friendRequests.enqueue(request);
    string type = "FRIEND_REQUEST";
    Notification notification(request, type);
    receiver.notifications.enqueue(notification);
    cout << GREEN << "\n-----Friend request sent to " << receiver.getUsername() << "-----" << RESET << "\n";
}

// Method to accept a friend request
void User::acceptFriendRequest(User* sender) {
    Queue<FriendRequest> temp = friendRequests;
    bool found = false;
    while (!temp.isEmpty()) {
        FriendRequest* request = temp.getFront();  // pointer
        if (request != nullptr && request->getSender() == sender->getUsername() && request->getStatus() == "PENDING") {
            request->acceptRequest();
            
             // Add sender to followers 
             if (!followers.contains(sender))
                followers.add(sender); 
 
             // Add sender to following 
             if (!following.contains(sender))
                following.add(sender); 

            Notification notification("Your friend request to " + username + " has been accepted.", getTime(), "FRIEND_REQUEST");
            sender->addNotification(notification);

            found = true;
            break;
        }
        temp.dequeue();
    }
    if (!found) {
        cout << RED << "\nNo pending friend request from " << sender->getUsername() << " found." << RESET << endl;
    }
    else {
        cout << "\nFriend request from " << sender->getUsername() << GREEN << " accepted." << RESET << endl;
        friendRequests.dequeue();
    }
}

// Method to reject a friend request
void User::rejectFriendRequest(string& senderUsername) {
    //Queue<FriendRequest> temp = friendRequests; bool found = false; 
    //while (!temp.isEmpty()) {
    //    FriendRequest* request = temp.getFront(); 
    //    // Use pointer instead of reference 
    //    if (request->getSender() == senderUsername && request->getStatus() == "PENDING") { 
    //    request->rejectRequest(); 
    //    string currentTime = getTime(); 
    //    Notification notification("Your friend request to " + username + " has been rejected.", currentTime, string("FRIEND_REQUEST")); 
    //    temp.dequeue();
    //    addNotification(notification); 
    //    found = true; 
    //    break; 
    //    } 
    //    temp.dequeue(); 
    //} 
    //if (!found) { 
    //    cout << RED << "\nNo pending friend request from " << senderUsername << " found." << RESET << endl;
    //} 
        cout << "\nFriend request from " << senderUsername << RED << " rejected." << RESET << endl;
}

void User::displayFriendRequests() const {
    Queue<FriendRequest> temp = friendRequests;

    if (temp.isEmpty()) {
        cout << RED << "\n-----No Pending Friend Requests!-----" << RESET << endl;
    }

    while (!temp.isEmpty()) {
        temp.getFront()->displayRequestInfo();
        temp.dequeue();
    }
}

bool User::isFriendOrFollower(const string& username) const {
    Node<User*>* current = followers.getHead();
    while (current != nullptr) {
        if (current->data->getUsername() == username) { 
            return true; 
        } 
        current = current->next; 
    } 

    current = following.getHead(); 
    
    while (current != nullptr) { 
        if (current->data->getUsername() == username) { 
            return true; 
        } 
        current = current->next; 
    }
    return false;
}

// Method to check if the receiver has a pending friend request from the sender
bool User::hasPendingFriendRequestFrom(const string& senderUsername) const {
    Queue<FriendRequest> temp = friendRequests;
    while (!temp.isEmpty()) {
        if (temp.getFront()->getSender() == senderUsername && temp.getFront()->getStatus() == "PENDING") {
            return true;
        }
        temp.dequeue();
    }
    return false;
}

void User::displayFriends() const {
    cout << "\n=== Friends ===" << endl; 

    Node<User*>* current = following.getHead(); 
    if (current == nullptr) { 
        cout << RED << "\n-----No Friends Found!-----" << RESET << endl;
    }
    else { 
        while (current != nullptr) { 
        cout << current->data->getUsername() << endl; current = current->next; 
        } 
    }    
}

// Method to add a notification
void User::addNotification(Notification& notification) {
    notifications.enqueue(notification);
}

// Method to display all notifications
void User::displayNotifications() {
    Queue<Notification> temp = notifications;

    if (temp.isEmpty()) {
        cout << RED << "\n-----No New Notificaitons!-----" << RESET << endl;
    }

    while (!temp.isEmpty()) {
        temp.getFront()->displayNotification();
        temp.dequeue();
    }
}

// Encapsulataion
string User::getUsername()
{
    return username;
}

string User::getCity()
{
    return city;
}

string User::getLastLogin()
{
    return lastLogin;
}

//User* User::getNext() { 
//    return next; 
//}
//
//void User::setNext(User* nextUser) {
//    next = nextUser; 
//}

void User::serialize(ofstream& ofs) const {
    ofs << username << "\n" << password << "\n" << city << "\n" << lastLogin << "\n";
}

bool User::deserialize(ifstream& ifs) {
    getline(ifs, username);
    getline(ifs, password);
    getline(ifs, city);
    getline(ifs, lastLogin);
    return !ifs.fail();
}

// Clean up dynamically allocated memory for conversations
User::~User() { 
    ConversationNode* current = conversationHead; 
    while (current != nullptr) { 
        ConversationNode* temp = current; 
        current = current->next; 
        delete temp; 
    } 
}