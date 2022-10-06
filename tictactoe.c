/*
  TicTacToe
  A game between 2 players or player vs. computer
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayBoard();
void printLine();
void initGame();

int main()
{
  // TODO: Create multidimensional array to hold the player values
  char board[3][3];
  // Initialize board array with ' ' (space)
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      board[i][j] = ' ';
    }
  }

  // TODO: Create a function for initGame
  // initGame:
  // - Display option to choose between vs. player or vs. computer

  // TODO: Create a function to display the board

  // TODO: Create game logic for TicTacToe

  // TODO: Create logic for computer


  return 0;
}

void displayBoard(char board[3][])
{
  printf("+-----------+");
  printf("| %d | %d | %d |", board[0][0], board[0][1], board[0][2]);

}

void printLine()
{
  printf("===========================");
}

void initGame()
{
  
}