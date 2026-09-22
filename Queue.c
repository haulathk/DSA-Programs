#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum capacity of the queue

int queue[MAX];
int front = -1;
int rear = -1;

// Function Prototypes
void enqueue(int value);
void dequeue();
void display();

int main() {
    int choice, value;

    while (1) {
        printf("\n=== LINEAR QUEUE MENU ===\n");
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
    // Check for Queue Overflow
    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot add %d.\n", value);
        return;
    }

    // If queue is empty, set front to 0
    if (front == -1) {
        front = 0;
    }

    rear++;
    queue[rear] = value;
    printf("Successfully added %d to the queue.\n", value);
}

// 2. DELETE / DEQUEUE OPERATION
void dequeue() {
    // Check for Queue Underflow
    if (front == -1 || front > rear) {
        printf("Queue Underflow! No elements to delete.\n");
        return;
    }

    printf("Successfully deleted %d from the queue.\n", queue[front]);
    front++;

    // Reset indices if the queue becomes completely empty after deletion
    if (front > rear) {
        front = -1;
        rear = -1;
    }
}

// 3. DISPLAY OPERATION
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
        return;
    }

    printf("\nCurrent Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
    printf("[front = %d, rear = %d]\n", front, rear);
}