#include <iostream>
using namespace std;

struct Play {
    int score, bonus;
};

void calculate(Play &P, int N = 10) {
    P.score++;
    P.bonus += N;
}

int main() {
    Play PL = {10, 15};
    calculate(PL, 5);
    cout << PL.score << ":" << PL.bonus << endl;
    calculate(PL);
    cout << PL.score << ":" << PL.bonus << endl;
    calculate(PL, 15);
    cout << PL.score << ":" << PL.bonus << endl;

    return 0;
}