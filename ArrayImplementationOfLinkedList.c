
#include <stdio.h>

#define MAX 10

int data[MAX];
int next[MAX];

int head = -1;
int freeIndex = 0;

// Insert a node at the beginning
void insertAtBeginning(int value) {
    if (freeIndex >= MAX) {
        printf("List is full!\n");
        return;
    }

    data[freeIndex] = value;
    next[freeIndex] = head;

    head = freeIndex;
    freeIndex++;
}

// Insert a node at the end
void insertAtEnd(int value) {
    if (freeIndex >= MAX) {
        printf("List is full!\n");
        return;
    }

    data[freeIndex] = value;
    next[freeIndex] = -1;

    if (head == -1) {
        head = freeIndex;
    } else {
        int temp = head;

        while (next[temp] != -1) {
            temp = next[temp];
        }

        next[temp] = freeIndex;
    }

    freeIndex++;
}

// Delete a node by value
void deleteNode(int value) {
    if (head == -1) {
        printf("List is empty!\n");
        return;
    }

    int current = head;
    int previous = -1;

    while (current != -1 && data[current] != value) {
        previous = current;
        current = next[current];
    }

    if (current == -1) {
        printf("%d not found!\n", value);
        return;
    }

    // If deleting the first node
    if (previous == -1) {
        head = next[current];
    } else {
        next[previous] = next[current];
    }

    printf("%d deleted successfully.\n", value);
}

// Display the linked list
void display() {
    if (head == -1) {
        printf("List is empty!\n");
        return;
    }

    int temp = head;

    printf("Linked List: ");

    while (temp != -1) {
        printf("%d -> ", data[temp]);
        temp = next[temp];
    }

    printf("NULL\n");
}

// Search for an element
void search(int value) {
    int temp = head;
    int position = 1;

    while (temp != -1) {
        if (data[temp] == value) {
            printf("%d found at position %d.\n", value, position);
            return;
        }

        temp = next[temp];
        position++;
    }

    printf("%d not found.\n", value);
}

int main() {

    insertAtBeginning(10);
    insertAtBeginning(20);
    insertAtBeginning(30);

    insertAtEnd(40);
    insertAtEnd(50);

    display();

    search(40);

    deleteNode(30);

    display();

    return 0;
}

