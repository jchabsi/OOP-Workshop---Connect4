////////////////////////////////////////////////////////////////////////////////
// Board Class implementation                                                 //
// Game board data and actions                                                //
////////////////////////////////////////////////////////////////////////////////
#include "board.h"
#include <iostream>

using namespace std;

//Board constructor
Board::Board() {
    //Inits the board
    for(int row = 0; row < 6; row++) {
        for(int col = 0; col < 7; col++) {
            board[row][col] = 0;
        }
    }

    //Draws the board on the screen
    Draw();    
}

// Adds a piece to the board according to the game rules
bool Board::Put(int col, int piece) {    
    int row = 0;
    for (; row < 6; row++) {
        if (board[row][col] != 0) {           
            break;
        }
    }
    if(row <= 0) {
        cout << "Invalid" << endl;
        return false;
    }
    else {
        row --;
        board[row][col] = piece;        
        Draw();
    }
    return true;    
}

//Updates the board on the screen 
//Make me pritier please!!!!!
void Board::Draw() {
    cout << endl;
    cout << "   -------------" << endl;;
    for(int row = 0; row < 6; row++) {
        cout << "   ";
        for(int col = 0; col < 7; col++) {
            cout << board[row][col] << " ";            
        }         
        cout << endl;
    }
    cout << "   -------------" << endl;
    cout << endl;
}

//Checks for 4 connected pieces according to the game rules
//Args: int piece - pattern to check for
bool Board::Connected4(int piece) {    
     for(int row = 0; row < 6; row++) {
        for(int col = 0; col < 7; col++) {
            
            if (board[row][col] == piece){

                int connected = 1;
                
                //Check horizontal
                int posH = col;
                while (++posH < 7 && board[row][posH] == piece){
                    connected++;
                    cout << "conected: " << connected << endl;
                    if(connected == 4) return true;
                }

                //Check vertical
                connected = 1;
                int posV = row;
                while (++posV < 6 && board[posV][col] == piece){
                    connected++;
                    cout << "conected: " << connected << endl;
                    if(connected == 4) return true;
                }

                //Check diagonal lower
                connected = 1;
                posH = col;
                posV = row;
                while (++posH < 7 && ++posV < 6 && board[posV][posH] == piece){
                    connected++;
                    cout << "conected: " << connected << endl;
                    if(connected == 4) return true;
                }
                //Check diagonal upper
                connected = 1;
                posH = col;
                posV = row;
                while (++posH < 7 && --posV >= 0 && board[posV][posH] == piece){
                    connected++;
                    cout << "conected: " << connected << endl;
                    if(connected == 4) return true;
                }                               
            }
        }
     }
     return false;
}