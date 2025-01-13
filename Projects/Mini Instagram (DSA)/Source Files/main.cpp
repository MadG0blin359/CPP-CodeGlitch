#include <ctime>
#include <cctype>
#include <stdexcept>
#include "HashMap.cpp"
#include "User.h"
using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

string getTime() {
    time_t now = time(0);
    char arr[26];
    ctime_s(arr, sizeof(arr), &now);
    return arr;
}

bool isAlphabetic(const string& str) { 
    for (char ch : str) { 
        if (!isalpha(static_cast<unsigned char>(ch))) { 
            return false; 
        } 
    } 
    return true; 
}

// Function to make sure at least 8 characters, including a number and a special character
bool isPasswordStrong(const string& password) {
    if (password.length() < 8) 
        return false;
    
    bool hasNumber = false, hasSpecial = false;

    for (char ch : password) {
        if (isdigit(ch)) 
            hasNumber = true;
        if (ispunct(ch)) 
            hasSpecial = true;
        if (hasNumber && hasSpecial) 
            return true;
    }
    return false;
}

int main() {
    HashMap<string, User*> userGraph;
    string username, password, city, lastLogin;
    User* currentUser = nullptr; // For tracking logged-in user
    bool userIn;        // Flag to check whether user is successfully logged in
    char choice;

    userGraph.deserialize("users.dat");

    do {
        userIn = false;

        cout << MAGENTA; 
        cout << "\t\t\t***************************************************************************************************\n";
        cout << "\t\t\t*                                                                                                 *\n";
        cout << "\t\t\t*   //////   |\\   |||     ////// ||||||     //\\        //////  //////      //\\     |\\       /|    *\n";
        cout << "\t\t\t*     ||     |\\\\  |||    ////      ||      // \\\\      //       ||  //     // \\\\    |\\\\     //|    *\n";
        cout << "\t\t\t*     ||     |\\\\  |||    \\\\\\\\\\     ||     //---\\\\    //        ||///     //---\\\\   ||\\\\   //||    *\n";
        cout << "\t\t\t*     ||     ||\\\\ |||    /////     ||    //     \\\\   ///  |||  ||\\\\\\    //     \\\\  ||\\\\  // ||    *\n";
        cout << "\t\t\t*   //////   || \\\\||| //////       ||   //       \\\\  ///////   || \\\\\\\  //       \\\\ || \\\\//  ||    *\n";
        cout << "\t\t\t*                                                                                                 *\n";
        cout << "\t\t\t***************************************************************************************************\n";
        cout << RESET; 

        cout << CYAN << "\n1. Signup" << RESET << endl;
        cout << CYAN << "2. Login" << RESET << endl;
        cout << CYAN << "3. Display All Users" << RESET << endl;
        cout << CYAN << "4. Exit" << RESET << endl;
        cout << YELLOW << "Enter your choice: " << RESET;
        cin >> choice;

        switch (choice) {
        case '1': {
            cout << GREEN << "\n=== Signup ===" << RESET << endl;
            cout << YELLOW << "Enter username: " << RESET;
            cin >> username;

            // Check if username is unique
            if (userGraph.get(username) != nullptr) {
                cout << RED << "\n-----Username already exists. Please try another-----\n" << RESET << endl;
                break;
            }

            cout << YELLOW << "Enter password: " << RESET;
            cin >> password;

            // Validate password strength
            if (!isPasswordStrong(password)) {
                cout << RED << "Error! Password is not strong enough. It must be at least 8 characters long and include a number and a special character.\n" << RESET << endl;
                break;
            }

            while(true) { 
                cout << YELLOW << "Enter city: " << RESET; 
                cin >> city; 
                
                if (isAlphabetic(city)) { 
                    break; 
                } 
                else { 
                    cout << RED << "Error! City name must contain only alphabets. Please try again." << RESET << endl; 
                } 
            }

            lastLogin = getTime();

            // Create a new user and insert into BST
            User* newUser = new User(username, password, city, lastLogin);
            userGraph.insert(username, newUser);
            currentUser = newUser;

            cout << GREEN << "\nSignup successful! Welcome, " << username << RESET << endl;
            userIn = true;
            break;
        }
        case '2': {
            cout << GREEN << "\n=== Login ===" << RESET << endl;
            cout << YELLOW << "Enter username: " << RESET;
            cin >> username;

            User** userPtr = userGraph.get(username);
            if (userPtr == nullptr) {
                cout << RED << "\n-----Username NOT Found! Please Signup First-----\n" << RESET << endl;
                break;
            }

            User* user = *userPtr;

            cout << YELLOW << "Enter password: " << RESET;
            cin >> password;

            if (user->validatePassword(password)) {
                currentUser = user;
                cout << GREEN << "\nLogin Successful! Welcome back, " << username << RESET << endl;
                userIn = true;
            }
            else
                cout << RED << "\n-----Incorrect Password! Please try again-----\n" << RESET << endl;
            break;
        }
        case '3':
            cout << GREEN << "\n=== Display All Users ===" << RESET << endl;
            userGraph.display();
            break;

        case '4':
            cout << RED << "\n-----Exiting Mini Instagram. Goodbye!-----" << RESET << endl;
            system("pause");
            break;

        default:
            cout << RED << "\n-----Invalid Input!-----\n" << RESET << endl;
            system("pause");
            break;
        }

        // Start user-specific menu after successful login
        while (userIn) {
            int userChoice;
            cout << CYAN << "\n=== User Menu ===" << RESET
                << YELLOW << "\n1. View Profile"
                << "\n2. Make a Post"
                << "\n3. View Notifications"
                << "\n4. View Follow/Friend Requests"
                << "\n5. View Followers List"
                << "\n6. Search Usernames"
                << "\n7. Send Friend Request"
                << "\n8. Accept Friend Request"
                << "\n9. Reject Friend Request"
                << "\n10. Send Message"
                << "\n11. View Messages"
                << "\n12. View Newsfeed"
                << "\n13. View Posts"
                << "\n14. Reset Password"
                << "\n15. Logout" << RESET
                << YELLOW << "\nEnter your choice: " << RESET;
            cin >> userChoice;

            switch (userChoice) {
            case 1:
                cout << CYAN << "\n=== View Profile ===" << RESET << endl;
                currentUser->displayProfile();
                break;

            case 2: {
                cout << CYAN << "\n=== Create a Post ===" << RESET << endl;
                string content, timestamp;
                cout << YELLOW << "Enter post content: " << RESET;
                cin.ignore();
                getline(cin, content);

                timestamp = getTime();

                currentUser->addPost(content, timestamp);
                cout << GREEN << "Post added successfully!\n" << RESET;
                break;
            }

            case 3:
                cout << CYAN << "\n=== Notifications ===" << RESET << endl;
                currentUser->displayNotifications();
                break;

            case 4:
                cout << CYAN << "\n=== View Follow/Friend Requests ===" << RESET << endl;
                currentUser->displayFriendRequests();
                break;

            case 5:
                cout << CYAN << "\n=== View Followers ===" << RESET << endl;
                currentUser->displayFollowers();
                break;

            case 6: {
                cout << CYAN << "\n=== Search Usernames ===" << RESET << endl;
                cout << YELLOW << "Enter username to search: " << RESET;
                cin >> username;

                User** userPtr = userGraph.get(username);
                if (userPtr == nullptr)
                    cout << RED << "\n-----Username NOT Found!-----" << RESET << endl;
                else {
                    User* user = *userPtr;
                    cout << GREEN << "Username found: " << username << RESET << endl;
                    user->displayProfile();
                }
                break;
            }
            case 7: {
                cout << CYAN << "\n=== Send Friend Request ===" << RESET << endl;
                cout << YELLOW << "Enter username to send friend request: " << RESET;
                cin >> username;

                if (username == currentUser->getUsername()) {
                    cout << RED << "\n-----Error! Invalid Operation-----" << RESET << endl;
                    break;
                }

                User** userPtr = userGraph.get(username);
                if (userPtr == nullptr) {
                    cout << RED << "\n-----Username NOT Found!-----\n" << RESET;
                }
                else {
                    User* user = *userPtr;
                    currentUser->sendFriendRequest(*user);
                }
                break;
            }

            case 8:
                cout << CYAN << "\n=== Accept Friend Request ===" << RESET << endl;
                currentUser->displayFriendRequests();
                if (currentUser->hasPendingFriendRequests()) {
                    cout << "Enter the username of the friend request to accept: ";
                    cin >> username;

                    User** userPtr = userGraph.get(username);
                    if (userPtr != nullptr) {
                        currentUser->acceptFriendRequest(*userPtr);
                    }
                    else {
                        cout << RED << "\nInvalid username. Please enter a valid username from the friend requests." << RESET << endl;
                    }
                }
                break;

            case 9:
                cout << CYAN << "\n=== Reject Friend Request ===" << RESET << endl;
                /*currentUser->displayFriendRequests();
                if (currentUser->hasPendingFriendRequests()) {
                    cout << "Enter the username of the friend request to reject: ";
                    cin >> username;
                    if (currentUser->isValidFriendRequest(username)) {
                        currentUser->rejectFriendRequest(username);
                    }
                    else {
                        cout << RED << "Invalid username. Please enter a valid username from the friend requests." << RESET << endl;
                    }
                }*/
                break;

            case 10: {
                cout << CYAN << "\n=== Send Messages ===" << RESET << endl;
                currentUser->displayFriends();
                currentUser->displayFollowers();
                if (currentUser->hasPendingFriendRequests()) {
                    if (!currentUser->isFriendOrFollower(username)) {
                        cout << RED << "Username not found in friends or followers list!\n" << RESET;
                    }
                    else {
                        cout << YELLOW << "Enter username to send message: " << RESET;
                        cin >> username;
                        User** userPtr = userGraph.get(username);
                        if (userPtr == nullptr) {
                            cout << RED << "Username not found in the system!\n" << RESET;
                        }
                        else {
                            User* user = *userPtr;
                            string content, timestamp;
                            cout << YELLOW << "Enter message content: " << RESET;
                            cin.ignore();
                            getline(cin, content);

                            timestamp = getTime();

                            Message newMessage(content, timestamp, currentUser->getUsername(), user->getUsername());
                            currentUser->sendMessage(*user, newMessage);
                            cout << GREEN << "Message sent to " << username << RESET << "\n";
                        }
                    }
                }
                else {
                    cout << BLUE << "No friends or followers found.\n" << RESET << endl;
                }
                break;
            }

            case 11:
                cout << CYAN << "\n=== View Messages ===" << RESET << endl;
                currentUser->displayFriends();
                currentUser->displayFollowers();
                if (currentUser->hasPendingFriendRequests()) {
                    cout << "Enter the username to view messages from: ";
                    cin >> username;
                    if (currentUser->isFriendOrFollower(username)) {
                        currentUser->displayMessages(username);
                    }
                    else {
                        cout << RED << "Invalid username. Please enter a valid username from the friends or followers list." << RESET << endl;
                    }
                }
                else {
                    cout << BLUE << "No friends or followers found.\n" << RESET << endl;
                }
                break;

            case 12:
                cout << CYAN << "\n=== View News Feed ===" << RESET << endl;
                currentUser->viewNewsfeed();
                break;

            case 13:
                cout << CYAN << "\n=== View My Posts ===" << RESET << endl;
                currentUser->viewPosts();
                break;

            case 14:

                cout << YELLOW << "Enter current password: " << RESET;
                cin >> password;

                if (currentUser->validatePassword(password)) {

                    cout << GREEN << "\n-----Verification Successfull!-----\n" << RESET << endl;

                    cout << YELLOW << "Enter new password: " << RESET;
                    cin >> password;

                    // Validate password strength
                    if (!isPasswordStrong(password)) {
                        cout << RED << "Error! Password is not strong enough. It must be at least 8 characters long and include a number and a special character.\n" << RESET << endl;
                        break;
                    }
                    currentUser->resetPassword(password);
                }
                else
                    cout << RED << "\n-----Incorrect Password! Please try again-----" << RESET << endl;
                break;

            case 15:
                // Save each user to file
                userGraph.serialize("users.dat");
                cout << RED << "\n-----Logging Out...-----" << RESET << endl;
                currentUser = nullptr;  // Logout the user
                userIn = false;
                system("pause");
                system("clear");
                break;

            default:
                cout << RED << "\n-----Invalid Input!-----" << RESET << endl;
                system("pause");
                break;
            }
        }

    } while (choice != '4');
    

	return 0;
}