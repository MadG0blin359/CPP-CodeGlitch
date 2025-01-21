#include <iostream>
using namespace std;

// Class for sets encapsulation
class Data {
    int* data, size;
public:
    Data(int s = 0) {
        size = s;
        if (size > 0)
            data = new int[size];
        else
            data = NULL;
    }

    // Copy Constructor
    Data(const Data& other) {
        size = other.size;
        if (size > 0) {
            data = new int[size];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];  // Deep copy the array
            }
        }
        else {
            data = nullptr;
        }
    }

    // Assignment Operator Overloading
    Data& operator=(const Data& other) {
        if (this != &other) {
            delete[] data;  // Free current memory

            size = other.size;
            if (size > 0) {
                data = new int[size];
                for (int i = 0; i < size; i++) {
                    data[i] = other.data[i];  // Deep copy the array
                }
            }
            else {
                data = nullptr;
            }
        }
        return *this;
    }

    // Function to set data
    void inputElements() {
        int element;
        for (int i = 0; i < size; i++) {
            cin >> element;

            if (!isDuplicate(element, i))
                data[i] = element;  // Store only the unique element
            else {
                cout << "Duplicate Element Detected! Please enter a different value: ";
                --i;
            }
        }
    }

    // Function to check duplicate
    bool isDuplicate(const int& element, const int i) {
        for (int j = 0; j <= i; j++) {
            if (data[j] == element) {
                return true;
            }
        }
        return false;
    }

    // Function to insert elements one by one
    void insertElement(const int index, const int value) {
        if (index >= 0 && index < size) {
            data[index] = value;
        }
    }

    // Sort the set in ascesding order using bubblesort
    void sortSet(int s = -1) {
        if (s == -1)
            s = size;
        for (int i = 0; i < s - 1; i++) {
            for (int j = 0; j < s - i - 1; j++) {
                if (data[j] > data[j + 1]) {
                    // Swap the elements
                    int temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
    }

    // Function to print data
    void printData(int s = -1) {
        if (s == -1)
            s = size;
        cout << "{";
        if (s > 0) {
            for (int i = 0; i < s; i++) {
                cout << data[i] << ", ";
            }
            cout << "\b\b}";
        }
        else
            cout << "}";
    }

    // Get element at any index
    int getElement(int index) const {
        if (index >= 0 && index < size) 
            return data[index];
        return -1;
    }

    // Get the size of the data array
    int getSize() const {
        return size;
    }

    // Functiont to check if the set is empty
    bool isEmpty() const {
        return (size == 0);
    }

    // Destructor
    ~Data() {
        delete[] data;
    }
};

// Class to perform set operations
class Sets : protected Data {
protected:
    Data A;
    Data B;

    // Function to get Difference of sets
    void getDifference(const Data& set1, const Data& set2) {
        int newSize = set1.getSize();
        Data differenceSet(newSize);

        int index = 0;

        for (int i = 0; i < set1.getSize(); i++) {
            bool flag = false;
            for (int j = 0; j < set2.getSize(); j++) {
                if (set1.getElement(i) == set2.getElement(j)) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                differenceSet.insertElement(index, set1.getElement(i));
                index++;
            }
        }

        differenceSet.sortSet(index);
        differenceSet.printData(index);
    }

public:
    // Function to create sets A & B
    void createSet(const char& name) {
        int n;
        do {
            cout << "\nNumber of elements in Set " << name << ": ";
            cin >> n;

            if (n <= 3)
                cout << "\n-----Invalid Input! Number of Elements Must Be Greater Than \"3\"-----\n";

        } while (n <= 3);
        
        cout << "Enter elements of Set " << name << ": ";

        if (name == 'A') {
            A = Data(n);
            A.inputElements();
        }
        else if (name == 'B') {
            B = Data(n);
            B.inputElements();
        }
    }

    // Function to display set elements
    bool printSets() {
        if (A.isEmpty() && B.isEmpty())
            return false;

        cout << "Set A = ";
        A.printData();
        cout << "\nSet B = ";
        B.printData();

        return true;
    }

    // Function to get Union of sets
    bool getUnion() {
        if (A.isEmpty() && B.isEmpty())
            return false;

        int newSize = A.getSize() + B.getSize();
        Data unionSet(newSize);

        int index = 0;

        // Inserting elements of set A
        for (int i = 0; i < A.getSize(); i++) {
            if (!unionSet.isDuplicate(A.getElement(i), index)) {
                unionSet.insertElement(index, A.getElement(i));
                index++;
            }
        }

        // Inserting elements of set B
        for (int i = 0; i < B.getSize(); i++) {
            if (!unionSet.isDuplicate(B.getElement(i), index)) {
                unionSet.insertElement(index, B.getElement(i));
                index++;

            }
        }

        cout << "\nUnion A U B = ";
        unionSet.sortSet(index);
        unionSet.printData(index);

        return true;
    }
    
    // Function to get Intersection of sets
    bool getIntersection() {
        if (A.isEmpty() && B.isEmpty())
            return false;

        int newSize = A.getSize();
        Data intersectionSet(newSize);

        int index = 0;

        for (int i = 0; i < newSize; i++) {
            for (int j = 0; j < newSize; j++) {
                if (A.getElement(i) == B.getElement(j)) {
                    intersectionSet.insertElement(index, A.getElement(i));
                    index++;
                    break;
                }
            }
        }

        cout << "\nIntersection A n B = ";
        intersectionSet.sortSet(index);
        intersectionSet.printData(index);

        return true;
    }

    // Function to get Difference of sets
    bool getDifference(const bool flag) {
        if (A.isEmpty() && B.isEmpty())
            return false;

        if (flag) {
            cout << "\nDifference A - B = ";
            getDifference(A, B);
        }
        else {
            cout << "\nDifference B - A = ";
            getDifference(B, A);
        }

        return true;
    }

    // Function to get total number of relations of set A & B
    bool getNumberOfRelations() {
        if (A.isEmpty() && B.isEmpty())
            return false;

        int relations = A.getSize() * B.getSize();

        relations = pow(2, relations);
        cout << "\nTotal number of relations: " << relations << endl;

        return true;
    }
};

// Class to perform relation operations
class Relations {
    int** relation;  // 2D array to store relation pairs
    int size;        // Number of pairs in the relation

public:
    Relations() : relation(NULL), size(0) {}

    // Function to input relations
    void inputRelation() {
        if (relation != nullptr) {
            // Free allocated memory
            for (int i = 0; i < size; i++)
                delete[] relation[i];
            delete[] relation;
        }

        do {
            cout << "Enter the number of pairs in the relation: ";
            cin >> size;

            if (size < 1)
                cout << "\n-----Invalid Input!-----\n" << endl;

        } while (size < 1);

        relation = new int* [size];
        for (int i = 0; i < size; i++)
            relation[i] = new int[2];

        cout << "Enter pairs (a, b) in the relation:\n";
        for (int i = 0; i < size; i++) {
            cin >> relation[i][0] >> relation[i][1];
        }
    }

    // Function to check Reflexive Relation
    void checkReflexive() {
        if (relation == NULL) {
            cout << "\n-----Relation is Empty! Input Relation First.-----\n";
            return;
        }

        // Extract unique elements
        int* elements = new int[size * 2];
        int elementCount = 0;

        for (int i = 0; i < size; i++) {
            bool foundA = false, foundB = false;

            // Add unique elements from pairs
            for (int j = 0; j < elementCount; j++) {
                if (relation[i][0] == elements[j])
                    foundA = true;
                if (relation[i][1] == elements[j])
                    foundB = true;
            }
            if (!foundA) elements[elementCount++] = relation[i][0];
            if (!foundB) elements[elementCount++] = relation[i][1];
        }

        // Check reflexivity for each element
        for (int i = 0; i < elementCount; i++) {
            bool reflexive = false;
            for (int j = 0; j < size; j++) {
                if (relation[j][0] == elements[i] && relation[j][1] == elements[i]) {
                    reflexive = true;
                    break;
                }
            }
            if (!reflexive) {
                cout << "\nRelation is not Reflexive.\n";
                delete[] elements;
                return;
            }
        }

        cout << "\nRelation is Reflexive.\n";
        delete[] elements;
    }

    // Function to check Symmetric Relation
    void checkSymmetric() {
        if (relation == nullptr) {
            cout << "\n-----Relation is Empty! Input Relation First.-----\n";
            return;
        }

        for (int i = 0; i < size; i++) {
            int a = relation[i][0], b = relation[i][1];
            bool symmetric = (a == b); // Reflexive pairs are inherently symmetric

            for (int j = 0; j < size; j++) {
                if (relation[j][0] == b && relation[j][1] == a) {
                    symmetric = true;
                    break;
                }
            }

            if (!symmetric) {
                cout << "\nRelation is not Symmetric.\n";
                return;
            }
        }

        cout << "\nRelation is Symmetric.\n";
    }

    // Function to check Anti-Symmetric Relation
    void checkAntiSymmetric() {
        if (relation == NULL) {
            cout << "\n-----Relation is Empty! Input Relation First.-----\n";
            return;
        }

        for (int i = 0; i < size; i++) {
            int a = relation[i][0], b = relation[i][1];
            if (a != b) {
                for (int j = 0; j < size; j++) {
                    if (relation[j][0] == b && relation[j][1] == a) {
                        cout << "\nRelation is not Anti-Symmetric.\n";
                        return;
                    }
                }
            }
        }

        cout << "\nRelation is Anti-Symmetric.\n";
    }

    // Destructor to free memory
    ~Relations() {
        if (relation != NULL) {
            for (int i = 0; i < size; i++)
                delete[] relation[i];
            delete[] relation;
        }
    }
};

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
