#include<stdio.h>

int sum_from_zero(int num);
int wrong_sum_from_zero(int num);

int main(){
    int result1;
    for(int i =0;i<=10;i++){
        result1 = wrong_sum_from_zero(i);
    }
    printf("Without \'static\', result1 = %d\n", result1);
    
    int result2;
    for(int i =0;i<=10;i++){
        result2 = sum_from_zero(i);
    }
    printf("With \'static\', result2 = %d\n", result2);
    return 0;
}

int sum_from_zero(int num){
    static int res = 0;
    res += num;
    return res;
}

int wrong_sum_from_zero(int num){
    int res = 0;
    res += num;
    return res;
}