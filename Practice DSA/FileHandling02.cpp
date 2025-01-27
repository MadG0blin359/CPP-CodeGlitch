#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string text;
    ofstream onFile;
    onFile.open("C:\\Users\\Shawaiz\\Desktop\\Run Codes\\CPP-CodeGlitch\\Practice DSA\\newFile02.txt");
    
    cout << "Instructions : Enter 0 to exit." 
        << "\nEnter Text to store in file : ";
    while (true) {
        getline(cin, text);
        if (text == "0")
            break;
        onFile << text;
        onFile << endl;
    }

    onFile.close();

    onFile.open("C:\\Users\\Shawaiz\\Desktop\\Run Codes\\CPP-CodeGlitch\\Practice DSA\\newFile02.txt", ios::app);
    onFile << "\n-----END OF FILE!-----";
    onFile.close();

    return 0;
}