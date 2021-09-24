#include<stdio.h>
#include<stdlib.h>

int getValue(char s){
    if(s=='I'){
        return 1;
    }else if(s=='V'){
        return 5;
    }else if(s=='X'){
        return 10;
    }else if(s=='L'){
        return 50;
    }else if(s=='C'){
        return 100;
    }else if(s=='D'){
        return 500;
    }else if(s=='M'){
        return 1000;
    }else{
        return 0;
    }
}

int romanToInt(char * s){
    int i = 0;
    static int num;
    num = 0;
    while (1){
        int current = getValue(*(s+i));
        int next = getValue(*(s+i+1));
        if(next==0){
            num += current;
            break;
        }else if(current<=next){
            num += (next-current);
            i+=2;
        }else{
            num += current;
            i++;
        }
    }
    return num;
}


void main(){
    char *s = (char*)malloc(10*sizeof(char));
    printf("Input Roman Num: \n");
    scanf("%s",s);
    printf("Convert to %d\n", romanToInt(s));
}

