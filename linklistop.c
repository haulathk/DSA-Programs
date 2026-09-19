#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Global head pointer
struct Node* head = NULL;

// Function prototypes
void insertAtBeginning(int value);
void insertAtEnd(int value);
void insertAtPosition(int value, int position);
void deleteFromBeginning();
void deleteFromEnd();
void deleteByValue(int value);
void search(int value);
void countNodes();
void display();

int main() {
    int choice, value, position;

    while (1) {
        printf("\n========== LINKED LIST OPERATIONS MENU ==========\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Specific Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete by Value\n");
        printf("7. Search Element\n");
        printf("8. Count Total Nodes\n");
        printf("9. Display List\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position (starting from 1): ");
                scanf("%d", &position);
                insertAtPosition(value, position);
                break;
            case 4:
                deleteFromBeginning();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteByValue(value);
                break;
            case 7:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;
            case 8:
                countNodes();
                break;
            case 9:
                display();
                break;
            case 10:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// 1. Insert at Beginning
void insertAtBeginning(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head; // Point new node to current head
    head = newNode;       // Move head to point to new node
    printf("Inserted %d at the beginning.\n", value);
}

// 2. Insert at End
void insertAtEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next; // Traverse to the last node
        }
        temp->next = newNode; // Link last node to new node
    }
    printf("Inserted %d at the end.\n", value);
}

// 3. Insert at Specific Position
void insertAtPosition(int value, int position) {
    if (position == 1) {
        insertAtBeginning(value);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds!\n");
        free(newNode);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Inserted %d at position %d.\n", value, position);
    }
}

// 4. Delete from Beginning
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }
    struct Node* temp = head;
    head = head->next; // Move head to next node
    printf("Deleted %d from beginning.\n", temp->data);
    free(temp); // Free memory of deleted node
}

// 5. Delete from End
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }
    if (head->next == NULL) { // Only one node in list
        printf("Deleted %d from end.\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    struct Node* temp = head;
    while (temp->next->next != NULL) { // Stop at second-to-last node
        temp = temp->next;
    }
    printf("Deleted %d from end.\n", temp->next->data);
    free(temp->next);   // Free last node
    temp->next = NULL;  // Set second-to-last node's next to NULL
}

// 6. Delete by Value
void deleteByValue(int value) {
    if (head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    if (head->data == value) {
        deleteFromBeginning();
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Value %d not found in the list!\n", value);
    } else {
        struct Node* target = temp->next;
        temp->next = target->next; // Bypass the node to delete
        printf("Deleted node with value %d.\n", value);
        free(target);
    }
}

// 7. Search for a Value
void search(int value) {
    struct Node* temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (temp->data == value) {
            printf("Value %d found at position %d.\n", value, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Value %d not found in list.\n", value);
}

// 8. Count Total Nodes
void countNodes() {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Total number of nodes: %d\n", count);
}

// 9. Display List
void display() {
    if (head == NULL) {
        printf("List is empty: NULL\n");
        return;
    }
    struct Node* temp = head;
    printf("List contents: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}