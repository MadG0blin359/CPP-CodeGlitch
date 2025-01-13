#pragma once
#include "Data.h"

class Sets : protected Data {
protected:
    Data A;
    Data B;

    void getDifference(const Data& set1, const Data& set2);

public:
    void createSet(const char& name);
    bool printSets();
    bool getUnion();
    bool getIntersection();
    bool getDifference(const bool flag);
    bool getNumberOfRelations();
};