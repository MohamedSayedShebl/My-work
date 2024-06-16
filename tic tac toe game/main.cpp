#include <iostream>
#include"BoardGame_Classes.hpp"
using namespace std;

int main() {


    cout<<"welcome to game menu:\n"
          "1-pyramid_XO\n"
          "2-four_in_a_row\n"
          "3-five_X_O_Board\n"
          "4- X_O\n";

          int c;
          cin>>c;



          if(c==1){

              Player* players[2];
              players[0] = new Player (1, 'x');


              cout << "Press 1 if you want to play with computer, press 2 to insert player number 2: ";
              cin >>c;
              if (c == 2)
                  players[1] = new Player(2, 'o');
              else if (c == 1)
                  players[1] = new RandomPlayer('o', 3);



              Board *x=new pyramid_XO;

              GameManager games(x,players);
              games.run();
          }



          else if (c==2){

              Player* players[2];
              players[0] = new Player (1, 'x');

              Board *x=new Four_in_a_row_Board;


              cout << "Press 1 if you want to play with computer, press 2 to insert player number 2: ";
              cin >>c;
              if (c == 2)
                  players[1] = new Player(2, 'o');
              else if (c == 1)
                  players[1] = new r2('o', 6,7);





              GameManager games(x,players);
              games.run();

          }


          else if (c==3){

              Player* players[2];
              players[0] = new Player (1, 'x');


              cout << "Press 1 if you want to play with computer, press 2 to insert player number 2: ";
              cin >>c;
              if (c == 2)
                  players[1] = new Player(2, 'o');
              else if (c == 1)
                  players[1] = new r2('o', 5,5);



              Board *x=new five_X_O_Board;

              GameManager games(x,players);
              games.run();

          }

          else if (c==4){

              Player* players[2];
              players[0] = new Player (1, 'x');


              cout << "Press 1 if you want to play with computer, press 2 to insert player number 2: ";
              cin >>c;
              if (c == 2)
                  players[1] = new Player(2, 'o');
              else if (c == 1)
                  players[1] = new RandomPlayer('o', 3);



              Board *x=new X_O_Board;

              GameManager games(x,players);
              games.run();

          }



}
