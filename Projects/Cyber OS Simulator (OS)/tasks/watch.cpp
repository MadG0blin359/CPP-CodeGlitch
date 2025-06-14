#include <iostream>
#include <chrono>
#include <thread>
#include <termios.h>
#include <unistd.h>
#include <iomanip>

using namespace std;
using namespace chrono;

class Stopwatch {
    steady_clock::time_point start_time;
    duration<double> elapsed{0};
    bool running{false};
    struct termios original_tio;

    void set_nonblocking_terminal() {
        struct termios new_tio = original_tio;
        new_tio.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);
    }

    void format_time(duration<double> d) {
        auto h = duration_cast<hours>(d);
        d -= h;
        auto m = duration_cast<minutes>(d);
        d -= m;
        auto s = duration_cast<seconds>(d);
        d -= s;
        auto ms = duration_cast<milliseconds>(d);

        cout << "\r" << setfill('0') 
             << setw(2) << h.count() << ":"
             << setw(2) << m.count() << ":"
             << setw(2) << s.count() << "."
             << setw(3) << ms.count() << flush;
    }

public:
    Stopwatch() {
        tcgetattr(STDIN_FILENO, &original_tio);
        set_nonblocking_terminal();
    }

    ~Stopwatch() {
        tcsetattr(STDIN_FILENO, TCSANOW, &original_tio);
    }

    void run() {
        char cmd;
        cout << "Stopwatch Controls:\n"
             << " [s] Start/Stop\n"
             << " [r] Reset\n"
             << " [q] Quit\n"
             << "-------------------\n";

        while(true) {
            // Check for input
            if(read(STDIN_FILENO, &cmd, 1) > 0) {
                switch(tolower(cmd)) {
                    case 's':
                        if(!running) start();
                        else stop();
                        break;
                    case 'r':
                        reset();
                        break;
                    case 'q':
                        return;
                }
            }

            // Update display
            if(running) {
                auto current = steady_clock::now();
                auto current_elapsed = current - start_time;
                format_time(elapsed + current_elapsed);
            }
            else {
                format_time(elapsed);
            }

            this_thread::sleep_for(100ms);
        }
    }

    void start() {
        if(!running) {
            start_time = steady_clock::now();
            running = true;
        }
    }

    void stop() {
        if(running) {
            elapsed += steady_clock::now() - start_time;
            running = false;
        }
    }

    void reset() {
        elapsed = duration<double>::zero();
        running = false;
        format_time(elapsed);
    }
};

int main() {
    Stopwatch sw;
    sw.run();
    cout << "\nExiting stopwatch...\n";
    return 0;
}
