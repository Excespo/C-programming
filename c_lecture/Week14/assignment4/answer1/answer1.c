#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _Word {
    struct _Word* next;
    int len;
} Word;

Word* append(Word* tail) {
    Word* new_word = (Word*)malloc(sizeof(Word));
    new_word->len = 0;
    new_word->next = NULL;
    
    tail->next = new_word;
    return new_word;
}

int count(Word* word, char* sentence) {
    int i = 0, total = 1;

    Word* tail = word;
    while (sentence[i]!='\n') {
        if (sentence[i]==' ') {
            tail = append(tail);
            total++;
        }else if (sentence[i]!=','&& sentence[i]!='.' && sentence[i]!='?' && sentence[i]!='!') {
            tail->len++;
        }
        i++;
    }
    return total;
}

int main() {
    char sentence[100] = {0};
    fgets(sentence, 100, stdin);
    
    Word* word = (Word*)calloc(1,sizeof(Word));
    word->next = NULL;
    word->len = 0;

    int total = count(word,sentence);
    if (sentence[0]=='\n') {
        printf("The number of words is 0.\n");
        return 0;
    }
    printf("The number of words is %d. The length of the %d words are ",total, total);
    while (word!=NULL) {
        printf("%d ",word->len);
        word = word->next;
    }
    printf("\n");
    return 0;
}