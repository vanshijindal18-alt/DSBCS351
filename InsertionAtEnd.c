#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL;
    struct Node *newNode, *temp;

    // Create a new node
    newNode = (struct Node *)malloc(sizeof(struct Node));

    // Store data
    newNode->data = 30;
    newNode->next = NULL;

    // If list is empty
    if (head == NULL) {
        head = newNode;
    }
    else {
        // Traverse to the last node
        temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        // Insert new node at the end
        temp->next = newNode;
    }

    // Display the linked list
    temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL");

    return 0;
}
