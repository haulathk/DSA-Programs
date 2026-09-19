#include<stdio.h>
int main() {
    int a[10],i,j,min;
    printf("Enter  the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for(i=0;i<n-2;i++)
    min = a[0];
    for (j = 1; j < n; j++) {
        if (a[j] < a[min]) {
            min = j;
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}