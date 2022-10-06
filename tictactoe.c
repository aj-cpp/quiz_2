/*
  TicTacToe
  A game between 2 players or player vs. computer
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int BOARD_SIZE = 3;
const int WINNING_STREAK = 3;

int main()
{
  // TODO: Create multidimensional array to hold the player values
  char board[BOARD_SIZE][BOARD_SIZE];
  // Initialize board array with ' ' (space)
  for (int i = 0; i < BOARD_SIZE; i++)
  {
    for (int j = 0; j < BOARD_SIZE; j++)
    {
      board[i][j] = ' ';
    }
  }

  

  // TODO: Create a function for initGame
  // initGame:
  // - Display option to choose between vs. player or vs. computer

  // TODO: Create a function to display the board

  // TODO: Create game logic for TicTacToe


  return 0;
}