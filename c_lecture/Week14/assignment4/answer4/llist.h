// #ifndef __LLIST_H
// #define __LLIST_H

// #endif
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

typedef enum {
    OK = 1,
    FAIL = 0,
} FLAG;

typedef struct _Student_t{
    char name[16];
    int age;
    int class;
    int mid_term_score;
    int homework_score;
    int final_score;
    int total_score;
} Student_t;

typedef struct _Student_node_t {
    Student_t* this;
    struct _Student_node_t* next;
    struct _Student_node_t* prev;
} Student_node_t;

/* head doesn't contain a student, but tail does
 */
typedef struct _Students_list_t {
    Student_node_t* head;
    Student_node_t* tail;
} Students_list_t;

Student_node_t* stu_node_create(void);

FLAG stu_info_input(Student_t*);

Students_list_t* list_create(void);

FLAG list_init(Students_list_t*);

FLAG list_append(Students_list_t*,Student_node_t*);

Student_node_t* list_pop(Students_list_t*);

FLAG print_stu_info(Student_t*);

FLAG list_remove(Students_list_t*, int, FLAG(*)(Student_t*, int));

FLAG lremove(Students_list_t*, int, FLAG(*)(Student_t*, int));

FLAG del_flag(Student_t*, int);

FLAG list_removeall(Students_list_t*);

FLAG list_destroy(Students_list_t*);