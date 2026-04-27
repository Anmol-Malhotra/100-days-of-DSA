#include <stdio.h>
#include <stdlib.h>

// Define the structure for a BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function to find LCA of two nodes in BST
struct Node* findLCA(struct Node* root, int n1, int n2) {
    if (root == NULL) return NULL;

    // If both n1 and n2 are smaller than root, LCA lies in left subtree
    if (n1 < root->data && n2 < root->data) {
        return findLCA(root->left, n1, n2);
    }

    // If both n1 and n2 are greater than root, LCA lies in right subtree
    if (n1 > root->data && n2 > root->data) {
        return findLCA(root->right, n1, n2);
    }

    // Otherwise, root is the LCA
    return root;
}

int main() {
    struct Node* root = NULL;
    int N, value, n1, n2;

    // Input specifications
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }
    scanf("%d %d", &n1, &n2);

    // Find LCA
    struct Node* lca = findLCA(root, n1, n2);

    // Output specifications
    if (lca != NULL) {
        printf("%d\n", lca->data);
    } else {
        printf("LCA not found\n");
    }

    return 0;
}