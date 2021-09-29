#include <stdio.h>
#include <stdlib.h>

int F(int n){
    if(n==0){
        return 0;
    }else if(n==1){
        return 1;
    }else{
        return F(n-1)+F(n-2);
    }

}

int fibbonaci(int n){
    if(n==0){
        return 0;
    }else if(n==1){
        return 1;
    }else{
        int prev = 0;
        int curr = 1;
        while(n-1){
            int tmp = curr;
            curr += prev;
            prev = tmp;
            n--;
        }
        return curr;
    }
}

int main(int argc, char **argv)
{
    int N;
    N = atoi(argv[1]);
    // for(int i=0; i<=N;i++){
    //     printf("terme %d, by loop %d, by recursion %d\n",i,fibbonaci(i),F(i));
    // }
    printf("%d\n",fibbonaci(N));
    return 0;
}
