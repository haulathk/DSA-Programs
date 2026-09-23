#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Capacity of the circular queue

int cqueue[MAX];
int front = -1;
int rear = -1;

// Function Prototypes
void enqueue(int value);
void dequeue();
void display();

int main() {
    int choice, value;

    while (1) {
        printf("\n=== CIRCULAR QUEUE MENU ===\n");
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
    // Condition for Circular Queue Overflow: Next rear hits front
    if ((rear + 1) % MAX == front) {
        printf("Circular Queue Overflow! Cannot add %d.\n", value);
        return;
    }

    // Case A: First element insertion
    if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
    } 
    // Case B: Normal or Wrap-around insertion
    else {
        rear = (rear + 1) % MAX;
    }

    cqueue[rear] = value;
    printf("Successfully added %d at index %d.\n", value, rear);
}

// 2. DELETE / DEQUEUE OPERATION
void dequeue() {
    // Condition for Circular Queue Underflow
    if (front == -1) {
        printf("Circular Queue Underflow! No elements to delete.\n");
        return;
    }

    printf("Successfully deleted %d from index %d.\n", cqueue[front], front);

    // Case A: Queue has only one element left
    if (front == rear) {
        front = -1;
        rear = -1; // Reset back to empty state
    } 
    // Case B: Normal or Wrap-around deletion
    else {
        front = (front + 1) % MAX;
    }
}

// 3. DISPLAY OPERATION
void display() {
    if (front == -1) {
        printf("Circular Queue is empty!\n");
        return;
    }

    printf("\nQueue Elements: ");
    int i = front;
    while (1) {
        printf("%d ", cqueue[i]);
        if (i == rear) break; // Reached the end of queue
        i = (i + 1) % MAX;    // Wrap around index
    }
    printf("\n[front = %d, rear = %d]\n", front, rear);
}