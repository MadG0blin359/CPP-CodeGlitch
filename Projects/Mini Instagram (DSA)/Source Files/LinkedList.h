#pragma once
#include <iostream>
#include "Node.h"
using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"

template <class T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    LinkedList();

    void add(const T& data);
    bool contains(const T& data) const;
    void display() const;
    Node<T>* getHead() const;

    ~LinkedList();
};