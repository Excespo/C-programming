/* 
 * trans.c - Matrix transpose B = A^T
 *
 * Each transpose function must have a prototype of the form:
 * void trans(int M, int N, int A[N][M], int B[M][N]);
 *
 * A transpose function is evaluated by counting the number of misses
 * on a 1KB direct mapped cache with a block size of 32 bytes.
 */ 
#include <stdio.h>
#include "cachelab.h"

int is_transpose(int M, int N, int A[N][M], int B[M][N]);

/* 
 * transpose_submit - This is the solution transpose function that you
 *     will be graded on for Part B of the assignment. Do not change
 *     the description string "Transpose submission", as the driver
 *     searches for that string to identify the transpose function to
 *     be graded. 
 */
char transpose_submit_desc[] = "Transpose submission";
void transpose_submit(int M, int N, int A[N][M], int B[M][N])
{
    if (M == 32){
        /* 理论值为256
         * 一个(5,1,5)的cache每一line最多容纳2^5/4 = 8 int, 因此考虑8*8 blocking.
         * 共4*4个block, 每个block中, 新引进一个row的数据都将造成1次miss, 此外, AB各有8个row, 这将造成额外的8次覆盖, 总共是16次miss.
         * 16 * 16 = 256
         * 若只考虑blocking, 实际中将会造成343次miss, 这是因为在读到主对角线上的元素时, A[k][l] = B[l][k]会将主对角线元素映射到同一行(矩阵大小正好为32*32=S*B), 于是在写B这个元素时必须将已有的A的一行替换,然而写下一个元素之前又必须将被替换掉的A读回来.
         * 使用额外的变量存储一整行可以将miss降到287, 就是避免了这个问题.
         * 这里没有达到理论值的原因是, B在对角线上仍有miss, https://zhuanlan.zhihu.com/p/79058089 介绍了降到259次miss的方法
         */
		int i, j, k, e1, e2, e3, e4, e5, e6, e7, e8;
    	for (i = 0; i < N; i+=8){
        	for (j = 0; j < M; j+=8){
                for (k = i; k < i+8; k++){
                    e1 = A[k][j]  ;
                    e2 = A[k][j+1];
                    e3 = A[k][j+2];
                    e4 = A[k][j+3];
                    e5 = A[k][j+4];
                    e6 = A[k][j+5];
                    e7 = A[k][j+6];
                    e8 = A[k][j+7];
                    B[j][k]   = e1;
                    B[j+1][k] = e2;
                    B[j+2][k] = e3;
                    B[j+3][k] = e4;
                    B[j+4][k] = e5;
                    B[j+5][k] = e6;
                    B[j+6][k] = e7;
                    B[j+7][k] = e8;
                }
        	}
    	}   
    }
    else if (M==61){
        /* 摆烂 */
        int i, j, k, l;
        for (i = 0; i < N; i+=16){
            for (j = 0; j < M; j+=16){
                for (k = i; k < i + 16 && k < N; k++){
                    for (l = j; l < j + 16 && l < M; l++){
                        B[l][k] = A[k][l];
                    }
                }
            }
        }
    }
    else if (M==64){
        /* 
         * 8*8 blocking 肯定不是最好的了, 因为矩阵一行就有64个元素, 也就是读4行的时候就会填满cache, 相差4行的两个元素就会发生conflict. 4611miss
         * 4*4 blocking 不能完整的利用cache, 但是相对来说利用率会高很多. 可以达到1699次miss.
         * 策略是在8*8的基础上, 再作2*2划分. 读入A的4个8int后, 先将其不转置地存入分块矩阵的对称位置
         */
        int i, j, k, l, v0, v1, v2, v3, v4, v5, v6, v7;
        for (i = 0; i < N; i+=8){
            for (j = 0; j < M; j+=8){
                for (k = i; k < i + 4; k++){
                    v0 = A[k][j];
                    v1 = A[k][j+1];
                    v2 = A[k][j+2];
                    v3 = A[k][j+3];
                    v4 = A[k][j+4];
                    v5 = A[k][j+5];
                    v6 = A[k][j+6];
                    v7 = A[k][j+7];

                    B[j][k] = v0;
                    B[j+1][k] = v1;
                    B[j+2][k] = v2;
                    B[j+3][k] = v3;

                    B[j][k+4] = v7;
                    B[j+1][k+4] = v6;
                    B[j+2][k+4] = v5;
                    B[j+3][k+4] = v4;
                }

                for (l = 0; l < 4; l++) {
                    
                    v0 = A[i+4][j+3-l];
                    v1 = A[i+5][j+3-l];
                    v2 = A[i+6][j+3-l];
                    v3 = A[i+7][j+3-l];
                    v4 = A[i+4][j+4+l];
                    v5 = A[i+5][j+4+l];
                    v6 = A[i+6][j+4+l];
                    v7 = A[i+7][j+4+l];

                    B[j+4+l][i] = B[j+3-l][i+4];
                    B[j+4+l][i+1] = B[j+3-l][i+5];
                    B[j+4+l][i+2] = B[j+3-l][i+6];
                    B[j+4+l][i+3] = B[j+3-l][i+7];
                    
                    B[j+3-l][i+4] = v0;
                    B[j+3-l][i+5] = v1;
                    B[j+3-l][i+6] = v2;
                    B[j+3-l][i+7] = v3;
                    B[j+4+l][i+4] = v4;
                    B[j+4+l][i+5] = v5;
                    B[j+4+l][i+6] = v6;
                    B[j+4+l][i+7] = v7;
                }
            }
        }
    }
}

/* 
 * You can define additional transpose functions below. We've defined
 * a simple one below to help you get started. 
 */ 

/* 
 * trans - A simple baseline transpose function, not optimized for the cache.
 */
char trans_desc[] = "Simple row-wise scan transpose";
void trans(int M, int N, int A[N][M], int B[M][N])
{
    int i, j, tmp;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            tmp = A[i][j];
            B[j][i] = tmp;
        }
    }    

}

/*
 * registerFunctions - This function registers your transpose
 *     functions with the driver.  At runtime, the driver will
 *     evaluate each of the registered functions and summarize their
 *     performance. This is a handy way to experiment with different
 *     transpose strategies.
 */
void registerFunctions()
{
    /* Register your solution function */
    registerTransFunction(transpose_submit, transpose_submit_desc); 

    /* Register any additional transpose functions */
    registerTransFunction(trans, trans_desc); 

}

/* 
 * is_transpose - This helper function checks if B is the transpose of
 *     A. You can check the correctness of your transpose by calling
 *     it before returning from the transpose function.
 */
int is_transpose(int M, int N, int A[N][M], int B[M][N])
{
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; ++j) {
            if (A[i][j] != B[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

