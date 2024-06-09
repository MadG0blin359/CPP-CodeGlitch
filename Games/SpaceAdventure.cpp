#include <iostream>
#include <string>
using namespace std;

int main() {

    char menu_choice, difficulty_choice, options_choice, planet_choice, language_choice;
    string user_nickname, enter_to_continue;
    bool first_time = true;

    do {

        cout << " _____                    _____   _             _               \n";
        cout << "|   __|___ ___ ___ ___   |  _  |_| |_ _ ___ ___| |_ _ _ ___ ___ \n";
        cout << "|__   | . | .'|  _| -_|  |     | . | | | -_|   |  _| | |  _| -_|\n";
        cout << "|_____|  _|__,|___|___|  |__|__|___|\\_/|___|_|_|_| |___|_| |___|\n";
        cout << "      |_|                                                        \n";

        // Display game menu
        cout << "\n1. Play\n";
        cout << "2. Options\n";
        cout << "3. Exit\n";
        cout << "--Enter Your Choice (1, 2, or, 3) : ";
        cin >> menu_choice;


        if (menu_choice == '1') {
            cout << "--Enter Your Nickname : ";
            cin >> user_nickname;
            
            // Welcome screen, a ship with an AI assistant
            cout << "\nHi " << user_nickname << "! I see you have finally woken up from your hibernation since the takeoff from Planet Earth. My name is Cindy, I'm an AI, and I handle most of the tasks on this ship. I will be guiding you through your adventure in this vast galaxy.";
            cout << "\n\n--Press \'Enter\' to Continue...";
            cin.get();          // Read & discard the newline character in the input buffer
            getline(cin, enter_to_continue);
            cout << "\nRight now, we are traveling in deep space, looking for a habitable planet. Here is the list of some Planets I have found by far :\n";
            
            do {    // Discoverable planets in the game
                cout << "\n1. Atheria Prime - Vast crystalline deserts with towering crystal formations";
                cout << "\n2. Calibris IX   - Lush, bioluminescent forests filled with vibrant flora and fauna.";
                cout << "\n3. Diamos V      - Storm-ridden gas giant with floating islands and turbulent atmospheric currents.";
                cout << "\n4. Elarion       - Arid, rocky landscapes with massive underground caverns.";
                cout << "\n5. Faelum Delta  - Oceanic planet with bioluminescent underwater cities and vast coral reefs.";

                // Prompt the user to enter planet choice
                
                // This statement will execute only once, on the first iteration
                if (first_time == true) {
                    cout << "\n\n--Cindy : Which one would you like to explore first (1 - 5): ";
                    cin >> planet_choice;

                    first_time = false;     // Set the flag to false after the first iteration
                }

                else {
                    cout << "\n\n--You : Lead the way, Cindy! Our next cosmic destination awaits... ";
                    cin >> planet_choice;
                }

                // Unique outcomes according to the user choice for planet
                if (planet_choice == '1') {
                    cout << "\n--You : It's scorching hot here, but rich in minerals. This planet could be suitable for mining, although it's not habitable.\n";
                    
                    cout << "\n--Press \'Enter\' to Leave This Planet...";
                    cin.get();      // Read & discard the newline character in the input buffer
                    getline(cin, enter_to_continue);
                    
                    cout << "\nBriefing To Headquaters About This Planet :";
                    cout << "\n--Atheria Prime - My sweat trickled down my forehead despite the pressurized suit. Every breath felt like inhaling fire. Cindy scanned the mineral deposits, rich veins of iridium and quartz glinting in the harsh light. This planet might be a barren inferno, but its treasures could power entire civilizations. It's no home, but a miner's paradise.\n";
                
                    cout << "\n--Press \'Enter\' to Continue...";
                    getline(cin, enter_to_continue);

                    cout << "\nCindy : Ready for another adventure? Buckle up, explorer!\n";
                }

                else if (planet_choice == '2') {
                    cout << "\n--Cindy : It's incredibly lush here with abundant fruits and vegetables. The air is clean, and there's enough oxygen to breathe. I believe you've found your new home planet, Calibris IX. Congratulations!\n";
                    
                    cout << "\n--Press \'Enter\' to Continue...";
                    cin.get();      // Read & discard the newline character in the input buffer
                    getline(cin, enter_to_continue);

                    cout << "\nBriefing To Headquaters About This Planet :";
                    cout << "\n--Calibris IX - Stepping out of the ship felt like entering a living fairytale. Strange, bioluminescent creatures chirped and hummed in perfect harmony. The air was sweet and warm, laden with the scent of exotic fruits. Lush vines draped over colossal trees, creating natural walkways. Every sight, every sound, whispered of life in its most vibrant form. This isn't just a new home, it is a symphony for the senses.\n";

                    cout << "\n\n\t\t-----YOU FOUND A NEW HOME PLANET FOR YOUR PEOPLE-----\n\n";
                }

                else if (planet_choice == '3') {
                    cout << "\n--You : It's very unstable here. Looks like the rain here has continued for over 100 years, and that has caused the planet to become unhabitable.\n";
                    
                    cout << "\n--Press \'Enter\' to Leave This Planet...";
                    cin.get();      // Read & discard the newline character in the input buffer
                    getline(cin, enter_to_continue);
                    
                    cout << "\nBriefing To Headquaters About This Planet :";
                    cout << "\n--Diamos V - We couldn't even land - the atmospheric currents were too chaotic. Giant, floating islands shrouded in mist poked through the storm, remnants of a world long drowned. This wasn't just uninhabitable, it was a graveyard of a planet, a chilling reminder of nature's raw power.\n";
                
                    cout << "\n--Press \'Enter\' to Continue...";
                    getline(cin, enter_to_continue);

                    cout << "\nCindy : Well, at least things can't get any worse... right? What's next on the list?\n";
                }

                else if (planet_choice == '4') {
                    cout << "\n--You : This planet is a mystery. Too many underground caves, looks like someone used to live here once.\n";

                    cout << "\n--Press \'Enter\' to Continue Exploring...";
                    cin.get();      // Read & discard the newline character in the input buffer
                    getline(cin, enter_to_continue);

                    cout << "\n--Cindy : You have found a hidden treasure, congrats! This will definitely come in handy.\n";
                    
                    cout << "\n--Press \'Enter\' to Leave To This Planet...";
                    getline(cin, enter_to_continue);

                    cout << "\nBriefing To Headquaters About This Planet :";
                    cout << "\n--Elarion -  The desolate landscape stretched before me, red rock formations jutting against a dusty sky. But beneath the barren surface, the planet held secrets. We ventured into a vast network of caverns, their walls adorned with faded murals depicting a lost civilization.\n";
                
                    cout << "\n--Press \'Enter\' to Continue...";
                    getline(cin, enter_to_continue);

                    cout << "\nCindy : Interesting... that wasn't what I expected. What do you think we should do next?\n";
                }
                
                else if (planet_choice == '5') {
                    cout << "\n--Cindy : RUN! I didn't knew Underwater Aliens lived here.\n";
                    
                    cout << "\n--Press \'Enter\' to Escape This Planet...";
                    cin.get();      // Read & discard the newline character in the input buffer
                    getline(cin, enter_to_continue);

                    cout << "\nBriefing To Headquaters About This Planet :";
                    cout << "\n--Faelum Delta - The bioluminescent glow that had beckoned us from space turned ominous as we descended. Sleek, metallic structures rose from the depths, their bioluminescent glow tinged with an unnatural blue. My visor translated the alien chatter, filled with hostility and suspicion.\n\nThese weren't just underwater cities, they were fortresses, and we were unwelcome intruders. Panic surged through me. This wasn't just an uncharted world, it was a potential enemy lurking in the depths. RUN!\n";
                
                    cout << "\n--Press \'Enter\' to Continue...";
                    getline(cin, enter_to_continue);

                    cout << "\nCindy : Phew, that got close! Are you sure we should visit another one so soon?\n";
                }

                // Display an error for invalid input
                else if (planet_choice < '1' || planet_choice > '5') {
                    cout << "\nInvalid Choice! Select from the listed planets.\n";
                }

            }

            while (planet_choice != '2');

        }

        // Game settings
        else if (menu_choice == '2') {
            cout << "\n\t-----Options-----\n";
            cout << "\n1. Difficulty Level";
            cout << "\n2. Language";
            cout << "\n--Select any option (1-2) : ";
            cin >> options_choice;

            switch (options_choice) {
            case '1':                 // Setting game difficulty
                cout << "\n\nSet Difficulty Level :";
                cout << "\n1. Novice (Easy)";
                cout << "\n2. Standard (Normal)";
                cout << "\n3. Expert (Hard)";
                cout << "\n--Enter Your Choice (1, 2, or, 3) : ";
                cin >> difficulty_choice;

                switch (difficulty_choice) {
                case '1':
                    cout << "\n--Difficulty level Set To : Novice\n";
                    break;
                
                case '2':
                    cout << "\n--Difficulty level Set To : Standard\n";
                    break;

                case '3':
                    cout << "\n--Difficulty level Set To : Expert\n";
                    break;
                
                default:
                    cout << "\n--Invalid Choice! Default Difficulty Level is Standard.\n";
                    break;
                }
                break;
            
            case '2':                 // Changing game language
                cout << "\n\nChange Language : ";
                cout << "\n1. English";
                cout << "\n2. Hindi";
                cout << "\n3. Mandarin Chinese";
                cout << "\n4. Spanish";
                cout << "\n5. Urdu";
                cout << "\n--Select any language : ";
                cin >> language_choice;

                switch (language_choice)
                {
                case '1':
                    cout << "\n--Language Changed To : English\n";
                    break;
                
                case '2':
                    cout << "\n--Language Changed To : Hindi\n";
                    break;
                
                case '3':
                    cout << "\n--Language Changed To : Mandarin Chinese\n";
                    break;

                case '4':
                    cout << "\n--Language Changed To : Spanish\n";
                    break;

                case '5':
                    cout << "\n--Language Changed To : Urdu\n";
                    break;
                
                default:
                    cout << "\n--Invalid Choice! Default Language is English.\n";
                    break;
                }
                break;

            default:
                cout << "\n--Invalid Choice!";
                break;
            }

        }
        
        // Display an error on invalid menu input
        else if (menu_choice < '1' || menu_choice > '3') {
            cout << "\n--Invalid Choice!\n\n";
        }
    }

    while (menu_choice != '3' && planet_choice != '2');

    return 0;
}