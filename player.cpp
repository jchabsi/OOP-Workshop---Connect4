////////////////////////////////////////////////////////////////////////////////
// Player Classes                                                             //
// player clases data and actions                                             //
////////////////////////////////////////////////////////////////////////////////
#include "player.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include "board.h"

using namespace std;

//PlayerHuman Constructor
PlayerHuman::PlayerHuman() {
    cout << "Player Human" << endl;
}
//PlayerHuman Constructor with args (Overloading)
//string name - provided human name
//int humanPiece - Piece pattern that represents a human instance
PlayerHuman::PlayerHuman(string pName, int humanPiece) {
    cout << pName << endl;
    name = pName;
    piecePattern = humanPiece;
    cout << "Player Human " << name << endl;
}

//PlayerHuman play method
//Humans have to think their own move and provide it 
//This methods overrides the pure virtual method from Player (Polimorfism)
int PlayerHuman::Play() {
    int col = 0;
    string scol;
    cout << "Human " << GetName() << " plays..." << endl;
    do {
        cout << "Enter Column number [1 - 7]: ";
        cin >> scol;
        col = atoi(scol.c_str());
    } while (col < 1 || col > 7);
    
    return col - 1;
}

//Bot Constructor
PlayerBot::PlayerBot() {
    cout << "Player Bot" << endl;    
}

//bot constructor
// string name - Bot name
// int botPiece - Piece pattern that represents a bot instance
PlayerBot::PlayerBot(string pName, int botPiece) {
    name = pName; 
    piecePattern = botPiece;  
    cout << "Player Bot " << name << endl;
    lastCol = -1;
}

//Bot play algorithm
//Please make me smarter!!!
//This methods overrides the pure virtual method from Player (Polimorfism)
int PlayerBot::Play() {
    cout << "Bot " << GetName() << " plays..." << endl;
    cout << "I still don't have AI, I play very bad..." << endl;

    int col = 0;
    if (lastCol = -1) {
        //before doing this we might analyse whether we should play defensive or offensive
        col = rand() % 6;
        return col;
    }
    else {
        //Here we should try to connect the bot pieces
    }

    return 0;
}
