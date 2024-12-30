//
// Created by munir on 04/12/2024.
//

#ifndef GAMEBOARD_H
#define GAMEBOARD_H

typedef struct {
    int** values;       // Stores the card values
    int** revealed;     // Stores the state of each card (0 = hidden, 1 = revealed)
    int size;           // Board size (size * size)
} GameBoard;

GameBoard* initBoard(const int* , int);             //initiate the gameBoard
int playTurn(GameBoard*, int, int, int, int);       // make the user pick 2 numbers by writing there indices
int checkVictory(GameBoard*);                       //checks if all cards have been discovered (all indices have revealed value of 1)
void printBoard(GameBoard*);                        //prints the board with the revealed cards values and * for not revealed cards
void freeBoard(GameBoard*);                         // free all the pointers (makes sure that there is no memory leakage)

#endif //GAMEBOARD_H
