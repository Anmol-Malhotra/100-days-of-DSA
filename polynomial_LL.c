#include <stdio.h>
#include <stdlib.h>

// Structure for Polynomial Node
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to print polynomial
void printPolynomial(struct Node* head) {
    struct Node* temp = head;

    while (temp != NULL) {
        if (temp->exp == 0) {
            printf("%d", temp->coeff);
        }
        else if (temp->exp == 1) {
            printf("%dx", temp->coeff);
        }
        else {
            printf("%dx^%d", temp->coeff, temp->exp);
        }

        if (temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }
}

// Main Function
int main() {
    int n;
    scanf("%d", &n);

    struct Node *head = NULL, *tail = NULL;

    for (int i = 0; i < n; i++) {
        int coeff, exp;
        scanf("%d %d", &coeff, &exp);

        struct Node* newNode = createNode(coeff, exp);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    printPolynomial(head);

    return 0;
}