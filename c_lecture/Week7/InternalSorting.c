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

void q2s_(aptr arrs, int head, int tail){
    int len = arrs->len;
    int* a = arrs->arr;
    int l=head, r=tail-1;
    int pivot = a[tail];

    if (head>=tail) return;
    while(l<r){
        while(a[l]>pivot && l<r) {l++;}
        while(a[r]<=pivot && l<r) {r--;}
        move(arrs,l,r);
    }
    if (a[l]<=pivot){
        move(arrs,tail,r); //zhe ye xing???? bu shi tail<->l???
    }else{
        l++;
    }
    if (l){
        q2s_(arrs,head,l-1);
    }
    q2s_(arrs,l+1,tail);
}

void q2s(aptr arrs){
    q2s_(arrs,0,arrs->len-1);
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
    printf("Test1 Insertion sort Ascend\n");
    aptr arrs1 = randaptr(10,100);
    printa(arrs1);
    insertionSort(arrs1,ascend);
    printa(arrs1);
    // test insertion sort, descend
    // sleep    unistd.h 
    printf("Test2 Insertion sort Descend\n");
    sleep(1);
    aptr arrs2 = randaptr(10,100);
    printa(arrs2);
    insertionSort(arrs2,descend);
    printa(arrs2);
    // test quick sort
    printf("Test3 Quick sort\n");
    sleep(1);
    aptr arrs3 = randaptr(10,100);
    printa(arrs3);
    quickSort(arrs3);
    printa(arrs3);
    // test bubble sort, descend
    printf("Test4 Bubble sort Descend\n");
    sleep(1);
    aptr arrs4 = randaptr(10,100);
    printa(arrs4);
    bubbleSort(arrs4,descend);
    printa(arrs4);
    // test selection sort, ascend
    printf("Test5 Selection sort Ascend\n");
    sleep(1);
    aptr arrs5 = randaptr(10,100);
    printa(arrs5);
    selectionSort(arrs5,ascend);
    printa(arrs5);
    // test quick sort with same elements
    printf("Test6 Quick sort with same elements\n");
    sleep(1);
    aptr arrs6 = randaptr(10,100);
    int arr6[] = {1,4,6,2,2,6,4,2,1,4};
    arrs6->arr = arr6;
    printa(arrs6);
    q2s(arrs6);
    printa(arrs6);
    quickSort(arrs6);
    printa(arrs6);
    // test my q2s
    printf("Test7 q2s\n");
    sleep(1);
    aptr arrs7 = randaptr(10,100);
    printa(arrs7);
    q2s(arrs7);
    printa(arrs7);


    return 0;
}