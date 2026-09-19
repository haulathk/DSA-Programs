#include<stdio.h>
int main() {
    int a[10],mid,lb,ub,i,n,search;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    printf("Enter the elements of the array in sorted order: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter the value to search: ");
    scanf("%d",&search);
    lb=0;
    ub=n-1;
    mid=(lb+ub)/2;
    while(lb<=ub) {
        if(a[mid]==search) {
            printf("Element found at position: %d\n",mid+1);
            break;
        }
        else if(a[mid]<search)
            lb=mid+1;
        else
            ub=mid-1; 
            mid=(lb+ub)/2;
    }
    if(lb>ub)
        printf("Element not found in the array.\n");
    return 0;
}