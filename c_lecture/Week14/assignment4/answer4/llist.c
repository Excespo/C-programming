#include "llist.h"

Student_node_t* stu_node_create(void) {
    Student_node_t* stu = (Student_node_t*)calloc(1,sizeof(Student_node_t));
    stu->this = (Student_t*)calloc(1,sizeof(Student_t));
    stu_info_input(stu->this);
    stu->next = stu->prev = NULL;
    return stu;
}

FLAG stu_info_input(Student_t* stu) {
    if (stu==NULL) return FAIL;
    printf("Enter the infomation of next student:\n");
    printf("Enter student's name: ");
    scanf("%s", stu->name);
    printf("Enter student's age: ");
    scanf("%d", &(stu->age));
    printf("Enter student's class: ");
    scanf("%d", &(stu->class));
    printf("Enter student's mid term score: ");
    scanf("%d", &(stu->mid_term_score));
    printf("Enter student's homework score: ");
    scanf("%d", &(stu->homework_score));
    printf("Enter student's final score: ");
    scanf("%d", &(stu->final_score));
    stu->total_score = stu->mid_term_score + stu->homework_score + stu->final_score;
    return OK;
}

Students_list_t* list_create(void) {
    Students_list_t* list = (Students_list_t*)calloc(1,sizeof(Students_list_t));
    list_init(list);
    return list;
}


FLAG list_init(Students_list_t* list) {
    if (list==NULL) return FAIL;
    list->head = (Student_node_t*)calloc(1,sizeof(Student_node_t));
    list->tail = list->head;
    list->head->prev = NULL;
    list->tail->next = NULL;
    return OK;
}

FLAG list_append(Students_list_t* list,Student_node_t* stu_node) {
    if (list==NULL || stu_node==NULL) return FAIL;
    list->tail->next = stu_node;
    stu_node->prev = list->tail;
    list->tail = stu_node;
    return OK;
}

Student_node_t* list_pop(Students_list_t* list) {
    Student_node_t* last_stu = list->tail;
    list->tail = list->tail->prev;
    list->tail->next = NULL;
    return last_stu;
}

FLAG print_stu_info(Student_t* stu) {
    if (stu==NULL) return FAIL;
    printf("Student: %s, total score:%d\n", stu->name, stu->total_score);
    return OK;
}

FLAG list_remove(Students_list_t* list, int eval, FLAG(*cmp)(Student_t* student, int eval)) {
    if (list->head==list->tail) return FAIL;
    printf("\nRemoving failed students...\n");
    Student_node_t* stu = list->head->next;
    while (stu!=NULL) {
        /* if cmp isn't verified, remove */
        if (!cmp(stu->this,eval)) {
            if (stu->next==NULL) {
                list->tail = list->tail->prev;
                list->tail->next = NULL;
                /* ? no NULL here ? */
                // stu->this = NULL, stu = NULL;
                free(stu->this);
                free(stu);
                return OK;
            }
            Student_node_t* curr = stu;
            stu = stu->next;
            stu->prev = curr->prev;
            stu->prev->next = stu;
            // curr->this = NULL, curr = NULL;
            free(curr->this);
            free(curr);
        }else {
            stu = stu->next;
        }
    }
    printf("Done!\n");
    return OK;
}

FLAG lremove(Students_list_t* list, int eval, FLAG(*cond)(Student_t* stu, int eval)) {
    Student_node_t* curr = list->head->next;
    while (curr!=NULL) {
        if (!cond(curr->this,eval)) {
            if (curr==list->tail) {
                list->tail = list->tail->prev;
                list->tail->next = NULL;
                free(list->tail->next->this);
                free(list->tail->next);
            }
            curr = curr->next;
            Student_node_t* tmp = curr->prev;
            curr->prev = tmp->prev;
            curr->prev->next = curr;
            free(tmp->this);
            free(tmp);
        } else {
            curr = curr->next;
        }
    }
}

FLAG del_flag(Student_t* student, int eval){
    return eval;
}

FLAG list_removeall(Students_list_t* list) {
    list_remove(list,0,del_flag);
    // list->tail = list->head;
    // list->tail->next = NULL; 
    return OK;
}

FLAG list_destroy(Students_list_t* list) {
    list_removeall(list);
    /*  why add this line, mem cannot be freed correctly??????????????????????????????????????????????????????????????????????   */
    // free(list->head->this); 实际上head里没有this所以free与否无所谓
    free(list->head);
    free(list);
    return OK;
}

/* ATTENTION
 *
 * 内存泄漏确实nt
 * One bug solved but not knowing why
 * 我真的泪目了，就硬一个个free调试过去
 * 你妈的，先赋值null再free就说0x0 is not stack'd, malloc'd or (recently) free'd
 * 还有在answer4.c里free head不free tail就可以
 * free head反而会少free两个malloc的heap mem？？什么鬼
 */