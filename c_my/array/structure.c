#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// array pointer
typedef struct Arr{
    int len;
    int* arr;
}*aptr;

// tools for array
void printa(aptr arrs){
    int len = arrs->len;
    int* arr = arrs->arr;
    printf("Array of size: %d, and elements:\n",len);
    for (int i=0; i<len; i++){
        printf("%d ",*(arr+i));
    }
    printf("\n");
}

void swap(aptr arrs, int i, int j){
    int len = arrs->len;
    int* arr = arrs->arr;
    if (i>=len | j>=len){
        printf("Wrong index range.");
        exit(0);
    }
    int tmp;
    tmp = *(arr+i);
    *(arr+i) = *(arr+j);
    *(arr+j) = tmp;
}

aptr genaptr(int size){
    // generate a ordered array from 0 to size (size+1)
    // IMPORTANT to allocate memory space at the very begining!
    aptr arrs = (aptr)malloc(sizeof(aptr));
    arrs->len = size+1;
    arrs->arr = (int*)malloc((arrs->len)*sizeof(int));
    for (int i=0; i<arrs->len; i++){
        *(arrs->arr+i) = i;
    }
    // random shuffle
    srand((unsigned)time(NULL));
    for (int i=0; i<size*size+1; i++){
        while(rand()/32767.0 > 0.50){
            swap(arrs, rand()%(arrs->len), rand()%(arrs->len));
        }
    }
    return arrs;
}