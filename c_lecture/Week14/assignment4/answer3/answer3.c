#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef struct {
    char name[N];
    int age;
    int class;
    int mid_term_score;
    int homework_score;
    int final_score;
} Student;

// typedef Student students[N];
// typedef int scores[N];

void load_from_keyboard(Student* students, int* scores) {
    for (int i=0; i<N; i++) {
        printf("Enter the infomation of student %d:\n",i);
        printf("Enter student's name: ");
        scanf("%s", students[i].name);
        printf("Enter student's age: ");
        scanf("%d", &(students[i].age));
        printf("Enter student's class: ");
        scanf("%d", &(students[i].class));
        printf("Enter student's mid term score: ");
        scanf("%d", &(students[i].mid_term_score));
        printf("Enter student's homework score: ");
        scanf("%d", &(students[i].homework_score));
        printf("Enter student's final score: ");
        scanf("%d", &(students[i].final_score));

        scores[i] = students[i].mid_term_score + students[i].homework_score + students[i].final_score;
    }
}

void display_sorted_record(Student* students, int* scores) {
    printf("\nTotal score listed from highest:\n");
    for (int i=0; i<N; i++) {
        int max = scores[i];
        for (int j=i; j<N; j++) {
            if (scores[j]>max) {
                int tmp = scores[j];
                scores[j] = scores[i];
                scores[i] = tmp;
                Student tmp1 = students[j];
                students[j] = students[i];
                students[i] = tmp1;
            }
        }
        printf("student name: %s, score: %d\n",students[i].name, scores[i]);
    }
}

int main(void) {
    Student* students = (Student*)malloc(N*sizeof(Student));
    int* scores = (int*)malloc(N*4);
    load_from_keyboard(students, scores);
    display_sorted_record(students, scores);
}