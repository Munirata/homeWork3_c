#include <stdio.h>
#include "gameboard.h"

int main() {
    int values[] = {1, 2, 3, 4, 5, 6, 7, 8, 8, 1, 2, 3, 4, 5, 6, 7};
    int size = 4; // Board size (4x4)

    // Initialize game board
    GameBoard* gameBoard = initBoard(values, size);
    printf("Welcome to the Memory Game!\n");
    printf("The board is %dx%d. Match all pairs to win.\n", size, size);
    printf("Enter -1 at any time to quit.\n\n");

    int row1, col1, row2, col2;
    int victory = 0; // Game status

    while (!victory) {
        // Print the current state of the board
        printBoard(gameBoard);

        // Get the first card input
        printf("\nChoose the first card (row column): ");
        scanf("%d %d", &row1, &col1);
        if (row1 == -1 || col1 == -1) break;

        // Get the second card input
        printf("Choose the second card (row column): ");
        scanf("%d %d", &row2, &col2);
        if (row2 == -1 || col2 == -1) break;

        // Play the turn
        int result = playTurn(gameBoard, row1, col1, row2, col2);
        if (result == -1) {
            printf("Invalid input. Please try again.\n");
        } else if (result == 1) {
            printf("Match found! Keep going.\n");
        } else {
            printf("No match. Try again.\n");
        }

        // Check for victory
        victory = checkVictory(gameBoard);
    }

    if (victory) {
        printf("\nCongratulations! You've matched all pairs and won the game!\n");
    } else {
        printf("\nYou exited the game. Thanks for playing!\n");
    }

    // Clean up
    freeBoard(gameBoard);

    return 0;
}