#include<stdio.h>
#include<stdlib.h>

typedef struct Len_arr{
    int len;
    int *arr;
}len_arr;

len_arr getInNumbers(void);

void search(int*, int);

int sum(int*, int);

void search_maxmin(int*, int);

void count_even(int*, int);

len_arr inverse(int*, int);

int main(void)
{
    len_arr l_a = getInNumbers();
    search(l_a.arr,l_a.len);
    int sumArr = sum(l_a.arr, l_a.len);
    search_maxmin(l_a.arr,l_a.len);
    count_even(l_a.arr, l_a.len);
    len_arr revl_a = inverse(l_a.arr,l_a.len);
    return 0;
}

len_arr getInNumbers(void)
{
    len_arr ret;
    int n = 0;
    printf("Input length of array\n");
    while ((n = getchar())
    fflush(stdin);
    int* arr = (int*)malloc(n*sizeof(int));
    printf("Input elements in array:\n");
    for(int j=0; j<n; j++)
    {
        scanf("%d",arr+j);
    }
    printf("%p, %p, %d, %d\n",arr, arr+1, *arr, arr[0]);
    
    printf("\nThe elements of the array are: ");
    for(int k=0; k<n; k++)
    {
        printf("%d ",*(arr+k));
    }
    printf("\n");
    ret.arr = arr;
    ret.len = n;
    fflush(stdin);
    return ret;
}

void search(int* arr,int length)
{
    int query = 0;
    printf("Input the number to query:\n");
    scanf("%d",&query);
    int have = 0;
    int* idx = (int*)malloc(length*sizeof(int));
    for (int i=0; i<length; i++)
    {
        if (query==*(arr+i)) 
        {
            have=1;
            idx[i] = i;
        }
        else{
            idx[i] = 1<<31;
        }
    }
    if (have){
        printf("The number exists, its index is ");
        for(int j=0; j<length; j++){
            if(idx[j]!=1<<31) printf("%d ",idx[j]);
        }
        printf("\n");
    }else{
        printf("The number does not exist.\n");
    }

}

int sum(int* arr, int len){
    int _sum = 0;
    for (int i=0; i<len; i++){
        _sum+=*(arr+i);
    }
    printf("The sum of array is: %d\n", _sum);
    return _sum;
}

void search_maxmin(int* arr, int len){
    int max, min = *arr;
    for (int i=0; i<len; i++){
        if (*(arr+i)<min){
            min = *(arr+i);
        }
        else if (*(arr+i)>max){
            max = *(arr+i);
        }
    }
    int* max_idx = (int*)malloc(len*sizeof(int));
    int* min_idx = (int*)malloc(len*sizeof(int));
    int count = 0;
    printf("The maximum element of array is: %d at index ",max);
    for (int i=0; i<len; i++){
        if (*(arr+i)==max){
            *(max_idx+count) = i;
            count++;
        }
    }
    for (int i=0; i<count; i++){
        printf("%d ",*(max_idx+i));
    }
    printf("\n");

    count = 0;
    printf("The minimum element of array is: %d at index ",min);
    for (int i=0; i<len; i++){
        if (*(arr+i)==min){
            *(min_idx+count) = i;
            count++;
        }
    }
    for (int i=0; i<count; i++){
        printf("%d ",*(min_idx+i));
    }
    printf("\n");
}

void count_even(int* arr, int len){
    int even_counter = 0;
    for(int i=0; i<len; i++){
        if (!(*(arr+i)%2)){
            even_counter++;
        }
    }
    printf("There are %d even numbers.",even_counter);
}

len_arr inverse(int* arr, int len){
    len_arr rev;
    rev.len = len;
    rev.arr = (int*)malloc(len*sizeof(int));
    printf("The array is reversed.\nThe elements of the array are: ");
    for (int i=0; i<len; i++){
        *(rev.arr+i) = *(arr+len-1-i);
        printf("%d ",*(rev.arr+i));
    }
    printf("\n");
    return rev;
}