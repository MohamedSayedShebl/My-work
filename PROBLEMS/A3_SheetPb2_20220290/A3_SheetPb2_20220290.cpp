// File name:A3_SheetPb2_20220290
// Purpose:A program testing out documents similarity
// Author(s):Mohamed sayed shebl
// ID(s):20220290
// Section:S20
// Date:12/7/2023

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <cctype>
#include <string>

using namespace std;

class StringSet {
private:
    set<string> words;

    // Helper function to tokenize a string into words
    vector<string> tokenizeString(const string &str) {
        vector<string> tokens;
        istringstream iss(str);
        string word;

        while (iss >> word) {
            // Remove punctuation and convert to lowercase
            word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            tokens.push_back(word);
        }

        return tokens;
    }

public:
    // Default constructor that creates an empty string set
    StringSet(){}
    // Constructor that loads words from a file or a string
    StringSet(const string &filename) {
        ifstream file(filename);
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                vector<string> tokens = tokenizeString(line);
                words.insert(tokens.begin(), tokens.end());
            }
            file.close();
        }else{
            vector<string> tokens = tokenizeString(filename);
            words.insert(tokens.begin(), tokens.end());
        }
    }

    // Function to add a string to the set
    void addString(const string &str) {
        vector<string> tokens = tokenizeString(str);
        words.insert(tokens.begin(), tokens.end());
    }

    // Function to remove a string from the set
    void removeString(const string &str) {
        vector<string> tokens = tokenizeString(str);
        for (const auto &token : tokens) {
            words.erase(token);
        }
    }

    // Function to clear the entire set
    void clearSet() {
        words.clear();
    }

    // Function to return the number of strings in the set
    int count() const {
        return words.size();
    }

    // Function to output all strings in the set
    void printSet() const {
        for (const auto &word : words) {
            cout << word << " ";
        }
        cout << endl;
    }

    // Overloading the + operator to return the union of two StringSet objects
    StringSet operator+(const StringSet &other) const {
        StringSet unionSet = *this;
        for (const auto &word : other.words) {
            unionSet.words.insert(word);
        }
        return unionSet;
    }

    // Overloading the * operator to return the intersection of two StringSet objects
    StringSet operator*(const StringSet &other) const {
        StringSet intersectionSet;
        for (const auto &word : words) {
            if (other.words.count(word) > 0) {
                intersectionSet.words.insert(word);
            }
        }
        return intersectionSet;
    }

    // Function to compute similarity using binary cosine coefficient
    double computeSimilarity(const StringSet &other) const {
        StringSet intersectSet = *this * other;
        double intersectionSize = static_cast<double>(intersectSet.words.size());
        double denominator = sqrt(static_cast<double>(words.size()) * static_cast<double>(other.words.size()));

        if (denominator == 0) {
            return 0.0; // Avoid division by zero
        }

        return intersectionSize / denominator;
    }
};

int main() {
    // Testing various operations
    StringSet docSet("Chocolate ice cream, chocolate milk, and chocolate bars are delicious.");
    StringSet querySet("Chocolate milk is tasty.");

    cout << "Document Set:" << endl;
    docSet.printSet();

    cout << "Query Set:" << endl;
    querySet.printSet();

    StringSet unionSet = docSet + querySet;
    cout << "Union Set:" << endl;
    unionSet.printSet();

    StringSet intersectionSet = docSet * querySet;
    cout << "Intersection Set:" << endl;
    intersectionSet.printSet();

    double similarity = docSet.computeSimilarity(querySet);
    cout << "Similarity between Document and Query: " << similarity << endl;

    return 0;
}
