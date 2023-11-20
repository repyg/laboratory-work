#define M 5
#define N 5
#include <stdio.h>

int main(void){
    int A=10,B=100;
    int init_array[N][M];
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            init_array[i][j]=(A+i*M+j);
        }
    }
    
    FILE *file;
    file=fopen("lb3_6.txt", "r+");
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            fprintf(file,"%d\t",init_array[i][j]);
        }
    fprintf(file,"\n");
    }
    fclose(file);

    FILE *newfile;
    newfile=fopen("lb3_6.txt", "r");
    int new_array[N][M];
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            fscanf(newfile,"%d",&new_array[i][j]);
        }
    }
    int max=new_array[0][0],multiples4=0,ending0=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if (new_array[i][j]%4==0)
                multiples4+=1;
            max=(new_array[i][j]>max && j<(M-i-1))?new_array[i][j]:max;
            if (new_array[i][j]%10==0)
                ending0+=1;
        }
    }
    printf("%d %d %d",multiples4,max,ending0);
}