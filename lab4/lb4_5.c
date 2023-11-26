#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 10

int main(void){
    int a[N];
    srand(time(NULL));
    for(int i=0;i<N;i++)
        a[i]=-100+rand()%200;
    for(int i=0;i<N;i++)
        printf("%d\t",a[i]);
    printf("\n");
    int j=0;
    while(j<N){
        int count=0;
        for(int i=1;i<N;i++){
            if (abs(a[i])%2==0){
                int copy=a[i-1];
                a[i-1]=a[i];
                a[i]=copy;
            }
        }
        j+=1;
    }
    for(int i=0;i<N;i++)
        printf("%d\t",a[i]);
}