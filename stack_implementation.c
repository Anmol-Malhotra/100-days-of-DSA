#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;
int n;   // size of stack

// Push operation
void push(int value) {
    if (top == n - 1) {
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
        printf("%d\n", stack[top]);
        top--;
    }
}

// Display operation
void display() {
    if (top == -1) {
        printf("Stack is Empty\n");
    } else {
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int operations;
    scanf("%d", &operations);

    n = MAX;  // You can change stack size if needed

    for (int i = 0; i < operations; i++) {
        int choice, value;
        scanf("%d", &choice);

        if (choice == 1) {
            scanf("%d", &value);
            push(value);
        } 
        else if (choice == 2) {
            pop();
        } 
        else if (choice == 3) {
            display();
        }
    }

    return 0;
}