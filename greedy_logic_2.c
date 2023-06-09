#include <stdio.h>

int max(int n, int* a) {
    int maxi = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (sum > maxi) {
            maxi = sum;
        }
        if (sum < 0) {
            sum = 0;
        }
    }
    return maxi;
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int max_sum = max(n, a);
    printf("The maximum subset sum in the array is %d\n", max_sum);
    return 0;
}
