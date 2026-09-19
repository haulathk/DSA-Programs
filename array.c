#include <stdio.h>

int main() {
    
    int a[10],b[10],c[10];
    int n1, n2, i;
    printf("Enter the number of elements in the first array: ");
    scanf("%d", &n1);
    printf("Enter the elements of the first array: ");
    for (i = 0; i < n1; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the number of elements in the second array: ");
    scanf("%d", &n2);22
    printf("Enter the elements of the second array: ");
    for (i = 0; i < n2; i++) {
        scanf("%d", &b[i]);
    }
    for(i = 0; i < n1; i++) {
        c[i] = a[i];
    }
    for (i = 0; i < n2; i++) {
        c[n1 + i] = b[i];
    }
    printf("The merged array is: ");
    for (i = 0; i < n1 + n2; i++) {
        printf("%d ", c[i]);}

return 0;
    }

