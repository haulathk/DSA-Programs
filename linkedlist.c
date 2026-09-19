#include <stdio.h>
#include <stdlib.h>

// 1. Define the Node structure
struct Node {
    int data;               // Stores the value
    struct Node* next;      // Address of the next node
};

int main() {
    // 2. Allocate memory for 3 nodes using malloc
    struct Node* head  = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third  = (struct Node*)malloc(sizeof(struct Node));

    // 3. Assign data and connect the links
    
    // First node
    head->data = 10;
    head->next = second; // 10 points to second node

    // Second node
    second->data = 20;
    second->next = third; // 20 points to third node

    // Third node
    third->data = 30;
    third->next = NULL;   // End of the list

    // 4. Print the linked list
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next; // Move to the next node
    }
    printf("NULL\n");

    return 0;
}