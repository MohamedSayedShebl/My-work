#include <bits/stdc++.h>
using namespace std;

struct dominoT {
    int leftDots;
    int rightDots;
    dominoT(int leftSide, int rightSide) {
        leftDots = leftSide;
        rightDots = rightSide;
    }
};

// Function to check if a domino chain can be formed
bool FormsDominoChain(vector<dominoT> &dominos, int &n) {
    n--;
    bool possible = false;
    vector<dominoT> remaining;
    vector<dominoT> chain;
    vector<dominoT> temp;

    // Copy the original dominos to a temporary vector
    for (int r = 0; r < dominos.size(); r++) {
        temp.push_back(dominos[r]);
    }

    // Loop until we try connecting all dominos or until it's impossible to form a chain
    while (n >= 0) {
        chain.push_back(dominos[n]); // Start a chain with the current domino
        dominos.erase(dominos.begin() + n); // Remove the current domino from the available list

        // Copy remaining dominos to a separate vector
        for (int j = 0; j < dominos.size(); j++) {
            remaining.push_back(dominos[j]);
        }

        // Try to extend the chain using available dominos
        for (int i = 0; i < remaining.size(); i++) {
            if (chain[0].rightDots == remaining[i].leftDots) {
                chain.push_back(remaining[i]); // Add domino to the chain
                remaining.erase(remaining.begin() + i); // Remove the used domino from remaining
                int y = 1;

                // Try to extend the chain further
                for (int u = 0; u < remaining.size() + 5; ++u) {
                    for (int l = 0; l < remaining.size(); ++l) {
                        if (chain[y].rightDots == remaining[l].leftDots) {
                            chain.push_back(remaining[l]); // Add domino to the chain
                            remaining.erase(remaining.begin() + l); // Remove used domino from remaining
                            y++;
                            break;
                        }
                    }
                }
            }
        }

        // If all dominos used and chain formed successfully
        if (remaining.empty()) {
            possible = true;
            break;
        } else {
            // Clear vectors to start again with a different initial domino
            chain.clear();
            remaining.clear();
            dominos.clear();

            // Reset dominos to the original state
            for (int h = 0; h < temp.size(); h++) {
                dominos.push_back(temp[h]);
            }
        }
        n--;
    }

    // Display the chain if formed successfully
    if (possible) {
        cout << "True" << endl;
        for (int p = 0; p < chain.size(); ++p) {
            if (p == chain.size() - 1)
                cout << chain[p].leftDots << '|' << chain[p].rightDots;
            else
                cout << chain[p].leftDots << '|' << chain[p].rightDots << " - ";
        }
        return true;
    } else {
        cout << "false";
        return false;
    }
}

int main() {
    int numberOfPieces, leftSide, rightSide;
    cout << "enter number of pieces: ";
    cin >> numberOfPieces;
    vector<dominoT> i(numberOfPieces, {1, 1});
    for (int o = 0; o < numberOfPieces; ++o) {
        cin >> leftSide >> rightSide;
        i[o].leftDots = leftSide;
        i[o].rightDots = rightSide;
    }
    FormsDominoChain(i, numberOfPieces);
    return 0;
}