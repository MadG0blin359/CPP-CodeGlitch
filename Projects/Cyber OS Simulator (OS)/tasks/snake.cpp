#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>

using namespace std;

const int WIDTH = 20;
const int HEIGHT = 20;
const string CLEAR = "\033[2J\033[1;1H";

struct Point { int x, y; };

class SnakeGame {
    vector<Point> snake;
    Point food;
    char dir;
    bool gameOver;
    int score;

    void setup() {
        snake = {{WIDTH/2, HEIGHT/2}};
        dir = 'r';
        gameOver = false;
        score = 0;
        spawnFood();
    }

    void spawnFood() {
        do {
            food = {rand()%(WIDTH-2)+1, rand()%(HEIGHT-2)+1};
        } while (isOnSnake(food));
    }

    bool isOnSnake(Point p) {
        for(auto& seg : snake)
            if(seg.x == p.x && seg.y == p.y) return true;
        return false;
    }

    void draw() {
        cout << CLEAR;
        cout << "Score: " << score << "\n";
        for(int y = 0; y < HEIGHT; y++) {
            for(int x = 0; x < WIDTH; x++) {
                if(y == 0 || y == HEIGHT-1 || x == 0 || x == WIDTH-1) {
                    cout << "#";
                } else if(x == food.x && y == food.y) {
                    cout << "*";
                } else {
                    bool drawn = false;
                    for(size_t i = 0; i < snake.size(); i++) {
                        if(snake[i].x == x && snake[i].y == y) {
                            cout << (i == 0 ? "O" : "o");
                            drawn = true;
                            break;
                        }
                    }
                    if(!drawn) cout << " ";
                }
            }
            cout << "\n";
        }
        cout.flush();
    }

    void input() {
        struct timeval tv = {0, 0};
        fd_set fds;
        FD_ZERO(&fds);
        FD_SET(STDIN_FILENO, &fds);
        
        if(select(STDIN_FILENO+1, &fds, NULL, NULL, &tv) > 0) {
            char c = cin.get();
            if(c == 27) { // Escape sequence
                cin.get(); // Skip [
                c = cin.get();
                switch(c) {
                    case 'A': if(dir != 'd') dir = 'u'; break;
                    case 'B': if(dir != 'u') dir = 'd'; break;
                    case 'C': if(dir != 'l') dir = 'r'; break;
                    case 'D': if(dir != 'r') dir = 'l'; break;
                }
            }
        }
    }

    void logic() {
        Point head = snake.front();
        Point newHead = head;

        switch(dir) {
            case 'u': newHead.y--; break;
            case 'd': newHead.y++; break;
            case 'l': newHead.x--; break;
            case 'r': newHead.x++; break;
        }

        // Collision checks
        if(newHead.x <= 0 || newHead.x >= WIDTH-1 || 
           newHead.y <= 0 || newHead.y >= HEIGHT-1 ||
           isOnSnake(newHead)) {
            gameOver = true;
            return;
        }

        snake.insert(snake.begin(), newHead);

        if(newHead.x == food.x && newHead.y == food.y) {
            score += 10;
            spawnFood();
        } else {
            snake.pop_back();
        }
    }

public:
    SnakeGame() {
        srand(time(0));
        setup();
    }

    void run() {
        struct termios oldt, newt;
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);

        while(!gameOver) {
            draw();
            input();
            logic();
            usleep(200000); // Adjust game speed
        }

        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        cout << CLEAR << "Game Over! Score: " << score << "\n";
        sleep(2);
    }
};

int main() {
    SnakeGame game;
    
    while (1) {
	    game.run();
    	    char input;
    	    cout << "Restart Game (y/n): ";
    	    cin >> input;
    	    if (input == 'n') break;
    }
    return 0;
}
