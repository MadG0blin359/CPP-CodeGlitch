//#include <iostream>
//#include <string>
//#include <ctime>
//#include <cctype>
//#include <stdexcept>
//using namespace std;
//
//template <typename K, typename V>
//class HashMap {
//private:
//    static const int BUCKET_COUNT = 100;
//
//    class HashNode {
//    public:
//        K key;
//        V value;
//        HashNode* next;
//
//        HashNode(const K& key, const V& value) : key(key), value(value), next(nullptr) {}
//    };
//
//    HashNode* table[BUCKET_COUNT];
//
//    int hash(const K& key) const {
//        int hashValue = 0;
//        for (char ch : key) {
//            hashValue = (hashValue * 31 + ch) % BUCKET_COUNT;
//        }
//        return hashValue;
//    }
//
//public:
//    HashMap() {
//        for (int i = 0; i < BUCKET_COUNT; ++i) {
//            table[i] = nullptr;
//        }
//    }
//
//    void insert(const K& key, const V& value) {
//        int bucketIndex = hash(key);
//        HashNode* prev = nullptr;
//        HashNode* entry = table[bucketIndex];
//        while (entry != nullptr && entry->key != key) {
//            prev = entry;
//            entry = entry->next;
//        }
//        if (entry == nullptr) {
//            entry = new HashNode(key, value);
//            if (prev == nullptr) {
//                table[bucketIndex] = entry;
//            }
//            else {
//                prev->next = entry;
//            }
//        }
//        else {
//            entry->value = value;
//        }
//    }
//
//    V* get(const K& key) {
//        int bucketIndex = hash(key);
//        HashNode* entry = table[bucketIndex];
//        while (entry != nullptr) {
//            if (entry->key == key) {
//                return &entry->value;
//            }
//            entry = entry->next;
//        }
//        return nullptr;
//    }
//
//    void display() const {
//        for (int i = 0; i < BUCKET_COUNT; ++i) {
//            HashNode* entry = table[i];
//            while (entry != nullptr) {
//                std::cout << entry->key << std::endl;
//                entry = entry->next;
//            }
//        }
//    }
//};
//
//template <typename T>
//class ListNode {
//public:
//    T data;
//    ListNode* next;
//    ListNode(const T& data) : data(data), next(nullptr) {}
//};
//
//template <typename T>
//class LinkedList {
//private:
//    ListNode<T>* head;
//    ListNode<T>* tail;
//
//public:
//    LinkedList() : head(nullptr), tail(nullptr) {}
//
//    void add(const T& data) {
//        ListNode<T>* newNode = new ListNode<T>(data);
//        if (tail) {
//            tail->next = newNode;
//        }
//        else {
//            head = newNode;
//        }
//        tail = newNode;
//    }
//
//    bool contains(const T& data) const {
//        ListNode<T>* current = head;
//        while (current) {
//            if (current->data == data) {
//                return true;
//            }
//            current = current->next;
//        }
//        return false;
//    }
//
//    void display() const {
//        ListNode<T>* current = head;
//        while (current) {
//            std::cout << current->data << " ";
//            current = current->next;
//        }
//        std::cout << std::endl;
//    }
//
//    ListNode<T>* getHead() const {
//        return head;
//    }
//
//    ~LinkedList() {
//        ListNode<T>* current = head;
//        while (current) {
//            ListNode<T>* next = current->next;
//            delete current;
//            current = next;
//        }
//    }
//};
//
//template <typename T>
//class Stack {
//private:
//    class Node {
//    public:
//        T data;
//        Node* next;
//        Node(const T& data) : data(data), next(nullptr) {}
//    };
//    Node* topNode;
//
//public:
//    Stack() : topNode(nullptr) {}
//
//    bool isEmpty() const {
//        return topNode == nullptr;
//    }
//
//    void push(const T& value) {
//        Node* newNode = new Node(value);
//        newNode->next = topNode;
//        topNode = newNode;
//    }
//
//    void pop() {
//        if (isEmpty()) return;
//        Node* temp = topNode;
//        topNode = topNode->next;
//        delete temp;
//    }
//
//    T& top() {
//        return topNode->data;
//    }
//
//    const T& top() const {
//        return topNode->data;
//    }
//};
//
//template <typename T>
//class Queue {
//private:
//    struct Node {
//        T data;
//        Node* next;
//    };
//    Node* frontNode;
//    Node* rearNode;
//    int size;
//
//public:
//    Queue() : frontNode(nullptr), rearNode(nullptr), size(0) {}
//
//    ~Queue() {
//        while (!isEmpty()) {
//            pop();
//        }
//    }
//
//    bool isEmpty() const {
//        return size == 0;
//    }
//
//    void push(const T& value) {
//        Node* newNode = new Node{ value, nullptr };
//        if (rearNode) {
//            rearNode->next = newNode;
//        }
//        else {
//            frontNode = newNode;
//        }
//        rearNode = newNode;
//        ++size;
//    }
//
//    void pop() {
//        if (isEmpty()) return;
//        Node* temp = frontNode;
//        frontNode = frontNode->next;
//        if (!frontNode) {
//            rearNode = nullptr;
//        }
//        delete temp;
//        --size;
//    }
//
//    T& front() {
//        if (isEmpty()) throw std::out_of_range("Queue is empty");
//        return frontNode->data;
//    }
//
//    const T& front() const {
//        if (isEmpty()) throw std::out_of_range("Queue is empty");
//        return frontNode->data;
//    }
//};
//
//class Post {
//private:
//    std::string content;
//    std::string timestamp;
//    std::string username;
//
//public:
//    Post(const std::string& content, const std::string& timestamp, const std::string& username)
//        : content(content), timestamp(timestamp), username(username) {}
//
//    void displayPost() const {
//        std::cout << "[" << timestamp << "] " << username << ": " << content << std::endl;
//    }
//};
//
//class Message {
//private:
//    std::string content;
//    std::string timestamp;
//    std::string sender;
//    std::string receiver;
//
//public:
//    Message() : content(""), timestamp(""), sender(""), receiver("") {}
//
//    Message(const std::string& content, const std::string& timestamp, const std::string& sender, const std::string& receiver)
//        : content(content), timestamp(timestamp), sender(sender), receiver(receiver) {}
//
//    void displayMessage() const {
//        std::cout << "[" << timestamp << "] " << sender << " to " << receiver << ": " << content << std::endl;
//    }
//
//    std::string getSender() const {
//        return sender;
//    }
//
//    std::string getTimestamp() const {
//        return timestamp;
//    }
//};
//
//class FriendRequest {
//private:
//    std::string senderName;
//    std::string requestTimestamp;
//    enum RequestStatus { PENDING, ACCEPTED, REJECTED } status;
//
//public:
//    FriendRequest() : senderName(""), requestTimestamp(""), status(PENDING) {}
//
//    FriendRequest(const std::string& sender) : senderName(sender), status(PENDING) {
//        
//
//         time_t now = time(0);
// char buffer[26];
// ctime_s(buffer, sizeof(buffer), &now);
// requestTimestamp = buffer;
//    }
//
//    std::string getSender() const {
//        return senderName;
//    }
//
//    std::string getTimestamp() const {
//        return requestTimestamp;
//    }
//
//    void acceptRequest() {
//        status = ACCEPTED;
//    }
//
//    void rejectRequest() {
//        status = REJECTED;
//    }
//
//    void displayRequestInfo() const {
//        std::cout << "Sender: " << senderName << "\nTimestamp: " << requestTimestamp << "\nStatus: ";
//        if (status == PENDING) {
//            std::cout << "Pending\n";
//        }
//        else if (status == ACCEPTED) {
//            std::cout << "Accepted\n";
//        }
//        else {
//            std::cout << "Rejected\n";
//        }
//    }
//};
//
//class Notification {
//private:
//    std::string content;
//    std::string timestamp;
//    std::string type;
//    FriendRequest friendRequest;
//    Message msg;
//
//public:
//    Notification(const std::string& content, const std::string& timestamp, const std::string& type)
//        : content(content), timestamp(timestamp), type(type) {}
//
//    Notification(const FriendRequest& friendRequest, const std::string& type)
//        : friendRequest(friendRequest), content("Friend request from " + friendRequest.getSender()),
//        timestamp(friendRequest.getTimestamp()), type(type) {}
//
//    Notification(const Message& msg, const std::string& type)
//        : msg(msg), content("New message from " + msg.getSender()), timestamp(msg.getTimestamp()), type(type) {}
//
//    void displayNotification() const {
//        if (type == "GENERAL") {
//            std::cout << "[" << timestamp << "] " << content << std::endl;
//        }
//        else if (type == "FRIEND_REQUEST") {
//            std::cout << "Friend Request: ";
//            friendRequest.displayRequestInfo();
//        }
//        else if (type == "MESSAGE") {
//            msg.displayMessage();
//        }
//    }
//
//    std::string getMessage() const {
//        return content;
//    }
//
//    std::string getTimestamp() const {
//        return timestamp;
//    }
//
//    std::string getType() const {
//        return type;
//    }
//};
//
//class User {
//public:
//    User(const std::string& username, const std::string& password, const std::string& city, const std::string& lastLogin);
//
//    void displayProfile() const;
//    bool validatePassword(const std::string& inputPassword) const;
//    std::string getName() const;
//
//    void addPost(const std::string& content, const std::string& timestamp);
//    void displayFriendRequests() const;
//    void displayFollowers() const;
//    void displayNotifications() const;
//
//    void sendMessage(User& friendUser, const Message& msg);
//    void viewNewsfeed() const;
//    void viewPosts() const;
//
//    void sendFriendRequest(User& user);
//
//private:
//    std::string username;
//    std::string password;
//    std::string city;
//    std::string lastLogin;
//
//    Stack<Post> posts;
//    Stack<Message> messages;
//    Queue<FriendRequest> friendRequests;
//    Queue<Notification> notifications;
//    LinkedList<User*> followers;
//    LinkedList<User*> following;
//};
//
//User::User(const std::string& username, const std::string& password, const std::string& city, const std::string& lastLogin)
//    : username(username), password(password), city(city), lastLogin(lastLogin) {}
//
//void User::displayProfile() const {
//    std::cout << "Username: " << username << "\nCity: " << city << "\nLast Login: " << lastLogin << "\n";
//}
//
//bool User::validatePassword(const std::string& inputPassword) const {
//    return password == inputPassword;
//}
//
//std::string User::getName() const {
//    return username;
//}
//
//void User::addPost(const std::string& content, const std::string& timestamp) {
//    Post newPost(content, timestamp, username);
//    posts.push(newPost);
//}
//
//void User::displayFriendRequests() const {
//    Queue<FriendRequest> temp = friendRequests;
//    while (!temp.isEmpty()) {
//        temp.front().displayRequestInfo();
//        temp.pop();
//    }
//}
//
//void User::displayFollowers() const {
//    std::cout << "Followers List:\n";
//    followers.display();
//}
//
//void User::displayNotifications() const {
//    Queue<Notification> temp = notifications;
//    while (!temp.isEmpty()) {
//        temp.front().displayNotification();
//        temp.pop();
//    }
//}
//
//void User::sendMessage(User& friendUser, const Message& msg) {
//    friendUser.messages.push(msg);
//    Notification notification(msg, "MESSAGE");
//    friendUser.notifications.push(notification);
//}
//
//void User::viewNewsfeed() const {
//    std::cout << "Newsfeed:\n";
//    ListNode<User*>* current = following.getHead();
//    while (current) {
//        Stack<Post> temp = current->data->posts;
//        while (!temp.isEmpty()) {
//            temp.top().displayPost();
//            temp.pop();
//        }
//        current = current->next;
//    }
//}
//
//void User::viewPosts() const {
//    Stack<Post> temp = posts;
//    while (!temp.isEmpty()) {
//        temp.top().displayPost();
//        temp.pop();
//    }
//}
//
//void User::sendFriendRequest(User& user) {
//    FriendRequest request(username);
//    user.friendRequests.push(request);
//    Notification notification(request, "FRIEND_REQUEST");
//    user.notifications.push(notification);
//}
//
//// Utility function to check if a password is strong
//bool isPasswordStrong(const std::string& password) {
//    if (password.length() < 8)
//        return false;
//
//    bool hasNumber = false, hasSpecial = false;
//
//    for (char ch : password) {
//        if (std::isdigit(ch))
//            hasNumber = true;
//        if (std::ispunct(ch))
//            hasSpecial = true;
//        if (hasNumber && hasSpecial)
//            return true;
//    }
//    return false;
//}
//
//int main() {
//    HashMap<std::string, User*> userTree;
//    std::string username, password, city, lastLogin;
//    User* currentUser = nullptr;
//    bool userIn;
//    char choice;
//
//    // cout << "***************************************\n";
//    // cout << "*                                                                                                                   *\n";
//    // cout << "*           //////   |\\   |||     ////// ||||||     //\\        //////  //////      //\\     |\\       /|              *\n";
//    // cout << "*             ||     |\\\\  |||    ////      ||      // \\\\      //       ||  //     // \\\\    |\\\\     //|              *\n";
//    // cout << "*             ||     |\\\\  |||    \\\\\\\\\\\     ||     //---\\\\    //        ||///     //---\\\\   ||\\\\   //||              *\n";
//    // cout << "*             ||     ||\\\\ |||    /////     ||    //     \\\\   ///  |||  ||\\\\\\    //     \\\\  ||\\\\  // ||              *\n";
//    // cout << "*           //////   || \\\\||| //////       ||   //       \\\\  ///////   || \\\\\\\  //       \\\\ || \\\\//  ||              *\n";
//    // cout << "*                                                                                                                   *\n";
//    // cout << "***************************************\n";
//    do {
//        userIn = false;
//        std::cout << "\n=== Mini Instagram ===\n1. Signup\n2. Login\n3. Display All Users\n4. Exit\nEnter your choice: ";
//        std::cin >> choice;
//
//        switch (choice) {
//        case '1': {
//            std::cout << "\n=== Signup ===\nEnter username: ";
//            std::cin >> username;
//
//            if (userTree.get(username) != nullptr) {
//                std::cout << "Username already exists. Please try another.\n";
//                break;
//            }
//
//            std::cout << "Enter password: ";
//            std::cin >> password;
//
//            if (!isPasswordStrong(password)) {
//                std::cout << "Password is not strong enough. It must be at least 8 characters long and include a number and a special character.\n";
//                break;
//            }
//
//            std::cout << "Enter city: ";
//            std::cin >> city;
//
//            time_t now = time(0);
//            char buffer[26];
//            ctime_s(buffer, sizeof(buffer), &now);
//            lastLogin = buffer;
//
//            User* newUser = new User(username, password, city, lastLogin);
//            userTree.insert(username, newUser);
//            currentUser = newUser;
//
//            std::cout << "Signup successful! Welcome, " << username << "\n";
//            userIn = true;
//            break;
//        }
//        case '2': {
//            std::cout << "\n=== Login ===\nEnter username: ";
//            std::cin >> username;
//
//            User** userPtr = userTree.get(username);
//            if (userPtr == nullptr) {
//                std::cout << "Username not found. Please signup first.\n";
//                break;
//            }
//            User* user = *userPtr;
//
//            std::cout << "Enter password: ";
//            std::cin >> password;
//
//            if (user->validatePassword(password)) {
//                currentUser = user;
//                std::cout << "Login successful! Welcome back, " << username << "\n";
//                userIn = true;
//            }
//            else {
//                std::cout << "Incorrect password! Please try again.\n";
//            }
//            break;
//        }
//        case '3':
//            std::cout << "\n=== Display All Users ===\n";
//            userTree.display();
//            break;
//
//        case '4':
//            std::cout << "Exiting Mini Instagram. Goodbye!\n";
//            break;
//
//        default:
//            std::cout << "Invalid input!\n";
//            break;
//        }
//
//        while (userIn) {
//            int userChoice;
//            std::cout << "\n=== User Menu ===\n1. View Profile\n2. Make a Post\n3. View Notifications\n4. View Follow/Friend Requests\n5. View Followers List\n6. Search Usernames\n7. Send Friend Request\n8. Send Message\n9. View Newsfeed\n10. View Posts\n11. Logout\nEnter your choice: ";
//            std::cin >> userChoice;
//
//            switch (userChoice) {
//            case 1:
//                currentUser->displayProfile();
//                break;
//            case 2: {
//                std::string content, timestamp;
//                std::cout << "Enter post content: ";
//                std::cin.ignore();
//                std::getline(std::cin, content);
//
//                time_t now = time(0);
//                char buffer[26];
//                ctime_s(buffer, sizeof(buffer), &now);
//                timestamp = buffer;
//
//                currentUser->addPost(content, timestamp);
//                std::cout << "Post added successfully!\n";
//                break;
//            }
//            case 3:
//                currentUser->displayNotifications();
//                break;
//            case 4:
//                currentUser->displayFriendRequests();
//                break;
//            case 5:
//                currentUser->displayFollowers();
//                break;
//            case 6: {
//                std::cout << "Enter username to search: ";
//                std::cin >> username;
//
//                User** userPtr = userTree.get(username);
//                if (userPtr == nullptr)
//                    std::cout << "Username not found!\n";
//                else {
//                    User* user = *userPtr;
//                    std::cout << "Username found: " << username << "\n";
//                    user->displayProfile();
//                }
//                break;
//            }
//            case 7: {
//                std::cout << "Enter username to send friend request: ";
//                std::cin >> username;
//
//                User** userPtr = userTree.get(username);
//                if (userPtr == nullptr) {
//                    std::cout << "Username not found!\n";
//                }
//                else {
//                    User* user = *userPtr;
//                    currentUser->sendFriendRequest(*user);
//                    std::cout << "Friend request sent to " << username << "\n";
//                }
//                break;
//            }
//            case 8: {
//                std::cout << "Enter username to send message: ";
//                std::cin >> username;
//
//                User** userPtr = userTree.get(username);
//                if (userPtr == nullptr) {
//                    std::cout << "Username not found!\n";
//                }
//                else {
//                    User* user = *userPtr;
//                    std::string content, timestamp;
//                    std::cout << "Enter message content: ";
//                    std::cin.ignore();
//                    std::getline(std::cin, content);
//
//                    time_t now = time(0);
//                    char buffer[26];
//                    ctime_s(buffer, sizeof(buffer), &now);
//                    timestamp = buffer;
//
//                    Message newMessage(content, timestamp, currentUser->getName(), user->getName());
//                    currentUser->sendMessage(*user, newMessage);
//                    std::cout << "Message sent to " << username << "\n";
//                }
//                break;
//            }
//            case 9:
//                currentUser->viewNewsfeed();
//                break;
//            case 10:
//                currentUser->viewPosts();
//                break;
//            case 11:
//                std::cout << "Logging out...\n";
//                currentUser = nullptr;
//                userIn = false;
//                break;
//            default:
//                std::cout << "Invalid input!\n";
//                break;
//            }
//        }
//
//    } while (choice != '4');
//
//    return 0;
//}