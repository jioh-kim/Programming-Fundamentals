//
//  GameState.cpp
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

#include "globals.h"
#include "GameState.h"
#include <iostream>
using namespace std;

GameState::GameState(){
    selectedRow = 0;
    selectedColumn = 0;
    moveValid = true;
    gameOver = false;
    winCode = 0;
    turn = 1;
   
    // turn is set as X as default and X is true, meaning its "1"
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            gameBoard[i][j] = Empty;
        }
    }
}

 // Return the selected row (in the range 0..boardSize-1)
    int GameState::get_selectedRow(){
        return selectedRow;
    }   

    // Return the selected column (in the range 0..boardSize-1)
    int GameState::get_selectedColumn(){
        return selectedColumn;
    } 
    
    // Set the selected row to value in the range (in the range 0..boardSize-1)
    // An out of range value is ignored and the function just returns
    void GameState::set_selectedRow(int value){
        selectedRow = value;
    }    

    // Set the selected column in the range (in the range 0..boardSize-1)
    // An out of range value is ignored and the function just returns
    void GameState::set_selectedColumn(int value){
        selectedColumn = value;
    }  
    
    // Get the moveValid value
    bool GameState::get_moveValid(){
        return moveValid;
    }

    // Set the moveValid variable to value
    void GameState::set_moveValid(bool value){
        moveValid = value;
    }

    // Get the gameOver value
    bool GameState::get_gameOver(){
        return gameOver;
    }

    // Set the gameOver variable to value
    void GameState::set_gameOver(bool value){
        gameOver = value;
    }

    // Get the winCode [0..8]
    int GameState::get_winCode(){
        return winCode;
    }
    
    // Set the winCode to value in the range (0..8)
    // An out of range value is ignored and the function just returns
    void GameState::set_winCode(int value){
        winCode = value;
    }
    
    // Get the value of turn
    bool GameState::get_turn(){
        return turn;
    }

    // Set the value of turn
    void GameState::set_turn(bool value){
        turn = value;
    }
    
    // Get the game board value at the board location at row and col
    // This method checks that row, col and value are in range/valid
    // and if not it returns Empty
    int GameState::get_gameBoard(int row, int col){
        return gameBoard[row][col];
    }

    // Set the game board value at the board location at row and col to value
    // This method checks that row, col and value are in range/valid and if not it
    // just returns
    void GameState::set_gameBoard(int row, int col, int value){
        if (value == 1){
            gameBoard[row][col] = 1;
        } else {
            // else is when value == 0 (when it is 0, it sets it as -1 so it can conver to O later)
            gameBoard[row][col] = -1;
        }
    }


