#include <iostream>
using namespace std;

// Modified mystery function to accept a pointer to a pointer
void mystery(int** ptr, int s)
{
    *ptr = new int[s]; // Allocate memory and assign to the original pointer
    int j=s;
    for (int i = 0; i < s; ++i) {
        ptr[0][i] = j;
        --j;
    }
}

int main()
{
    int* ptr = NULL; // Initialize the pointer to null
    int s = 5;
    
    cout << ptr << endl;        // Random address inside ptr if not initialized to NULL
    
    mystery(&ptr, s); // Pass the address of the pointer
    
    cout << ptr << endl;
    
    for (int i = 0; i < s; ++i)
        cout << ptr[i] << " "; // Correctly access the allocated memory
    cout << endl; // Add a newline for better formatting
    
    delete[] ptr; // Free the allocated memory
    
    cout << ptr << endl;
    cout << ptr[9] << endl;     // Garbage value
    
    ptr = NULL; // Set pointer to null after deletion
    
    cout << ptr[9] << endl;     // Code exits
    cout << ptr << endl;        // Zero

    return 0;
}
