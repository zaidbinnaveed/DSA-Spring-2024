#include <iostream>

using namespace std;

#define N 4

bool isSafe(int board[N][N], int row, int col) {
    for (int i = 0; i < row; i++) if (board[i][col]) return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) if (board[i][j]) return false;
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) if (board[i][j]) return false;
    return true;
}

bool placeFlags(int board[N][N], int row) {
    if (row >= N) return true;
    for (int i = 0; i < N; i++) {
        if (isSafe(board, row, i)) {
            board[row][i] = 1;
            if (placeFlags(board, row + 1)) return true;
            board[row][i] = 0;
        }
    }
    return false;
}

int main() {
    int board[N][N] = {0};
    if (placeFlags(board, 0)) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) cout << board[i][j] << " ";
            cout << endl;
        }
    }
    return 0;
}
