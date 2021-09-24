#include<stdio.h>
#include<limits.h>

int reverse(int x){
    long long n = 0;
    while(x){
        n = n*10 + x%10;
        x /= 10;
    }
    return (n>INT_MAX || n<INT_MIN)? 0:n;
}

void main(){
    int x;
    printf("x = \n");
    scanf("%d",&x);
    printf("%d, %d\n",INT_MIN, INT_MAX);
    printf("Input = %d, Output = %d\n", x, reverse(x));
}