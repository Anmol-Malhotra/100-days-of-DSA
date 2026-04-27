#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push operation
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = value;
    }
}

// Pop operation
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        top--;
    }
}

int main() {
    int n, m, i, value;

    // number of elements to push
    scanf("%d", &n);

    // pushing elements
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        push(value);
    }

    // number of pops
    scanf("%d", &m);

    for (i = 0; i < m; i++) {
        pop();
    }

    // print remaining stack from top to bottom
    for (i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}