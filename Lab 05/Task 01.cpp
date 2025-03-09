#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    int n;
    cout << "Enter number of crates: ";
    cin >> n;
    int arr[n];
    cout << "Enter crate values: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    selectionSort(arr, n);

    cout << "Sorted crates: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}
