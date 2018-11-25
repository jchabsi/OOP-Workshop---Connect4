////////////////////////////////////////////////////////////////////////////////
// Board Class fefinition                                                     //
// Game board data and actions                                                //
////////////////////////////////////////////////////////////////////////////////

#ifndef BOARD_H
#define BOARD_H

class Board {
    private:
    // private attributes
    int board[6][7]; //matrix that represents the game board

    // prvate methods
    void Draw(); //Draws the board on the screen

    public:
    // Public Methods
        Board(); //Board constructor
        bool Put(int column, int piece); //Adds a piece to the board
        int Get(int column, int row); //Retrieves a piece from the board
        bool Connected4(int piece); //Checks if there is 4 consecutive pieces
};

#endif /*BOARD_H*/