#include<stdio.h>
#include "tools.h"

int main(void)
{
    printf("%d\n",1<<31);
    printf("%d\n",(1<<31)^(-1));

    return 0;
}