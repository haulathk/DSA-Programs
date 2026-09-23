#include <stdio.h>
#include <stdlib.h>

// Structure for Queue Node
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
        printf("\n=== QUEUE USING LINKED LIST MENU ===\n");
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
    
    // Check if heap memory allocation failed
    if (temp == NULL) {
        printf("Heap Overflow! Cannot allocate memory.\n");
        return;
    }

    temp->data = value;
    temp->next = NULL;

    // Case A: Queue is empty
    if (front == NULL && rear == NULL) {
        front = temp;
        rear = temp;
        printf("Successfully added %d to the queue.\n", value);
        return;
    }

    // Case B: Queue already has nodes
    rear->next = temp; // Link old rear node to new node
    rear = temp;       // Move rear pointer to new node
    printf("Successfully added %d to the queue.\n", value);
}

// 2. DELETE / DEQUEUE OPERATION
void dequeue() {
    // Case A: Queue Underflow (Empty Queue)
    if (front == NULL) {
        printf("Queue Underflow! No elements to delete.\n");
        return;
    }

    // Temporary pointer to hold current front node address
    struct Node* temp = front;
    printf("Successfully deleted %d from the queue.\n", temp->data);

    // Move front pointer forward to next node
    front = front->next;

    // Case B: If queue becomes empty after deletion, reset rear to NULL
    if (front == NULL) {
        rear = NULL;
    }

    // Free memory of deleted node
    free(temp);
}

// 3. DISPLAY OPERATION
void display() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    struct Node* temp = front;
    printf("\nCurrent Queue elements: ");
    while (temp != NULL) {
        printf("[Data: %d | Addr: %p | Next: %p] ---> ", temp->data, (void*)temp, (void*)temp->next);
        temp = temp->next;
    }
    printf("NULL\n");
    printf("[front = %p, rear = %p]\n", (void*)front, (void*)rear);
}