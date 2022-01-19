#include <stdio.h>
#include <stdlib.h>
#include "debug.h"

#define BUFMAX 1024
// #define USE_FGETS 

typedef enum {
    FAIL = 0,
    OK = 1,
} FLAG;

typedef struct {
    char* line_content;
    line_t* next;
} line_t;

typedef struct {
    line_t* head;
    line_t* tail;
} line_parser_t;

line_parser_t* create_parser(void){
    line_parser_t* parser = (line_parser_t*)calloc(1,sizeof(line_parser_t));
    parser->head->next = parser->tail;
    parser->tail->next = NULL;
    return parser;
}

FLAG get_line(buffer){
    ;
}

line_t* create_line(void){
    line_t* line = (line_t*)calloc(1,sizeof(line_t));
    get_line(line->content);
    line->next = NULL;
    return line;
}

int main()
{
    char buf[128];
#if USE_FGETS
    while (fgets(buf, sizeof(buf) - 1, stdin))
    {
        printf("%ld",sizeof(buf));
        LOGI("%s", buf);
    }
#else
    while (scanf("%s", buf) != -1)
    {

        LOGI("%s", buf);
    }
#endif
    return 0;
}