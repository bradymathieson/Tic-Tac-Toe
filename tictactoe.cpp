//
//  tictactoe.cpp
//  :)
//
//  Created by Brady Mathieson on 11/19/14.
//  Copyright (c) 2014 Brady Mathieson. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

// TO DO:
// Add comments to describe each function (consider RMEs?)

class Mark { // create a datatype known as 'Mark' to denote the char value in the spaces
private:
    char mark; // holds the value in each space in a char
public:
    
    /*
     * Mark() - default constructor, creating blanks for each mark
     * setMove() - checks if spot is taken, then changes mark
     * returnMove() - returns the value in the mark
     */
    
    Mark(){
        mark = ' ';
    }
    void setMove(bool ifX, int &moveNumber){
        if (mark != ' '){
            cout << "Spot already taken, try again!" << endl;
        }
        else {
            if (ifX){
                mark = 'X';
            }
            else {
                mark = 'O';
            }
            moveNumber++;
        }
    }
    char returnMove(){
        return mark;
    }
};

void showTitle(string title){
    for (int i = 0; i < title.length(); i++){
        cout << "*";
    }
    cout << endl << title << endl;
    for (int i = 0; i < title.length(); i++){
        cout << "*";
    }
    cout << endl;
}

void getNames(string &player1, string &player2){
    cout << "Enter X's name: ";
    getline(cin, player1);
    cout << "Enter O's name: ";
    getline(cin, player2);
    return;
}

void printBoard(Mark TL, Mark TM, Mark TR, Mark ML, Mark MM, Mark MR, Mark BL, Mark BM, Mark BR){
    cout << endl << " " << TL.returnMove() << " | " << TM.returnMove() << " | " << TR.returnMove() << endl;
    cout << "-----------" << endl;
    cout << " " << ML.returnMove() << " | " << MM.returnMove() << " | " << MR.returnMove() << endl;
    cout << "-----------" << endl;
    cout << " " << BL.returnMove() << " | " << BM.returnMove() << " | " << BR.returnMove() << endl << endl;
}

void changeMark(int location, bool ifX, Mark &TL, Mark &TM, Mark &TR, Mark &ML, Mark &MM, Mark &MR, Mark &BL, Mark &BM, Mark &BR, int &moveNumber){
    if (location == 1){
        TL.setMove(ifX, moveNumber);
    }
    else if (location == 2){
        TM.setMove(ifX, moveNumber);
    }
    else if (location == 3){
        TR.setMove(ifX, moveNumber);
    }
    else if (location == 4){
        ML.setMove(ifX, moveNumber);
    }
    else if (location == 5){
        MM.setMove(ifX, moveNumber);
    }
    else if (location == 6){
        MR.setMove(ifX, moveNumber);
    }
    else if (location == 7){
        BL.setMove(ifX, moveNumber);
    }
    else if (location == 8){
        BM.setMove(ifX, moveNumber);
    }
    else if (location == 9){
        BR.setMove(ifX, moveNumber);
    }
}

bool checkIfWin(Mark TL, Mark TM, Mark TR, Mark ML, Mark MM, Mark MR, Mark BL, Mark BM, Mark BR, string player1, string player2, string &winner, bool &draw){
    if (TL.returnMove() == TM.returnMove() && TM.returnMove() == TR.returnMove() && TL.returnMove() != ' '){
        if (TL.returnMove() == 'X'){
            winner = player1;
        }
        else {
            winner = player2;
        }
        return true;
    }
    else if (TL.returnMove() == MM.returnMove() && MM.returnMove() == BR.returnMove() && TL.returnMove() != ' '){
        if (TL.returnMove() == 'X'){
            winner = player1;
        }
        else {
            winner = player2;
        }
        return true;
    }
    else if (TL.returnMove() == ML.returnMove() && ML.returnMove() == BL.returnMove() && TL.returnMove() != ' '){
        if (TL.returnMove() == 'X'){
            winner = player1;
        }
        else {
            winner = player2;
        }
        return true;
    }
    else if (TM.returnMove() == MM.returnMove() && MM.returnMove() == BM.returnMove() && TM.returnMove() != ' '){
        if (TM.returnMove() == 'X'){
            winner = player1;
        }
        else {
            winner = player2;
        }
        return true;
    }
    else if (TR.returnMove() == MM.returnMove() && MM.returnMove() == BL.returnMove() && TR.returnMove() != ' '){
        if (TR.returnMove() == 'X'){
            winner = player1;
        }
        else {
            winner = player2;
        }
        return true;
    }
    else if (TR.returnMove() == MR.returnMove() && MR.returnMove() == BR.returnMove() && TR.returnMove() != ' '){
        if (TR.returnMove() == 'X'){
            winner = player1;
        }
        else {
            winner = player2;
        }
        return true;
    }
    else if (ML.returnMove() == MM.returnMove() && MM.returnMove() == MR.returnMove() && ML.returnMove() != ' '){
        if (ML.returnMove() == 'X'){
            winner = player1;
        }
        else {
            winner = player2;
        }
        return true;
    }
    else if (BL.returnMove() == BM.returnMove() && BM.returnMove() == BR.returnMove() && BL.returnMove() != ' '){
        if (BL.returnMove() == 'X'){
            winner = player1;
        }
        else {
            winner = player2;
        }
        return true;
    }
    else if (TL.returnMove() != ' ' && TM.returnMove() != ' ' && TR.returnMove() != ' ' && ML.returnMove() != ' '
             && MM.returnMove() != ' ' && MR.returnMove() != ' ' && BL.returnMove() != ' ' && BM.returnMove() != ' '
             && BR.returnMove() != ' '){ // Cat's Game
        draw = true;
        return true;
    }
    return false;
}

void getMove(int &move, int moveNumber, string player1, string player2){
    if (moveNumber % 2 == 1){
        cout << player1 << ", enter your location: ";
    }
    else {
        cout << player2 << ", enter your location: ";
    }
    cin >> move;
    while (cin.fail()){
        cin.clear();
        string trash;
        getline(cin, trash);
        cout << "Bad data, please try again: ";
        cin >> move;
    }
    while (move > 9 || move < 1){
        cout << "Please enter a number within 1 and 9: ";
        cin >> move;
    }
}

bool checkIfX(int moveNumber){
    if (moveNumber % 2 == 0){
        return false;
    }
    return true;
}

void changeBoard(int &moveNumber, int location, Mark &TL, Mark &TM, Mark &TR, Mark &ML, Mark &MM, Mark &MR, Mark &BL, Mark &BM, Mark &BR){
    if (checkIfX(moveNumber)){
        changeMark(location, true, TL, TM, TR, ML, MM, MR, BL, BM, BR, moveNumber);
    }
    else {
        changeMark(location, false, TL, TM, TR, ML, MM, MR, BL, BM, BR, moveNumber);
    }
}

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