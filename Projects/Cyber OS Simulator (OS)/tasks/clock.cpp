#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <unistd.h>

using namespace std;
using namespace chrono;

void display_clock() {
    auto now = system_clock::now();
    time_t time = system_clock::to_time_t(now);
    tm local_time = *localtime(&time);

    cout << "\033[2J\033[1;1H"; // Clear screen
    cout << "  ╔════════════════╗\n";
    cout << "  ║  DIGITAL CLOCK ║\n";
    cout << "  ╠════════════════╣\n";
    cout << "  ║ " << put_time(&local_time, "%H:%M:%S") << "       ║\n";
    cout << "  ╚════════════════╝\n";
    cout.flush();
}

int main() {
    while (true) {
        display_clock();
        sleep(1); // Update every second
    }
    return 0;
}
