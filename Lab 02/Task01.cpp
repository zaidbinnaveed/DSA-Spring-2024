#include <iostream>
using namespace std;

bool isDiagonalMatrix(int matrix[3][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i != j && matrix[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int matrix[3][3] = {{1, 0, 0}, {0, 2, 0}, {0, 0, 3}};
    if (isDiagonalMatrix(matrix, 3, 3))
        cout << "Matrix is diagonal." << endl;
    else
        cout << "Matrix is not diagonal." << endl;
    return 0;
}
