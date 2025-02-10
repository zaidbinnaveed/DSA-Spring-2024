#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 2, 0, 14, 43, 25, 18, 1, 5, 45};
    int n = sizeof(arr) / sizeof(arr[0]);
    int passes = 0;

    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        passes++;
        if (!swapped) break;
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nTotal passes: " << passes << endl;
    
    return 0;
}
