#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void init_matrix(int* A, int* B, int* C, int n) {
    int i, j = 0;
    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            A[i*n+j] = i+j;
            B[i*n+j] = j+i;
            C[i*n+j] = 0;
        }
    }
}

void cnt_time(int* A, int* B, int* C, int n,void(*func)(int*, int*, int*, int)){
	clock_t start, end;
	start = clock();

	func(A,B,C,n);

	end = clock();
	double time =(double)(end - start)/CLOCKS_PER_SEC;
	printf("Use time: %.6f secs\n",time);
}

// 1
void ijk(int* A, int* B, int* C, int n){
    int i, j, k = 0;
    int sum = 0;

    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            sum = 0;
            for (k=0; k<n; k++){
                sum += A[i*n+k]*B[k*n+j];
            }
            C[i*n+j] += sum;
        }
    }
    printf("C[%d][%d]=%d ",25,25,C[25*n+25]);
}

// 2
void jik(int* A, int* B, int* C, int n){
    int i, j, k = 0;
    int sum = 0;

    for (j=0; j<n; j++){
        for (i=0; i<n; i++){
            sum = 0;
            for (k=0; k<n; k++){
                sum += A[i*n+k]*B[k*n+j];
            }
            C[i*n+j] += sum;
        }
    }
    printf("C[%d][%d]=%d ",25,25,C[25*n+25]);
}

// 3
void jki(int* A, int* B, int* C, int n){
    int i, j, k = 0;
    int sum = 0;

    for (j=0; j<n; j++){
        for (k=0; k<n; k++){
            sum = B[k*n+j];
            for (i=0; i<n; i++){
                C[i*n+j] += A[i*n+k]*sum;
            }
        }
    }
    printf("C[%d][%d]=%d ",25,25,C[25*n+25]);
}

// 4
void kji(int* A, int* B, int* C, int n){
    int i, j, k = 0;
    int sum = 0;

    for (k = 0; k < n; k++) {
        for (j = 0; j < n; j++) {
            sum = B[k*n+j];
            for (i = 0; i < n; i++) {
                C[i*n+j] += A[i*n+k]*sum;
            }
        }
    }
    printf("C[%d][%d]=%d ",25,25,C[25*n+25]);
}

// 5
void kij(int* A, int* B, int* C, int n){
    int i, j, k = 0;
    int sum = 0;

    for (k=0; k<n; k++){
        for (i=0; i<n; i++){
            sum = A[i*n+k];
            for (j=0; j<n; j++){
                C[i*n+j] += sum*B[k*n+j];
            }
        }
    }
    printf("C[%d][%d]=%d ",25,25,C[25*n+25]);
}

// 6
void ikj(int* A, int* B, int* C, int n){
    int i, j, k = 0;
    int sum = 0;

    for (i = 0; i < n; i++) {
        for (k = 0; k < n; k++) {
        sum = A[i*n+k];
            for (j = 0; j < n; j++) {
                C[i*n+j] += sum*B[k*n+j];
            }
        }
    }
    printf("C[%d][%d]=%d ",25,25,C[25*n+25]);
}

// 7 l1 cache is 32K (/sys/devices/system/cpu/cpu0/cache/index0)
void blocked_ijk(int*A, int* B, int* C, int n) {
    int i, j, k = 0;
    int ii, jj, kk = 0;
    int b = 32;

    for (i=0; i<n; i+=b){
        for (j=0; j<n; j+=b) {
            for (k=0; k<n; k+=b) {
                for (ii=i; ii<i+b; ii++){
                    for (jj=j; jj<j+b; jj++) {
                        for (kk=k; kk<k+b; kk++) {
                            C[ii*n+jj] += A[ii*n+kk]*B[kk*n+jj];
                        }
                    }
                }
            }
        }
    }
    printf("C[%d][%d]=%d ",25,25,C[25*n+25]);
}

int main(void){
    int n = 4096;
    int *A = (int*)malloc(sizeof(int)*n*n);
    int *B = (int*)malloc(sizeof(int)*n*n);
    int *C = (int*)malloc(sizeof(int)*n*n);
    printf("MATRIX MUL with size %d:\n",n);

    // ijk, 1.25
    init_matrix(A,B,C,n);
    printf("In order ijk, ");
	cnt_time(A,B,C,n,ijk);

    /*
    // jik, 1.25
    init_matrix(A,B,C,n);
    printf("In order jik, ");
	cnt_time(A,B,C,n,jik);

    // jki, 2
    printf("In order jki, ");
    init_matrix(A,B,C,n);
	cnt_time(A,B,C,n,jki);

    // kji, 2
    printf("In order kji, ");
    init_matrix(A,B,C,n);
	cnt_time(A,B,C,n,kji);

    // kij, 0.5
    printf("In order kij, ");
    init_matrix(A,B,C,n);
	cnt_time(A,B,C,n,kij);
    */

    // ikj, 0.5
    printf("In order ikj, ");
    init_matrix(A,B,C,n);
	cnt_time(A,B,C,n,ikj);

    // block ijk
    printf("BLOCK, In order ijk, ");
    init_matrix(A,B,C,n);
	cnt_time(A,B,C,n,blocked_ijk);
}