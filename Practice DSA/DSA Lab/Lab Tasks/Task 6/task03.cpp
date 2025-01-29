#include <iostream>
using namespace std;

void reverseArray(int*, int);

int main() {
	const int size = 5;
	int arr[size];

	for (int i = 0; i < size; i++) {
		cout << "\nEnter element " << i + 1 << " : ";
		cin >> arr[i];
	}

	cout << "\nOriginial Array : ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}

	reverseArray(arr, size);

	cout << "\nReversed Array : ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}

void reverseArray(int* arr, int size) {
	int temp, index;
	for (int i = 0; i < size/2; i++) {
		temp = arr[i];
		index = (size - 1) - i;
		arr[i] = arr[index];
		arr[index] = temp;
	}
}