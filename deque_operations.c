#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

int dq[MAX];
int front = -1;
int rear = -1;

/* Check empty */
bool empty() {
    return (front == -1);
}

/* Size of deque */
int size() {
    if (empty()) return 0;
    return rear - front + 1;
}

/* Push front */
void push_front(int x) {
    if (front == -1) {
        front = rear = 0;
        dq[front] = x;
    } else if (front > 0) {
        dq[--front] = x;
    } else {
        printf("Deque overflow\n");
    }
}

/* Push back */
void push_back(int x) {
    if (rear == MAX - 1) {
        printf("Deque overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    dq[++rear] = x;
}

/* Pop front */
void pop_front() {
    if (empty()) {
        printf("Deque underflow\n");
        return;
    }
    front++;
    if (front > rear)
        front = rear = -1;
}

/* Pop back */
void pop_back() {
    if (empty()) {
        printf("Deque underflow\n");
        return;
    }
    rear--;
    if (rear < front)
        front = rear = -1;
}

/* Front element */
int get_front() {
    if (empty()) return -1;
    return dq[front];
}

/* Rear element */
int get_back() {
    if (empty()) return -1;
    return dq[rear];
}

/* Clear deque */
void clear() {
    front = rear = -1;
}

/* Reverse deque */
void reverse() {
    if (empty()) return;

    int i = front, j = rear;
    while (i < j) {
        int temp = dq[i];
        dq[i] = dq[j];
        dq[j] = temp;
        i++;
        j--;
    }
}

/* Sort deque (ascending) */
void sortDeque() {
    for (int i = front; i <= rear; i++) {
        for (int j = i + 1; j <= rear; j++) {
            if (dq[i] > dq[j]) {
                int temp = dq[i];
                dq[i] = dq[j];
                dq[j] = temp;
            }
        }
    }
}

/* Display deque */
void display() {
    if (empty()) {
        printf("Deque is empty\n");
        return;
    }

    for (int i = front; i <= rear; i++)
        printf("%d ", dq[i]);
    printf("\n");
}

int main() {
    push_back(10);
    push_back(20);
    push_front(5);
    push_back(30);

    printf("Deque: ");
    display();

    printf("Front: %d\n", get_front());
    printf("Back: %d\n", get_back());
    printf("Size: %d\n", size());

    pop_front();
    pop_back();

    printf("After pops: ");
    display();

    reverse();
    printf("After reverse: ");
    display();

    sortDeque();
    printf("After sort: ");
    display();

    clear();
    printf("Empty: %d\n", empty());

    return 0;
}