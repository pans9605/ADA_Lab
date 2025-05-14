#include <stdio.h>

#define N 4

int board[N][N];
int solutionCount = 0;

int isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i][col]) return 0;
        if (col - (row - i) >= 0 && board[i][col - (row - i)]) return 0;
        if (col + (row - i) < N && board[i][col + (row - i)]) return 0;
    }
    return 1;
}

void printBoard() {
    printf("Solution %d:\n", ++solutionCount);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%c ", board[i][j] ? 'Q' : '.');
        printf("\n");
    }
    printf("\n");
}

void solve(int row) {
    if (row == N) {
        printBoard();  // Found one solution
        return;
    }
    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;
            solve(row + 1);       // Try next row
            board[row][col] = 0;  // Backtrack
        }
    }
}

int main() {
    solve(0);
    if (solutionCount == 0)
        printf("No solution found\n");
    return 0;
}
