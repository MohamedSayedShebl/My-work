//// Class definition for Four_in_a_row app
//// Author:  Mohamed sayed shebl
//// Date:    12/14/2023.
//
//#include <iostream>
//#include"BoardGame_Classes.hpp"
//using namespace std;
//
//int main() {
//    int choice = 0;
//    Player* players[2];
//    players[0] = new Player (1, 'x');
//    while(choice != 1 && choice != 2) {
//    cout << "Welcome to the Four in a row Game. \n";
//    cout << "Press 1 if you want to play with computer, press 2 to insert player number 2: ";
//    cin >> choice;
//        if (choice == 2)
//            players[1] = new Player(2, 'o');
//        else if (choice == 1)
//            players[1] = new RandomPlayer('o', 7);
//    }
//
//    GameManager four_in_a_row_game (new Four_in_a_row_Board(), players);
//    four_in_a_row_game.run();
//    system ("pause");
//}
