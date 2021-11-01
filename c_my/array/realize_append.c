#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

// array pointer
// typedef void(*)(aptr,int) Opt;
typedef struct Arr{
    int len;
    int* arr;
    struct Arr *self;
    void* opt(*Arr, int);
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

// class aptr
void append(aptr arrs, int ele){
    aptr new = (aptr)malloc(sizeof(aptr));
    new->len = arrs->len+1;
    new->arr = (int*)malloc(new->len*sizeof(int));
    memcpy(new->arr, arrs->arr, arrs->len*sizeof(int));
    *(new->arr+arrs->len) = ele;
    // REMEMBER that you cannot rewrite the adress, but you can change the reference !
    *arrs = *new;
}


int main(void){
    aptr arrs = genaptr(15);
    printa(arrs);
    append(arrs, 9);
    printa(arrs);
    arrs->opt = append;
    arrs->opt(arrs,99);
    printa(arrs);
    return 0;
}