#include <iostream>
#include <vector>
#include <string>
#include <limits> // Required for numeric_limits
#include <iomanip> // Required for setw

using namespace std;

// Function to print the Tic-Tac-Toe board
void printBoard(const vector<string>& board) {
    cout << "\n";
    cout << "     |     |     \n";
    cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "  \n";
    cout << "     |     |     \n";
    cout << "\n";
}

// Function to check if a player has won
bool checkWin(const vector<string>& board, const string& player) {
    // Check rows
    for (int i = 0; i < 9; i += 3) {
        if (board[i] == player && board[i + 1] == player && board[i + 2] == player) {
            return true;
        }
    }
    // Check columns
    for (int i = 0; i < 3; ++i) {
        if (board[i] == player && board[i + 3] == player && board[i + 6] == player) {
            return true;
        }
    }
    // Check diagonals
    if (board[0] == player && board[4] == player && board[8] == player) {
        return true;
    }
    if (board[2] == player && board[4] == player && board[6] == player) {
        return true;
    }
    return false;
}

// Function to check if the board is full
bool checkFull(const vector<string>& board) {
    for (const string& cell : board) {
        if (cell == " ") {
            return false;
        }
    }
    return true;
}

int main() {
    vector<string> board(9, " "); // Initialize the board with empty spaces
    string currentPlayer = "X";
    int move;
    bool gameWon = false;
    bool boardFull = false;

    cout << "Welcome to Tic-Tac-Toe!\n";

    while (!gameWon && !boardFull) {
        printBoard(board);
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";

        // Input validation loop
        while (!(cin >> move)) {
            cout << "Invalid input. Please enter a number between 1 and 9: ";
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }

        // Adjust move to be 0-indexed
        move--;

        // Check if the move is valid
        if (move < 0 || move > 8 || board[move] != " ") {
            cout << "Invalid move. Please try again.\n";
            continue; // Go back to the beginning of the while loop
        }

        // Make the move
        board[move] = currentPlayer;

        // Check for win
        gameWon = checkWin(board, currentPlayer);
        if (gameWon) {
            printBoard(board);
            cout << "Player " << currentPlayer << " wins!\n";
        }
        else
        {
            // Switch player
            currentPlayer = (currentPlayer == "X") ? "O" : "X";
        }


        // Check if the board is full
        boardFull = checkFull(board);
        if (boardFull && !gameWon) {
            printBoard(board);
            cout << "It's a tie!\n";
        }
    }

    cout << "Thanks for playing!\n";
    return 0;
}

