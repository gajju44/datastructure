#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

int board[MAX_SIZE];
int count = 0;
int solutionCount = 0;

int isSafe(int row, int col) {
    for (int prev = 0; prev < row; prev++) {
        if (board[prev] == col ||
            board[prev] - prev == col - row ||
            board[prev] + prev == col + row) {
            return 0;
        }
    }
    return 1;
}

void printSolution(int N) {
    printf("\nSolution %d:\n", ++count);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i] == j) {
                printf("Q ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

void solveNQueens(int N, int row) {
    if (solutionCount >= 2) {
        return;
    }
    if (row == N) {
        printSolution(N);
        solutionCount++;
        return;
    }
    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            solveNQueens(N, row + 1);
        }
    }
}

int main() {
    int N;
    printf("Enter the size of the chessboard (N): ");
    scanf("%d", &N);
   
    solveNQueens(N, 0);
   
    return 0;
}

