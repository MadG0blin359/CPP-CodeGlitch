#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>
#include <algorithm>
#include <random> // Required for std::shuffle
#include <stdexcept> // Required for std::runtime_error

using namespace std;

const vector<string> FORTUNES = {
    "A sudden opportunity will appear when least expected",
    "Beware of false friends offering help",
    "Financial prosperity is in your future",
    "Travel plans may lead to unexpected adventures",
    "Your creativity will open new doors soon",
    "A secret admirer will reveal themselves",
    "Patience will be key to overcoming obstacles",
    "An old conflict will finally find resolution",
    "Trust your instincts in upcoming decisions",
    "A career change may bring great fulfillment"
};

const vector<string> CRYSTAL_BALL = {
    R"(
    .-"-.
   / 4 4 \
  |  \_/  |
   \_/ \_/
    )",
    R"(
    .-"-.
   / ^ ^ \
  |  \_/  |
   \_/ \_/
    )",
    R"(
    .-"-.
   / o o \
  |  \-/  |
   \_/ \_/
    )"
};

class FortuneTeller {
    vector<string> fortunes;
    struct termios original_termios;
    mt19937 rng; // Random number generator

    void setup_terminal() {
        struct termios new_termios;
        if (tcgetattr(STDIN_FILENO, &original_termios) != 0) {
            throw runtime_error("tcgetattr failed");
        }
        new_termios = original_termios;
        new_termios.c_lflag &= ~(ICANON | ECHO);
        if (tcsetattr(STDIN_FILENO, TCSANOW, &new_termios) != 0) {
             throw runtime_error("tcsetattr failed");
        }
    }

    void restore_terminal() {
        if (tcsetattr(STDIN_FILENO, TCSANOW, &original_termios) != 0) {
            throw runtime_error("tcsetattr failed");
        }
    }

    void animate_crystal() {
        cout << "\033[2J\033[1;1H"; // Clear screen
        cout << "\033[35m"; // Purple color
        cout << "╔════════════════════════════╗\n";
        cout << "║     CRYSTAL BALL 3000     ║\n";
        cout << "╚════════════════════════════╝\n";
        
        static int frame = 0;
        cout << CRYSTAL_BALL[frame % CRYSTAL_BALL.size()] << endl;
        frame++;
        
        cout << "\033[33m"; // Yellow color
        cout << "  The mists are clearing...\n";
        cout << "\033[0m";
        cout.flush();
    }

    string random_fortune() {
        uniform_int_distribution<size_t> dist(0, fortunes.size() - 1);
        return fortunes[dist(rng)];
    }

public:
    FortuneTeller() : fortunes(FORTUNES), rng(random_device{}()) { // Initialize rng
        try
        {
            setup_terminal();
        }
        catch(const runtime_error& e)
        {
            cerr << "Error: " << e.what() << endl;
            // Consider if you want to throw again or continue.  For this example, continuing.
        }
        shuffle(fortunes.begin(), fortunes.end(), rng); // Use std::shuffle
    }

    ~FortuneTeller() {
        try
        {
           restore_terminal();
        }
        catch(const runtime_error& e)
        {
             cerr << "Error: " << e.what() << endl;
        }
    }

    void run() {
        char input = ' ';
        do {
            // Crystal ball animation
            for (int i = 0; i < 5; i++) {
                animate_crystal();
                usleep(200000);
            }

            // Reveal fortune
            cout << "\033[35m"; // Purple color
            cout << "\nYour Destiny Reveals:\n";
            cout << "\033[36m"; // Cyan color
            cout << "« " << random_fortune() << " »\n\n";
            cout << "\033[33mPress [N] for new fortune, [Q] to quit\033[0m\n";
            cout.flush();

            // Get input
            fd_set fds;
            struct timeval tv = {1, 0};
            FD_ZERO(&fds);
            FD_SET(STDIN_FILENO, &fds);
            
            do {
                if (select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv) > 0) {
                    if (read(STDIN_FILENO, &input, 1) > 0)
                    {
                        input = tolower(input);
                    }
                    else
                    {
                         input = 'q'; //handle no input
                         break;
                    }
                }
            } while (input != 'n' && input != 'q');

        } while (input != 'q');

        cout << "\033[2J\033[1;1H"; // Clear screen
        cout << "The mists fade... until next time...\n";
        sleep(1);
    }
};

int main() {
    FortuneTeller teller;
    teller.run();
    return 0;
}

