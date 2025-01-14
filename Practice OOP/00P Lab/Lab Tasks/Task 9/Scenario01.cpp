#include <iostream>
#include <string>
using namespace std;

// Base class
class Animal {
	protected:
	string name;
	double age;
};

// Parent class
class Bird : private Animal {
	public:
	int wingLength;
	
	// Parameterized construstor to initialize variables
	Bird(int animal_wingLength, string animal_name, int animal_age) {
		wingLength = animal_wingLength;
		name = animal_name;
		age = animal_age;	
	}

	void speak() {
		cout << "\nAnimal Type : Bird";
		cout << "\nAnimal Sound : Chirp";
		cout << "\nThe Bird can sing";
		cout << "\nName : "<< name;
		cout << "\nAge : " << age << " years";
		cout << "\nWing Length : " << wingLength << " inches" << endl;
	}
};

class Reptile : private Animal {
	public:
	string habitat;
	
	// Parameterized construstor to initialize variables
	Reptile(string animal_habitat, string animal_name, int animal_age) {
		habitat = animal_habitat;
		name = animal_name;
		age = animal_age;	
	}

	void speak() {
		cout << "\nAnimal Type : Reptile";
		cout << "\nAnimal Sound : Hiss";
		cout << "\nReptile can creep";
		cout << "\nName : " << name;
		cout << "\nAge : " << age << " years";
		cout << "\nHabitat : " << habitat << endl;
	}
};

int main() {

	Bird animal01(4, "Pigeon", 1);
	Reptile animal02("Underground", "Lizard", 2);
	
	animal01.speak();
	animal02.speak();

	return 0;
}
