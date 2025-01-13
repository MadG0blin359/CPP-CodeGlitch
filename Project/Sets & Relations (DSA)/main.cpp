#include <iostream>
#include "Sets.h"
#include "Relations.h"
using namespace std;

int main() {
    Sets obj;
    Relations obj2;
    int choice;

    do {        // Menu based program
        cout << "\n\t\t\t\t\t\t->> Please choose which operation you wish to do <<-\n"
            << "\t\t\t1) Create the sets.\n"
            << "\t\t\t2) Print sets.\n"
            << "\t\t\t3) Union of A and B.\n"
            << "\t\t\t4) Intersection of A and B.\n"
            << "\t\t\t5) A - B.\n"
            << "\t\t\t6) B - A.\n"
            << "\t\t\t7) Total number of relations.\n"
            << "\t\t\t8) Reflexive Relations.\n"
            << "\t\t\t9) Symmetric Relations.\n"
            << "\t\t\t10) Anti-Symmetric Relations.\n"
            << "\t\t\t11) Exit\n"
            << "\t\t\t->> Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            obj.createSet('A');
            obj.createSet('B');
            break;
        case 2:
            if (!obj.printSets())
                cout << "\n-----Sets are Empty-----\n" << endl;
            break;

        case 3:
            if (!obj.getUnion())
                cout << "\n-----Sets are Empty-----\n" << endl;
            break;

        case 4:
            if (!obj.getIntersection())
                cout << "\n-----Sets are Empty-----\n" << endl;
            break;

        case 5:
            if (!obj.getDifference(1))      // A - B
                cout << "\n-----Sets are Empty-----\n" << endl;
            break;

        case 6:
            if (!obj.getDifference(0))      // B - A
                cout << "\n-----Sets are Empty-----\n" << endl;
            break;

        case 7:
            if (!obj.getNumberOfRelations())
                cout << "\n-----Sets are Empty-----\n" << endl;
            break;

        case 8:
            obj2.inputRelation();
            obj2.checkReflexive();
            break;

        case 9:
            obj2.inputRelation();
            obj2.checkSymmetric();
            break;

        case 10:
            obj2.inputRelation();
            obj2.checkAntiSymmetric();
            break;

        case 11:
            cout << "\n-----Program Terminated!-----\n" << endl;
            break;

        default:
            cout << "\n-----Invalid Input!-----\n" << endl;
            break;
        }

    } while (choice != 11);

    system("pause");
    return 0;
}
