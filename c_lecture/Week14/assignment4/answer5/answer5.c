// #include "../answer4/llist.h"
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

FLAG list_reverse(Students_list_t* list, Students_list_t* rev) {
    if (list->head==list->tail) {
        printf("\nNo student in the list, list cannot be reversed\n");
        return FAIL;
    }
    printf("Reversing students list...\n");
    Student_node_t* curr = list->tail;
    while (curr!=list->head) {
        // printf("age%d, %d, %d\n",curr->this->age, rev->head==rev->tail, curr==NULL);
        Student_node_t* tmp = calloc(1,sizeof(Student_node_t));
        tmp->this = curr->this;
        tmp->prev = tmp->next = NULL;
        list_append(rev, tmp);
        curr = curr->prev;
    }
    // free(curr);
    printf("Done!\n");
    return OK;
}

void demo_reverse(void) {
    Students_list_t* stu_list = list_create();
    demo_append(stu_list,3);
    display_all(stu_list);
    Students_list_t* rev = list_create();
    list_reverse(stu_list, rev);
    display_all(rev);

}

int main(){
    demo_reverse();
    return 0;
}