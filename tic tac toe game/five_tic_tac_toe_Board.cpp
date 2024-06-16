
#include "bits/stdc++.h"
#include "BoardGame_Classes.hpp"
using namespace std;


five_X_O_Board::five_X_O_Board() {


    n_rows =5;

    n_cols = 5;

    board = new char*[n_rows];


    for (int i = 0; i < n_rows; i++) {

        board[i] = new char[n_cols];

        for (int j = 0; j < n_cols; j++)
            board[i][j] = ' ';
    }
}




bool five_X_O_Board::is_winner() {


    if (n_moves<24)
        return false;

    int x=0,y=0,cnt=1;

    for (int i = 0; i <=4 ; ++i) {

        for (int j = 0; j <=3 ; ++j) {

            if (cnt==3){

                ++x;
            }

            if (board[i][j]==board[i][j+1] && board[i][j]=='X')
                ++cnt;

            else
                cnt=1;
        }
    }



    cnt=1;


    for (int i = 0; i <=4 ; ++i) {
        for (int j = 0; j <=3 ; ++j) {


            if (cnt==3)
                ++x;


            if (board[j][i]==board[j+1][i] && board[j][i]=='X')
                ++cnt;


            else
                cnt=1;
        }
    }


    cnt=1;




    for (int i = 0; i <=4 ; ++i) {

        for (int j = 0; j <=3 ; ++j) {

            if (cnt==3){

                ++y;
            }

            if (board[i][j]==board[i][j+1] && board[i][j]=='O')
                ++cnt;

            else
                cnt=1;
        }
    }



    cnt=1;


    for (int i = 0; i <=4 ; ++i) {
        for (int j = 0; j <=3 ; ++j) {


            if (cnt==3)
                ++y;


            if (board[j][i]==board[j+1][i] && board[j][i]=='O')
                ++cnt;


            else
                cnt=1;
        }
    }


    cnt=1;



    if(board[0][0]==board[1][1] &&board[1][1]==board[2][2]
    && board[0][0]=='X')
        ++x;

    if (board[1][1]==board[2][2] && board[2][2]==board[3][3] && board[1][1]=='X')
        ++x;

    if(board[2][2]==board[3][3] && board[3][3]==board[4][4] && board[2][2]=='X')
        ++x;




    if (board[1][0]==board[2][1] && board[2][1]==board[3][2]  && board[1][0]=='X')
        ++x;

    if (board[2][1]==board[3][2] && board[3][2]==board[4][3]  && board[2][1]=='X')
        ++x;


    if (board[2][0]==board[3][1] && board[3][1]==board[4][2]  && board[2][0]=='X')
        ++x;

    if (board[2][0]==board[1][1] && board[1][1]==board[0][2] && board[2][0]=='X')
        ++x;

    if (board[3][0]==board[2][1] && board[2][1]==board[1][2] && board[3][0]=='X')
        ++x;


    if (board[2][1]==board[1][2] && board[1][2]==board[0][3] && board[2][1]=='X')
        ++x;


    if (board[4][0]==board[3][1] && board[3][1]==board[2][2] && board[4][0]=='X')
        ++x;

    if (board[3][1]==board[2][2] && board[1][3] && board[3][1]=='X')
        ++x;


    if (board[2][2]==board[1][3] && board[1][3]==board[0][4] && board[2][2]=='X')
        ++x;


    if (board[4][1]==board[3][2] && board[3][2]==board[2][3] &&  board[4][1]=='X')
        ++x;

    if (board[3][2]==board[2][3] && board[2][3]==board[1][4] && board[3][2]=='X')
        ++x;

    if (board[4][2]==board[3][3] && board[3][3]==board[2][4] && board[4][2]=='X')
        ++x;



    if(board[0][0]==board[1][1] &&board[1][1]==board[2][2]
       && board[0][0]=='O')
        ++y;

    if (board[1][1]==board[2][2] && board[2][2]==board[3][3] && board[1][1]=='O')
        ++y;

    if(board[2][2]==board[3][3] && board[3][3]==board[4][4] && board[2][2]=='O')
        ++y;




    if (board[1][0]==board[2][1] && board[2][1]==board[3][2]  && board[1][0]=='O')
        ++y;

    if (board[2][1]==board[3][2] && board[3][2]==board[4][3]  && board[2][1]=='O')
        ++y;


    if (board[2][0]==board[3][1] && board[3][1]==board[4][2]  && board[2][0]=='O')
        ++y;

    if (board[2][0]==board[1][1] && board[1][1]==board[0][2] && board[2][0]=='O')
        ++y;

    if (board[3][0]==board[2][1] && board[2][1]==board[1][2] && board[3][0]=='O')
        ++y;


    if (board[2][1]==board[1][2] && board[1][2]==board[0][3] && board[2][1]=='O')
        ++y;


    if (board[4][0]==board[3][1] && board[3][1]==board[2][2] && board[4][0]=='O')
        ++y;

    if (board[3][1]==board[2][2] && board[1][3] && board[3][1]=='O')
        ++y;


    if (board[2][2]==board[1][3] && board[1][3]==board[0][4] && board[2][2]=='O')
        ++y;


    if (board[4][1]==board[3][2] && board[3][2]==board[2][3] &&  board[4][1]=='O')
        ++y;

    if (board[3][2]==board[2][3] && board[2][3]==board[1][4] && board[3][2]=='O')
        ++y;

    if (board[4][2]==board[3][3] && board[3][3]==board[2][4] && board[4][2]=='O')
        ++y;

    


    if (x>y) {
        cout << "x wins\n";
        return true;

    }

    else if (y>x){
        cout << "o wins\n";
        return true;
    }

    else
        return false;




}

bool five_X_O_Board::update_board(int x, int y, char mark) {


    if (x>4 || y>4)
        return false;

    if (x<0 || y<0)
        return false;

    else{
        board[x][y]= toupper(mark);
        ++n_moves;
        return true;
    }
}

bool five_X_O_Board::game_is_over() {
    return (n_moves==24);
}


bool five_X_O_Board::is_draw() {
    return (n_moves==24 && !is_winner());
}


void five_X_O_Board::display_board() {

    for (int i=0;i<5;i++){
        cout << "\n| ";
        for (int j=0;j<5;j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n-----------------------------------------------------------------";
    }
    cout << endl;
}