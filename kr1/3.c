#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define M 5
#define A -50
#define B 100

void randomNumberArray(int array[N][M]){
    srand(time(0));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
           array[i][j]=A+rand()%B; 
        }     
    }
}

void printfArray(int array[N][M]){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
           printf("%5d",array[i][j]); 
        }
        printf("\n");     
    }
}

float crZnachenie(int array[N][M]){
    float sum=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
           sum+=array[i][j];
        }     
    }
    float cr=sum/(N*M);
    return cr;
}

int maxElement(int array[N][M]){
    int max=0;
    for(int i=0;i<N;i++){
        if(array[i][i]%3==0){
            max=array[i][i];
            break;
        }
    }
    for(int i=0;i<N;i++){
        max=(array[i][i]>max && array[i][i]%3==0)?array[i][i]:max;
    }
    return max;
}

int main(void){
    int array[N][M];
    randomNumberArray(array);
    printfArray(array);
    printf("\n");
    printf("%.2f ",crZnachenie(array)*maxElement(array));
    return 0;
}