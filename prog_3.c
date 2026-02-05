#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Insert at end
void insert(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Normal traversal
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Reverse traversal using recursion
void reverseTraversal(Node* head) {
    if (head == NULL)
        return;

    reverseTraversal(head->next);
    printf("%d -> ", head->data);
}

// Main function
int main() {
    Node* head = NULL;

    // Insert elements
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);

    printf("Normal Traversal:\n");
    display(head);

    printf("\nReverse Traversal:\n");
    reverseTraversal(head);
    printf("NULL\n");

    return 0;
}
