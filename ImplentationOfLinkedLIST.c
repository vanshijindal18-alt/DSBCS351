
#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node *next;
};

// Insert a node at the beginning
void insertAtBeginning(struct Node **head, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Insert a node at the end
void insertAtEnd(struct Node **head, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Delete a node by value
void deleteNode(struct Node **head, int data) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = *head;
    struct Node *prev = NULL;

    // If the first node contains the value
    if (temp->data == data) {
        *head = temp->next;
        free(temp);
        printf("%d deleted.\n", data);
        return;
    }

    // Search for the node
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("%d not found.\n", data);
        return;
    }

    prev->next = temp->next;
    free(temp);

    printf("%d deleted.\n", data);
}

// Display the linked list
void display(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;

    printf("Linked List: ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Search for an element
void search(struct Node *head, int data) {
    struct Node *temp = head;
    int position = 1;

    while (temp != NULL) {
        if (temp->data == data) {
            printf("%d found at position %d.\n", data, position);
            return;
        }

        temp = temp->next;
        position++;
    }

    printf("%d not found.\n", data);
}

// Main function
int main() {
    struct Node *head = NULL;

    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);

    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);

    display(head);

    search(head, 40);

    deleteNode(&head, 30);

    display(head);

    return 0;
}

