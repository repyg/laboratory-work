#define N 5
#define M 5

#include <math.h>
#include <time.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
    int a[N][M];
    srand(time(0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++){
            a[i][j]=-100+rand()%200;
        }
    }
    int * arr;
    arr = (int*)malloc(M * sizeof(int));
    int minSumEven=(int) INFINITY;
    for(int i = 0; i < N; i++) {
        int sumEven=0;
        for(int j = 0; j < M; j++){
            if(abs(a[i][j])%2==0)
                sumEven+=a[i][j];
        }
        arr[i]=sumEven;
        minSumEven=(sumEven<minSumEven)?sumEven:minSumEven;
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++){
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0;i<N;i++)
        printf("%d\t",arr[i]);
    printf("\n\n");
    for(int i=0;i<N;i++){
        if (arr[i]==minSumEven)
            printf("%d\t",++i);
    }
}