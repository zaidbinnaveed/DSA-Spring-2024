#include <iostream>
#include <algorithm>
using namespace std;

int interpolationSearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    while (low <= high && x >= arr[low] && x <= arr[high]) {
        if (low == high) {
            if (arr[low] == x) return low;
            return -1;
        }

        int pos = low + ((x - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if (arr[pos] == x) {
            return pos;
        }
        if (arr[pos] < x) {
            low = pos + 1;
        }
        else {
            high = pos - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {10, 2, 0, 14, 43, 25, 18, 1, 5, 45};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n);
    
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int x = 5;
    int index = interpolationSearch(arr, n, x);
    cout << "Index of " << x << " is: " << index << endl;

    return 0;
}
