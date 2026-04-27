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

// Function to check if two subtrees are mirror images
int isMirror(struct Node* t1, struct Node* t2) {
    if (t1 == NULL && t2 == NULL) return 1;
    if (t1 == NULL || t2 == NULL) return 0;
    return (t1->data == t2->data) &&
           isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}

// Function to check if tree is symmetric
int isSymmetric(struct Node* root) {
    if (root == NULL) return 1;
    return isMirror(root->left, root->right);
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, N);

    if (isSymmetric(root)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}