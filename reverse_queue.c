#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// -------- Queue Implementation --------
int queue[MAX];
int front = -1, rear = -1;

// Enqueue
void enqueue(int value) {
    if (rear == MAX - 1) return;

    if (front == -1) front = 0;
    queue[++rear] = value;
}

// Dequeue
int dequeue() {
    if (front == -1 || front > rear)
        return -1;

    return queue[front++];
}

// -------- Stack Implementation --------
int stack[MAX];
int top = -1;

// Push
void push(int value) {
    if (top == MAX - 1) return;
    stack[++top] = value;
}

// Pop
int pop() {
    if (top == -1) return -1;
    return stack[top--];
}

// -------- Main Logic --------
int main() {
    int N;
    scanf("%d", &N);

    int x;

    // Input queue
    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    // Step 1: Dequeue all elements and push to stack
    while (front != -1 && front <= rear) {
        push(dequeue());
    }

    // Reset queue
    front = rear = -1;

    // Step 2: Pop from stack and enqueue back
    while (top != -1) {
        enqueue(pop());
    }

    // Print reversed queue
    while (front != -1 && front <= rear) {
        printf("%d ", dequeue());
    }

    return 0;
}