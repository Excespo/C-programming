# Matrix Multiplication Optimisation

# Naive realisation

## order of loop

Why? -> Cache

```terminal
yijie@speit01:~/C-programming$ ./matmul.outMATRIX MUL with size 2000:
In order ijk, C[25][25]=-1529100296 Use time: 33.111418
In order jik, C[25][25]=-1529100296 Use time: 31.141375
In order jki, C[25][25]=-1529100296 Use time: 75.188948
In order kji, C[25][25]=-1529100296 Use time: 73.261576
In order kij, C[25][25]=-1529100296 Use time: 22.384581
In order ikj, C[25][25]=-1529100296 Use time: 22.560776
```

# Block mul

```terminal
yijie@speit01:~/C-programming/optim/matmul$ cd "/home/yijie/C-programming/optim/matmul/" && gcc matmul.c -o matmul.out && "/home/yijie/C-programming/optim/matmul/"matmul.out
MATRIX MUL with size 4096:
In order ijk, C[25][25]=1845155840 Use time: 942.492340 secs
In order ikj, C[25][25]=1845155840 Use time: 194.292517 secs
BLOCK, In order ijk, C[25][25]=1845155840 Use time: 371.085692 secs
```
