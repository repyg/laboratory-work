#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 5

int main(void){
    int a[N];
    srand(time(0));
    for(int i = 0; i < N; i++){
        a[i]=-100+rand()%200;
        printf("%3d\t",a[i]);
    }
    printf("\n");
    int minA=a[0],index=0;
    for(int i = 0; i < N; i++){
        if (a[i]<minA){
            minA=a[i];
            index=i;
        }
    }
    for(int i = 0; i < index/2; i++){
        int copy=a[i];
        a[i]=a[index-i-1];
        a[index-i-1]=copy;
    }
    for(int i = 0; i < N; i++)
        printf("%3d\t",a[i]);
// printf("\n\n");
//     int b[N][N];
//     for(int i = 0; i < N; i++) {
//         for(int j = 0; j < N; j++){
//             b[i][j]=-100+rand()%200;
//             printf("%4d\t",b[i][j]);
//         }
//         printf("\n");
//     }
//     printf("\n");
//     for(int j = 2; j<N; j++) {
//         int copyColum[j], k=0;
//         for(int i=N-j; i<N; i++){
//             copyColum[k]=b[i][j];
//             k+=1;
//         }
//         k-=1;
//         for(int i=N-j; i<N; i++){
//             b[i][j]=copyColum[k];
//             k-=1;
//         }
//     }
//     for(int i = 0; i < N; i++) {
//         for(int j = 0; j < N; j++){
//             printf("%4d\t",b[i][j]);
//         }
//         printf("\n");
//     }
}