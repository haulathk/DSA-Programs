#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;

// Push Operation
void push(int item)
{
    if(top == MAX - 1)
    {
        printf("\nStack Overflow!\n");
    }
    else
    {
        top++;
        stack[top] = item;
        printf("%d inserted into the stack.\n", item);
    }
}

// Pop Operation
void pop()
{
    if(top == -1)
    {
        printf("\nStack Underflow!\n");
    }
    else
    {
        printf("%d deleted from the stack.\n", stack[top]);
        top--;
    }
}

// Display Operation
void display()
{
    int i;

    if(top == -1)
    {
        printf("\nStack is Empty.\n");
    }
    else
    {
        printf("\nStack Elements are:\n");
        for(i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

int main()
{
    int n, item, i, choice;

    // Initial insertion
    printf("Enter the number of elements to push initially: ");
    scanf("%d", &n);

    if(n > MAX)
    {
        printf("Only %d elements can be inserted.\n", MAX);
        return 0;
    }

    printf("Enter %d elements:\n", n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &item);
        push(item);
    }

    // Menu
    do
    {
        printf("\n----- STACK MENU -----\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &item);
                push(item);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Program Ended.\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 4);

    return 0;
}