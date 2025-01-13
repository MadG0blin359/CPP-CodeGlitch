#pragma once
#include <iostream>

template <class T>
class Node {
public:
	Node<T>* next;
	T data;
	
	Node(const T& value) : data(value), next(nullptr) {}
};