#include <stdio.h>
#include <stdlib.h>

// Structure for Circular Queue Node
struct Node {
    int data;
    struct Node* next;
};

// Global front and rear pointers (Stack variables)
struct Node* front = NULL;
struct Node* rear = NULL;

// Function Prototypes
void enqueue(int value);
void dequeue();
void display();

int main() {
    int choice, value;

    while (1) {
        printf("\n=== CIRCULAR QUEUE (LINKED LIST) MENU ===\n");
        printf("1. Add (Enqueue)\n");
        printf("2. Delete (Dequeue)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to add: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// 1. ADD / ENQUEUE OPERATION
void enqueue(int value) {
    // Allocate heap memory for new node
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    
    // Check Heap Overflow
    if (temp == NULL) {
        printf("Heap Overflow! Cannot allocate memory.\n");
        return;
    }

    temp->data = value;

    // Case A: First node insertion
    if (front == NULL && rear == NULL) {
        front = temp;
        rear = temp;
        temp->next = front; // Points back to itself!
        printf("Successfully added %d as the first node.\n", value);
        return;
    }

    // Case B: Subsequent node insertions
    rear->next = temp;   // Old rear points to new node
    rear = temp;         // Update rear to new node
    rear->next = front;  // Maintain circular link back to front

    printf("Successfully added %d.\n", value);
}

// 2. DELETE / DEQUEUE OPERATION
void dequeue() {
    // Case A: Empty Queue (Underflow)
    if (front == NULL && rear == NULL) {
        printf("Circular Queue Underflow! No elements to delete.\n");
        return;
    }

    struct Node* temp = front;

    // Case B: Queue has only ONE node left
    if (front == rear) {
        printf("Successfully deleted %d. Queue is now empty.\n", temp->data);
        front = NULL;
        rear = NULL;
        free(temp);
        return;
    }

    // Case C: Queue has multiple nodes
    printf("Successfully deleted %d.\n", temp->data);
    front = front->next; // Move front pointer to second node
    rear->next = front;  // Rewire last node's next pointer to new front

    free(temp);          // Release old front memory
}

// 3. DISPLAY OPERATION
void display() {
    if (front == NULL && rear == NULL) {
        printf("Circular Queue is empty!\n");
        return;
    }

    struct Node* temp = front;
    printf("\nCurrent Circular Queue elements:\n");
    do {
        printf("[Data: %d | Addr: %p | Next: %p] ---> ", temp->data, (void*)temp, (void*)temp->next);
        temp = temp->next;
    } while (temp != front);

    printf("(FRONT: %p)\n", (void*)front);
    printf("[front = %p, rear = %p]\n", (void*)front, (void*)rear);
}