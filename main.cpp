//
//  main.cpp
//  Othello
//
//  Created by Pongsakorn Cherngchaosil on 2/26/15.
//  Copyright (c) 2015 Pongsakorn Cherngchaosil. All rights reserved.
//

#include <iostream>
#include "OthelloGame.h"

using namespace std;

/** Gathering all user input and display output after each move. Keep track of whose turn it is
 and is responsible for detecting the end of the game. 
   Game ends when both player have to pass their turn in succession
   - need some way to determine when the game is over 
 45 lines
 */
////////////////////////////////////////////////////////////////////////
int main(int argc, const char * argv[]) {
   int row, column, pass = 0;
   // black goes first
   char currentPlayer = 1;
   char board[8][8] = {
      {0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0},
      {0,0,0,-1,1,0,0,0},
      {0,0,0,1,-1,0,0,0},
      {0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0},};
   while (pass != 2) {
      PrintBoard(board);
      if (currentPlayer == 1) {
         cout << "Black's turn, please choose move: ";
         GetMove(&row, &column);
      }
      else{
         cout << "White's turn, please choose move: ";
         GetMove(&row, &column);
      }
      while (!IsValidMove(board, row, column)) {
         cout << "Invalid move, try again: ";
         GetMove(&row, &column);
      }
      bool passMove = (row == -1) && (column == -1);
      if (passMove) {
         pass += 1;
         currentPlayer = -currentPlayer;
      }
      else{
         ApplyMove(board, row, column, currentPlayer);
         currentPlayer = -currentPlayer;
         pass = 0;
      }
   }
   int boardValue = GetValue(board);
   if (boardValue < 0) {
      cout << "Game over. White wins." << endl;
   }
   else if (boardValue > 0){
      cout << "Game over. Black wins." << endl;
   }
   else{
      cout << "Game over. Tie game." << endl;
   }
   return 0;
}