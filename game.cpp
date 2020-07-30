////////////////////////////////////////////////////////////////////////////////
// Game Class                                                                 //
// player clases data and actions                                             //
////////////////////////////////////////////////////////////////////////////////
#include "game.h"
#include "player.h"
#include <memory>
#include <iostream>
#include <typeinfo>

using namespace std;

//constructor with args
//args:
//Player *p1 - first player
//Player *p2 - second player
Game::Game(Player* p1, Player* p2)  {
    SetPlayers(p1, p2);
}

//Sets the game players
void Game::SetPlayers(Player* p1, Player* p2) {
    player1 = p1; //Associates the first player
    player2 = p2; //Associates the second player    
}

//Game Loop
//Asks for the moves from both players until there is a winner
//TODO: if there is a tie will never exits te loop
int Game::PlayGame() {
    cout << "Let's play" << endl;

    int col = 0;
    bool valid = false;
    while (true) {
        while (!valid) {
            col = player1->Play();
            valid = board.Put(col, player1->GetPiecePattern()); 
        }
        valid = false;
        if(board.Connected4(1)){
            cout << "Ganó " << player1->GetName() << endl;
            return 1;
        }
        
        while (!valid) {
            col = player2->Play(); 
            valid = board.Put(col, player2->GetPiecePattern()); 
        }
        valid = false;
        if(board.Connected4(2)){
            cout << "Ganó " << player2->GetName() << endl;
            return 2;
        }
    }
}

