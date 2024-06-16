#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "BoardGame_Classes.hpp"
using namespace std;
pyramid_XO::pyramid_XO()
{
    n_rows =3;
    n_cols = 5; // maximum columns in the pyramid
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = ' '; // Initialize to empty space
    }
}
bool pyramid_XO::update_board(int x, int y, char mark)
{
    if (x==0 && y!=2)
        return false;


    else if ((x==1) && (y==0 ||y==4 ))
        return false;


    else if ((x<0 || y<0) || (x>2 || y>4))
        return false;

    else if (board[x][y]!=' ')
        return false;

    else
    {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
}
void pyramid_XO::display_board()
{
    for (int i: {0,1,2}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4})
        {
            if (((i==0&&j==0) || (i==0 && j==1) ||(i==0 && j==3) || (i==0 && j==4) || (i==1&&j==0)||(i==1&&j==4)))
            {
                cout<<setw(2)<<"       "<<" |";
            }
            else
            {
                cout << "(" << i << "," << j << ")";
                cout << setw(2) << board[i][j] << " |";
            }
        }
        cout << "\n-------------------------------------------------";
    }
    cout << endl;
}
bool pyramid_XO::is_winner()
{
    int row_W=1;
    for (int j = 1; j <3 ; ++j) {
        if (board[1][j]==board[1][j+1] && board[1][j]!=' ')
            row_W++;
    }

    if (row_W==3){return true;}

    row_W = 1;
    for (int j = 0; j <= 3; ++j)
    {
        if (row_W==3)
            return true;
        if (board[2][j]==board[2][j+1] && board[2][j]!=' ')
            row_W++;
        else
        {
            row_W=1;
        }

    }

    if (row_W==3){return true;}
    row_W = 1;

    int col_W = 1;
    for (int i = 0; i <= 1; ++i) {
        if (board[i][2]==board[i+1][2] && board[i][2]!=' ')
            col_W++;
    }
    if (col_W==3){return true;}
    col_W = 1;

    if ((board[0][2]==board[1][1])&&(board[1][1]==board[2][0]) && (board[0][2]!=' '))
    {
        return true;
    }
    if ((board[0][2]==board[1][3])&&(board[1][3]==board[2][4]) && (board[0][2]!=' '))
    {
        return true;
    }
    return false;
}
bool pyramid_XO::is_draw()
{
    return (n_moves == 9 && !is_winner());
}
bool pyramid_XO::game_is_over()
{
    return n_moves >= 9;
}
/*
int main() {
    pyramid_XO p1;
    p1.display_board();


}*/