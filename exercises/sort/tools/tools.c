#include<stdio.h>
#include "tools.h"

void show_arr(int* arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int * reverse(int *arr, int size)
{
    int *reversed = (int*)calloc(size,sizeof(int));
    memmove(reversed, arr, 2*size*sizeof(int)); 

    for(int i = 0; i<size/2; ++i)
    {
        int tmp = reversed[size-1-i];
        reversed[size-1-i] = reversed[i];
        reversed[i] = tmp;
    }

    return reversed;
}

int *random_generate(int size)
{
    srand((unsigned) time(NULL));

    int *arr = (int*)calloc(size,sizeof(int));

    for (int i = 0; i < size; i ++)
    {
        arr[i] = rand() % RANGE + 1;
    }

    return arr;
}

int *bubble_sort(int *arr, int size, bool reversed)
{
    int *sorted = (int*)calloc(size,sizeof(int));
    memmove(sorted, arr, size*sizeof(int));

    for(int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size - i ; ++j)
        {
            if (sorted[j]<sorted[j+1])
            {
                int tmp = sorted[j+1];
                sorted[j+1] = sorted[j];
                sorted[j] = tmp;
            }
        }
    }

    if (reversed)
    {
        return reverse(sorted,size);
    }
    else
    {
        return sorted;
    }
}

int * shell_sort(int *arr, int size, bool reversed)
{
    
}