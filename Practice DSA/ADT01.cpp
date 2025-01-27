#include <iostream>
using namespace std;

class Array {
private:
	int size;
	int* arr;

public:
	Array(int s) : size(s) {					// Allocating memory
		arr = new int[size];
	}
	
	int* getArr() {				// Address of first index
		return arr;
	}

	void display() {			// Display values
		for (int i = 0; i < size; i++) {
			cout << "Index " << i + 1 << " : " << arr[i] << "\n";
		}
	}

	~Array() {					// De-allocating memory
		delete[] arr;
	}
};

int main() {
	const int size = 10;
	Array obj(size);
	int* ptr;

	ptr = obj.getArr();

	for (int i = 0; i < size; i++) {				// Initializing array
		ptr[i] = i + 5;
	}

	obj.display();

	system("pause");
	return 0;
}