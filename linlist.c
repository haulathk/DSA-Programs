#include <stdio.h>
#include <stdlib.h> // Needed for malloc() and free()

// 1. Define what a Node looks like
struct Node {
    int data;          // Holds the integer value
    struct Node* next; // Holds the address of the next node
};

int main() {
    struct Node *head = NULL; // Start with an empty list
    struct Node *temp = NULL; // Temporary pointer to build new nodes
    struct Node *current = NULL; // Used to walk through the list
    
    int totalNodes, value;

    // 2. Ask the user how many numbers they want to store
    printf("How many numbers do you want to enter? ");
    scanf("%d", &totalNodes);

    for (int i = 0; i < totalNodes; i++) {
        // Allocate memory for one node dynamically
        temp = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);

        temp->data = value; // Store the number
        temp->next = NULL;  // Set next to NULL since it's the last node for now

        // If it's the first node, make it the 'head'
        if (head == NULL) {
            head = temp;
            current = temp;
        } else {
            // Attach the new node to the end of the existing list
            current->next = temp; // Connect previous node to new node
            current = temp;       // Move 'current' pointer to the new node
        }
    }

    // 3. Display the linked list
    printf("\nYour Linked List: ");
    current = head; // Start back at the beginning

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next; // Move to the next node
    }
    printf("NULL\n");

    return 0;
}