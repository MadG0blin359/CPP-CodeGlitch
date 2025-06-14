#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <sys/select.h>

using namespace std;

const vector<string> VISUALIZER = {
    "■ ▁ ▂ ▃ ▄ ▅ ▆ ▇ ▆ ▅ ▄ ▃ ▂ ▁",
    "▁ ▂ ▃ ▄ ▅ ▆ ▇ ▆ ▅ ▄ ▃ ▂ ▁ ■",
    "♫ ♪ ♫ ♪ ♫ ♪ ♫ ♪ ♫ ♪ ♫ ♪ ♫ ♪",
    "▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔",
    "◉◉◉◉◉◉◉◉◉◉◉◉◉◉◉◉◉◉◉◉◉◉◉◉◉◉"
};

void display_player(const string& title, int progress, int viz_frame) {
    cout << "\033[2J\033[1;1H"; // Clear screen
    cout << "♫ CYBER-OS MUSIC PLAYER ♫\n";
    cout << "──────────────────────────\n";
    cout << " Now Playing: " << title << "\n\n";
    
    // ASCII progress bar
    cout << "┌──────────────────────────┐\n";
    cout << "│";
    for(int i=0; i<25; i++) 
        cout << (i < progress/4 ? "█" : " ");
    cout << "│ " << progress << "%\n";
    cout << "└──────────────────────────┘\n\n";
    
    // Visualizer animation
    cout << "  " << VISUALIZER[viz_frame % VISUALIZER.size()] << "\n\n";
    
    cout << "Controls:\n";
    cout << " [P] Play/Pause  [N] Next  [Q] Quit\n";
    cout.flush();
}

int main() {
    vector<string> playlist = {
        "Cyber Symphony No.1",
        "8-bit Adventure",
        "Retro Wave Mix",
        "Terminal Lullaby"
    };
    
    bool playing = true;
    int current_track = 0;
    int progress = 0;
    int viz_frame = 0;
    
    while(true) {
        if(playing) {
            progress = (progress + 1) % 100;
            viz_frame++;
        }
        
        display_player(playlist[current_track], progress, viz_frame);
        
        // Non-blocking input
        fd_set fds;
        FD_ZERO(&fds);
        FD_SET(STDIN_FILENO, &fds);
        struct timeval timeout = {0, 100000}; // 0.1s
        
        if(select(STDIN_FILENO+1, &fds, NULL, NULL, &timeout) > 0) {
            char cmd;
            cin >> cmd;
            
            switch(tolower(cmd)) {
                case 'p': playing = !playing; break;
                case 'n': 
                    current_track = (current_track + 1) % playlist.size();
                    progress = 0;
                    break;
                case 'q': return 0;
            }
        }
        
        usleep(200000); // Update every 0.2s
    }
}
