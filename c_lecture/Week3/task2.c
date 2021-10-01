#include<stdio.h>

long reverse(int);

int main(void)
{
    int _x;
    scanf("%d",&_x);
    long x = _x;
    long rx = reverse(x);
    long diff = rx-x;
    if ((int)rx==rx&&(int)diff==diff)
    {
        printf("%d\n",(int)diff);
    }
    else
    {
        printf("%d\n",0);
    }

    return 0;
}

long reverse(int x)
{
    int last_digit = 0;
    int reverse = 0;
    while (x)
    {
        last_digit = x % 10;
        x = x / 10;
        reverse = 10 * reverse + last_digit;
    }
    return reverse;
}