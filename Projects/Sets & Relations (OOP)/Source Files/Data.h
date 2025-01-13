#pragma once
#include <iostream>
using namespace std;

class Data {
private:
    int* data;
    int size;

public:
    Data(int s = 0);
    Data(const Data& other);
    Data& operator=(const Data& other);
    ~Data();

    void inputElements();
    bool isDuplicate(const int& element, const int i);
    void insertElement(const int index, const int value);
    void sortSet(int s = -1);
    void printData(int s = -1) const;
    int getElement(int index) const;
    int getSize() const;
    bool isEmpty() const;
};