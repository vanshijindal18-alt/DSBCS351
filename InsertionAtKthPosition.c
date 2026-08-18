#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL;
    struct Node *newNode, *temp;
    int k, i;

    // Create the first node
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = 10;
    head->next = NULL;

    // Create second node
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = 20;
    temp->next = NULL;
    head->next = temp;

    // Create third node
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = 30;
    temp->next = NULL;
    head->next->next = temp;

    // Position where we want to insert
    printf("Enter position: ");
    scanf("%d", &k);

    // Create new node
    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &newNode->data);

    // Insertion at beginning
    if (k == 1) {
        newNode->next = head;
        head = newNode;
    }
    else {
        temp = head;

        // Move to (k-1)th node
        for (i = 1; i < k - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        // Check if position is valid
        if (temp == NULL) {
            printf("Invalid position\n");
            free(newNode);
            return 0;
        }

        // Insert new node
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Display the linked list
    printf("Linked list: ");

    temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");

    return 0;
}
