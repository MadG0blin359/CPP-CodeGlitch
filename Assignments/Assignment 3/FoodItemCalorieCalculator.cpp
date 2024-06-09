#include <iostream>
#include <string>
using namespace std;

class Food {
    string name;
    double calories;
    double fat;
    double carbs;
    double protein;

    public:
    // Default constructor
    Food() {}

    // Constructor overloading
    Food(string fname) {
        name = fname;
    }

    Food(string fname, double fcalories) {
        name = fname;
        calories = fcalories;
    }

    Food(string fname, double fcalories, double ffat, double fcarbs, double fprotein) {
        name = fname;
        calories = fcalories;
        fat = ffat;
        carbs = fcarbs;
        protein = fprotein;
    }

    // Function prototype
    friend double calculateCalories(Food &obj);

    // Getters
    string getName() {
        return name;
    }

    double getCalories() {
        return calories;
    }

    double getFat() {
        return fat;
    }

    double getCarbs() {
        return carbs;
    }

    double getProtein() {
        return protein;
    }

    // Setters
    void setName(string fname) {
        name = fname;
    }

    // void setCalories(double fcalorie) {
    //     calories = fcalorie;
    // }

    void setFat() {
        do {
            cout << "--Enter fat (in grams) : ";
            cin >> fat;
            
            if (fat < 0)      // Condition to handle invalid inputs
                cout << "\n-----Invalid Input!-----\n";
        }
        
        while (fat < 0);
    }

    void setCarbs() {
        do {
            cout << "--Enter carbs (in grams) : ";
            cin >> carbs;

            if (carbs < 0)      // Condition to handle invalid inputs
                cout << "\n-----Invalid Input!-----\n";
        }

        while (carbs < 0);
    }

    void setProtein() {
        do {
            cout << "--Enter proteins (in grams) : ";
            cin >> protein;

            if (protein < 0)    // Condition to handle invalid inputs
                cout << "\n-----Invalid Input!-----\n";
        }

        while (protein < 0);
    }

};

// Definiton of friend function to calculate total calories
double calculateCalories(Food &obj) {
    obj.calories = (9*obj.fat) + (4*obj.carbs) + (4*obj.protein);
}

int main() {

    Food food;

    string fname;   

    cout << "\n\t-----Calorie Calculator-----\n\n";

    // Loop to add as much food item as the user wants
    do {
        cout << "\n\t-----Add Details-----\n\n";

        cout << "Enter name of food item (or type 'exit' to quit) : ";
        cin >> fname;

        if (fname != "exit") {
            food.setName(fname);
            food.setFat();
            food.setCarbs();
            food.setProtein();
            
            calculateCalories(food);        // Calling the friend function

            cout << "\n-----Item Details-----"
                 << "\nName : " << food.getName()
                 << "\nCalories : " << food.getCalories()
                 << "\nFat : " << food.getFat()
                 << "\nCarbs : " << food.getCarbs()
                 << "\nProtein : " << food.getProtein()
                 << "\n----------------------\n";
            
        }

        else {
            break;
        }

    }

    while (1);

    return 0;
}