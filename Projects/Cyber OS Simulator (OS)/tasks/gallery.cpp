#include <iostream>
#include <vector>
#include <unistd.h>

using namespace std;

const vector<string> ASCII_ARTS = {
    R"(
  _____
 /     \
| () () |
 \  ^  /
  |||||
  |||||
    )",
    
    R"(
   /\
  /  \
  |  |
  |__|
  |  |
  |  |
 /    \
/______\
    )",
    
    R"(
   .-.
   | |
  .' '.
  |   |
  |___|
  |   |
  |   |
  '---'
    )",
    
    R"(
  ██████ 
 ██░░░░██
██░██░███
██░██░███
██░██░███
 ██░░░░██
  ██████ 
    )",
    
    R"(
   ╔═══╗
   ║   ║
   ╠═══╣
   ║   ║
   ╚═══╝
    )"
};

void display_art(const string& art) {
    cout << "\033[2J\033[1;1H"; // Clear screen
    cout << art << endl;
    cout.flush();
}

int main() {
    size_t current = 0;
    while(true) {
        display_art(ASCII_ARTS[current]);
        current = (current + 1) % ASCII_ARTS.size();
        sleep(3); // Rotate every 3 seconds
    }
    return 0;
}
