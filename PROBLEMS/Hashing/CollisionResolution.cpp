#include "CollisionResolution.h"
#include <iostream>
using namespace std;

// HashTableChaining Implementation
HashTableChaining::HashTableChaining(int size) : table(size) {}

int HashTableChaining::hashFunction(int key) {
    return key % table.size();
}

void HashTableChaining::insert(int key) {
    int index = hashFunction(key);
    table[index].push_back(key);
}

void HashTableChaining::display() {
    for (size_t i = 0; i < table.size(); ++i) {
        cout << i << ": ";
        for (int val : table[i]) {
            cout << val << " -> ";
        }
        cout << "NULL\n";
    }
}

// HashTableOpenAddressing Implementation
HashTableOpenAddressing::HashTableOpenAddressing(int size) : table(size, -1), tableSize(size) {}

int HashTableOpenAddressing::hashFunction(int key) {
    return key % tableSize;
}

void HashTableOpenAddressing::insert(int key) {
    int index = hashFunction(key);
    int i = 0;

    while (table[(index + i) % tableSize] != -1 && i < tableSize) {
        ++i;
    }

    if (i < tableSize) {
        table[(index + i) % tableSize] = key;
    }
}

void HashTableOpenAddressing::display() {
    for (int i = 0; i < tableSize; ++i) {
        cout << i << ": " << (table[i] == -1 ? "EMPTY" : to_string(table[i])) << "\n";
    }
}

// HashTableDoubleHashing Implementation
HashTableDoubleHashing::HashTableDoubleHashing(int size) : table(size, -1), tableSize(size) {}

int HashTableDoubleHashing::primaryHash(int key) {
    return key % tableSize;
}

int HashTableDoubleHashing::secondaryHash(int key) {
    return 7 - (key % 7);
}

void HashTableDoubleHashing::insert(int key) {
    int index = primaryHash(key);
    int stepSize = secondaryHash(key);
    int i = 0;

    while (table[(index + i * stepSize) % tableSize] != -1 && i < tableSize) {
        ++i;
    }

    if (i < tableSize) {
        table[(index + i * stepSize) % tableSize] = key;
    }
}

void HashTableDoubleHashing::display() {
    for (int i = 0; i < tableSize; ++i) {
        cout << i << ": " << (table[i] == -1 ? "EMPTY" : to_string(table[i])) << "\n";
    }
}