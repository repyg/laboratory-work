#define N 10
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    FILE *file;
    file = fopen("lb3_5.txt", "w");
    int a[N];
    int A=10, B=100;
    srand(time(NULL));
    for(int i=0;i<N;i++){
        int x = A + rand() % (B - A +1);
        fprintf(file, "%d\t", x);
        a[i]=x;
    }
    double sumx=0;
    for(int i=0;i<N/2;i++)
        sumx+=a[i];
    fprintf(file, "\n%.2f\t", sumx/(N/2));
    sumx=0;
    for(int i=N/2;i<N;i++)
        sumx+=a[i];
    fprintf(file, "%.2f\t", sumx/(N/2));
}