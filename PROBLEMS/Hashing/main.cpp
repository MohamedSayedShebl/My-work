#include <iostream>
#include "HashingTechniques.h"
#include "CollisionResolution.h"

using namespace std;

int main() {
    // Hashing Example
    int key = 12345, tableSize = 10;
    cout << "Division Method: " << divisionMethod(key, tableSize) << "\n";
    cout << "Multiplication Method: " << multiplicationMethod(key, tableSize) << "\n";
    cout << "Mid-Square Method: " << midSquareMethod(key, tableSize) << "\n";
    cout << "Folding Method: " << foldingMethod(key, tableSize) << "\n";

    // Collision Resolution Example
    cout << "\nChaining Method:\n";
    HashTableChaining chainingTable(10);
    chainingTable.insert(10);
    chainingTable.insert(20);
    chainingTable.insert(25);
    chainingTable.display();

    cout << "\nOpen Addressing Method:\n";
    HashTableOpenAddressing openTable(10);
    openTable.insert(10);
    openTable.insert(20);
    openTable.insert(25);
    openTable.display();

    cout << "\nDouble Hashing:\n";
    HashTableDoubleHashing doubleHashTable(10);
    doubleHashTable.insert(10);
    doubleHashTable.insert(20);
    doubleHashTable.insert(25);
    doubleHashTable.display();
}