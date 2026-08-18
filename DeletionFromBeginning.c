#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL;
    struct Node *temp;

    // Create first node
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = 10;

    // Create second node
    head->next = (struct Node *)malloc(sizeof(struct Node));
    head->next->data = 20;

    // Create third node
    head->next->next = (struct Node *)malloc(sizeof(struct Node));
    head->next->next->data = 30;
    head->next->next->next = NULL;

    // Display original list
    printf("Original list: ");
    temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    // Deletion from beginning
    if (head == NULL) {
        printf("List is empty\n");
    }
    else {
        temp = head;       // Store the first node
        head = head->next; // Move head to the second node
        free(temp);        // Delete the first node
    }

    // Display list after deletion
    printf("After deletion: ");
    temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}
