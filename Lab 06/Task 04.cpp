#include <iostream>

using namespace std;

int recursiveArraySum(int* arr[], int sizes[], int dim) {
    if (dim == 0) return 0;
    int sum = 0;
    for (int i = 0; i < sizes[0]; i++) sum += recursiveArraySum(arr[i], sizes + 1, dim - 1);
    return sum;
}
