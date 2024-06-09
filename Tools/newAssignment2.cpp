#include <iostream>
#include <string>
using namespace std;

// Function declaration - Displaying Menu & Options
void displayVehicleOptions(char &, int &, int &);
void displayCarAttributesMenu(char &);
void displayBikeAttributesMenu(char &);

// Base Class
class Vehicle {
    protected:
    double mileage;         // Mileage = Total Distance Travelled / Total Fuel Consumed
    double price;
};

// Derived class
class Car : protected Vehicle {
    protected:
    double ownership_cost;
    int warranty;           // (by years)
    int seating_capacity;
    string fuel_type;       // (diesel or petrol)

    public:

    Car() {     // Initializing all data members to null using constructor, avoiding garbage values
        price = 0.0;
        ownership_cost = 0.0;
        warranty = 0;
        seating_capacity = 0;
        fuel_type = " ";
        mileage = 0.0;
    }
};

// Derived class
class Audi : private Car {
    private:
    string model_type;

    public:
    
    void resetCar() {
        // Resetting all data members equals to null
        model_type = " ";
        price = 0.0;
        ownership_cost = 0.0;
        warranty = 0;
        seating_capacity = 0;
        fuel_type = " ";
        mileage = 0.0;
    }

    // Setters
    void setModelType() {
        cout << "\n----------------------------------------\n";
        cout << "--Enter Model Type : ";
        cin >> model_type;
    }

    void setPrice() {
        cout << "----------------------------------------\n";
        cout << "--Enter Price : ";
        cin >> price;
    }

    void setOwnershipCost() {
        cout << "----------------------------------------\n";
        cout << "--Enter Ownership Cost : ";
        cin >> ownership_cost;
    }

    void setWarranty() {
        cout << "----------------------------------------\n";
        cout << "--Enter Warranty Period (in Years) : ";
        cin >> warranty;
    }

    void setSeatingCapacity() {
        cout << "----------------------------------------\n";
        cout << "--Enter Seating Capacity : ";
        cin >> seating_capacity;
    }

    void setFuelType() {
        cout << "----------------------------------------\n";
        cout << "--Fuel Type : ";
        cout << "\n1. Diesel";
        cout << "\n2. Petrol";
        cout << "\n--Enter choice : ";
        cin >> fuel_type;

        if (fuel_type == "1") {
            fuel_type = "Diesel";
        }

        else if (fuel_type == "2") {
            fuel_type = "Petrol";
        }

        else {
            cout << "----------------------------------------\n";
            cout << "\n-----Invalid Input!-----\n";
        }
    }

    void setMileage() {
        cout << "----------------------------------------\n";
        cout << "--Enter Mileage : ";
        cin >> mileage;
        cout << "----------------------------------------\n";
    }

    // Getters
    string getModelType() {
        return model_type;
    }

    double getPrice() {
        return price;
    }

    double getOwnershipCost() {
        return ownership_cost;
    }

    int getWarranty() {
        return warranty;
    }

    int getSeatingCapacity() {
        return seating_capacity;
    }

    string getFuelType() {
        return fuel_type;
    }

    double getMileage() {
        return mileage;
    }

};

// Derived class
class Ford : private Car {
    private:
    string model_type;

    public:

    void resetCar() {
        // Resetting all data members equals to null
        model_type = " ";
        price = 0.0;
        ownership_cost = 0.0;
        warranty = 0;
        seating_capacity = 0;
        fuel_type = " ";
        mileage = 0.0;
    }

    // Setters
    void setModelType() {
        cout << "\n----------------------------------------\n";
        cout << "--Enter Model Type : ";
        cin >> model_type;
    }

    void setPrice() {
        cout << "----------------------------------------\n";
        cout << "--Enter Price : ";
        cin >> price;
    }

    void setOwnershipCost() {
        cout << "----------------------------------------\n";
        cout << "--Enter Ownership Cost : ";
        cin >> ownership_cost;
    }

    void setWarranty() {
        cout << "----------------------------------------\n";
        cout << "--Enter Warranty Period (in Years) : ";
        cin >> warranty;
    }

    void setSeatingCapacity() {
        cout << "----------------------------------------\n";
        cout << "--Enter Seating Capacity : ";
        cin >> seating_capacity;
    }

    void setFuelType() {
        cout << "----------------------------------------\n";
        cout << "--Fuel Type : ";
        cout << "\n1. Diesel";
        cout << "\n2. Petrol";
        cout << "\n--Enter choice : ";
        cin >> fuel_type;

        if (fuel_type == "1") {
            fuel_type = "Diesel";
        }

        else if (fuel_type == "2") {
            fuel_type = "Petrol";
        }

        else {
            cout << "----------------------------------------\n";
            cout << "\n-----Invalid Input!-----\n";
        }
    }

    void setMileage() {
        cout << "----------------------------------------\n";
        cout << "--Enter Mileage : ";
        cin >> mileage;
        cout << "----------------------------------------\n";
    }

    // Getters
    string getModelType() {
        return model_type;
    }

    double getPrice() {
        return price;
    }

    double getOwnershipCost() {
        return ownership_cost;
    }

    int getWarranty() {
        return warranty;
    }

    int getSeatingCapacity() {
        return seating_capacity;
    }

    string getFuelType() {
        return fuel_type;
    }

    double getMileage() {
        return mileage;
    }
};

// Derived class
class Bike : protected Vehicle {
    protected:
    int cylinders;
    int gears;
    string cooling_type;    // (air, liquid or oil)
    string wheel_type;      // (alloys or spokes)
    double tank_size;       // (in inches)

    public:

    Bike() {     // Initializing all data members to null using constructor, avoiding garbage values
        price = 0.0;
        tank_size = 0.0;
        cylinders = 0;
        gears = 0;
        cooling_type = " ";
        wheel_type = " ";
        mileage = 0.0;
    }
};

// Derived class
class Bajaj : private Bike {
    private:
    string make_type;

    public:

    void resetBike() {
        // Resetting all data members equals to null
        make_type = " ";
        price = 0.0;
        tank_size = 0.0;
        cylinders = 0;
        gears = 0;
        cooling_type = " ";
        wheel_type = " ";
        mileage = 0.0;
    }

    // Setters
    void setMakeType() {
        cout << "\n----------------------------------------\n";
        cout << "--Enter Make Type : ";
        cin >> make_type;
    }

    void setPrice() {
        cout << "----------------------------------------\n";
        cout << "--Enter Price : ";
        cin >> price;
    }

    void setTankSize() {
        cout << "----------------------------------------\n";
        cout << "--Enter Tank Size (in inches) : ";
        cin >> tank_size;
    }

    void setCylinders() {
        cout << "----------------------------------------\n";
        cout << "--Enter Cylinders : ";
        cin >> cylinders;
    }

    void setGears() {
        cout << "----------------------------------------\n";
        cout << "--Enter Gears : ";
        cin >> gears;
    }

    void setCoolingType() {
        cout << "----------------------------------------\n";
        cout << "--Cooling Type : ";
        cout << "\n1. Air";
        cout << "\n2. Liquid";
        cout << "\n3. Oil";
        cout << "\n--Enter choice : ";
        cin >> cooling_type;

        if (cooling_type == "1")
            cooling_type = "Air";

        else if (cooling_type == "2")
            cooling_type = "Liquid";
        
        else if (cooling_type == "3")
            cooling_type = "Oil";
        
        else
            cout << "\n-----Invalid Input!-----\n";
    }

    void setWheelType() {
        cout << "----------------------------------------\n";
        cout << "--Wheel Type : ";
        cout << "\n1. Alloys";
        cout << "\n2. Spokes";
        cout << "\n--Enter choice : ";
        cin >> wheel_type;

        if (wheel_type == "1")
            wheel_type = "Alloys";
        
        else if (wheel_type == "2")
            wheel_type = "Spokes";
        
        else
            cout << "\n-----Invalid Input!-----\n";
    }

    void setMileage() {
        cout << "----------------------------------------\n";
        cout << "--Enter Mileage : ";
        cin >> mileage;
    }

    // Getters
    string getMakeType() {
        return make_type;
    }

    double getPrice() {
        return price;
    }

    double getTankSize() {
        return tank_size;
    }

    int getCylinders() {
        return cylinders;
    }

    int getGears() {
        return gears;
    }

    string getCoolingType() {
        return cooling_type;
    }

    string getWheelType() {
        return wheel_type;
    }

    double getMileage() {
        return mileage;
    }
};

// Derived class
class TVS : private Bike {
    private:
    string make_type;

    public:

    void resetBike() {
        // Resetting all data members equals to null
        make_type = " ";
        price = 0.0;
        tank_size = 0.0;
        cylinders = 0;
        gears = 0;
        cooling_type = " ";
        wheel_type = " ";
        mileage = 0.0;
    }

    // Setters
    void setMakeType() {
        cout << "\n----------------------------------------\n";
        cout << "--Enter Make Type : ";
        cin >> make_type;
    }

    void setPrice() {
        cout << "----------------------------------------\n";
        cout << "--Enter Price : ";
        cin >> price;
    }

    void setTankSize() {
        cout << "----------------------------------------\n";
        cout << "--Enter Tank Size (in inches) : ";
        cin >> tank_size;
    }

    void setCylinders() {
        cout << "----------------------------------------\n";
        cout << "--Enter Cylinders : ";
        cin >> cylinders;
    }

    void setGears() {
        cout << "----------------------------------------\n";
        cout << "--Enter Gears : ";
        cin >> gears;
    }

    void setCoolingType() {
        cout << "----------------------------------------\n";
        cout << "--Cooling Type : ";
        cout << "\n1. Air";
        cout << "\n2. Liquid";
        cout << "\n3. Oil";
        cout << "\n--Enter choice : ";
        cin >> cooling_type;

        if (cooling_type == "1")
            cooling_type = "Air";

        else if (cooling_type == "2")
            cooling_type = "Liquid";
        
        else if (cooling_type == "3")
            cooling_type = "Oil";
        
        else
            cout << "\n-----Invalid Input!-----\n";
    }

    void setWheelType() {
        cout << "----------------------------------------\n";
        cout << "--Wheel Type : ";
        cout << "\n1. Alloys";
        cout << "\n2. Spokes";
        cout << "\n--Enter choice : ";
        cin >> wheel_type;

        if (wheel_type == "1")
            wheel_type = "Alloys";
        
        else if (wheel_type == "2")
            wheel_type = "Spokes";
        
        else
            cout << "\n-----Invalid Input!-----\n";
    }

    void setMileage() {
        cout << "----------------------------------------\n";
        cout << "--Enter Mileage : ";
        cin >> mileage;
    }

    // Getters
    string getMakeType() {
        return make_type;
    }

    double getPrice() {
        return price;
    }

    double getTankSize() {
        return tank_size;
    }

    int getCylinders() {
        return cylinders;
    }

    int getGears() {
        return gears;
    }

    string getCoolingType() {
        return cooling_type;
    }

    string getWheelType() {
        return wheel_type;
    }

    double getMileage() {
        return mileage;
    }
};

// Function declaration - Finding the specific type of vehicle
void findAudi(Audi[], int, string, int &, int &);
void findFord(Ford[], int, string, int &, int &);
void findBajaj(Bajaj[], int, string, int &, int &);
void findTVS(TVS[], int, string, int &, int &);

int main() {
    int numOfAudi = 1, numOfFord = 1, numOfBajaj = 1, numOfTVS = 1;     // Variables to count the total number of vehicles
    // Array of Objects to store multiple vehicles of any brand
    Audi audiCar[numOfAudi];
    Ford fordCar[numOfFord];
    Bajaj bajajBike[numOfBajaj];
    TVS tvsBike[numOfTVS];
    // Variables for menu and option choices
    char menu_choice, option_choice, car_attribute = 0, bike_attribute = 0;
    int car_choice = 0, bike_choice = 0, vehicle_found = 0, index = 0;
    string make_type, model_type;

    cout << "\n\t-----Vehicle Management System-----\n";

    // Keep displaying the menu until the user decides to exit the program
    do {
        cout << "\n-----Menu-----";
        cout << "\n1. Add Vehicle";
        cout << "\n2. Remove Vehicle";
        cout << "\n3. Find Vehicle";
        cout << "\n4. Exit";
        cout << "\n--Enter choice : ";
        cin >> menu_choice;

        switch (menu_choice) {
            case '1':       // Add Vehicle
                do {
                    cout << "\n\t----------Add Vehicle----------\n";

                    displayVehicleOptions(option_choice, car_choice, bike_choice);      // Calling display vehicle options function

                    if (option_choice == '1') {
                        if (car_choice == 1) {             // Calling Audi class setter functions to prompt the user and store the input
                            cout << "\n--------Audi - Add Information--------";
                            audiCar[numOfAudi - 1].setModelType();
                            audiCar[numOfAudi - 1].setPrice();
                            audiCar[numOfAudi - 1].setOwnershipCost();
                            audiCar[numOfAudi - 1].setWarranty();
                            audiCar[numOfAudi - 1].setSeatingCapacity();
                            audiCar[numOfAudi - 1].setFuelType();
                            audiCar[numOfAudi - 1].setMileage();
                            numOfAudi++;        // Incrementing the size of the array of the object
                        }

                        else if (car_choice == 2) {         // Calling Ford class setter functions to prompt the user and store the input
                            cout << "\n--------Ford - Add Information--------";
                            fordCar[numOfFord - 1].setModelType();
                            fordCar[numOfFord - 1].setPrice();
                            fordCar[numOfFord - 1].setOwnershipCost();
                            fordCar[numOfFord - 1].setWarranty();
                            fordCar[numOfFord - 1].setSeatingCapacity();
                            fordCar[numOfFord - 1].setFuelType();
                            fordCar[numOfFord - 1].setMileage();
                            numOfFord++;        // Incrementing the size of the array of the object
                        }
                    }

                    else if (option_choice == '2') {
                        if (bike_choice == 1) {        // Calling Bajaj class setter functions to prompt the user and store the input
                            cout << "\n--------Bajaj - Add Information--------";
                            bajajBike[numOfBajaj - 1].setMakeType();
                            bajajBike[numOfBajaj - 1].setPrice();
                            bajajBike[numOfBajaj - 1].setTankSize();
                            bajajBike[numOfBajaj - 1].setCylinders();
                            bajajBike[numOfBajaj - 1].setGears();
                            bajajBike[numOfBajaj - 1].setCoolingType();
                            bajajBike[numOfBajaj - 1].setWheelType();
                            bajajBike[numOfBajaj - 1].setMileage();
                            numOfBajaj++;       // Incrementing the size of the array of the object
                        }

                        else if (bike_choice == 2) {        // Calling TVS class setter functions to prompt the user and store the input
                            cout << "\n--------TVS - Add Information---------";
                            tvsBike[numOfTVS - 1].setMakeType();
                            tvsBike[numOfTVS - 1].setPrice();
                            tvsBike[numOfTVS - 1].setTankSize();
                            tvsBike[numOfTVS - 1].setCylinders();
                            tvsBike[numOfTVS - 1].setGears();
                            tvsBike[numOfTVS - 1].setCoolingType();
                            tvsBike[numOfTVS - 1].setWheelType();
                            tvsBike[numOfTVS - 1].setMileage();
                            numOfTVS++;         // Incrementing the size of the array of the object
                        }
                    }
                }

                while(option_choice != '3');

            break;
        
            case '2':       // Remove Vehicle
                cout << "\n\t----------Remove Vehicle----------\n";

                displayVehicleOptions(option_choice, car_choice, bike_choice);      // Calling display vehicle options function
                // Prompt the user to enter the Model Type of the car
                if (car_choice == 1 || car_choice == 2) {
                    cout << "\n--Enter Model Type : ";
                    cin >> model_type;
                }
                // Prompt the user to enter the Make Type of the bike
                else if (bike_choice == 1 || bike_choice == 2) {
                    cout << "\n--Enter Make Type : ";
                    cin >> make_type;
                }

                // Conditions to determine the user input and call a specific function accordingly
                if (car_choice == 1) {
                    findAudi(audiCar, numOfAudi, model_type, vehicle_found, index);
                    if (vehicle_found != 0) {
                        audiCar[index].resetCar();
                        cout << "\n--------Audi - " << model_type << " Information Erased--------\n";
                    }
                }

                else if (car_choice == 2) {
                    findFord(fordCar, numOfFord, model_type, vehicle_found, index);
                    if (vehicle_found != 0) {
                        fordCar[index].resetCar();
                        cout << "\n--------Ford - " << model_type << " Information Erased--------\n";
                    }
                }

                else if (bike_choice == 1) {
                    findBajaj(bajajBike, numOfBajaj, make_type, vehicle_found, index);
                    if (vehicle_found != 0) {
                        bajajBike[index].resetBike();
                        cout << "\n--------Bajaj - " << make_type << " Information Erased--------\n";
                    }
                }

                else if (bike_choice == 2) {
                    findTVS(tvsBike, numOfTVS, make_type, vehicle_found, index);
                    if (vehicle_found != 0) {
                        tvsBike[index].resetBike();
                        cout << "\n--------TVS - " << make_type << " Information Erased--------\n";
                    }
                }
                
            break;

            case '3':       // Find Vehicle
                cout << "\n\t----------Find Vehicle----------\n";

                displayVehicleOptions(option_choice, car_choice, bike_choice);      // Calling display vehicle options function
                // Prompt the user to enter the Model Type of the car
                if (car_choice == 1 || car_choice == 2) {
                    cout << "\n--Enter Model Type : ";
                    cin >> model_type;
                }
                // Prompt the user to enter the Make Type of the bike
                else if (bike_choice == 1 || bike_choice == 2) {
                    cout << "\n--Enter Make Type : ";
                    cin >> make_type;
                }

                if (option_choice == '1') {
                    
                    if (car_choice == 1) {
                        findAudi(audiCar, numOfAudi, model_type, vehicle_found, index);
                        if (vehicle_found != 0) {
                            do {
                                cout << "\n\t-----Audi Information-----";
                                displayCarAttributesMenu(car_attribute);        // Calling the function to display the car attributes menu
                                switch (car_attribute) {
                                    case '1':
                                        cout << "\n--Model Type : " << audiCar[index].getModelType() << "\n";
                                    break;

                                    case '2':
                                        cout << "\n--Price : " << audiCar[index].getPrice() << "\n";
                                    break;
                                    
                                    case '3':
                                        cout << "\n--Ownership Cost : " << audiCar[index].getOwnershipCost() << "\n";
                                    break;

                                    case '4':
                                        cout << "\n--Warranty : " << audiCar[index].getWarranty() << "\n";
                                    break;

                                    case '5':
                                        cout << "\n--Seating Capacity : " << audiCar[index].getSeatingCapacity() << "\n";
                                    break;

                                    case '6':
                                        cout << "\n--Fuel Type : " << audiCar[index].getFuelType() << "\n";
                                    break;

                                    case '7':
                                        cout << "\n--Mileage : " << audiCar[index].getMileage() << "\n";
                                    break;

                                    case '8':
                                        // Back to Menu
                                    break;
                                    
                                    default:
                                        cout << "\n-----Invalid Input!-----\n";
                                    break;
                                }
                            }
                            // Condition to keep displaying the attributes until the user decides to go back to menu
                            while (car_attribute != '8');
                            
                        }
                    }

                    else if (car_choice == 2) {
                        findFord(fordCar, numOfFord, model_type, vehicle_found, index);
                        if (vehicle_found != 0) {
                            do {
                                cout << "\n\t-----Ford Information-----";
                                displayCarAttributesMenu(car_attribute);        // Calling the function to display the car attributes menu
                                switch (car_attribute) {
                                    case '1':
                                        cout << "\n--Model Type : " << fordCar[index].getModelType() << "\n";
                                    break;

                                    case '2':
                                        cout << "\n--Price : " << fordCar[index].getPrice() << "\n";
                                    break;
                                    
                                    case '3':
                                        cout << "\n--Ownership Cost : " << fordCar[index].getOwnershipCost() << "\n";
                                    break;

                                    case '4':
                                        cout << "\n--Warranty : " << fordCar[index].getWarranty() << "\n";
                                    break;

                                    case '5':
                                        cout << "\n--Seating Capacity : " << fordCar[index].getSeatingCapacity() << "\n";
                                    break;

                                    case '6':
                                        cout << "\n--Fuel Type : " << fordCar[index].getFuelType() << "\n";
                                    break;

                                    case '7':
                                        cout << "\n--Mileage : " << fordCar[index].getMileage() << "\n";
                                    break;

                                    case '8':
                                        // Back to Menu
                                    break;
                                    
                                    default:
                                        cout << "\n-----Invalid Input!-----\n";
                                    break;
                                }
                            }
                            // Condition to keep displaying the attributes until the user decides to go back to menu
                            while (car_attribute != '8');
                        }
                    }
                }

                else if (option_choice == '2') {
                    if (bike_choice == 1) {
                        findBajaj(bajajBike, numOfBajaj, make_type, vehicle_found, index);
                        if (vehicle_found != 0) {
                            do {
                                cout << "\n\t-----Bajaj Information-----";
                                displayBikeAttributesMenu(bike_attribute);        // Calling the function to display the car attributes menu
                                switch (bike_attribute) {
                                    case '1':
                                        cout << "\n--Make Type : " << bajajBike[index].getMakeType() << "\n";
                                    break;

                                    case '2':
                                        cout << "\n--Price : " << bajajBike[index].getPrice() << "\n";
                                    break;
                                    
                                    case '3':
                                        cout << "\n--Tank Size : " << bajajBike[index].getTankSize() << "\n";
                                    break;

                                    case '4':
                                        cout << "\n--Cylinders : " << bajajBike[index].getCylinders() << "\n";
                                    break;

                                    case '5':
                                        cout << "\n--Gears : " << bajajBike[index].getGears() << "\n";
                                    break;

                                    case '6':
                                        cout << "\n--Cooling Type : " << bajajBike[index].getCoolingType() << "\n";
                                    break;

                                    case '7':
                                        cout << "\n--Wheel Type : " << bajajBike[index].getWheelType() << "\n";
                                    break;
                                    
                                    case '8':
                                        cout << "\n--Mileage : " << bajajBike[index].getMileage() << "\n";
                                    break;

                                    case '9':
                                        // Back to menu
                                    break;
                                    
                                    default:
                                        cout << "\n-----Invalid Input!-----\n";
                                    break;
                                }
                            }
                            // Condition to keep displaying the attributes until the user decides to go back to menu
                            while (bike_attribute != '9');
                        
                        }
                    }

                    else if (bike_choice == 2) {
                        findTVS(tvsBike, numOfTVS, make_type, vehicle_found, index);
                        if (vehicle_found != 0) {
                            do {
                                cout << "\n\t-----TVS Information-----";
                                displayBikeAttributesMenu(bike_attribute);        // Calling the function to display the car attributes menu
                                switch (bike_attribute) {
                                    case '1':
                                        cout << "\n--Make Type : " << tvsBike[index].getMakeType() << "\n";
                                    break;

                                    case '2':
                                        cout << "\n--Price : " << tvsBike[index].getPrice() << "\n";
                                    break;
                                    
                                    case '3':
                                        cout << "\n--Tank Size : " << tvsBike[index].getTankSize() << "\n";
                                    break;

                                    case '4':
                                        cout << "\n--Cylinders : " << tvsBike[index].getCylinders() << "\n";
                                    break;

                                    case '5':
                                        cout << "\n--Gears : " << tvsBike[index].getGears() << "\n";
                                    break;

                                    case '6':
                                        cout << "\n--Cooling Type : " << tvsBike[index].getCoolingType() << "\n";
                                    break;

                                    case '7':
                                        cout << "\n--Wheel Type : " << tvsBike[index].getWheelType() << "\n";
                                    break;
                                    
                                    case '8':
                                        cout << "\n--Mileage : " << tvsBike[index].getMileage() << "\n";
                                    break;

                                    case '9':
                                        // Back to menu
                                    break;
                                    
                                    default:
                                        cout << "\n-----Invalid Input!-----\n";
                                    break;
                                }
                            }
                            // Condition to keep displaying the attributes until the user decides to go back to menu
                            while (bike_attribute != '9');

                        }
                    }
                }
            break;

            case '4':       // Exit the program
                cout << "\n-----Thank You For Using Our Software! Have a Nice Day-----";
            break;
            
            default:
                cout << "\n-----Invalid Input!-----\n";
            break;
        }

    }
    // Condition to exit the program whenever the user wants
    while (menu_choice != '4');

    return 0;
}

// Function to display vehicle options
void displayVehicleOptions(char &option_choice, int &car_choice, int &bike_choice) {

    cout << "\n-----Options-----";
    cout << "\n1. Car";
    cout << "\n2. Bike";
    cout << "\n3. Menu";
    cout << "\n--Enter choice : ";
    cin >> option_choice;
    
    switch (option_choice) {
        case '1':
            cout << "\n-----Cars-----";
            cout << "\n1. Audi";
            cout << "\n2. Ford";
            cout << "\n--Enter choice : ";
            cin >> car_choice;

            if (car_choice != 1 && car_choice != 2) {
                cout << "\n-----Invalid Input!-----\n";
            }
        break;

        case '2':
            cout << "\n-----Bikes-----";
            cout << "\n1. Bajaj";
            cout << "\n2. TVS";
            cout << "\n--Enter choice : ";
            cin >> bike_choice;

            if (bike_choice != 1 && bike_choice != 2) {
                cout << "\n-----Invalid Input!-----\n";
            }
        break;

        case '3':
            // Back to menu
        break;

        default:
            cout << "\n-----Invalid Input!-----\n";
        break;
    }
}

// Function to display car attributes menu
void displayCarAttributesMenu(char &attribute) {
    cout << "\n-----Car Attributes-----";
    cout << "\n1. Model Type";
    cout << "\n2. Price";
    cout << "\n3. Ownership Cost";
    cout << "\n4. Warranty";
    cout << "\n5. Seating Capacity";
    cout << "\n6. Fuel Type";
    cout << "\n7. Mileage";
    cout << "\n8. Menu";
    cout << "\n--Enter choice : ";
    cin >> attribute;
}

// Function to display bike attributes menu
void displayBikeAttributesMenu(char &attribute) {
    cout << "\n-----Bike Attributes-----";
    cout << "\n1. Make Type";
    cout << "\n2. Price";
    cout << "\n3. Tank Size";
    cout << "\n4. Cylinders";
    cout << "\n5. Gears";
    cout << "\n6. Cooling Type";
    cout << "\n7. Wheel Type";
    cout << "\n8. Mileage";
    cout << "\n9. Menu";
    cout << "\n--Enter choice : ";
    cin >> attribute;
}

// Function to find Audi of specific model type
void findAudi(Audi audiCar[], int numOfAudi, string model_type, int &vehicle_found, int &index) {
    vehicle_found = 0;
    for (int i = 0; i < numOfAudi; i++) {
        if (audiCar[i].getModelType() == model_type) {      // Loop to find the car by its model type
            cout << "\n\t-----Vehicle Type Found!-----\n";
            vehicle_found++;
            index = i;
            break;
        }
    }

    if (vehicle_found == 0) {
        cout << "\n\t-----Vehicle Type Not Found!-----\n";
    }
}

// Function to find Ford of specific model type
void findFord(Ford fordCar[], int numOfFord, string model_type, int &vehicle_found, int &index) {
    vehicle_found = 0;
    for (int j = 0; j < numOfFord; j++) {
        if (fordCar[j].getModelType() == model_type) {      // Loop to find the car by its model type
            cout << "\n\t-----Vehicle Type Found!-----\n";
            vehicle_found++;
            index = j;
            break;
        }
    }

    if (vehicle_found == 0) {
        cout << "\n\t-----Vehicle Type Not Found!-----\n";
    }    
}

// Function to find Bajaj of specific model type
void findBajaj(Bajaj bajajBike[], int numOfBajaj, string make_type, int &vehicle_found, int &index) {
    vehicle_found = 0;
    for (int k = 0; k < numOfBajaj; k++) {              // Loop to find the bike by its make type
        if (bajajBike[k].getMakeType() == make_type) {
            cout << "\n\t-----Vehicle Type Found!-----\n";
            vehicle_found++;
            index = k;
            break;
        }
    }

    if (vehicle_found == 0) {
        cout << "\n\t-----Vehicle Type Not Found!-----\n";
    }
}

// Function to find TVS of specific model type
void findTVS(TVS tvsBike[], int numOfTVS, string make_type, int &vehicle_found, int &index) {
    vehicle_found = 0;
    for (int l = 0; l < numOfTVS; l++) {                // Loop to find the bike by its make type
        if (tvsBike[l].getMakeType() == make_type) {
            cout << "\n\t-----Vehicle Type Found!-----\n";
            vehicle_found++;
            index = l;
            break;
        }
    }

    if (vehicle_found == 0) {
        cout << "\n\t-----Vehicle Type Not Found!-----\n";
    }
}