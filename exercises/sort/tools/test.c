#include<stdio.h>
#include "tools.h"

int main(void)
{
    int size = 30;
    int *arr = random_generate(size);


    printf("Tests begin\n");
    /* Test for show_arr, reverse */
    printf("Original array is: ");
    show_arr(arr,size);
    // printf("Reverse array is: ");
    // show_arr(reverse(arr,size),size);

    /* Test for bubble_sort */
    printf("Sorted with bubble: ");
    show_arr(bubble_sort(arr,size,0),size);
    printf("Reversed sorted with bubble: ");
    show_arr(bubble_sort(arr,size,1),size);

    /*Test for shell_sort */

    return 0;
}