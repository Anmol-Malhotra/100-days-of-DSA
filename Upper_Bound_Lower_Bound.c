#include <stdio.h>

// Function to find lower bound
int lowerBound(int arr[], int n, int x) {
    int low = 0, high = n;
    while (low < high) {
        int mid = (low + high) / 2;
        if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid;
    }
    return low; // First index where arr[i] >= x
}

// Function to find upper bound
int upperBound(int arr[], int n, int x) {
    int low = 0, high = n;
    while (low < high) {
        int mid = (low + high) / 2;
        if (arr[mid] <= x)
            low = mid + 1;
        else
            high = mid;
    }
    return low; // First index where arr[i] > x
}

int main() {
    int n, x;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &x);

    int lb = lowerBound(arr, n, x);
    int ub = upperBound(arr, n, x);

    printf("%d %d\n", lb, ub);

    return 0;
}
