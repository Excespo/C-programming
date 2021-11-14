/* Internal sort refers to kind of sorting 
 * where all data are loaded into memory in one time(other word batch=1)
 * Including: Bubble sort, insertion sort, selection sort
 *            Shell sort, quick sort
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<unistd.h>

// tools
typedef struct arr_ *aptr;
struct arr_{
    int len;
    int* arr;
};

void printa (aptr arrs){
    printf("Array of len: %d, ele: ",arrs->len);
    for (int i=0; i<arrs->len; i++){
        printf("%d ",*(arrs->arr+i));
    }
    printf("\n");
}

aptr randaptr (int n, int max){
    aptr arrs = (aptr)malloc(sizeof(aptr));
    // printf("address of arrs, %p\n", &arrs);
    arrs->len = n;
    arrs->arr = (int*)malloc(sizeof(int)*n);
    srand((unsigned)time(NULL));
    for (int i=0; i<n; i++){
        *(arrs->arr+i) = rand()%max;
    }
    return arrs;
}

int ascend(int i, int j){
    if (i<=j) return 1;
    return 0;
}

int descend(int i, int j){
    if (i>=j) return 1;
    return 0;
}

void move(aptr arrs, int i, int j){
    if(i>=arrs->len | j>=arrs->len) exit(0);
    int tmp = *(arrs->arr+i);
    *(arrs->arr+i) = *(arrs->arr+j);
    *(arrs->arr+j) = tmp;
}

// algorithms
void insertionSort (aptr arrs,int(*cmp)(int i,int j)){
    int len = arrs->len;
    int* arr = arrs->arr;
    for (int i=0; i<len; i++){
        int j = i;
        while(--j>=0){
            if (!(*cmp)(arr[j],arr[j+1])) move(arrs,j,j+1);
        }
    }
}

void quickSort_ (aptr arrs, int start, int end){
    int len = arrs->len;
    int* arr = arrs->arr;
    int piv = arr[end];
    int left = start, right = end-1;

    if (start>=end) return;
    while(left<right){
        while(arr[left]<piv && left<right) {left++;}
        while(arr[right]>=piv && left<right) {right--;}
        move(arrs,right,left);
    }
    if (arr[left]>=piv){
        move(arrs,left,end);
    }else{
        left++;
    }
    if (left){
        quickSort_(arrs, start, left-1);
    }
    quickSort_(arrs, left+1, end);
}

void quickSort(aptr arrs){
    quickSort_(arrs, 0, arrs->len-1);
}

void bubbleSort(aptr arrs, int(*cmp)(int i,int j)){
    int len = arrs->len;
    int* arr = arrs->arr;
    for (int j=0;j<len;j++){
        for (int i=0;i<len-1;i++){
            if (!(*cmp)(arr[i],arr[i+1])){
            move(arrs,i,i+1);
            }
        }
    }
}

void selectionSort(aptr arrs, int(*cmp)(int i,int j)){
    int len = arrs->len;
    int* arr = arrs->arr;
    int min, idx;
    for (int i=0; i<len; i++){
        min = arr[i];
        for (int j=i; j<len; j++){
            if ((*cmp)(arr[j],min)){
                min = arr[j];
                idx = j;
            }
        }
        move(arrs, idx, i);
    }
}

void binarySort (aptr arrs){
    ;
}

void sampleSort (aptr arrs){
    ;
}


// test part
int main(void){
    // test insertion sort, ascend
    printf("Test1\n");
    aptr arrs1 = randaptr(10,100);
    printa(arrs1);
    insertionSort(arrs1,ascend);
    printa(arrs1);
    // test insertion sort, descend
    // sleep    unistd.h 
    printf("Test2\n");
    sleep(1);
    aptr arrs2 = randaptr(10,100);
    printa(arrs2);
    insertionSort(arrs2,descend);
    printa(arrs2);
    // test quick sort
    printf("Test3\n");
    sleep(1);
    aptr arrs3 = randaptr(10,100);
    printa(arrs3);
    quickSort(arrs3);
    printa(arrs3);
    // test bubble sort, descend
    printf("Test4\n");
    sleep(1);
    aptr arrs4 = randaptr(10,100);
    printa(arrs4);
    bubbleSort(arrs4,descend);
    printa(arrs4);
    // test selection sort, ascend
    printf("Test5\n");
    sleep(1);
    aptr arrs5 = randaptr(10,100);
    printa(arrs5);
    selectionSort(arrs5,ascend);
    printa(arrs5);

    return 0;
}