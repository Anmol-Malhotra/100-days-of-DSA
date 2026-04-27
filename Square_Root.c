#include <stdio.h>

// Function to compute integer square root using Binary Search
int integerSqrt(int n) {
    if (n == 0 || n == 1) return n;

    int low = 0, high = n, ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if ((long long)mid * mid == n) {
            return mid; // exact square root
        }

        if ((long long)mid * mid < n) {
            ans = mid;   // store possible answer
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    int n;
    scanf("%d", &n);

    int result = integerSqrt(n);
    printf("%d\n", result);

    return 0;
}
