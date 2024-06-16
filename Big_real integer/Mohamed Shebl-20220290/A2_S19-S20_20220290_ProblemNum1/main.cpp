//File: A2_S19-S20_20220290_ProblemNum1
//Purpose : A program that reads in a sentence and outputs it with spacing corrected and with letters corrected for capitalization.
//Author:  Mohamed Shebl.
//Section: S19-S20.
//ID: 20220290
//TA: Mohamed Talaat
//Date: 30 Oct 2023

#include <iostream>
using namespace std;
int main() {
    string input;
    int firstLetter;
    cout<<"Please enter your sentence: ";
    getline(cin,input);
    firstLetter=input[0];
    if(firstLetter>96&&firstLetter<123)input[0]-=32;
    for (int i = 0; i < input.size(); ++i) {
        if(input[i]>64&&input[i]<91)input[i]+=32;
        int counter = 1;
        if (input[i] == ' ' && input[i + 1] == ' ') {
            for (int j = i + 1; j < input.size(); ++j) {
                if (input[j] == ' ')counter += 1;
                else break;
            }
            input.replace(i, counter, " ");
            counter = 0;

        }
    }
    cout<<input;

    return 0;
}
