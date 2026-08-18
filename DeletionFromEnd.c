#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL;
    struct Node *temp, *prev;

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

    // Deletion from end
    if (head == NULL) {
        printf("List is empty\n");
    }
    else if (head->next == NULL) {
        // Only one node
        free(head);
        head = NULL;
    }
    else {
        temp = head;

        // Move to the last node
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }

        // Remove the last node
        prev->next = NULL;
        free(temp);
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
