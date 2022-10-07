/*
  TicTacToe
  A game between 2 players or player vs. computer
*/
#include "tictactoe.h"

int main()
{
  // TODO: Create game logic for TicTacToe

  // TODO: Create logic for computer

  char board[BOARD_SIZE][BOARD_SIZE];

  initGame(board);

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
  printf("The current status is:\n");
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
  int option = -1;

  do
  {
    printLine();
    printf("WELCOME TO TIC TAC TOE!\n");
    printf("1 --- player vs. player\n");
    printf("2 --- player vs. computer\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &option);
    // printf("Option: %d\n", option);

    if (option < 0 || option > 2)
      printf("Invalid input.\n");
      
  } while (option < 0 || option > 2);

  printLine();
  return option;
}

void initGame(char (*board)[BOARD_SIZE])
{
  initBoard(board);

  if (displayMenu() != 1)
  {
    initVsComputer(board);
    return;
  }

  initVsPlayer(board);
}

// TODO: initVsPlayer
void initVsPlayer(char (*board)[BOARD_SIZE])
{
  
}

// TODO: initVsComputer
void initVsComputer(char (*board)[BOARD_SIZE])
{

}

// TODO: movePlayer
void movePlayer(char (*board)[BOARD_SIZE])
{

}

// TODO: moveComputer
void moveComputer(char (*board)[BOARD_SIZE])
{

}

// TODO: checkUnoccupied
int checkUnoccupied(char (*board)[BOARD_SIZE])
{
  return 0;
}

// TODO: checkWinner
int checkWinner(char (*board)[BOARD_SIZE], char *winner)
{
  return 0;
}