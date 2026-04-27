#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void removeCycle(struct Node* head) {
    if (head == NULL || head->next == NULL) return;
    
    struct Node *slow = head, *fast = head;
    int cycleFound = 0;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            cycleFound = 1;
            break;
        }
    }
    
    if (!cycleFound) return;
    
    struct Node *ptr1 = head;
    struct Node *ptr2 = slow;
    
    while (ptr1 != ptr2) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    
    struct Node *lastNode = ptr2;
    while (lastNode->next != ptr2) {
        lastNode = lastNode->next;
    }
    
    lastNode->next = NULL;
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int hasCycle(struct Node* head) {
    struct Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return 1;
    }
    return 0;
}

int main() {
    struct Node *head = createNode(1);
    struct Node *node3 = createNode(3);
    struct Node *node4 = createNode(4);
    
    head->next = node3;
    node3->next = node4;
    node4->next = node3;
    
    printf("Before: Cycle %s\n", hasCycle(head) ? "exists" : "doesn't exist");
    removeCycle(head);
    printf("After: Cycle %s\n", hasCycle(head) ? "exists" : "doesn't exist");
    
    return 0;
}