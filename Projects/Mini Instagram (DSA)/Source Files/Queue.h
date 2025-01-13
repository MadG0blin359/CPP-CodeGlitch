#pragma once
#include <iostream>
#include "Node.h"

template <class T>
class Queue {
    Node<T>* front;  
    Node<T>* rear;   
    int currentSize; 

    void copyQueue(const Queue<T>& other); 
    void clearQueue();

public:
    Queue();           
    Queue(const Queue<T>& other); 
    Queue<T>& operator=(const Queue<T>& other);

    bool isEmpty() const;
    bool enqueue(T);   
    bool dequeue(); 
    T* getFront();

    ~Queue();          
};