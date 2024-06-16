#include <bits/stdc++.h>
using namespace std;

void message(){
    ifstream in("inp.txt");
    ifstream ccin("test.txt");
    ofstream out("output.txt");
    map<string,int>main_words; // store the words of the main words and their positions
    vector<vector<string>>word_meanings;   // to access the alternative of one word
    string s;
    int pos=0;
    while(getline(ccin,s)){          // loop for every string in the test.txt
        string var;
        int i=0;
        word_meanings.push_back(vector<string>());
        for(;i<s.size();i++){   //loop for every char in the string
            if(s[i]>0 )break;    // if found any english char break to maintain the word we alternate
            var+=s[i];        // store the main word
        }
        main_words[var]=pos;        // here we access all main words with integers to access it with alternatives
        var="";
        for(;i<s.size();i++){  //skip the main word and loop for every char in string
            if(s[i]>0 ){        // in this if we search the space between all alternative arabic words
                if(var.size())   // if we get one alternative word we store it in the meaning of the main word stored by its index
                    word_meanings[pos].push_back(var);
                var="";
                continue;
            }
            var+=s[i]; // here we collect the string to store it
        }
        if(var.size()) // this is last alternative word and store it
            word_meanings[pos].push_back(var);
        pos++;

    }
    s="";
    while(getline(in,s)){ // iterate for all characters in the input line by line

        string var;
        for(int i=0;i<s.size()+1;i++){ // iterate for all charcters in the line
            if(s[i]>0 or (i==s.size())){ // here if true this means we get a word
                if(main_words.count(var)){ // check if this word exist in the table we create
                    srand(time(NULL));  //function random to choose randomly the word we print
                    int pos_word=main_words[var];
                    int rand_num=rand()%(word_meanings[pos_word].size());
                    out<<word_meanings[pos_word][rand_num]; // print random alternative word
                    if(i<s.size())  // here we print spaces between the words
                        out<<s[i];
                    var=""; // return empty to receive another alternative word
                    continue;
                }
                else {   // here we assume that the word doesnt exist in the table
                    out <<var;
                    if(i<s.size()) // cout the space
                        out << s[i];
                    var = "";
                }
                continue;
            }
            else
                var+=s[i]; // here we collect the charchters of the word


        }
        out<<'\n';
    }

}
int main(){
    message();
}