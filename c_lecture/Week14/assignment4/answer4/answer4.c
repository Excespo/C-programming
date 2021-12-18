#include <stdio.h>
#include <stdlib.h>
#include "llist.h"


FLAG display_all(Students_list_t* list) {
    if (list->head==list->tail) {
        printf("\nNo student in the list\n");
        return FAIL;
    }
    printf("\nStudents and their scores:\n");
    Student_node_t* stu = list->head->next;
    while (stu!=NULL) {
        print_stu_info(stu->this);
        stu = stu->next;
    }
    return OK;
}

FLAG demo_append(Students_list_t* list, int n) {
    if (list==NULL) return FAIL;
    printf("Demo append students:\n");
    for (int i=0; i<n; i++) {
        Student_node_t* new_stu = stu_node_create();
        list_append(list, new_stu);
    }

    return OK;
}

FLAG cmp(Student_t* student, int eval) {
    return student->total_score>=eval;
}

FLAG demo_remove_stupid(Students_list_t* list) {
    list_remove(list,60,cmp);
    return OK;
}

int end(Students_list_t* list) {
    list_destroy(list);
    printf("Students list destroyed\n");
    return OK;
}

int main (void) {
    Students_list_t* stu_list = list_create();
    demo_append(stu_list,2);
    display_all(stu_list);

    // demo_remove_stupid(stu_list);
    // display_all(stu_list);
    list_remove(stu_list, 60, cmp);
    display_all(stu_list);

    end(stu_list);
    return 0;
}
