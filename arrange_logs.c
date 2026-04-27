#include <stdio.h>

int main() {
    int p, q;
    int i = 0, j = 0, k = 0;

    scanf("%d", &p);
    int a[p];
    for (i = 0; i < p; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &q);
    int b[q];
    for (i = 0; i < q; i++) {
        scanf("%d", &b[i]);
    }

    int c[p + q];
    i = 0;
    j = 0;

    while (i < p && j < q) {
        if (a[i] <= b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }

    while (i < p) {
        c[k++] = a[i++];
    }

    while (j < q) {
        c[k++] = b[j++];
    }

    for (i = 0; i < p + q; i++) {
        printf("%d ", c[i]);
    }

    return 0;
}