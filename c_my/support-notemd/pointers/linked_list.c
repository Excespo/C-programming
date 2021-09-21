#include<stdio.h>
#include<stdlib.h>

// define the node of a linked list
typedef struct Node
{
    int data;
    char *element;
    struct Node *next;
    struct Node *prev;
}node;

static int length;

// define a linked list
// in the form of root(empty)->element1->element2->...->lastelement->tail(empty)
node *list(){

    // initialize the head of linked list
    node *head = NULL;
    // define the first node
    node *tmp = (node*)malloc(sizeof(node));
    if (tmp==NULL) exit(1); // check if the memory is allocated successfully
    tmp->data = 1; // equals to (*tmp).data = 1
    tmp->element = "node";
    tmp->next = NULL;
    // point head to the first node
    head = tmp;
    // length change
    length++;

    // initialize root node
    node *root = (node*)malloc(sizeof(node));
    root->next = head;


    // next node
    for(int i=2;i<10;i++){
        // define the next node
        node *new_node = (node*)malloc(sizeof(node));
        if (new_node==NULL) exit(2);
        (*new_node).data = i;
        (*new_node).next = NULL;
        // link the list to new code
        (*tmp).next = new_node;
        tmp = (*tmp).next;
        length++;
    }

    // initialize tail root
    node *tail = NULL;
    tmp->next = tail;

    return root;
}

// insert an element at the n-th position(0 as head)
void insert(node *root, int element, int n){
    if(n>length) exit(1);

    // define new node data
    node *insert_node = (node*)malloc(sizeof(node));
    insert_node->data = element;   
    
    // // if n is 0
    // if(n==0){
    //     // need to reconstruct the head node
    //     node *new_head = (node*)malloc(sizeof(node));
    //     new_head->data = element;
    //     new_head->next = head;
    //     head = new_head;

    // }else{ // if n not 0
        node *current = root;
        // proceed to exact the position
        while(n){
            current = current->next;
            n--;
        }
        // insert the new element m, link to next node
        insert_node->next = current->next;
        // link to the previous node
        current->next = insert_node;
    // }

    length++;
}

// void pop(node *root, int element, int n){
//     if(n>length) exit(1);
//     while(n){
//         return 0;
//     }
// }

void display_list(node *root){
    node *tmp = NULL;
    printf("Show list\n");
    tmp = root->next;
    int index = 0;
    // while node is not a null pointer
    while(tmp){
        printf("N.%d value: %d, address: %p, size of node struct: %ld\n",index,tmp->data, &(tmp->data), sizeof(*tmp));
        tmp = (*tmp).next;
        index++;
    }
    printf("Done. Length = %d\n", length);
}

void main(){

    static node *list_root = NULL;
    list_root = list();

    // compare to an array

    // int arr[] = {1,2,3,4,5,6,7,8,9};
    // printf("case fot an array\n");
    // for(int i=0;i<9;i++){
    //     printf("arr[%d]'s value: %d, adress: %p\n", i, arr[i], &arr[i]);
    // }

    // Part3.1, insert at 0
    insert(list_root, 100, 0);
    // display_list(head);
    // Part3.2, insert at 5(that is to say, n.4)
    insert(list_root, 100, 10);
    display_list(list_root);
} 
