#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "User.h"
using namespace std;

// HashMap class for storing users
template <class K, class V>
class HashMap {
private:
    static const int BUCKET_COUNT = 100;

    class HashNode {
    public:
        K key;
        V value;
        HashNode* next;

        HashNode(const K& key, const V& value) : key(key), value(value), next(nullptr) {}
    };

    HashNode* table[BUCKET_COUNT];

    int hash(const K& key) const {
        int hashValue = 0;
        for (char ch : key) {
            hashValue = (hashValue * 31 + ch) % BUCKET_COUNT;
        }
        return hashValue;
    }

public:
    HashMap();
    void insert(const K& key, const V& value);
    V* get(const K& key);
    void display() const;
    void serialize(const string& filename) const;
    void deserialize(const string& filename);
};
