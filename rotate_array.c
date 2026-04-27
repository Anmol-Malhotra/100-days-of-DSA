#include <stdio.h>

int main() {
    int n;

    // Read size of array
    scanf("%d", &n);

    int arr[n];

    // Read elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int k;
    scanf("%d", &k);

    // Handle cases where k > n
    k = k % n;

    int temp[n];

    // Place last k elements at the beginning
    for(int i = 0; i < k; i++) {
        temp[i] = arr[n - k + i];
    }

    // Shift remaining elements
    for(int i = k; i < n; i++) {
        temp[i] = arr[i - k];
    }

    // Print rotated array
    for(int i = 0; i < n; i++) {
        printf("%d ", temp[i]);
    }

    return 0;
}