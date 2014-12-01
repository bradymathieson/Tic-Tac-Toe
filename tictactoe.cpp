//
//  tictactoe.cpp
//  :)
//
//  Created by Brady Mathieson on 11/19/14.
//  Copyright (c) 2014 Brady Mathieson. All rights reserved.
//

#include "tictactoe.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
    // VARIABLE DECLARATIONS
    string player1, player2, winner;
    int location;
    int moveNumber = 1;
    bool draw;
    Mark topLeft;
    Mark topMiddle;
    Mark topRight;
    Mark middleLeft;
    Mark middleMiddle;
    Mark middleRight;
    Mark bottomLeft;
    Mark bottomMiddle;
    Mark bottomRight;
    
    // INTRODUCTION
    showTitle("TIC-TAC-TOE v1");
    getNames(player1, player2);
    printBoard(topLeft, topMiddle, topRight, middleLeft, middleMiddle, middleRight, bottomLeft, bottomMiddle, bottomRight);
    
    // THE GAME
    while (!checkIfWin(topLeft, topMiddle, topRight, middleLeft, middleMiddle, middleRight, bottomLeft, bottomMiddle, bottomRight, player1, player2, winner, draw)){
        getMove(location, moveNumber, player1, player2);
        changeBoard(moveNumber, location, topLeft, topMiddle, topRight, middleLeft, middleMiddle, middleRight, bottomLeft, bottomMiddle, bottomRight);
        printBoard(topLeft, topMiddle, topRight, middleLeft, middleMiddle, middleRight, bottomLeft, bottomMiddle, bottomRight);
    }
    
    // PRINTS WINNER
    if (draw){
        cout << "It's a tie!";
    }
    else {
        cout << winner << " wins!";
    }
    
    cout << endl;
    return 0;
}