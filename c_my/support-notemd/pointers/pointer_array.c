#include<stdio.h>

int main(){

    int a[3][4] = {{0,1,2,3},{4,5,6,7},{8,9,10,11}};
    int length = sizeof(a[0])/sizeof(a[0][0]);
    printf("length of every row = %d\n", length);

    for (int i = 0;i<2;i++){
        // int length = sizeof(a[0])/sizeof(a[0][0]);
        printf("row %d of arrar a, size = %ld, elements are ", i, sizeof(a[i]));
        for (int j = 0;j<length;j++){
            printf("%d, ", a[i][j]);
        }
        printf("\n");
    }

    printf("Use pointer to traverse array\n");

    int (*p)[4] = a; // p = &a[0]
    printf("%ld\n",sizeof(*(p+1)));
    printf("1,1, path = %p, value =%d \n", *(p+1)+1, *(*(p+1)+1));
    return 0;
}