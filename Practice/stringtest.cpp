#include <iostream>
#include <string>

int main() {
    std::string myString = "boss\n\0";  // Length function counts until it encounters \0, however \0 is automatically added to a string without adding it explicitly, its not included in the count.
    std::cout << "Length of the string: " << myString.length() << std::endl;

    return 0;
}
