#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    int passCount = 0;
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        passCount++;
        if (!swapped) break;
    }
    cout << "Number of passes: " << passCount << endl;
}

int main() {
    int arr[] = {10, 2, 0, 14, 43, 25, 18, 1, 5, 45};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}
