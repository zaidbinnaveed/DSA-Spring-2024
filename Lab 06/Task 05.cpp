#include <iostream>

using namespace std;

#define N 5

bool isValid(int maze[N][N], int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

bool solveMaze(int maze[N][N], int x, int y, int sol[N][N]) {
    if (x == N - 1 && y == N - 1) {
        sol[x][y] = 1;
        return true;
    }
    if (isValid(maze, x, y)) {
        sol[x][y] = 1;
        if (solveMaze(maze, x + 1, y, sol) || solveMaze(maze, x, y + 1, sol)) return true;
        sol[x][y] = 0;
    }
    return false;
}

int main() {
    int maze[N][N] = {{1, 0, 0, 0, 0}, {1, 1, 0, 1, 1}, {0, 1, 1, 0, 1}, {0, 0, 1, 1, 1}, {0, 0, 0, 1, 1}};
    int sol[N][N] = {0};
    if (solveMaze(maze, 0, 0, sol)) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) cout << sol[i][j] << " ";
            cout << endl;
        }
    }
    return 0;
}
