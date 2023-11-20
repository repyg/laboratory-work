#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define M 5

void fillingArray(int array[N][M],int a,int b){
    srand(time(NULL));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)
            array[i][j]=a+rand()%(b-a+1);
    } 
}

void outputArray(int array[N][M]){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)
            printf("%5d\t",array[i][j]);
        printf("\n"); 
    }
    printf("\n");

}

void outputPositiveEvenArrayElements(int array[N][M]){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(array[i][j]>0 && array[i][j]%2==0)
                printf("%5d\t", array[i][j]);
            else
                printf("    *\t");
        }
        printf("\n"); 
    }
    printf("\n"); 
}

int main(){
    int a=-100, b=200, array[N][M];
    fillingArray(array,a,b);
    outputArray(array);
    outputPositiveEvenArrayElements(array);
}