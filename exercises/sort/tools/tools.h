#ifndef _TOOLS_H
#define _TOOLS_H

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<string.h>

#define RANGE 1000

void show_arr(int *, int);

int* reverse(int *, int);

int* random_generate(int);

int* bubble_sort(int *, int, bool);

int* shell_sort(int *, int, bool);

int* selectionsort(int *, int);

int* insertionsort(int *, int);

int* mergesort(int *, int);

int* quicksort(int *, int);

int* heapsort(int *, int);

int* countingsort(int *, int);

int* bucketsort(int *, int);

int* radixsort(int *, int);

#endif