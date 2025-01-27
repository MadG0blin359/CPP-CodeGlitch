#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

	fstream myFile;
	myFile.open("newFile01.txt", ios::in | ios::out);

	if (!myFile) {
		cout << "Error! FILE Not Found.";
		return 0;
	}

	myFile << "Test test tes." << endl;

	// Read and print the file content
	char line[6]; // One extra character for null terminator
	while (myFile.read(line, 5)) {
		line[5] = '\0'; // Null-terminate the string
		cout << line;   // Print the 5 characters
	}
	
	cout << endl;
	myFile.close();

	system("pause");
	return 0;
}