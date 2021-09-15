#include<stdio.h>

int main(int argc, char *argv[])
{
    printf("There are %d parameter(s) in command line\n", argc);
    for(int i=0;i<argc;i++)
    {
        printf("arguments[%d]: %s\n",i,argv[i]);
    }
    return 0;
}