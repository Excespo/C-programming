#include<stdio.h>

int factorial(int);

int catalan(int);

void main(){
    int n = 0;
    printf("Input n:\n");
    scanf("%d",&n);
    printf("For n = %d, Ans is %u\n",n,catalan(n));
}

int catalan(int n){
    const long long unsigned ctlnums[] = {
    1ull,
    1ull,
    2ull,
    5ull,
    14ull,
    42ull,
    132ull,
    429ull,
    1430ull,
    4862ull,
    16796ull,
    58786ull,
    208012ull,
    742900ull,
    2674440ull,
    9694845ull,
    35357670ull,
    129644790ull,
    477638700ull,
    1767263190ull,
    6564120420ull,
    24466267020ull,
    };
    return ctlnums[n];
}
