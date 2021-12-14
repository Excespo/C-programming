#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "matrix.h"

err_t matrix_assign(double* mat, size_t n_row, size_t n_col){
    if (n_row<=0 || n_col<=0){
        return MATRIX_FAIL;
    }
    size_t row, col;
    for (row=0; row<n_row; row++){
        for (col=0; col<n_col; col++){
           mat[row*n_col+col] = (double)(rand()%100);
        }
    }
    return MATRIX_OK;
}

err_t matrix_repr(double* mat, size_t n_row, size_t n_col){
    if (n_row<=0 || n_col<=0){
        return MATRIX_FAIL;
    }
    size_t row, col;
    printf("array([");
    for(row=0; row<n_row; row++){
        printf("[");
        for(col=0; col<n_col; col++){
            printf("%.3f,",mat[row*n_col+col]);
        }
        printf("],\n");
    }
    printf("])");
    return MATRIX_OK;
}

err_t matrix_add(double* mat1, double* mat2, double* res, double lmd1, double lmd2, double k, size_t n_row, size_t n_col){
    if (n_row<=0 || n_col<=0){
        return MATRIX_FAIL;
    }
    size_t row, col;
    for (row=0; row<n_row; row++){
        for (col=0; col<n_col; col++){
            res[row*n_col+col] = lmd1*mat1[row*n_col+col] + lmd2*mat2[row*n_col+col] + k;
        }
    }
    return MATRIX_OK;
}

err_t matrix_matmul(double * mat1, double * mat2, double * res, size_t n_row1, size_t n_col1, size_t n_row2, size_t n_col2){
    if (n_col1!=n_row2) return MATRIX_FAIL;
    if (n_row1<=0 || n_col1<=0 || n_row2<=0 || n_col2<=0) return MATRIX_FAIL;
    size_t row, col;
    for (row=0; row<n_row1; row++){
        for (col=0; col<n_col2; col++){
            res[row*n_col2+col] = 0;
            for (size_t k=0; k<n_col1; k++){
            res[row*n_col2+col] += mat1[row*n_col1+k]*mat2[k*n_col2+col];
            }
        }
    }
    return MATRIX_OK;
}