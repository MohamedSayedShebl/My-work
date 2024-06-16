//File: A2_S19-S20_20220290_ProblemNum7
//Purpose : A function that forms a domino chain out of a set of dominoes given by the user (only if possible)
//Author: Mohamed Shebl.
//Section: S19-S20.
//ID: 20220290
//TA: Mohamed Talaat
//Date: 30 Oct 2023
#include <bits/stdc++.h>
using namespace std;
struct dominoT {
    int leftDots;
    int rightDots;
    dominoT(int leftSide,int rightSide){
        leftDots=leftSide;
        rightDots=rightSide;
    }
};
bool FormsDominoChain(vector<dominoT> & dominos,int &n) {
        bool possible = false;
        vector<dominoT> remaining;
        vector<dominoT> chain;
        vector<dominoT>temp;
        for (int r = 0; r < dominos.size(); r++) {
            temp.push_back(dominos[r]);
        }
        while(n>=0) {
            chain.push_back(dominos[n]);
            dominos.erase(dominos.begin() + n);
            for (int j = 0; j < dominos.size(); j++) {
                remaining.push_back(dominos[j]);
            }
            for (int i = 0; i < remaining.size(); i++) {
                if (chain[0].rightDots == remaining[i].leftDots) {
                    chain.push_back(remaining[i]);
                    remaining.erase(remaining.begin() + i);
                    int y = 1;
                    for (int u = 0; u < remaining.size()+5; ++u) {
                        for (int l = 0; l < remaining.size(); ++l) {
                            if (chain[y].rightDots == remaining[l].leftDots) {
                                chain.push_back(remaining[l]);
                                remaining.erase(remaining.begin() + l);
                                y++;
                                break;
                            }
                        }
                    }
                }

            }
            if (remaining.empty()){
                possible = true;
                break;
            }else{
                chain.clear();
                remaining.clear();
                dominos.clear();
                for (int h = 0; h < temp.size(); h++) {
                    dominos.push_back(temp[h]);
                }
            }
            n--;
        }
        if (possible) {
            cout << "True" << endl;
            for (int p = 0; p < chain.size(); ++p) {
                if (p == chain.size() - 1)cout << chain[p].leftDots << '|' << chain[p].rightDots;
                else cout << chain[p].leftDots << '|' << chain[p].rightDots << " - ";
            }
            return true;
        } else {
            cout<<"false";
            return false;
        }
    }
int main() {
    int numberOfPieces,leftSide,rightSide;
    cout<<"enter number of pieces: ";
    cin>>numberOfPieces;
    vector<dominoT>i(numberOfPieces,{1,1});
    for (int o = 0; o < numberOfPieces; ++o) {
        cin>>leftSide>>rightSide;
        i[o].leftDots=leftSide;
        i[o].rightDots=rightSide;
    }
    numberOfPieces-=1;
    FormsDominoChain(i,numberOfPieces);
    return 0;
}