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

  switch (displayMenu())
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

  endGame();
}

void initVsPlayer(char (*board)[BOARD_SIZE])
{
  char winner = ' ';
  char current_player = PLAYER1;

  while (winner == ' ' && checkUnoccupied(board) != 0)
  {
    printBoard(board);

    if (current_player == PLAYER1)
    {
      movePlayer(board, current_player);
      winner = checkWinner(board);
      current_player = PLAYER2;
      continue;
    }

    movePlayer(board, current_player);
    winner = checkWinner(board);
    current_player = PLAYER1;
  }

  printBoard(board);
  printWinnerPlayer(winner);
}

void initVsComputer(char (*board)[BOARD_SIZE])
{
  char winner = ' ';
  char current_player = PLAYER1;

  while (winner == ' ' && checkUnoccupied(board) != 0)
  {
    printBoard(board);

    if (current_player == PLAYER1)
    {
      movePlayer(board, current_player);
      winner = checkWinner(board);
      current_player = COMPUTER;
      continue;
    }

    moveComputer(board);
    winner = checkWinner(board);
    current_player = PLAYER1;
  }

  printBoard(board);
  printWinnerComputer(winner);
}

void movePlayer(char (*board)[BOARD_SIZE], const char player)
{
  int row;
  int column;

  do
  {
    if (player == PLAYER1)
      printf("Player 1: make your move\n");
    else if (player == PLAYER2)
      printf("Player 2: make your move\n");

    scanf("%d", &row);
    scanf(" %d", &column);

    // printf("Input: %d %d\n", row, column); // debug

    row--;
    column--;

    // printf("Row: %d | Column: %d\n", row, column); // debug

    if (board[row][column] != ' ')
    {
      printf("Invalid move! Position is occupied.\n");
      printBoard(board);
      continue;
    }

    board[row][column] = player;
    break;
  } while (board[row][column] != ' ');
}

void moveComputer(char (*board)[BOARD_SIZE])
{
  srand(time(0));
  int row;
  int column;

  if (checkUnoccupied(board) < 1)
    return;

  do
  {
    row = rand() % 3;
    column = rand() % 3;
  } while (board[row][column] != ' ');

  board[row][column] = COMPUTER;
  printf("Computer chooses %d and %d as the move!\n", row+1, column+1);
}

int checkUnoccupied(char (*board)[BOARD_SIZE])
{
  int unoccupied = pow(BOARD_SIZE, 2);

  for (int row = 0; row < BOARD_SIZE; row++)
    for (int column = 0; column < BOARD_SIZE; column++)
      if (board[row][column] != ' ')
        unoccupied--;

  if (unoccupied < 0)
  {
    printf("Exception: Lowest unoccupied is 0\n");
    exit(1);
  }

  // printf("Unoccupied: %d\n", unoccupied); // debug

  return unoccupied;
}

char checkWinner(char (*board)[BOARD_SIZE])
{
  // NOTE: only works for BOARD_SIZE = 3
  
  for(int row = 0; row < BOARD_SIZE; row++)
    if(board[row][0] == board[row][1] 
       && board[row][1] == board[row][2])
      return board[row][0];

  for(int column = 0; column < BOARD_SIZE; column++)
    if(board[0][column] == board[1][column]
       && board[1][column] == board[2][column])
      return board[0][column];

  // diagonal
  if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
    return board[0][0];

  // anti-diagonal
  if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
    return board[0][2];

  return ' ';
}

void printWinnerPlayer(char winner)
{
  if (winner == ' ')
  {
    printf("It's a tie!\n");
    return;
  }

  if (winner == PLAYER1)
  {
    printf("Player 1 wins!\n");
    return;
  }

  if (winner == PLAYER2)
  {
    printf("Player 2 wins!\n");
    return;
  }
}

void printWinnerComputer(char winner)
{
  if (winner == ' ')
  {
    printf("It's a tie!\n");
    return;
  }

  if (winner == PLAYER1)
  {
    printf("Player 1 wins!\n");
    return;
  }

  if (winner == COMPUTER)
  {
    printf("Computer wins!\n");
    return;
  }
}

void endGame()
{
  printf("End of game.\n");
}