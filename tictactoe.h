#ifndef TICTACTOE_AJ_H
#define TICTACTOE_AJ_H

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
void initGame(char (*board)[BOARD_SIZE]);
void initVsPlayer(char (*board)[BOARD_SIZE]);
void initVsComputer(char (*board)[BOARD_SIZE]);

void movePlayer(char (*board)[BOARD_SIZE]); // initiate player move
void moveComputer(char (*board)[BOARD_SIZE]); // initiate computer move
int checkUnoccupied(char (*board)[BOARD_SIZE]); // check unoccupied spot
int checkWinner(char (*board)[BOARD_SIZE], char *winner); // 1 if there's a winner

#endif // TICTACTOE_AJ_H