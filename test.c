#include<stdio.h>
int main() {
    int a[10],i,j,min,temp,n;
    printf("Enter  the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {

        scanf("%d", &a[i]);
    }
    for(i=0;i<n-1;i++){
    min = i;
    for (j = i+1; j < n; j++) {
        if (a[j] < a[min]) {
            min = j;
        }
    }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}