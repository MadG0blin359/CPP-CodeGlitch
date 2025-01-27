#include <iostream>
using namespace std;

int recursiveSum(int);

int main() {
	int num;

	do {
		cout << "Enter any postive number : ";
		cin >> num;

		if (num < 1)
			cout << "\n-----Invalid Input!-----\n";
	} while (num < 1);

	cout << "\nTotal sum : " << recursiveSum(num) << endl;

	system("pause");
	return 0;
}

int recursiveSum(int n) {
	if (n == 0)
		return 0;

	return n + recursiveSum(n - 1);
}
