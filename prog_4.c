#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};


void insertEnd(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void insertAfter(struct Node* node, int value) {
    if (node == NULL) return;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    newNode->next = node->next;
    newNode->prev = node;

    if (node->next != NULL)
        node->next->prev = newNode;

    node->next = newNode;
}

void deleteNode(struct Node** head, struct Node* node) {
    if (*head == NULL || node == NULL) return;

    if (*head == node)
        *head = node->next;

    if (node->next != NULL)
        node->next->prev = node->prev;

    if (node->prev != NULL)
        node->prev->next = node->next;

    free(node);
}


void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main() {
    struct Node* head = NULL;

    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);

    printf("Original list:\n");
    display(head);

    
    insertAfter(head->next, 25);
    printf("After insertion:\n");
    display(head);

    
    deleteNode(&head, head->next);
    printf("After deletion:\n");
    display(head);

    return 0;
}
