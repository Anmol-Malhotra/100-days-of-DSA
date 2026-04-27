#include <stdio.h>
#include <stdlib.h>

// Function to check if array represents a Min-Heap
int isMinHeap(int arr[], int n) {
    // For every parent node, check children
    for (int i = 0; i <= (n - 2) / 2; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // If left child exists and is smaller than parent
        if (left < n && arr[i] > arr[left]) {
            return 0;
        }

        // If right child exists and is smaller than parent
        if (right < n && arr[i] > arr[right]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    if (isMinHeap(arr, N)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}