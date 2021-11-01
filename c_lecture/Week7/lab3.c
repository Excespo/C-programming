#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// typedef void (*operation1d)(as, int);

typedef struct {
    int len;
    int *arr;
}as;

int ascending(int i, int j){
    if (i<=j) return 1;
    else return 0;
}

int descending(int i, int j){
    if (i>=j) return 1;
    else return 0;
}

void printa(as);

void swap(as, int, int);

as genas(int);

void inssort(as);

void bubblesort(as);

void ctrl_inssort(as, int(*)(int,int));

void ctrl_bubblesort(as, int(*)(int,int));

int main(void){
    // generate an array
    int _arr[] = {12,29,4,13,1};
    as arrs;
    arrs.len = 5;
    arrs.arr = _arr;
    // test printa
    printa(arrs);
    // test swap
    swap(arrs,1,2);
    printa(arrs);
    // test genas
    arrs = genas(20);
    as arrst = arrs;
    printa(arrst);
    // test inssort
    printf("Insert sort:\n");
    arrst = arrs;
    inssort(arrst);
    printa(arrst);
    // test bubblesort
    printf("Bubble sort:\n");
    arrst = arrs;
    bubblesort(arrst);
    printa(arrst);  
    // test ctrl_inssort
        // int(*cmp)(int,int);
    printf("Ascending insert sort:\n");
    arrst = arrs;
        // cmp = ascending;
    ctrl_inssort(arrst,ascending);
    printa(arrst);
    printf("Descending insert sort:\n");
    arrst = arrs;
        // cmp = descending;
    ctrl_inssort(arrst,descending);
    printa(arrst);  
    // test ctrl_bubblesort
    printf("Ascending bubble sort:\n");
    arrst = arrs;
    ctrl_bubblesort(arrst,ascending);
    printa(arrst);   
    printf("Ascending bubble sort:\n");
    arrst = arrs;
    ctrl_bubblesort(arrst,descending);
    printa(arrst);

    return 0;
}

void printa(as arrs){
    int len = arrs.len;
    int* arr = arrs.arr;
    for (int i=0; i<len; i++){
        printf("%d ",*(arr+i));
    }
    printf("\n");
}

void swap(as arrs, int i, int j){
    int len = arrs.len;
    int* arr = arrs.arr;
    if (i>=len | j>=len) printf("Wrong index range.");
    int tmp;
    tmp = *(arr+i);
    *(arr+i) = *(arr+j);
    *(arr+j) = tmp;
}

as genas(int size){
    // generate a ordered array
    as arrs;
    arrs.len = size+1;
    arrs.arr = (int*)malloc(arrs.len*sizeof(int));
    for (int i=0; i<arrs.len; i++){
        *(arrs.arr+i) = i;
    }
    // random shuffle
    srand((unsigned)time(NULL));
    for (int i=0; i<size*size+1; i++){
        while(rand()/32767.0 > 0.50){
            swap(arrs, rand()%arrs.len, rand()%arrs.len);
        }
    }
    return arrs;
}

void inssort(as arrs){
    int len = arrs.len;
    int* arr = arrs.arr;
    // first pointer, show the current sorted range
    for (int i=0; i<len; i++){
        int ele = *(arr+i);
        // second loop, compare current element with previous and insert(swap)
        int j = i-1;
        while(*(arr+j)>=ele && j>=0){
            swap(arrs, j, j+1);
            j--;
        }
    }
}

void bubblesort(as arrs){
    int len = arrs.len;
    int* arr = arrs.arr;
    // bubble from head
    for (int i=0; i<len; i++){
        for (int j=0; j<len-1; j++){
            if (*(arr+j)>=*(arr+j+1)){
                swap(arrs, j, j+1);
            }
        }
    }
}

void ctrl_inssort(as arrs, int(*cmp)(int i, int j)){
    int len = arrs.len;
    int* arr = arrs.arr;
    for (int i=0; i<len; i++){
        int ele = *(arr+i);
        int j = i-1;
        while(!(*cmp)(*(arr+j),ele) && j>=0){
            swap(arrs, j, j+1);
            j--;
        }
    }
}

void ctrl_bubblesort(as arrs, int(*cmp)(int i, int j)){
    int len = arrs.len;
    int* arr = arrs.arr;
    for (int i=0; i<len; i++){
        for (int j=0; j<len-1; j++){
            if (!(*cmp)(*(arr+j),*(arr+j+1))){
                swap(arrs, j, j+1);
            }
        }
    }
}