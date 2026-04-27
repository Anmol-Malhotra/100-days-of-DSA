#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

// Structure to store nodes with horizontal distance
struct List {
    int data;
    struct List* next;
};

struct Map {
    int hd;
    struct List* nodes;
    struct Map* next;
};

// Add node to map
void addToMap(struct Map** head, int hd, int data) {
    struct Map* temp = *head;
    while (temp != NULL) {
        if (temp->hd == hd) {
            struct List* newNode = (struct List*)malloc(sizeof(struct List));
            newNode->data = data;
            newNode->next = NULL;
            struct List* curr = temp->nodes;
            while (curr->next != NULL) curr = curr->next;
            curr->next = newNode;
            return;
        }
        temp = temp->next;
    }
    // If hd not found, create new entry
    struct Map* newMap = (struct Map*)malloc(sizeof(struct Map));
    newMap->hd = hd;
    newMap->nodes = (struct List*)malloc(sizeof(struct List));
    newMap->nodes->data = data;
    newMap->nodes->next = NULL;
    newMap->next = *head;
    *head = newMap;
}

// DFS traversal to fill map
void verticalTraversal(struct Node* root, int hd, struct Map** head) {
    if (root == NULL) return;
    addToMap(head, hd, root->data);
    verticalTraversal(root->left, hd - 1, head);
    verticalTraversal(root->right, hd + 1, head);
}

// Print vertical order
void printVerticalOrder(struct Map* head) {
    // Find min and max hd
    int minHd = INT_MAX, maxHd = INT_MIN;
    struct Map* temp = head;
    while (temp != NULL) {
        if (temp->hd < minHd) minHd = temp->hd;
        if (temp->hd > maxHd) maxHd = temp->hd;
        temp = temp->next;
    }

    for (int hd = minHd; hd <= maxHd; hd++) {
        temp = head;
        while (temp != NULL) {
            if (temp->hd == hd) {
                struct List* curr = temp->nodes;
                while (curr != NULL) {
                    printf("%d ", curr->data);
                    curr = curr->next;
                }
                printf("\n");
                break;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, N);

    struct Map* head = NULL;
    verticalTraversal(root, 0, &head);

    printVerticalOrder(head);
    return 0;
}
   