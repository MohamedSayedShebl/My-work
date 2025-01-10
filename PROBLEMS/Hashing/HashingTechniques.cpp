#include "HashingTechniques.h"
#include <cmath>
#include <string>

using namespace std;

int divisionMethod(int key, int tableSize) {
    return key % tableSize;
}

int multiplicationMethod(int key, int tableSize) {
    const double A = 0.6180339887;
    double fractionalPart = key * A - int(key * A);
    return int(fractionalPart * tableSize);
}

int midSquareMethod(int key, int tableSize) {
    int squaredKey = key * key;
    int middle = (squaredKey / 100) % 100;
    return middle % tableSize;
}

int foldingMethod(int key, int tableSize) {
    string keyStr = to_string(key);
    int sum = 0;
    for (size_t i = 0; i < keyStr.size(); i += 2) {
        int part = stoi(keyStr.substr(i, 2));
        sum += part;
    }
    return sum % tableSize;
}
