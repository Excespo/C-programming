#include<stdio.h>

typedef struct{ // anonymous def
    int a;
    int b;
    int (*func)(int, int);
}Calculator;

static int add(int a, int b){
    return a+b;
}

int sub(int a, int b){
    return a-b;
}

int max(int a, int b){
    int res = a>=b?a:b;
    return res;
}

void main(){
    Calculator calc;
    calc.func = add;
    printf("calc.add = %d\n",calc.func(10,2));
    calc.func = sub;
    printf("calc.sub = %d\n",calc.func(10,2));
    calc.func = max;
    printf("calc.max = %d\n",calc.func(10,2));
}
