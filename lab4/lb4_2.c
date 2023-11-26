#define N 5
#define M 5

#include <math.h>
#include <time.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
    int b[N][M];
    srand(time(0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++){
            b[i][j]=-100+rand()%200;
        }
    }
    
    int maxElementStr[N],columnProduct[M];
    for(int i=0;i<N;i++)
        maxElementStr[i]=(int)-INFINITY;
    for(int i=0;i<M;i++)
        columnProduct[i]=1;
    for(int i = 0; i < N; i++) {
        maxElementStr[i];
        for(int j = 0; j < M; j++){
            printf("%d\t",b[i][j]);
            maxElementStr[i]=(b[i][j]>maxElementStr[i] && abs(b[i][j])%7==0)?b[i][j]:maxElementStr[i];
            if (b[i][j]<0 && abs(b[i][j])%2==0)
                columnProduct[j]*=abs(b[i][j]);
            if (j==M-1){
                if (maxElementStr[i]==(int)-INFINITY)
                    maxElementStr[i]=0;
                printf("%d\n",maxElementStr[i]);
            }
        }
    }
    for(int i=0;i<M;i++){
        if (columnProduct[i]==1)
            columnProduct[i]=0;
        printf("%d\t",columnProduct[i]);
    }
}