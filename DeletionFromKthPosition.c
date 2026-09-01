#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* deleteKth(struct Node *head, int k) {
    struct Node *temp, *del;

    // Empty list
    if (head == NULL)
        return head;

    // Delete first node
    if (k == 1) {
        temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    temp = head;

    // Move to (k-1)th node
    for (int i = 1; i < k - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // K is out of range
    if (temp == NULL || temp->next == NULL)
        return head;

    // Delete kth node
    del = temp->next;
    temp->next = del->next;
    free(del);

    return head;
}
