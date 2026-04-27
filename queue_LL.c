#include <stdio.h>
#include <stdlib.h>

// Define Node structure
struct Node {
    int data;
    struct Node* next;
};

// Front and Rear pointers
struct Node *front = NULL, *rear = NULL;

// Enqueue operation
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

// Dequeue operation
int dequeue() {
    if (front == NULL) {
        return -1;  // Queue is empty
    }

    struct Node* temp = front;
    int value = temp->data;

    front = front->next;

    // If queue becomes empty
    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
    return value;
}

// Main function
int main() {
    int N;
    scanf("%d", &N);

    char operation[10];
    int value;

    for (int i = 0; i < N; i++) {
        scanf("%s", operation);

        if (operation[0] == 'e') { // enqueue
            scanf("%d", &value);
            enqueue(value);
        } else if (operation[0] == 'd') { // dequeue
            int result = dequeue();
            printf("%d\n", result);
        }
    }

    return 0;
}