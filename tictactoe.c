/*
  TicTacToe
  A game between 2 players or player vs. computer
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int BOARD_SIZE = 3;
const int WINNING_COND = 3;

void printLine() { printf("===========================\n"); }
void initBoard(char (*board)[BOARD_SIZE]); // initialize or reset the board
void printBoard(char (*board)[BOARD_SIZE]);

int displayMenu(); // let player choose:
                   // - player vs. player
                   // - player vs. computer

int main()
{
  // TODO: Create a function for initGame
  // initGame:
  // - Display option to choose between vs. player or vs. computer

  // TODO: Create game logic for TicTacToe

  // TODO: Create logic for computer

  char board[BOARD_SIZE][BOARD_SIZE];

  initBoard(board);
  printf("%d", displayMenu());


  return 0;
}

void initBoard(char (*board)[BOARD_SIZE])
{
  for (int i = 0; i < BOARD_SIZE; i++)
  {
    for (int j = 0; j < BOARD_SIZE; j++)
    {
      board[i][j] = ' ';
    }
  }
}

void printBoard(char (*board)[BOARD_SIZE])
{
  printf("+-----------+\n");
  for (int row = 0; row < BOARD_SIZE; row++)
  {
    for (int column = 0; column < BOARD_SIZE; column++)
    {
      printf("| %c ", board[row][column]);
    }
    printf("|\n");
    printf("+-----------+\n");
  }
}

int displayMenu()
{
  int option;

  printLine();
  printf("WELCOME TO TIC TAC TOE!\n");
  printf("1 --- player vs. player\n");
  printf("2 --- player vs. computer\n");
  printf("Enter your choice (1 or 2): ");
  scanf("%d", &option);
  printLine();

  return option;
}