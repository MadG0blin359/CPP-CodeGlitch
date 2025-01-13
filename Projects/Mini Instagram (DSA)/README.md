# Project : Mini Instagram

**Mini Instagram** is a terminal-based social media application that implements advanced concepts of Data Structures and Algorithms (DSA). It includes features such as user signup, login, profile management, friend requests, messaging, and more. The program also leverages file handling to store and retrieve user data.

## Features

### Main Menu
- **Signup**: Create a new account.
- **Login**: Access your existing account.
- **Display All Users**: View a list of all registered users.
- **Exit**: Exit the program.

### User Menu (Post Login)
1. **View Profile**: Display your profile information, including username, city, and posts.
2. **Make a Post**: Add a new post to your profile.
3. **View Notifications**: Check all notifications, including messages and friend requests.
4. **View Follow/Friend Requests**: See pending friend requests.
5. **View Followers List**: Display a list of your followers.
6. **Search Usernames**: Search for other users by their username.
7. **Send Friend Request**: Send a friend request to another user.
8. **Accept Friend Request**: Accept a pending friend request.
9. **Reject Friend Request**: Decline a pending friend request.
10. **Send Message**: Send a private message to another user.
11. **View Messages**: Read messages from other users.
12. **View Newsfeed**: See posts made by your followers.
13. **View Posts**: View all your posts.
14. **Reset Password**: Change your account password.
15. **Logout**: Logout of your account.

## How It Works

### Signup
Users provide their desired username, password, and city to register an account. Passwords are securely stored using file handling techniques.

### Login
Users authenticate themselves using their username and password. Successful login grants access to the User Menu.

### User Interaction
The program allows users to interact with each other by:
- Sending and accepting friend requests.
- Messaging friends.
- Viewing and responding to notifications.
- Searching for other users.

### Newsfeed and Posts
Users can create posts, which are displayed on their profile and shared in the newsfeed for followers.

### File Handling
All data, such as user credentials, posts, friend requests, and messages, are stored persistently using file handling mechanisms.

## Technologies and Concepts Used

### Data Structures:
- **Stack**: Managing posts and notifications.
- **Queue**: Handling friend requests and notifications.
- **Linked List**: Storing user relationships (followers and friends).
- **Graphs**: Representing connections between users.

### Algorithms:
- Search and traversal for finding users and navigating profiles.
- Sorting for displaying data like followers and newsfeed posts.

### File Handling:
- Storing user data persistently in text file.

### Object-Oriented Programming (OOP):
- Classes for encapsulating user, post, message, and friend request data.
- Polymorphism and inheritance for reusability and flexibility.

## Future Improvements
- Add support for multimedia posts (images, videos).
- Implement recommendation algorithms for friends and posts.
- Enhance the messaging system with group chats.
- Add authentication enhancements like OTP-based login.

## How to Run

### Prerequisites
Make sure you have the following installed on your system:

- C++ Compiler (e.g., GCC)
- Terminal, Command Prompt (CMD), or Visual Studio Code

### Steps to Run

1. **Clone the Repository:**

   ```bash
   git clone https://github.com/MadG0blin359/CPP-CodeGlitch.git

2. **Navigate to the Project Directory:**

   ```bash
   cd CPP-CodeGlitch/Projects

3. **Run the Executable:**

   ```bash
   ./MiniInstagram

## Contributor

This project is developed and maintained by:

- **Shawaiz Shahid**

## Contact

For any questions or suggestions, feel free to reach out:

- **Email**: shawaizshahid312+github@gmail.com

---

**Enjoy using Mini Instagram!** 🎉
