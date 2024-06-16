// Class definition for Four_in_a_row_Board class
// Author:  Mohamed sayed shebl
// Date:    12/14/2023.

#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "BoardGame_Classes.hpp"
using namespace std;


// Set the board
Four_in_a_row_Board::Four_in_a_row_Board () {
    n_rows =6;
    n_cols = 7;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool Four_in_a_row_Board::update_board (int x,int y, char mark){
    // Determining which is the lowest row available
    int level=5;
    for (int i = 5; i > 0; --i) {
        if(board[i][y] != 0)level--;
    }
    // Only update if move is valid
    if (!(y < 0 || y > 6) && (board[level][y] == 0)) {
        board[level][y] = mark;
        n_moves++;
        return true;
    }
    else
        return false;
}

// Display the board and the pieces on it
void Four_in_a_row_Board::display_board() {
    for (int i=0;i<6;i++){
        cout << "\n| ";
        for (int j=0;j<7;j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n-----------------------------------------------------------------";
    }
    cout << endl;
}

// Returns true if there is any winner
// either X or O
bool Four_in_a_row_Board::is_winner(){
    // Check horizontally
    for (int x = 0; x < 6; ++x) {
        for (int y = 0; y <= 7 - 4; ++y) {
            if (board[x][y] ==board[x][y + 1] &&
                board[x][y + 1] == board[x][y + 2]&&
                board[x][y + 2] == board[x][y + 3] &&board[x][y]!=0
               ) {
                return true;
            }
        }
    }

    // Check vertically
    for (int y = 0; y < 7; ++y) {
        for (int x = 0; x <= 6 - 4; ++x) {
            if (board[x][y] ==board[x + 1][y] &&
                board[x + 1][y] ==board[x + 2][y] &&
                board[x + 2][y] ==board[x + 3][y] &&board[x][y]!=0
                ) {
                return true;
            }
        }
    }

    // Check diagonally (top-left to bottom-right)
    for (int x = 0; x <= 6 - 4; ++x) {
        for (int y = 0; y <= 7 - 4; ++y) {
            if (board[x][y] ==board[x + 1][y + 1]&&
                board[x + 1][y + 1] == board[x + 2][y + 2] &&
                board[x + 2][y + 2] ==board[x + 3][y + 3] &&board[x][y]!=0
                ) {
                return true;
            }
        }
    }

    // Check diagonally (top-right to bottom-left)
    for (int x = 0; x <= 6 - 4; ++x) {
        for (int y = 7 - 1; y >= 3; --y) {
            if (board[x][y] == board[x + 1][y - 1] &&
                board[x + 1][y - 1] == board[x + 2][y - 2] &&
                board[x + 2][y - 2] == board[x + 3][y - 3] &&board[x][y]!=0
         ) {
                return true;
            }
        }
    }

    return false;
}



// Return true if 42 moves are done and no winner
bool Four_in_a_row_Board::is_draw() {
    return (n_moves == 42 && !is_winner());
}

bool Four_in_a_row_Board::game_is_over () {
    return n_moves >= 42;
}
