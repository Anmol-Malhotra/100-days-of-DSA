#include <stdio.h>

#define MAX 1000

// Simple hash map using arrays (for demo)
int main() {
    int n;
    scanf("%d", &n);

    int arr[MAX];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefixSum = 0;
    int maxLen = 0;

    // Hash map arrays
    int sum[MAX * 2];
    int index[MAX * 2];

    int size = 0;

    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // Case 1: sum = 0
        if(prefixSum == 0) {
            maxLen = i + 1;
        }

        // Check if prefixSum seen before
        int found = -1;
        for(int j = 0; j < size; j++) {
            if(sum[j] == prefixSum) {
                found = j;
                break;
            }
        }

        if(found != -1) {
            int len = i - index[found];
            if(len > maxLen)
                maxLen = len;
        } else {
            sum[size] = prefixSum;
            index[size] = i;
            size++;
        }
    }

    printf("%d\n", maxLen);

    return 0;
}