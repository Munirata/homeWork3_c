#include "GameBoard.h"
#include <stdlib.h>
#include <stdio.h>
GameBoard* initBoard(const int* predefinedValues, int size) {

    GameBoard* gameBoard = (GameBoard *) malloc(sizeof(GameBoard));
    if (gameBoard == NULL) {
        printf("Memory allocation failed for game");
        exit(1);
    }

    gameBoard->size = size;

    gameBoard->revealed = (int*) malloc(size * sizeof(int));
    if (gameBoard->revealed == NULL) {
        printf("Memory allocation failed for revealed values");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        gameBoard->revealed[i] = (int*) malloc(size * sizeof(int));
        if (gameBoard->revealed == NULL) {
            printf("Memory allocation failed for revealed values");
            exit(1);
        }

        for (int j = 0; j < size; j++) {
            gameBoard->revealed[i][j] = 0;
        }
    }

        gameBoard->values = (int*) malloc(size * sizeof(int));
        if (gameBoard->values == NULL) {
            printf("Memory allocation failed for values");
            exit(1);
        }

        for (int i = 0; i < size; i++) {
            gameBoard->values[i] = (int*) malloc(size * sizeof(int));
            if (gameBoard->values == NULL) {
                printf("Memory allocation failed for values");
                exit(1);
            }

            for (int j = 0; j < size; j++) {
                gameBoard->values[i][j] = predefinedValues[i*size + j];
            }
        }
    return gameBoard;
}

void printBoard(GameBoard* gb){
    int size = gb->size;

    for (int i = 0 ; i<size ; i++){
        for (int j = 0; j<size ; j++){
            if(gb->revealed[i][j] == 0 ){
            printf("*  ");
            }
            else
                printf("%d  ", gb->values[i][j]);
        }
        printf("\n");
    }
         printf("\n");
}

int playTurn(GameBoard* gb, int row1, int col1, int row2, int
col2){
    int size = gb->size;
    if(row1 >= size || col1 > size || row2 >= size || col2 >= size)
        return -1;

        gb->revealed[row1][col1] = 1;
        gb->revealed[row2][col2] = 1;
        printBoard(gb);

        if (gb->values[row1][col1] != gb->values[row2][col2]){
            gb->revealed[row1][col1] = 0;
            gb->revealed[row2][col2] = 0;
            return 0;
        }
            return 1;
    }


int checkVictory(GameBoard* gb){
    int size = gb->size;

    for (int i = 0 ; i<size ; i++){
        for (int j = 0; j<size ; j++){
            if(gb->revealed[i][j] != 1 ) {
                return 0;
            }
        }
    }
    return 1;
}

void freeBoard(GameBoard* gb){
    int size = gb->size;

    for (int i = 0; i < size; i++) {
        free(gb->revealed[i]);
    }
    free(gb->revealed);

    for (int i = 0; i < size; i++) {
        free(gb->values[i]);
    }
    free(gb->values);

 free(gb);
}