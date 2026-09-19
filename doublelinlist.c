#include <stdio.h>
#include <stdlib.h>

// 1. Define the Doubly Linked List Node
struct Node {
    int data;
    struct Node* prev; // Points to the previous node
    struct Node* next; // Points to the next node
};

int main() {
    struct Node *head = NULL;
    struct Node *current = NULL;
    struct Node *temp = NULL;

    int totalNodes, value;

    printf("How many nodes do you want to enter? ");
    scanf("%d", &totalNodes);

    for (int i = 0; i < totalNodes; i++) {
        // Allocate memory for a new doubly linked list node
        temp = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);

        // Assign data and initialize both pointers
        temp->data = value;
        temp->prev = NULL;
        temp->next = NULL;

        if (head == NULL) {
            // First Node: head and current both point to temp
            head = temp;
            current = temp;
        } else {
            // Linking in Both Directions:
            current->next = temp; // 1. Forward link: previous node's next points to new node
            temp->prev = current; // 2. Backward link: new node's prev points to previous node
            current = temp;       // 3. Move current forward
        }
    }

    // 2. Display Forward
    printf("\nForward Traversal:  NULL <-> ");
    struct Node *walker = head;
    struct Node *lastNode = NULL;

    while (walker != NULL) {
        printf("%d <-> ", walker->data);
        lastNode = walker; // Save the reference to the last node
        walker = walker->next;
    }
    printf("NULL\n");

    // 3. Display Backward (Demonstrates the power of doubly linked lists!)
    printf("Backward Traversal: NULL <-> ");
    walker = lastNode; // Start from the tail

    while (walker != NULL) {
        printf("%d <-> ", walker->data);
        walker = walker->prev; // Walk backwards using 'prev'
    }
    printf("NULL\n");

    return 0;
}