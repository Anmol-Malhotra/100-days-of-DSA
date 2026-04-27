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
struct Node* buildTree(int inorder[], int postorder[], int start, int end, int* postIndex) {
    if (start > end) return NULL;

    // Create root from postorder (last element)
    struct Node* root = createNode(postorder[*postIndex]);
    (*postIndex)--;

    // If leaf node
    if (start == end) return root;

    // Find root in inorder
    int inIndex = search(inorder, start, end, root->data);

    // Build right subtree first (because postorder is left-right-root)
    root->right = buildTree(inorder, postorder, inIndex + 1, end, postIndex);
    root->left = buildTree(inorder, postorder, start, inIndex - 1, postIndex);

    return root;
}

// Preorder traversal
void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int N;
    scanf("%d", &N);

    int inorder[N], postorder[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &inorder[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &postorder[i]);
    }

    int postIndex = N - 1;
    struct Node* root = buildTree(inorder, postorder, 0, N - 1, &postIndex);

    // Print preorder traversal
    preorder(root);
    printf("\n");

    return 0;
}