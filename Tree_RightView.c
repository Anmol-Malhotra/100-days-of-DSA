#include <stdio.h>
#include <stdlib.h>

// Define structure for a Binary Tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue structure for building tree from level-order input
struct Queue {
    struct Node** arr;
    int front, rear, size;
};

// Function to create a new node
struct Node* createNode(int value) {
    if (value == -1) return NULL;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Initialize queue
struct Queue* createQueue(int size) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->arr = (struct Node**)malloc(size * sizeof(struct Node*));
    q->front = q->rear = 0;
    q->size = size;
    return q;
}

// Enqueue
void enqueue(struct Queue* q, struct Node* node) {
    if (node != NULL) {
        q->arr[q->rear++] = node;
    }
}

// Dequeue
struct Node* dequeue(struct Queue* q) {
    if (q->front == q->rear) return NULL;
    return q->arr[q->front++];
}

// Build Binary Tree from level-order input
struct Node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;
    struct Node* root = createNode(arr[0]);
    struct Queue* q = createQueue(n);
    enqueue(q, root);

    int i = 1;
    while (i < n) {
        struct Node* current = dequeue(q);
        if (current != NULL) {
            // Left child
            current->left = createNode(arr[i++]);
            enqueue(q, current->left);

            if (i < n) {
                // Right child
                current->right = createNode(arr[i++]);
                enqueue(q, current->right);
            }
        }
    }
    return root;
}

// Function to print right view using level order traversal
void rightView(struct Node* root) {
    if (root == NULL) return;

    struct Queue* q = createQueue(1000);
    enqueue(q, root);

    while (q->front < q->rear) {
        int levelSize = q->rear - q->front;
        for (int i = 0; i < levelSize; i++) {
            struct Node* node = dequeue(q);

            // Print the last node of each level
            if (i == levelSize - 1) {
                printf("%d ", node->data);
            }

            if (node->left) enqueue(q, node->left);
            if (node->right) enqueue(q, node->right);
        }
    }
    printf("\n");
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, N);

    rightView(root);

    return 0;
}