#include<stdio.h>
#include<stdlib.h>

typedef struct _la{
    int* arr;
    int len;
}la;

la getDigits(long long);

long long table[13][10] = {
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
    {0, 1, 4, 9, 16, 25, 36, 49, 64, 81},
    {0, 1, 8, 27, 64, 125, 216, 343, 512, 729},
    {0, 1, 16, 81, 256, 625, 1296, 2401, 4096, 6561},
    {0, 1, 32, 243, 1024, 3125, 7776, 16807, 32768, 59049},
    {0, 1, 64, 729, 4096, 15625, 46656, 117649, 262144, 531441},
    {0, 1, 128, 2187, 16384, 78125, 279936, 823543, 2097152, 4782969},
    {0, 1, 256, 6561, 65536, 390625, 1679616, 5764801, 16777216, 43046721},
    {0, 1, 512, 19683, 262144, 1953125, 10077696, 40353607, 134217728, 387420489},
    {0, 1, 1024, 59049, 1048576, 9765625, 60466176, 282475249, 1073741824, 3486784401},
    {0, 1, 2048, 177147, 4194304, 48828125, 362797056, 1977326743, 8589934592, 31381059609},
    {0, 1, 4096, 531441, 16777216, 244140625, 2176782336, 13841287201, 68719476736, 282429536481},
    {0, 1, 8192, 1594323, 67108864, 1220703125, 13060694016, 96889010407, 549755813888, 25418658828329}
};

int main(void)
{
    int k = 0;
    printf("Input k:\n");
    scanf("%d",&k);
    
    long long* ptable = *(table+k-1);
    long long init=1;
    while(k-1){
        init*=10;
        k--;
    }

    int found = 0;
    for(long long i=init; i<10*init; i++){
        la l_a = getDigits(i);

        long long _sum=0;
        for(int j=0; j<l_a.len; j++){
            _sum += *(ptable+l_a.arr[j]);
        }
        
        if (_sum==i){
            found = 1;
            printf("%lld ",i);
        }
    }
    if (!found){
        printf("Not found.\n");
    }else{
        printf("\n");
    }
    
    return 0;
}

la getDigits(long long k){
    long long copy_k = k;
    la ret;
    ret.len = 0;
    while(copy_k){
        copy_k /= 10;
        ret.len++;
    }
    ret.arr = (int*)malloc((ret.len)*sizeof(int));
    ret.len = 0;
    while(k){
        *(ret.arr+ret.len) = k%10;
        ret.len++;
        k/=10;
    }
    return ret;
}