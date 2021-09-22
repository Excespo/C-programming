#include<stdio.h>

int gcd(int, int);

void main(){
    int A, B;
    printf("Input A B\n");
    scanf("%d%d", &A, &B);
    int max = A>=B?A:B;
    int min = A>=B?B:A;
    printf("%d\n", gcd(max, min));
}

int gcd(int max, int min){
    int rest = max%min;
    if(rest==0){
        return min;
    }else{
        return gcd(min, rest);
    }
};