#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * longestCommonPrefix(char ** strs, int strsSize){
    if(strsSize==0){
       return ""; 
    }else if(strsSize==1){
        return strs[0];
    }else{
        int str_len = strlen(strs[0]);
        int DO = 1;
        int finish_if=1;
        while(DO){
            finish_if = 1;
            for(int i=1;i<strsSize;i++){
                if(memcmp(strs[0],strs[i],str_len)){ // if not the same
                    str_len--;
                    finish_if = 0;
                    break;
                }
            }
            if(finish_if) DO=0;
        }
        char *common = (char*)malloc((str_len+1)*sizeof(char));
        memcpy(common,strs[0],str_len);
        common[str_len] = '\0';
        return common;
    }
}

int main(void)){
    char *_strings[] = {"flow", "flower", "flight","flire"};
    char **strings = _strings;
    int stringsSize = sizeof(_strings)/sizeof(char*);
    printf("%d\n",stringsSize);
    printf("Longest common prefix is: %s, is null: %d\n", longestCommonPrefix(strings, stringsSize), longestCommonPrefix(strings, stringsSize)=="");
    return 0;
}