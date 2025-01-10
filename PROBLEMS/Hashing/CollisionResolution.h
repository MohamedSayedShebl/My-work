#ifndef COLLISIONRESOLUTION_H
#define COLLISIONRESOLUTION_H

#include <vector>
#include <list>
#include <iostream>

class HashTableChaining {
private:
    std::vector<std::list<int>> table;

public:
    HashTableChaining(int size);
    int hashFunction(int key);
    void insert(int key);
    void display();
};

class HashTableOpenAddressing {
private:
    std::vector<int> table;
    int tableSize;

public:
    HashTableOpenAddressing(int size);
    int hashFunction(int key);
    void insert(int key);
    void display();
};

class HashTableDoubleHashing {
private:
    std::vector<int> table;
    int tableSize;

    int primaryHash(int key);
    int secondaryHash(int key);

public:
    HashTableDoubleHashing(int size);
    void insert(int key);
    void display();
};

#endif // COLLISIONRESOLUTION_H