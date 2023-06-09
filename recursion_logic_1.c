#include <stdio.h>

int max_array(int arr[], int n) {
    if (n == 1) {
        return arr[0];
    } else {
        int max_so_far = max_array(arr, n-1);
        if (arr[n-1] > max_so_far) {
            return arr[n-1];
        } else {
            return max_so_far;
        }
    }
}

int main() {
    int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int n = 11;
    int result = max_array(arr, n);
    printf("Maximum element in array is %d\n", result);
    return 0;
}

