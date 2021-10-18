#include<stdio.h>
#include<stdlib.h>

int max_prime(int);

int main(void)
{
    int n,i=1;
    printf("Input n\n");
    scanf("%d",&n);

    int* pA = (int*)malloc(n*sizeof(int)/2 + 1);
    pA[0] = 2;
    int idx = 0; // index of last element in pA
    while(i++<=n) // test all prime from 2 to max_prime
    {
        int k=0; // test all num in pA
        int isPrime = 1;
        while(k<=idx)
        {
            int nk = *(pA+k);
            if(!(i%nk))
            {
                isPrime = 0;
            }
            k++;
        }
        if (isPrime)
        {
            idx++;
            *(pA+idx) = i;
        }
    }
    for (int j=0; j<idx+1; j++)
    {
        printf("%d ",*(pA+j));
    }
    printf("\n");
    return 0;
}

int max_prime(int n)
{
    int ret = 0;
    while(++ret){
        if (ret*ret>n) break;
    }
    return ret+1;
}