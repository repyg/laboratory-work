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
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++){
            printf("%4d\t",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int randomStrArray=1+rand()%(N-1);
    printf("%d\n\n",randomStrArray);
    for(int j=0;j<M;j++){
        int copy=a[0][j];
        a[0][j]=a[randomStrArray][j];
        a[randomStrArray][j]=copy;
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++){
            printf("%4d\t",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    int maxEvenElement=(int)-INFINITY,index;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++){
            maxEvenElement=(a[i][j]>maxEvenElement && abs(a[i][j])%2==0)?a[i][j]:maxEvenElement;
            index=(a[i][j]==maxEvenElement)?j:index;
        }
    }
    printf("%4d\t%4d\n\n",maxEvenElement,index);
    if (maxEvenElement==(int)-INFINITY){
        printf("There are no even elements in the array.");
        return 0;
    }
    if (N>=M){
        for(int i=0;i<N;i++){
            int copy=a[i][i];
            a[i][i]=a[i][index];
            a[i][index]=copy;
        }
    }else{
        for(int i=0;i<M;i++){
            int copy=a[i][i];
            a[i][i]=a[i][index];
            a[i][index]=copy;
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++){
            printf("%4d\t",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}