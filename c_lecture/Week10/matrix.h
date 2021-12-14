#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#ifndef _MATRIX__H
#define _MATRIX__H

#define N_ROW 4
#define N_COL 4

enum err_t {
    MATRIX_OK = 0,
    MATRIX_FAIL = -1,
};
typedef enum err_t err_t;

err_t matrix_assign(double* mat, size_t n_row, size_t n_col);

err_t matrix_repr(double* mat, size_t n_row, size_t n_col);

err_t matrix_add(double* mat1, double* mat2, double* res, double lmd1, double lmd2, double k, size_t n_row, size_t n_col);

err_t matrix_matmul(double * mat1, double * mat2, double * res, size_t n_row1, size_t n_col1, size_t n_row2, size_t n_col2);

#endif