#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    // Loop to create 10 nodes
    for (int i = 1; i <= 10; i++) {
        // 1. Allocate memory for a new node
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = i * 10; // Assign data (10, 20, 30... 100)
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode; // First node becomes the head
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next; // Find the last node
            }
            temp->next = newNode; // Attach the new node at the end
        }
    }

    // Print the linked list
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}