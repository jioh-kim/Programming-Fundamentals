//
//  playMove.cpp
//  TicTacToe
//
//  Created by Tarek Abdelrahman on 2019-06-07.
//  Modified by Tarek Abdelrahman on 2020-09-17.
//  Copyright © 2019-2020 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.
//
//  ECE244 Student: write your code for playMove in this file

#include "globals.h"
#include "GameState.h"
#include <iostream>
using namespace std;

void playMove(GameState& game_state) {

    if (game_state.get_gameBoard(game_state.get_selectedRow(), game_state.get_selectedColumn()) == Empty){
        game_state.set_moveValid(true);
        // fill the selected array with X or O depends on the turn
        game_state.set_gameBoard(game_state.get_selectedRow(), game_state.get_selectedColumn(), game_state.get_turn()); 
    } else {
        game_state.set_moveValid(false);
    }
    
    // when it moveValid is true and it is X's turn (true)
    if (game_state.get_moveValid() == true && game_state.get_turn() == true){
        // setting the [row][col] = X
        game_state.set_gameBoard(game_state.get_selectedRow(), game_state.get_selectedColumn(), X);
        // now check if there is a winner
            // row 0
        if (game_state.get_gameBoard(0,0) == X 
        && game_state.get_gameBoard(0,1) == X
        && game_state.get_gameBoard(0,2) == X){
            game_state.set_winCode(1);
            game_state.set_gameOver(true);
            // row 1
        } if (game_state.get_gameBoard(1,0) == X 
        && game_state.get_gameBoard(1,1) == X
        && game_state.get_gameBoard(1,2) == X){
            game_state.set_winCode(2);
            game_state.set_gameOver(true);
            // row 2
        } if (game_state.get_gameBoard(2,0) == X 
        && game_state.get_gameBoard(2,1) == X
        && game_state.get_gameBoard(2,2) == X){
            game_state.set_winCode(3);
            game_state.set_gameOver(true);
            // column 0
        } if (game_state.get_gameBoard(0,0) == X 
        && game_state.get_gameBoard(1,0) == X
        && game_state.get_gameBoard(2,0) == X){
            game_state.set_winCode(4);
            game_state.set_gameOver(true);
            // column 1
        } if (game_state.get_gameBoard(0,1) == X 
        && game_state.get_gameBoard(1,1) == X
        && game_state.get_gameBoard(2,1) == X){
            game_state.set_winCode(5);
            game_state.set_gameOver(true);
            // column 2
        } if (game_state.get_gameBoard(0,2) == X 
        && game_state.get_gameBoard(1,2) == X
        && game_state.get_gameBoard(2,2) == X){
            game_state.set_winCode(6);
            game_state.set_gameOver(true);
            // left to right diagonal
        } if (game_state.get_gameBoard(0,0) == X 
        && game_state.get_gameBoard(1,1) == X
        && game_state.get_gameBoard(2,2) == X){
            game_state.set_winCode(7);
            game_state.set_gameOver(true);
            // right to left diagonal
        } if (game_state.get_gameBoard(2,0) == X 
        && game_state.get_gameBoard(1,1) == X
        && game_state.get_gameBoard(0,2) == X){
            game_state.set_winCode(8);
            game_state.set_gameOver(true);
        } 
    }

        if (game_state.get_moveValid() == true && game_state.get_turn() == false){
        // when it is false, it is O's turn 
        game_state.set_gameBoard(game_state.get_selectedRow(), game_state.get_selectedColumn(), O);
            // now check if there is a winner
            // row 0
        if (game_state.get_gameBoard(0,0) == O
        && game_state.get_gameBoard(0,1) == O
        && game_state.get_gameBoard(0,2) == O){
            game_state.set_winCode(1);
            game_state.set_gameOver(true);
            // row 1
        } if (game_state.get_gameBoard(1,0) == O 
        && game_state.get_gameBoard(1,1) == O
        && game_state.get_gameBoard(1,2) == O){
            game_state.set_winCode(2);
            game_state.set_gameOver(true);
            // row 2
        } if (game_state.get_gameBoard(2,0) == O 
        && game_state.get_gameBoard(2,1) == O
        && game_state.get_gameBoard(2,2) == O){
            game_state.set_winCode(3);
            game_state.set_gameOver(true);
            // column 0
        } if (game_state.get_gameBoard(0,0) == O 
        && game_state.get_gameBoard(1,0) == O
        && game_state.get_gameBoard(2,0) == O){
            game_state.set_winCode(4);
            game_state.set_gameOver(true);
            // column 1
        } if (game_state.get_gameBoard(0,1) == O 
        && game_state.get_gameBoard(1,1) == O
        && game_state.get_gameBoard(2,1) == O){
            game_state.set_winCode(5);
            game_state.set_gameOver(true);
            // column 2
        } if (game_state.get_gameBoard(0,2) == O 
        && game_state.get_gameBoard(1,2) == O
        && game_state.get_gameBoard(2,2) == O){
            game_state.set_winCode(6);
            game_state.set_gameOver(true);
            // left to right diagonal
        } if (game_state.get_gameBoard(0,0) == O 
        && game_state.get_gameBoard(1,1) == O
        && game_state.get_gameBoard(2,2) == O){
            game_state.set_winCode(7);
            game_state.set_gameOver(true);
            // right to left diagonal
        } if (game_state.get_gameBoard(2,0) == O 
        && game_state.get_gameBoard(1,1) == O
        && game_state.get_gameBoard(0,2) == O){
            game_state.set_winCode(8);
            game_state.set_gameOver(true);
        }
    } 
    
     if (game_state.get_turn () == true){
            game_state.set_turn(false);
        } else if (game_state.get_turn () == false){
            game_state.set_turn(true);
        }

// check the tie cases
    bool checkTie = true;
// check for empty spaces
    for (int i = 0; i < 3; i++){
            cout << "   ";
            for (int j = 0; j < 3; j++){
                if(game_state.get_gameBoard(i,j) == Empty){
                    checkTie = false;
                }
            }
        }
    
// if theres no empty space, game ends and wincode sets to 0
    if (checkTie == true){
        game_state.set_gameOver(true);
    } 

}

