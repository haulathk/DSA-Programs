#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push(int item)
{
    if(top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        stack[top] = item;
    }
}
2
void display()
{
    int i;

    if(top == -1)
    {
        printf("Stack is Empty\n");
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
    int n, item, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if(n > MAX)
    {
        printf("Stack can hold only %d elements.\n", MAX);
        return 0;
    }

    printf("Enter %d elements:\n", n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &item);
        push(item);
    }

    display();

    return 0;
}