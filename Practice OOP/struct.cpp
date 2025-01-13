#include <iostream>
using namespace std;

typedef struct Employee
{
    int salary;
    char favChar;
    double bonus;
} ep;


int main() {

    Employee e1;

    e1.salary = 1500;
    e1.favChar = 'G';
    e1.bonus = 0.8;

    ep e2;

    e2.salary = 3200;

    return 0;
}