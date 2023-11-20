#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 12

int main(void){
    int a[N];
    srand(time(0));
    for(int i = 0; i < N; i++){
        a[i]=-100+rand()%200;
        printf("%3d\t",a[i]);
    }
    printf("\n");
    int k;
    scanf("%d",&k);
    for (int j=0;j<N/k;j++){
        for(int q=0;q<=k;q++){
            for(int i=0;i<k;i++){
                if (a[i+j*k]>a[i+1+j*k]){
                    int copy=a[i+j*k];
                    a[i+j*k]=a[i+1+j*k];
                    a[i+1+j*k]=copy;
                }
            }
        }
    }
    for(int i = 0; i < N; i++){
        printf("%3d\t",a[i]);
        if((i+1)%k==0)
            printf("\n");
    }
}