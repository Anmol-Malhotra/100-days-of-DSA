#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* deleteFirstOccurrence(Node* head, int key) {
    if (head != NULL && head->data == key) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    
    Node* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->next->data == key) {
            Node* nodeToDelete = current->next;
            current->next = nodeToDelete->next;
            free(nodeToDelete);
            return head;
        }
        current = current->next;
    }
    
    return head;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) printf(" ");
        current = current->next;
    }
    printf("\n");
}

void freeList(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n, key;
    scanf("%d", &n);
    
    Node* head = NULL;
    Node* tail = NULL;
    
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        Node* newNode = createNode(data);
        
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    scanf("%d", &key);
    head = deleteFirstOccurrence(head, key);
    printList(head);
    freeList(head);
    
    return 0;
}