#include <stdio.h>
#include <stdlib.h>

// Define structure of Node
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, i, value;
    
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    // Read number of elements
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &value);

        // Allocate memory for new node
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        // If list is empty
        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } 
        else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Traverse and print the linked list
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}