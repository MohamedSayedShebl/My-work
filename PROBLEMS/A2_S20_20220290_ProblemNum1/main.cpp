#include <iostream>
using namespace std;
int main() {
    string input;
    int firstLetter;
    cout<<"Please enter your sentence: ";
    getline(cin,input);
    firstLetter=input[0];
    if(firstLetter>96&&firstLetter<123)input[0]-=32;
    for (int i = 1; i < input.size(); ++i) {
        if(input[i]>64&&input[i]<91)input[i]+=32;
        int counter = 1;
        if (input[i] == ' ' && input[i + 1] == ' ') {
            for (int j = i + 1; j < input.size(); ++j) {
                if (input[j] == ' ')counter += 1;
                else break;
            }
            input.replace(i, counter, " ");

        }
    }
    cout<<input;

    return 0;
}
