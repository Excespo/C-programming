#include<stdio.h>

int out_stack_num(int);

void main(){
    int n = 0;
    printf("Input n:\n");
    scanf("%d",&n);
    printf("For n = %d, Ans is %d\n",n, out_stack_num(n));
}

int out_stack_num(int n){
    int ans = 0;
    if(n==0||n==1){
        return 1;
    }else if(n>=2){
        int counter = 0;
        for(int i=0;i<n;i++){
            counter += out_stack_num(i)*out_stack_num(n-1-i);
        }
        return counter;
    }
    return 0;
}