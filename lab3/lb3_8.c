#define N 5
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillingTheArray(double a[N][N],int maxNumberOfGaps, int minNumberOfGaps){
    srand(time(NULL));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            double x = (float) rand() / RAND_MAX * (maxNumberOfGaps - (minNumberOfGaps)) + (minNumberOfGaps);
            a[i][j]=x;
        }
    }
}

double sumOf10RandomNumbers(double a[N][N]){
    srand(time(NULL));
    double sum=0;
    for(int i=0;i<10;i++){
        int x=(rand()%(N+1)), y=(rand()%(N+1));
        sum+=a[x][y];
    }
    return sum;
}

int numberOfNegativeNumbersOnTheSideDiagonal(double array[N][N]){
    int count=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==(N-j-1) && array[i][j]<0)
                count+=1;
        }
    }
    return count;
}

double minimumPositiveElementAboveTheMainDiagonal(double array[N][N]){
    double min = 1000000;
    for(int i=0;i<N;i++){
        for(int j=i;j<N;j++){
            min=(array[i][j]<min && array[i][j]>0)?array[i][j]:min;
        }
    }
    return min;
}

int main(void){
    double a[N][N];
    int A=-100, B=100;
    fillingTheArray(a,A,B);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%f\t",a[i][j]);
        }
        printf("\n");
    }
    printf("%f\n",sumOf10RandomNumbers(a));
    printf("%d\n",numberOfNegativeNumbersOnTheSideDiagonal(a));
    printf("%f",minimumPositiveElementAboveTheMainDiagonal(a));
}