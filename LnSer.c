#include<stdio.h>
int main() {
    int a[10],n,pos,i,val;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    printf("Enter the elements of the array: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter the value where you want to search element: ");
    scanf("%d",&val);
    pos=-1;
    for(i=0;i<n;i++) {
        if(a[i]==val) {
            pos=i+1;
            break;
        }
    }
    if(pos!=-1)
        printf("Element found at position: %d\n",pos);
    else
        printf("Element not found in the array.\n");
    return 0;
}
