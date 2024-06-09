#include <iostream>
#include <string>
using namespace std;

int main() {

    string sentence;

    cout << "\nEnter a sentence : ";       // Promtpt the user to enter a sentence
    getline(cin, sentence);                // String function to read a sentence

    int length = sentence.length();        // String function to get the total length of the string 

    cout << "\nReversed Sentence : ";

    // Loop to display the reversed sentence
    for (int i = length-1; i >= 0; i--) {
        cout << sentence[i];
    }

    return 0;
}