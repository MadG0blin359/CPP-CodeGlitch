#include <iostream>
using namespace std;

int recursiveFactorial(int);

int main() {
	int num;

	do {
		cout << "Enter any positve number : ";
		cin >> num;

		if (num < 1)
			cout << "\n-----Invalid Input-----\n";
	} while (num < 1);

	cout << "\nFactorial : " << recursiveFactorial(num) << endl;

	system("pause");
	return 0;
}

int recursiveFactorial(int n) {
	// Base case:  factorial of 0 or 1 is 1
	if (n == 0 || n == 1)
		return 1;

	return n * recursiveFactorial(n - 1);
}