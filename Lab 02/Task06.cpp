#include <iostream>
using namespace std;

int main() {
    int* marks[5];
    int courses[] = {4, 3, 4, 1, 2};
    int studentIDs[] = {8818, 8821, 8835, 8842, 8856};

    for (int i = 0; i < 5; i++) {
        marks[i] = new int[courses[i]];
        for (int j = 0; j < courses[i]; j++) {
            marks[i][j] = (i + 1) * 10 + j + 1;
        }
    }

    for (int i = 0; i < 5; i++) {
        cout << "Student " << studentIDs[i] << ": ";
        for (int j = 0; j < courses[i]; j++) {
            cout << marks[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < 5; i++) delete[] marks[i];
    return 0;
}
