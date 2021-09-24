#include<stdio.h>
#include<stdlib.h>

void main(){
    char *ch = (char*)malloc(sizeof(char)*10);
    printf("%lu, %lu\n", sizeof(ch), sizeof(*ch));
    char *a = {'0'};
    printf("%ld\n",sizeof(a));
    
}