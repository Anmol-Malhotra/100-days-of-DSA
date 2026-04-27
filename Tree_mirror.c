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

// Function to convert tree into its mirror
void mirrorTree(struct Node* root) {
    if (root == NULL) return;

    // Swap left and right children
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recurse for children
    mirrorTree(root->left);
    mirrorTree(root->right);
}

// Inorder traversal
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, N);

    // Convert to mirror
    mirrorTree(root);

    // Print inorder traversal of mirrored tree
    inorder(root);
    printf("\n");

    return 0;
}