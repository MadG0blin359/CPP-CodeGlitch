#include <iostream>
#include <string>
using namespace std;

// Global variable for DMA
int const size = 10;

class Orion_Space_Station_23p_0599 {
    static int lives;
    int count;
    // Items
    string *tools;
    string *supplies;
    string *artifacts;
    string *repair;
    
    public:
    Orion_Space_Station_23p_0599() : count(0) {
        // Allocating Memory fo items using DMA
        tools = new string[size];
        supplies = new string[size];
        artifacts = new string[size];
        repair = new string[size];

        cout << "\n--Choose where do you want to 'Start'\n";
        navigateStation();
    }

    // Function to display the player with navigation choices
    char navigateStation() {
        cout << "\n\n\t-----Navigation Station-----"
             << "\n1. Engineering Bay: Repair the stations's life support & communication systems."
             << "\n2. Habitat Module: Find food, water, and rest."
             << "\n3. Research Lab: Discover scientific artificats & tools that could aid in your survival."
             << "\n4. Cargo Hold: Scavenge for useful items and repair materials."
             << "\n5. Escape Pod Bay: Prepare and escape pod for a last-ditch effort to leave the station."
             << "\n6. Count Items in Inventory"
             << "\n7. Remove Items from Inventory"
             << "\n8. Exit Game"
             << "\n--Enter choice : ";
    }

    void startGame() {
        // Initializing the static lives variable
        lives = 5;
    }

    bool endGame() {
        if (lives == 0)
            return 1;
        else
            return 0;
    }

    void addItem(string item) {
        if (item == "Wrench" || item == "Screwdriver" || item == "ScolderingIron") {
            for (int i = 0; i < size; i++) {
                if (tools[i] == "") {
                    tools[i] = item;
                    cout << "\n-----Item Added to Inventory-----\n";
                    break;
                }
            }
        }

        else if (item == "FoodPacks" || item == "WaterBottles" || item == "OxygenTanks") {
            for (int i = 0; i < size; i++) {
                if (supplies[i] == "") {
                    supplies[i] = item;
                    cout << "\n-----Item Added to Inventory-----\n";
                    break;
                }
            }
        }

        else if (item == "SpaceSamples" || item == "ResearchNotes") {
            for (int i = 0; i < size; i++) {
                if (artifacts[i] == "") {
                    artifacts[i] = item;
                    cout << "\n-----Item Added to Inventory-----\n";
                    break;
                }
            }
        }

        else if (item == "Metal Plates" || item == "Wires" || item == "Microchips") {
            for (int i = 0; i < size; i++) {
                if (repair[i] == "") {
                    repair[i] = item;
                    cout << "\n-----Item Added to Inventory-----\n";
                    break;
                }
            }
        }
    }

    void removeItem(char choice) {
        if (choice == '1') {
            for (int i = 0; i < size; i++) {
                tools[i] == "";
            }
        
            cout << "\n-----Tools Items Removed-----\n";
        }
    
        else if (choice == '2') {
            for (int i = 0; i < size; i++) {
                supplies[i] = "";
            }
            
            cout << "\n-----Supplies Items Removed-----\n";
        }
        
        else if (choice == '3') {
            for (int i = 0; i < size; i++) {
                artifacts[i] == "";
                
            }
            
            cout << "\n-----Artifacts Items Removed-----\n";
        }
        
        else if (choice == '4') {
            for (int i = 0; i < size; i++) {
                repair[i] == "";
            }
            
            cout << "\n-----Repair Items Removed-----\n";
        }
    }

    friend void totalItems(Orion_Space_Station_23p_0599 &, char);

    // Deallocating Memory
    ~Orion_Space_Station_23p_0599() {
        delete[] tools, supplies, artifacts, repair;
    }

};

// Initializing the static lives variable
int Orion_Space_Station_23p_0599::lives = 5;

// Function to count total items in a specific category
void totalItems(Orion_Space_Station_23p_0599 &player, char choice) {
    if (choice == '1') {
        for (int i = 0; i < size; i++) {
            if (player.tools[i] != "")
                player.count++;
        }
        
        cout << "\n-----Total Tools Items : " << player.count;
        player.count = 0;
    }
    
    else if (choice == '2') {
        for (int i = 0; i < size; i++) {
            if (player.supplies[i] != "")
                player.count++;
        }
        
        cout << "\n-----Total Supplies Items: " << player.count;
        player.count = 0;
    }
    
    else if (choice == '3') {
        for (int i = 0; i < size; i++) {
            if (player.artifacts[i] != "")
                player.count++;
        }
        
        cout << "\n-----Total Artifacts  Items: " << player.count;
        player.count = 0;
    }
    
    else if (choice == '4') {
        for (int i = 0; i < size; i++) {
            if (player.repair[i] != "")
                player.count++;
        }
        
        cout << "\n-----Total Repair Items : " << player.count;
        player.count = 0;
    }
}

int main() {

    char choice;

    cout << "\n\t-----Orion Space Station-----\n";

    cout << "\n-----Menu-----"
        << "\n1. Start Game"
        << "\n2. End Game"
        << "\n--Enter Choice : ";
    cin >> choice;

    if (choice == '1') {
        Orion_Space_Station_23p_0599 player;
        player.startGame();
        cin >> choice;

        do {    
        
            switch (choice) {
            case '1':
                cout << "\n\t-----Engineering Bay-----\n";
                
                cout << "Congratulations! You have found 'Screwdriver'\n";
                player.addItem("Screwdriver");
            break;

            case '2':
                cout << "\n\t-----Habitat Module-----\n";
                
                cout << "Congratulations! You have found 'Oxygen Tanks'\n";
                player.addItem("OxygenTanks");
            break;

            case '3':
                cout << "\n\t-----Research Lab-----\n";
                
                cout << "Congratulations! You have found 'Research Notes'\n";
                player.addItem("ResearchNotes");
            break;

            case '4':
                cout << "\n\t-----Cargo Hold-----\n";
                
                cout << "Congratulations! You have found 'Wrench'\n";
                player.addItem("Wrench");
            break;
            
            case '5':
                cout << "\n\t-----Escape Pod Bay-----\n";
                cout << "\n-----Escape Successfull! Returning to Earth-----\n";
                return 0;
            break;

            case '6':
                do {
                    cout << "\n\t-----Count Total Items in Inventory-----\n"
                        << "\n-----Options-----"
                        << "\n1. Tools"
                        << "\n2. Supplies"
                        << "\n3. Artifacts"
                        << "\n4. Repair"
                        << "\n--Enter choice : ";
                    cin >> choice;

                    if (choice < '1' || choice > '4')
                        cout << "\n-----Invalid Input!-----\n";
                }

                while (choice < '1' || choice > '4');

                totalItems(player, choice);
            break;
            
            case '7':
                do {
                    cout << "\n\t-----Remove Total Items in Inventory-----\n"
                        << "\n-----Options-----"
                        << "\n1. Tools"
                        << "\n2. Supplies"
                        << "\n3. Artifacts"
                        << "\n4. Repair"
                        << "\n--Enter choice : ";
                    cin >> choice;

                    if (choice < '1' || choice > '4')
                        cout << "\n-----Invalid Input!-----\n";
                }

                while (choice < '1' || choice > '4');

                player.removeItem(choice);
            break;
            
            case '8':       // Exit Game
                return 0;
            break;
            
            default:
                cout << "\n-----Invalid Input!-----\n";
            break;
        
            }

            player.navigateStation();
            cin >> choice;
        }

        while (1);

    }

    else if (choice == '2') {
        return 0;
    }

    else {
        cout << "\n-----Invalid Input!-----\n";
    }

    return 0;
}