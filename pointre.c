#include <stdio.h>

int main() {
    int age = 20;        // 1. Normal integer variable
    int a=10;
    int b=20;
    int c;
    int *ptr1=&a;
    int *ptr2=&b;
    int *ptr3=&c;
    int *ptr; 

             
c=*ptr1 + *ptr2; // 2. Using pointers to add values of a and b
    ptr = &age;          

    printf("Value of age: %d\n", age);
    printf("Address of age (&age): %p\n", (void*)&age);
    printf("Value stored in ptr: %p\n", (void*)ptr);
    printf("Value pointed to by ptr (*ptr): %d\n", *ptr);
    printf("Value of c: %d\n", c);

    return 0;
}