#pragma once
class Relations {
private:
    int** relation;
    int size;

public:
    Relations();
    ~Relations();

    void inputRelation();
    void checkReflexive();
    void checkSymmetric();
    void checkAntiSymmetric();
};