////////////////////////////////////////////////////////////////////////////////
// Connect 4                                                                  //
// Demo and practice code for the OOP Revised workshop                        //
// This is just demo code to show some principles of OOP                      //
// This app is not a complete app. A lot of stuff is missing or could be      //
// coded more efficiently                                                     //
// Game rules: https://en.wikipedia.org/wiki/Connect_Four                     //
////////////////////////////////////////////////////////////////////////////////                  

#include <iostream>
#include <string>
#include <cstdlib>
#include "game.h"
#include "player.h"

using namespace std;

int main()
{
    //Intanciates the two players and the Bot
    PlayerHuman player1("Player 1", 1);
    PlayerHuman player2("Player 2", 2);
    PlayerBot playerBot("Player Bot", 2);
    
    //instanciates the game
    Game game;
    
    //Allows to choose game mode
    string sopt;
    int opt = 0;

    while (opt == 0) {
        cout << "Choose game mode:" << endl;
        cout << "1 - Human vs Human:" << endl;
        cout << "2 - Human vs Bot:" << endl;
        
        cin >> sopt;
        opt = atoi(sopt.c_str());

        switch (opt) {
            case 1:
                //Polimorfism SetPlayers accepts 2 parameters of type Player
                //Here we call it with two HumanPlayers (childs of Players)
                game.SetPlayers(&player1, &player2);
                break;
            case 2:
                //Polimorfism SetPlayers accepts 2 parameters of type Player
                //Here we call it with a HumanPlayer and a BotPlayer (childs of Players)
                game.SetPlayers(&player1, &playerBot);
                break;
            default:
                opt = 0;
                cout << "invalid option..." << endl;
        } 
    }   
    
    //Starts the game
    game.PlayGame();
    return 0;
        
}