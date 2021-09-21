#include<stdio.h>

void main(void){
    /*int *ptr1 = 1;*/
    int *ptr1 = 0;
    int *ptr2;
    int n = 1;
    // int m = 1;
    // ptr1 = &m;
    ptr2 = &n;
    printf("pointer1's value: %d\npointer1's memory path: %p\n", *ptr1, ptr1);
    printf("pointer2's value: %d\npointer2's memory path: %p\n", *ptr2, ptr2);
    (*ptr1)++;
    *ptr2++;
    printf("After different ++\n");
    printf("pointer1's value: %d\npointer1's memory path: %p\n", *ptr2, ptr2);
    printf("pointer2's value: %d\npointer2's memory path: %p\n", *ptr2, ptr2);
    
    printf("ptr2-ptr1=%ld",ptr2-ptr1);

}