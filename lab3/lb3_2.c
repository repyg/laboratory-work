#define N 10
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    int a[N];
    int A=10, B=100;
    srand(time(NULL));
    int i=0;
    while(i<N){
        int x = A + rand() % (B - A +1);
        
        int x1=x;
        int sumx=0;
        while(x1>0){
            sumx+=(x1%10);
            x1/=10;
        }
        if (sumx<=5){
            a[i]=x;
            i+=1;
        }
    }

    for(int i=0;i<N;i++)
        printf("%d\t",a[i]);
    return 0;
}