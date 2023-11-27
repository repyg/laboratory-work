#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define N 7
#define A -50
#define B 100

void randomNumberArray(int array[]){
    srand(time(0));
    for(int i=0;i<N;i++){
        array[i]=A+rand()%B;
    }
}

void printfArray(int array[]){
    for(int i=0;i<N;i++){
        printf("%d ",array[i]);
    }
}

int minNumberPol(int array[]){
    int min=(int)INFINITY;
    for(int i=0;i<N;i++){
        min=(array[i]>0 && array[i]<min)?array[i]:min;
    }
    min=(min==(int)INFINITY)?0:min;  
    return min;
}

int maxNumberOtr(int array[]){
    int max=(int)-INFINITY;
    for(int i=0;i<N;i++){
        max=(array[i]<0 && array[i]>max && abs(array[i])%7==0)?array[i]:max;
    }
    max=(max==(int)-INFINITY)?0:max;  
    return max;
}

int main(void){
    int array[N];
    randomNumberArray(array);
    printfArray(array);
    int min=minNumberPol(array);
    int max=maxNumberOtr(array);
    FILE *file;
    file=fopen("output.txt","w");
    fprintf(file,"%d",max*min);
    return 0;
}