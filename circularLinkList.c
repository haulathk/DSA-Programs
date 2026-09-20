#include <stdio.h>
#include <stdlib.h>

// Structure for a Circular Linked List Node
struct Node {
    int data;
    struct Node* next;
};

// Global head pointer initialized to NULL (stack variable)
struct Node* head = NULL;

// Function Prototypes
void insertAtBeginning(int value);
void deleteByValue(int value);
void displayList();

int main() {
    int choice, value;

    while (1) {
        printf("\n=== CIRCULAR LINKED LIST MENU ===\n");
        printf("1. Insert at Beginning\n");
        printf("2. Delete by Value\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteByValue(value);
                break;
            case 3:
                displayList();
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

// 1. INSERTION AT THE BEGINNING
void insertAtBeginning(int value) {
    // Allocate heap memory for new node
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;

    // Case A: List is empty
    if (head == NULL) {
        head = temp;
        temp->next = head; // Points back to itself
        printf("Inserted %d as the first node.\n", value);
        return;
    }

    // Case B: List has 1 or more nodes
    // Step 1: Traverse using stack pointer 'last' to find the final node
    struct Node* last = head;
    while (last->next != head) {
        last = last->next;
    }

    // Step 2: Rewire pointers
    temp->next = head; // New node points to current head
    last->next = temp; // Last node points to new node
    head = temp;       // head updates to point to new node

    printf("Inserted %d at the beginning.\n", value);
}

// 2. DELETION BY VALUE
void deleteByValue(int value) {
    // Case A: Empty list check
    if (head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    struct Node *current = head, *prev = NULL;

    // Case B: Deleting the head node
    if (head->data == value) {
        // Sub-case B1: Only 1 node in the list
        if (head->next == head) {
            printf("Deleted node with value %d. List is now empty.\n", head->data);
            free(head);
            head = NULL;
            return;
        }

        // Sub-case B2: Multiple nodes, finding the last node to rewire its next pointer
        struct Node* last = head;
        while (last->next != head) {
            last = last->next;
        }

        struct Node* temp = head;
        head = head->next;   // Move head forward
        last->next = head;   // Last node points to new head
        printf("Deleted head node with value %d.\n", temp->data);
        free(temp);          // Release memory
        return;
    }

    // Case C: Deleting middle or last node
    do {
        prev = current;
        current = current->next;
        if (current->data == value) {
            prev->next = current->next; // Bypass current node
            printf("Deleted node with value %d.\n", value);
            free(current);             // Free memory of target node
            return;
        }
    } while (current != head);

    // Case D: Value not found in list
    printf("Value %d not found in the list!\n", value);
}

// 3. DISPLAY CIRCULAR LINKED LIST
void displayList() {
    if (head == NULL) {
        printf("List is empty: NULL\n");
        return;
    }

    struct Node* temp = head;
    printf("\nList contents: ");
    do {
        printf("[Data: %d | Addr: %p | Next: %p] ---> ", temp->data, (void*)temp, (void*)temp->next);
        temp = temp->next;
    } while (temp != head);
    printf("(HEAD: %p)\n", (void*)head);
}