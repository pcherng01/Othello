//
//  OthelloGame.cpp
//  Othello
//
//  Created by Pongsakorn Cherngchaosil on 2/26/15.
//  Copyright (c) 2015 Pongsakorn Cherngchaosil. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "OthelloGame.h"

using namespace std;

// 15 lines of code
void PrintBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
   cout << "- 0 1 2 3 4 5 6 7" << endl;
   for (int row = 0; row < BOARD_SIZE; row++) {
      cout << row << " ";
      for (int column = 0; column < BOARD_SIZE; column++) {
         char playr = board[row][column];
         char player = (playr == 0) ? '.' : (playr == 1) ? 'B' : 'W';
         cout << player << " ";
      }
      cout << endl;
   }
}
// 2 lines
bool InBounds(int row, int col) {
   bool inTheBound = (row >= 0) && (col >= 0);
   return (inTheBound && (row < BOARD_SIZE) && (col < BOARD_SIZE));
}
////////////////////////////////////////////////////////////////////////
// 3 lines
bool IsValidMove(char board[BOARD_SIZE][BOARD_SIZE], int row, int col) {
   bool pass = ((row < 1) && (col < 1)) ? true : false;
   bool emptyNBound = (board[row][col] == 0) && InBounds(row, col);
   return (emptyNBound || pass);
}

////////////////////////////////////////////////////////////////////////
// 2 lines
void GetMove(int *row, int *col) {
   char aChar = 0;
   cin >> aChar >> *row >> aChar >> *col >> aChar;
}

// 20 lines
////////////////////////////////////////////////////////////////////////
void ApplyMove(char board[BOARD_SIZE][BOARD_SIZE], int row, int col,
               char currentPlayer) {
   board[row][col] = currentPlayer;
   for (int i = -1; i <= 1; i++) {
      for (int ii = -1; ii <= 1; ii++){
         if (InBounds(row + i, col + ii)) {
            if (board[row + i][col + ii] == -currentPlayer) {
               int dx = i, dy = ii, nDx = -i, nDy = -ii;
               while(board[row + dx][col + dy] != currentPlayer){
                  dx += i;
                  dy += ii;
                  if (board[row + dx][col + dy] == 0) {
                     break;
                  }
               }
               if (board[row + dx][col + dy] == currentPlayer) {
                  char aPiece = board[row + dx + nDx][col + dy + nDy];
                  while (aPiece != currentPlayer){
                     aPiece = currentPlayer;
                     nDx += -i;
                     nDy += -ii;
                  }
               }
            }
         }
         
      }
   }
}

// 5 lines
int GetValue(char board[BOARD_SIZE][BOARD_SIZE]) {
   int sum = 0;
   for (int row = 0; row < BOARD_SIZE; row++) {
      for (int col = 0; col < BOARD_SIZE; col++){
         sum += board[row][col];
      }
   }
   return sum;
}