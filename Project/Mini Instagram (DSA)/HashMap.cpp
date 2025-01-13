#include "HashMap.h"

// Constructor
template <class K, class V>
HashMap<K, V>::HashMap() {
    for (int i = 0; i < BUCKET_COUNT; ++i) {
        table[i] = nullptr;
    }
}

// Insert method
template <class K, class V>
void HashMap<K, V>::insert(const K& key, const V& value) {
    int bucketIndex = hash(key);
    HashNode* prev = nullptr;
    HashNode* entry = table[bucketIndex];
    while (entry != nullptr && entry->key != key) {
        prev = entry;
        entry = entry->next;
    }
    if (entry == nullptr) {
        entry = new HashNode(key, value);
        if (prev == nullptr) {
            table[bucketIndex] = entry;
        }
        else {
            prev->next = entry;
        }
    }
    else {
        entry->value = value;
    }
}

// Get method
template <class K, class V>
V* HashMap<K, V>::get(const K& key) {
    int bucketIndex = hash(key);
    HashNode* entry = table[bucketIndex];
    while (entry != nullptr) {
        if (entry->key == key) {
            return &entry->value;
        }
        entry = entry->next;
    }
    return nullptr;
}

// Display method
template <class K, class V>
void HashMap<K, V>::display() const {
    for (int i = 0; i < BUCKET_COUNT; ++i) {
        HashNode* entry = table[i];
        while (entry != nullptr) {
            cout << entry->key << endl;
            entry = entry->next;
        }
    }
}

// Serialize method
template <class K, class V>
void HashMap<K, V>::serialize(const string& filename) const {
    ofstream ofs(filename);
    for (int i = 0; i < BUCKET_COUNT; ++i) {
        HashNode* entry = table[i];
        while (entry != nullptr) {
            entry->value->serialize(ofs);
            entry = entry->next;
        }
    }
}

// Deserialize method
template <class K, class V>
void HashMap<K, V>::deserialize(const string& filename) {
    ifstream ifs(filename);
    if (!ifs) return;

    while (!ifs.eof()) {
        User* user = new User();
        if (user->deserialize(ifs)) {
            insert(user->getUsername(), user);
        }
        else {
            delete user;
        }
    }
}