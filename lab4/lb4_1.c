#define N 5
#define M 5

#include <math.h>
#include <time.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
    int a[N];
    srand(time(0));
    for(int i = 0; i < N; i++){
        a[i]=-10000+rand()%20000;
        printf("%d\t",a[i]);
    }
    printf("\n");

    int averageValue=0,count=0;
    for(int i=0;i<N;i++)
        averageValue+=a[i];
    averageValue=averageValue/N;
    for(int i = 0; i < N; i++)
        count+= (abs(a[i])%2==1 && a[i]>averageValue)?1:0;

    int * arr;
    arr = (int*)malloc(count * sizeof(int));
    for(int i=0, j=0; i < N; i++) {
        if (abs(a[i])%2==1 && a[i]>averageValue){
            arr[j]=a[i];
            j++;
        }
    }

    for(int i = 0; i < count; i++)
        printf("%d\t",arr[i]);
    printf("\n\n");
    free(arr);

    int b[N][M];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++){
            b[i][j]=-10000+rand();
            printf("%d\t",b[i][j]);
            if (j==M-1)
                printf("\n");
        }
    }
    count=0;
    for(int i=0;i<N;i++){
        for(int j=1;j<M;j+=2){
            count+=(b[i][j]<0)?1:0;
        }
    }
    int * arr1;
    arr1 = (int*)malloc(count * sizeof(int));
    for(int i=0,k=0;i<N;i++) {
        for(int j=1;j<M;j+=2){
            if (b[i][j]<0){
                arr1[k]=b[i][j];
                k++;
            }
        }
    }
    for(int i = 0; i < count; i++)
        printf("%d\t",arr1[i]);
}