#include <stdio.h>

char board[3][3];  // The Tic-Tac-Toe board

// Function to initialize the board
void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to display the board
void displayBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i < 2) {
            printf("\n---|---|---\n");
        }
    }
    printf("\n");
}

// Function to check if there is a winner
char checkWinner() {
    for (int i = 0; i < 3; i++) {
        // Check rows
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return board[i][0];
        // Check columns
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return board[0][i];
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return board[0][2];

    return ' '; // No winner yet
}

// Function to check if the board is full
int isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}

// Function to play the game
void playGame() {
    int row, col;
    char player = 'X';
    initializeBoard();

    while (1) {
        displayBoard();
        printf("Player %c, enter your move (row and column 1-3): ", player);
        scanf("%d %d", &row, &col);

        // Adjust for 0-based index
        row--;
        col--;

        // Check if the move is valid
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = player;
        } else {
            printf("Invalid move, try again.\n");
            continue;
        }

        // Check for a winner
        char winner = checkWinner();
        if (winner != ' ') {
            displayBoard();
            printf("Player %c wins!\n", winner);
            break;
        }

        // Check if it's a draw
        if (isBoardFull()) {
            displayBoard();
            printf("It's a draw!\n");
            break;
        }

        // Switch player
        player = (player == 'X') ? 'O' : 'X';
    }
}

// Main function
int main() {
    printf("Welcome to Tic-Tac-Toe!\n");
    playGame();
    return 0;
}