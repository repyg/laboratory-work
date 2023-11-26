#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 5

int main(void){
    int a[N][N];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++){
            a[i][j]=-100+rand()%200;
            printf("%4d\t",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int j=0;j<N;j++){
        for(int q=0;q<=N;q++){
            for(int i=1;i<N;i++){
                if (a[i][j]<a[i-1][j]){
                    int copy=a[i][j];
                    a[i][j]=a[i-1][j];
                    a[i-1][j]=copy;
                }
            }
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++){
            printf("%4d\t",a[i][j]);
        }
        printf("\n");
    }
}