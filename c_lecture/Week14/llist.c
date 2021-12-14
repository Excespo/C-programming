#include <stdio.h>
#include <stdlib.h>
#include "llist.h"
#include "debug.h"

llist_err_t list_init(llist_t* self) {
    self->head = (llist_node_t*)calloc(1,sizeof(llist_node_t));
    self->head->prev = NULL;
    self->tail = self->head;
    self->fence = self->head;
    self->tail->next = NULL;
    self->len = 0;
    return LLIST_OK;
}

llist_err_t list_deinit(llist_t* self) {
    list_removeall(self);
    free(self->head);
    return LLIST_OK;
}

llist_t* list_create(void) {
    llist_t* self = (llist_t*)malloc(sizeof(llist_t));
    list_init(self);
    return self;
}

llist_err_t list_removeall(llist_t* self) {
    self->fence = self->head;
    llist_node_t* nxt = self->fence->next;
    while (nxt!=NULL) {
        self->fence = nxt;
        nxt = nxt->next;
        free(self->fence);
    }
    self->tail, self->fence = self->head;
    return LLIST_OK;
}

llist_err_t list_destroy(llist_t* self) {
    list_deinit(self);
    self->head = NULL;
    free(self);
    return LLIST_OK;
}

llist_err_t list_append(llist_t* self, LLIST_DTYPE data) {
    llist_node_t* node = (llist_node_t*)calloc(1,sizeof(llist_node_t));
    // printf("self->tail is %p\n",self->tail);
    node->data = data;
    node->next = NULL;
    node->prev = self->tail;
    self->tail->next = node;
    self->tail = self->tail->next;
    return LLIST_OK;
}

int fp_format_int(llist_node_t* node, FILE * fp) {
    return fprintf(fp, "{\"data\": %d}, ", node->data);
}

llist_err_t list_print(llist_t* self, FILE* fp, fp_fmt_fn_t fmt) {
    if (self->tail==self->head) return LLIST_FAIL;
    do{
        self->fence = self->fence->next;
        fmt(self->fence, fp);
    }while(self->fence!=self->tail);
    return LLIST_OK;
}

llist_err_t list_print_reverse(llist_t* self, FILE*fp, fp_fmt_fn_t fmt) {
    if (self->tail==self->head) return LLIST_FAIL;
    self->fence = self->tail;
    while(self->fence!=self->head){
        fmt(self->fence, fp);
        self->fence = self->fence->prev;
    }
    return LLIST_OK;    
}

void test() {
    llist_t* llist_on_heap = list_create();
    llist_t llist_on_stack = {0};
    list_init(&llist_on_stack);

    list_append(llist_on_heap, 0);
    list_append(llist_on_heap, 1);
    list_append(llist_on_heap, 10);
    list_append(&llist_on_stack, 0);
    list_append(&llist_on_stack, 1);
    list_append(&llist_on_stack, 10);

    printf("Print list_on_heap:\n");
    list_print(llist_on_heap, stdout, fp_format_int);
    printf("\n");
    printf("Print list_on_stack:\n");
    list_print(&llist_on_stack, stdout, fp_format_int);
    printf("\n");
    printf("Print list_on_heap reverse:\n");
    list_print_reverse(llist_on_heap, stdout, fp_format_int);
    printf("\n");
    printf("Print list_on_stack reverse:\n");
    list_print_reverse(&llist_on_stack, stdout, fp_format_int);
    printf("\n");

    list_destroy(llist_on_heap);
    llist_on_heap = NULL;
    list_deinit(&llist_on_stack);
    return;
}
int main() {
    test();
    return 0;
}