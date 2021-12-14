// https://notes.sjtu.edu.cn/s/4PbeMM_kR

#include<stdio.h>
#include<stdlib.h>

typedef enum {
    student = 0,
    teacher = 1,
} type_t;

typedef struct {
    unsigned int is_present:1;
    unsigned int is_infected:1;
    unsigned int is_cured:1;
    unsigned int is_curing:1;
    unsigned int is_inoculated_1:1;
    unsigned int is_inoculated_2:1;
    unsigned int is_inoculated_3:1;
    unsigned int is_alive:1;
} covid_t;

typedef union {
    int grade;
    char domain[20];
} grade_domain_t;

typedef struct {
    unsigned int year:15;
    unsigned int month:5;
    unsigned int day:4;
} birthday_t;

struct _person_t{
    char name[10];
    int age;
    type_t type;
    // grade_domain_t grade_domain;
    // char* email;
    // birthday_t birthday;
    // covid_t covid;
};
typedef struct _person_t person_t;

person_t* addpersons(int n){
    person_t* persons = (person_t*)malloc(n*sizeof(person_t));
    for (int i=0; i<n; i++){
        printf("Please Input the name of person: ");
        int p = scanf("%s",(persons+i)->name);
        
        printf("\nPlease Input the age of person:");
        p = scanf("%d",&((persons+i)->age));

        printf("\n");
    }
    return persons;
}

void printperson(person_t person){
    printf("The person name is %s, age is %d",person.name, person.age);
    printf("\n");
}

int main(void){
    // person_t* persons = (person_t*)malloc(2*sizeof(person_t));
    // printf("%p %p\n", persons, persons+1);

    // scanf("%s",(persons+1)->name);
    // scanf("%d",&((persons+1)->age));
    // printf("name: %s, age: %d\n",(persons+1)->name,(persons+1)->age);

    printf("size:%ld\n",sizeof(person_t));

    person_t* persons1 = addpersons(1);
    printperson(*persons1);

    return 0;
}