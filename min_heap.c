#include <stdio.h>
#include <string.h>

#define MAX 100

int heap[MAX];
int size = 0;

/* Swap function */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Heapify Up (after insertion) */
void heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;

        if (heap[parent] <= heap[index])
            break;

        swap(&heap[parent], &heap[index]);
        index = parent;
    }
}

/* Heapify Down (after deletion) */
void heapifyDown(int index) {
    while (1) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;

        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == index)
            break;

        swap(&heap[index], &heap[smallest]);
        index = smallest;
    }
}

/* Insert element */
void insert(int x) {
    if (size == MAX)
        return;

    heap[size] = x;
    heapifyUp(size);
    size++;
}

/* Peek minimum */
int peek() {
    if (size == 0)
        return -1;
    return heap[0];
}

/* Extract minimum */
int extractMin() {
    if (size == 0)
        return -1;

    int min = heap[0];
    heap[0] = heap[size - 1];
    size--;

    heapifyDown(0);

    return min;
}

int main() {
    int N, x;
    char op[20];

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            scanf("%d", &x);
            insert(x);
        }
        else if (strcmp(op, "peek") == 0) {
            printf("%d\n", peek());
        }
        else if (strcmp(op, "extractMin") == 0) {
            printf("%d\n", extractMin());
        }
    }

    return 0;
}