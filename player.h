////////////////////////////////////////////////////////////////////////////////
// Player Classes                                                             //
// player clases data and actions                                             //
////////////////////////////////////////////////////////////////////////////////
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "board.h"

using namespace std;

// Abstract Class Player for common members for all type of players
class Player {
    private:
        Board* board; //reference to the game board (Association)
                
    protected:
        string name; //Player Name
        int piecePattern; //Piece pattern that is drawn on the board
        int lastCol; //Last Column where a piece were introduced
           
    public:
        virtual int Play() = 0; //Pure virtual method (Polimorfism)
        string GetName() { return name; } //Getter for the name attribute
        void SetBoard(Board *refBoard) { board = refBoard; } // Setter for the Game board association
        int GetPiecePattern() { return piecePattern; } // Gets the piece pattern  
};

//Class PlayerHuman - specialization for a Human Player
class PlayerHuman : public Player {
    
    public:
        PlayerHuman(); //constructor with no args
        PlayerHuman(string pName, int humanPiece); //constructor with args (constructor overloading)
        int Play(); // Play method for a Human (Polimorfism)
};

//Class PlayerBot - specialization for a Bot Player
class PlayerBot : public Player {     
     public:
        PlayerBot(); //constructor with no args
        PlayerBot(string pName, int botPiece); //constructor with args (constructor overloading)
        int Play(); // Play method for a Bot (Polimorfism)       
};

#endif /*PLAYER_H*/