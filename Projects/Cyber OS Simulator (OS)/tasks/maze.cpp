#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <termios.h>
#include <sys/select.h>

using namespace std;

const int WIDTH = 21;
const int HEIGHT = 21;

struct Cell {
    bool visited = false;
    bool walls[4] = {true, true, true, true}; // N, E, S, W
    int x, y;
};

class Maze {
    vector<vector<Cell>> grid;
    vector<Cell*> stack;
    Cell* current;
    int px, py; // Player position
    int exitX, exitY;

    void setup() {
        grid = vector<vector<Cell>>(HEIGHT, vector<Cell>(WIDTH));
        for(int y = 0; y < HEIGHT; y++) {
            for(int x = 0; x < WIDTH; x++) {
                grid[y][x] = Cell();
                grid[y][x].x = x;
                grid[y][x].y = y;
            }
        }
        current = &grid[0][0];
        px = 1;
        py = 1;
        exitX = WIDTH-2;
        exitY = HEIGHT-2;
    }

    vector<Cell*> getUnvisitedNeighbors(Cell* cell) {
        vector<Cell*> neighbors;
        int x = cell->x;
        int y = cell->y;

        if(y > 0 && !grid[y-1][x].visited) neighbors.push_back(&grid[y-1][x]); // N
        if(x < WIDTH-1 && !grid[y][x+1].visited) neighbors.push_back(&grid[y][x+1]); // E
        if(y < HEIGHT-1 && !grid[y+1][x].visited) neighbors.push_back(&grid[y+1][x]); // S
        if(x > 0 && !grid[y][x-1].visited) neighbors.push_back(&grid[y][x-1]); // W

        return neighbors;
    }

    void removeWalls(Cell* a, Cell* b) {
        int dx = a->x - b->x;
        int dy = a->y - b->y;

        if(dx == 1) { a->walls[3] = false; b->walls[1] = false; } // W-E
        if(dx == -1) { a->walls[1] = false; b->walls[3] = false; } // E-W
        if(dy == 1) { a->walls[0] = false; b->walls[2] = false; } // N-S
        if(dy == -1) { a->walls[2] = false; b->walls[0] = false; } // S-N
    }

public:
    Maze() {
        srand(time(0));
        setup();
    }

    void generate() {
        current->visited = true;
        vector<Cell*> neighbors = getUnvisitedNeighbors(current);

        while(!stack.empty() || !neighbors.empty()) {
            if(!neighbors.empty()) {
                Cell* next = neighbors[rand() % neighbors.size()];
                stack.push_back(current);
                removeWalls(current, next);
                current = next;
                current->visited = true;
            }
            else if(!stack.empty()) {
                current = stack.back();
                stack.pop_back();
            }
            neighbors = getUnvisitedNeighbors(current);
        }
    }

    void draw() {
        cout << "\033[2J\033[H"; // Clear screen
        
        for(int y = 0; y < HEIGHT; y++) {
            for(int x = 0; x < WIDTH; x++) {
                if(x == px && y == py) {
                    cout << "\033[32m@\033[0m"; // Green player
                }
                else if(x == exitX && y == exitY) {
                    cout << "\033[31mE\033[0m"; // Red exit
                }
                else {
                    bool wall = grid[y][x].walls[0] || grid[y][x].walls[1] ||
                               grid[y][x].walls[2] || grid[y][x].walls[3];
                    cout << (wall ? "#" : " ");
                }
            }
            cout << endl;
        }
        cout << "Use arrow keys to move (@=you, E=exit)" << endl;
    }

    bool movePlayer(int dx, int dy) {
        int nx = px + dx;
        int ny = py + dy;

        if(nx < 0 || nx >= WIDTH || ny < 0 || ny >= HEIGHT) return false;
        
        // Check walls between current cell and target cell
        Cell& current = grid[py][px];
        if(dx == 1 && current.walls[1]) return false;  // E wall
        if(dx == -1 && current.walls[3]) return false; // W wall
        if(dy == 1 && current.walls[2]) return false;  // S wall
        if(dy == -1 && current.walls[0]) return false; // N wall

        px = nx;
        py = ny;
        return true;
    }

    bool atExit() {
        return px == exitX && py == exitY;
    }
};

int main() {
    // Set up terminal
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    Maze maze;
    maze.generate();
    
    while(true) {
        maze.draw();
        if(maze.atExit()) {
            cout << "\nCongratulations! You escaped!\n";
            break;
        }

        // Input handling
        fd_set fds;
        FD_ZERO(&fds);
        FD_SET(STDIN_FILENO, &fds);
        struct timeval timeout = {0, 10000};
        
        if(select(STDIN_FILENO+1, &fds, NULL, NULL, &timeout) > 0) {
            char c = cin.get();
            if(c == 27) { // Escape sequence
                cin.get(); // Skip [
                c = cin.get();
                switch(c) {
                    case 'A': maze.movePlayer(0, -1); break; // Up
                    case 'B': maze.movePlayer(0, 1);  break; // Down
                    case 'C': maze.movePlayer(1, 0);  break; // Right
                    case 'D': maze.movePlayer(-1, 0); break; // Left
                }
            }
        }
    }

    // Restore terminal
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return 0;
}
