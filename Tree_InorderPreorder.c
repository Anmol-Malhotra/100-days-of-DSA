#include <stdio.h>
#include <stdlib.h>

// Define structure for a Binary Tree node
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

// Search for index of value in inorder array
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value) return i;
    }
    return -1;
}

// Recursive function to build tree
struct Node* buildTree(int preorder[], int inorder[], int start, int end, int* preIndex) {
    if (start > end) return NULL;

    // Create root from preorder
    struct Node* root = createNode(preorder[*preIndex]);
    (*preIndex)++;

    // If leaf node
    if (start == end) return root;

    // Find root in inorder
    int inIndex = search(inorder, start, end, root->data);

    // Build left and right subtrees
    root->left = buildTree(preorder, inorder, start, inIndex - 1, preIndex);
    root->right = buildTree(preorder, inorder, inIndex + 1, end, preIndex);

    return root;
}

// Postorder traversal
void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int N;
    scanf("%d", &N);

    int preorder[N], inorder[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &preorder[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &inorder[i]);
    }

    int preIndex = 0;
    struct Node* root = buildTree(preorder, inorder, 0, N - 1, &preIndex);

    // Print postorder traversal
    postorder(root);
    printf("\n");

    return 0;
}