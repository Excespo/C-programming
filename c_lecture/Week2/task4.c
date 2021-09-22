#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char **argv){
    char *date = argv[1];
    printf("%s\n",date);
    int datelist[] = {0,0,0};
    char *seg = "-";
    char* substr = strtok(date,seg);
    int i = 0;
    while(substr!=NULL){
        datelist[i] = i;
        i++;
        printf("%d, %s, %d\n",i, substr, datelist[i]);
        substr = strtok(NULL,seg);
    }
    // printf("%s\n",data);
    return 0;
}