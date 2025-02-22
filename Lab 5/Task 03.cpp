#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void bubbleSort(int arr[], int n, int &comparisons) {
    comparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
        }
    }
}

void insertionSort(int arr[], int n, int &comparisons) {
    comparisons = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n, int &comparisons) {
    comparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[minIndex]) minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

void shellSort(int arr[], int n, int &comparisons) {
    comparisons = 0;
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i], j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                comparisons++;
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main() {
    srand(time(0));
    int n = 20, arr[100], comparisons;
    for (int i = 0; i < n; i++) arr[i] = rand() % 100 + 1;

    int temp[100];
    for (int i = 0; i < n; i++) temp[i] = arr[i];
    bubbleSort(temp, n, comparisons);
    cout << "Bubble Sort comparisons: " << comparisons << endl;

    for (int i = 0; i < n; i++) temp[i] = arr[i];
    insertionSort(temp, n, comparisons);
    cout << "Insertion Sort comparisons: " << comparisons << endl;

    for (int i = 0; i < n; i++) temp[i] = arr[i];
    selectionSort(temp, n, comparisons);
    cout << "Selection Sort comparisons: " << comparisons << endl;

    for (int i = 0; i < n; i++) temp[i] = arr[i];
    shellSort(temp, n, comparisons);
    cout << "Shell Sort comparisons: " << comparisons << endl;
}
