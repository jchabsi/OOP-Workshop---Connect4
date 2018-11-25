////////////////////////////////////////////////////////////////////////////////
// Game Class                                                                 //
// player clases data and actions                                             //
////////////////////////////////////////////////////////////////////////////////
#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "player.h"
#include <memory>

class Game {

    private:
        Board board; //Game board (Composition)
        Player* player1; //points to the first player (Association)
        Player* player2; //points to the second player (association)    
    public:
        Game(){}; //no args empty contructor 
        Game(Player *player1, Player *player2); //Constructor with args (overloading) 
        void SetPlayers(Player *player1, Player *player2); //Sets the game players (polimorfism)
        int PlayGame(); // game loop    
};

#endif /*GAME_H*/