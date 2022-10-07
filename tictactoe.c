/*
  TicTacToe
  A game between 2 players or player vs. computer
*/
#include "tictactoe.h"

int main()
{
  char board[BOARD_SIZE][BOARD_SIZE];

  initGame(board);

  return 0;
}

// = = = = = = = = = = = = = = = = = =
// FUNCTIONS IMPLEMENTATION
// = = = = = = = = = = = = = = = = = =
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
    // printf("Option: %d\n", option); // debug

    if (option < 0 || option > 2)
      printf("Invalid input.\n");
      
  } while (option < 0 || option > 2);

  printLine();
  printf("You have entered choice %d\n", option);

  return option;
}

void initGame(char (*board)[BOARD_SIZE])
{
  initBoard(board);

  switch(displayMenu())
  {
    case 1:
      initVsPlayer(board);
      break;

    case 2:
      initVsComputer(board);
      break;

    default:
      initVsComputer(board);
      break;
  }
}

// TODO: initVsPlayer
char initVsPlayer(char (*board)[BOARD_SIZE])
{
  printf("initVsPlayer called\n");
  char winner = ' ';

  while (winner == ' ' && checkUnoccupied(board) != 0)
  {
    printBoard(board);

  }

  return winner;
}

// TODO: initVsComputer
char initVsComputer(char (*board)[BOARD_SIZE])
{
  char winner = ' ';

  printBoard(board);

  return winner;
}

// TODO: movePlayer
void movePlayer(char (*board)[BOARD_SIZE])
{
  int row;
  int column;

  
}

// TODO: moveComputer
void moveComputer(char (*board)[BOARD_SIZE])
{

}

// TODO: checkUnoccupied
int checkUnoccupied(char (*board)[BOARD_SIZE])
{
  int unoccupied = pow(BOARD_SIZE, 2);

  for(int row = 0; row < BOARD_SIZE; row++)
    for(int column = 0; column < BOARD_SIZE; column++)
      if(board[row][column] != ' ')
        unoccupied--;

  if (unoccupied < 0)
  {
    printf("Exception: Lowest unoccupied is 0\n");
    exit(1);
  }

  printf("Unoccupied: %d\n", unoccupied);

  return unoccupied;
}

// TODO: checkWinner
int checkWinner(char (*board)[BOARD_SIZE], char *winner)
{
  return 0;
}

