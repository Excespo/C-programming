#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "matrix.h"

int main(int argc, char** argv) {
    srand((unsigned)(time(NULL)));
    double mat1[N_ROW][N_COL];
    matrix_assign((double *)mat1, N_ROW, N_COL);
    printf("\nmat1 = \n");
    matrix_repr((double *)mat1, N_ROW, N_COL);

    return 0;
}