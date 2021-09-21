#include<stdio.h>
#include<stdlib.h>

typedef struct _node{
    int value;
    struct _node *prev;
    struct _node *next;
}node;

typedef struct _list{
    node *head;
    node *tail;
}list;

// NULL <-> head <-> node 1 <-> ... <-> node n <-> tail <-> NULL

list double_list(int n){
    // construct a int(0~n-1) linked_list, with head and tail given

    // initialize head and tail
    node *head = (node*)malloc(sizeof(node));
    node *tail = (node*)malloc(sizeof(node));
    if(head==NULL||tail==NULL) exit(1);
    list d_list;
    // boundary
    head->prev = NULL;
    tail->next = NULL;
    head->next = NULL;
    tail->prev = NULL;
    // // initialize the first node
    // node* first_node = (node*)malloc(sizeof(node));
    // if (first_node==NULL) exit(1);
    // first_node->value = 0;
    // // link between head and first node
    // head->next = first_node;
    // first_node->prev = head;

    // constuct next node by iteration
    node *current_node = (node*)malloc(sizeof(node));
    if (current_node==NULL) exit(1);
    // current_node->next = NULL;
    // current_node->prev = NULL;
    // next_node->next = NULL;
    // next_node->prev = NULL;
    // current_node = first_node;
    current_node = head;
    for(int i=0;i<n;i++){
        node *next_node = (node*)malloc(sizeof(node)); // 怎么想的循环外面定义next node啊
        next_node->value = i;
        next_node->prev = current_node;
        current_node->next = next_node;
        current_node = next_node;
    }
    // now current is the n-th node and last node's value and prev is defined
    current_node->next = tail;
    tail->prev = current_node;

    //return head and tail
    d_list.head = head;
    d_list.tail = tail;
    return d_list;
}

void show_list(node* head){
    node *tmp = (node*)malloc(sizeof(node));
    tmp = head->next;
    while(tmp->next){
        printf("node with value %d, address %p\nit's next: ", tmp->value, tmp);
        tmp = tmp->next;
    }
    printf("tail, because tail->next=NULL\n");
}

void show_list_inverse(node* tail){
    node *tmp = (node*)malloc(sizeof(node));
    tmp = tail->prev;
    while(tmp->prev){
        printf("node with value %d, address %p\nit's next: ", tmp->value, tmp);
        tmp = tmp->prev;
    }
    printf("head, because head->prev=NULL\n");
}

void main(){
    void (*show)(node*);
    list d_list = double_list(10);

    printf("node is of size %ld\n", sizeof(node));
    printf("Show list to check if next pointer works\n");
    show = &show_list;
    show(d_list.head);
    printf("Show list to check if prev pointer works\n");
    show = &show_list_inverse;
    show(d_list.tail);

}