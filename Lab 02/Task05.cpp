#include <iostream>
using namespace std;

int main() {
    int* courses[4];
    int courseCount[] = {3, 4, 2, 1};
    for (int i = 0; i < 4; i++) {
        courses[i] = new int[courseCount[i]];
        for (int j = 0; j < courseCount[i]; j++) {
            courses[i][j] = (i + 1) * 10 + j;
        }
    }

    for (int i = 0; i < 4; i++) {
        cout << "Department " << i + 1 << ": ";
        for (int j = 0; j < courseCount[i]; j++) {
            cout << courses[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < 4; i++) delete[] courses[i];
    return 0;
}
