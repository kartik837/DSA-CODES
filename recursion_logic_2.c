#include <stdio.h>

int sum_array(int arr[], int n) {
    if (n == 0) {
        return 0;
    } else {
        return arr[n-1] + sum_array(arr, n-1);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    int result = sum_array(arr, n);
    printf("Sum of array elements is %d\n", result);
    return 0;
}

