#include<stdio.h>
#include<stdlib.h>

#define N 5

void func1(int x, int* arr){
    for (int i=0; i<N; i++){
        *(arr+i) = x*i;
    }
}

int main(void){
    int x = 0;
    int* arr = (int*)malloc(N*sizeof(int));
    printf("Input x\n");
    scanf("%d", &x);
    func1(x,arr);
    return 0;
}